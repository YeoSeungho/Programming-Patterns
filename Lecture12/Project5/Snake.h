#ifndef SNAKE_H_   /* Include guard */
#define SNAKE_H_
#include "Food.h"

class Snake
{
public:

    Food* head, * tail;
    
    int length;

    Snake(int x, int y);

    void moveSnake(int t1, int t2);

    void eat(Food* f);


};
#endif
