#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define BUF_SIZE 256

int main(int argc, char **argv)
{
    struct sockaddr_in svaddr;
    struct sockaddr_in6 svaddr6;
    int sfd;
    int j = 0;
    size_t msg_len;
    ssize_t num_bytes;
    char resp[BUF_SIZE];
    char msg[BUF_SIZE];
    bool is_ipv6 = false;

    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "%s host-address msg...\n", argv[0]);
        exit(1);
    }

    // Проверка на ввод адреса 
    if (inet_pton(AF_INET, argv[1], &svaddr.sin_addr) == 1)
    {
        memset(&svaddr, 0, sizeof(struct sockaddr_in));
        svaddr.sin_family = AF_INET;
        svaddr.sin_port = htons(atoi(argv[2]));
        sfd = socket(AF_INET, SOCK_STREAM, 0);
    }
    else if (inet_pton(AF_INET6, argv[1], &svaddr6.sin6_addr) == 1)
    {
        memset(&svaddr6, 0, sizeof(struct sockaddr_in6));
        svaddr6.sin6_family = AF_INET6;
        svaddr6.sin6_port = htons(atoi(argv[2]));
        sfd = socket(AF_INET6, SOCK_STREAM, 0);
        is_ipv6 = true;
    }
    else
    {
        // Преобразование доменного имени в адрес
        struct addrinfo hints, *result;
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        int r = getaddrinfo(argv[1], NULL, &hints, &result);
        if (r != 0)
        {
            fprintf(stderr, "getaddrinfo: %s\n", strerror(r));
            exit(EXIT_FAILURE);
        }

        struct addrinfo *p;
        for (p = result; p != NULL; p = p->ai_next)
        {
            if (p->ai_family == AF_INET)
            {
                memset(&svaddr, 0, sizeof(struct sockaddr_in));
                svaddr.sin_family = AF_INET;
                svaddr.sin_port = htons(atoi(argv[2]));
                svaddr.sin_addr = ((struct sockaddr_in *)p->ai_addr)->sin_addr;
                sfd = socket(AF_INET, SOCK_STREAM, 0);
            }
            else if (p->ai_family == AF_INET6)
            {
                memset(&svaddr6, 0, sizeof(struct sockaddr_in6));
                svaddr6.sin6_port = htons(atoi(argv[2]));
                svaddr6.sin6_family = AF_INET6;
                svaddr6.sin6_addr = ((struct sockaddr_in6 *)p->ai_addr)->sin6_addr;
                sfd = socket(AF_INET6, SOCK_STREAM, 0);
                is_ipv6 = true;
            }
        }

        freeaddrinfo(result);
    }

    if (sfd == -1) {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
        exit(1);
    }

    while (true) {
        fgets(msg, BUF_SIZE, stdin);
        msg_len = strlen(msg);
        if (send(sfd, msg, msg_len, 0) != msg_len) {
            fprintf(stderr, "sendto\n");
            exit(1);
        }

        num_bytes = recv(sfd, resp, BUF_SIZE, 0);
        if (num_bytes == -1) {
            fprintf(stderr, "recvfrom\n");
            exit(1);
        }

        printf("Response %d: %.*s\n", ++j, (int)num_bytes, resp);
    }

    return 0;
}