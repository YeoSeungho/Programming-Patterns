#ifndef GRID_H_
#define GRID_H_
#include "Food.h"
#include <vector>
#include <iostream>
#include "Snake.h"
class Grid
{
    int rows, cols;
    char* arr;
    std::vector<Snake*> snakes;
    Food* food;
    int snakeCount;
public:
    Grid();

    Grid(int l, int b);

    char& location(int x, int y);
    void addSnake(Snake* new_snake);
    void addFood(Food* new_food);
    void putFoodOnGrid();
    bool putSnakesOnGrid();
    bool clearGrid();
    void print();
    

    ~Grid();

};
#endif
