#ifndef FOOD_H_   /* Include guard */
#define FOOD_H_
class Food
{
public:
    int x_pos, y_pos;
    char data;
    Food* next;
    Food* prev;
    Food();
    Food(int x, int y, int dt = 'A');
};

#endif
