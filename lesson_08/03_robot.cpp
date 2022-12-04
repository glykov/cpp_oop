/**
 * Написать класс «робот», моделирующий перемещения робота по сетке 10x10, 
 * у которого есть метод, означающий задание переместиться на соседнюю позицию. 
 * Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, 
 * и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне). 
 * Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. 
 * Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, 
 * а также выводящую подробную информацию о всех возникающих ошибках.
*/
#include <iostream>
#include <exception>
#include <string>
#include <sstream>

const int MAX_WIDTH = 10;
const int MAX_HEIGHT = 10;

class OffTheField : std::exception
{
public:
    OffTheField(int cur_x, int cur_y, int new_x, int new_y);
    virtual const char* what() { return message.c_str(); }
private:
    std::string message;
};

OffTheField::OffTheField(int cur_x, int cur_y, int new_x, int new_y)
{
    std::stringstream ss;
    ss << "Robot's current x position: " << cur_x;
    ss << " and current y position: " << cur_y;
    if (new_x < 1 || new_x > MAX_WIDTH) {
        ss << "\nMoving horizontally to " << new_x << " will lead Robot off the field";
    } else {
        ss << "\nMoving vertically to " << new_y << " will lead Robot off the field";
    }

    message = ss.str();
}

class IllegalCommand : std::exception
{
public:
    IllegalCommand(int cur_x, int cur_y, int new_x, int new_y);
    virtual const char* what() { return message.c_str(); }
private:
    std::string message;
};

IllegalCommand::IllegalCommand(int cur_x, int cur_y, int new_x, int new_y)
{
    std::stringstream ss;
    ss << "Robot's current x position: " << cur_x;
    ss << " and current y position: " << cur_y;
    ss << "\nMoving to " << new_x << " and " << new_y << " assumes diagonal movement ";
    ss << "which is prohibited";

    message = ss.str();
}

class Robot
{
public:
    Robot() : h_pos(1), v_pos(1) {}
    void move(int x, int y);
    std::string show_pos() const;
private:
    int h_pos;
    int v_pos;
};

// пердполагается, что робот может двигаться только горизонтально или вертикально
// на любое количество клеток, движение по диагонали запрещено
void Robot::move(int x, int y)
{
    if (x < 1 || x > MAX_WIDTH || y < 1 || y > MAX_HEIGHT) {
        throw OffTheField(h_pos, v_pos, x, y);
    }
    if (x != h_pos && y != v_pos) {
        throw IllegalCommand(h_pos, v_pos, x, y);
    }
    h_pos = x;
    v_pos = y;
}

std::string Robot::show_pos() const
{
    std::stringstream ss;

    ss << "current x position: " << h_pos;
    ss << ", current y position: " << v_pos;
    
    return ss.str();
}

int main()
{
    Robot robot;
    std::cout << "Robot position is ";
    std::cout << robot.show_pos() << std::endl;
    std::cout << "Enter new position for Robot to move.\n";
    
    std::cout << "horizontal position: ";
    int x;
    std::cin >> x;
    
    std::cout << "vertical position: ";
    int y;
    std::cin >> y;

    try {
        robot.move(x, y);
        std::cout << "Robot position is ";
        std::cout << robot.show_pos() << std::endl;
    } catch (IllegalCommand ic) {
        std::cout << ic.what() << std::endl;
    } catch (OffTheField of) {
        std::cout << of.what() << std::endl;
    }
    
    return 0;
}
