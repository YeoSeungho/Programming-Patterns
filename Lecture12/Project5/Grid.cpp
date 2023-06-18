#include "Grid.h"

using namespace std;

Grid::Grid()
{
    rows = 40;
    cols = 40;
    arr = new char[rows * cols]();
};
Grid::Grid(int l, int b)
{
    rows = l;
    cols = b;
    arr = new char[rows * cols]();
};
char& Grid::location(int x, int y)
{   
    return arr[cols * x + y];
}
void Grid::addSnake(Snake* new_snake)
{
    snakes.push_back(new_snake);
}
void Grid::addFood(Food* new_food)
{
    food = new_food;
}
void Grid::putFoodOnGrid()
{
    location(food->x_pos, food->y_pos) = food->data;
}

bool Grid::putSnakesOnGrid()
{
    for (int i = 0; i < snakes.size(); i++)
    {
        Food* block = snakes[i]->head;
        do
        {
            location(block->x_pos, block->y_pos) = block->data;
            //cout<<block->x_pos<<" "<<block->y_pos<<endl;
            if (block->x_pos > rows || block->x_pos<0 || block->y_pos>cols || block->y_pos < 0)
                return 0;
            block = block->next;
        } while (block != NULL);
    }
    return 1;
}
bool Grid::clearGrid()
{
    for (int i = 0; i < rows * cols; i++) arr[i] = ' ';
    putFoodOnGrid();
    return putSnakesOnGrid();
}
void Grid::print()
{
    for (int i = 0; i < cols + 2; i++) cout << "# ";
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << '#';
        for (int j = 0; j < cols; j++)
            cout << " " << location(i, j);
        cout << " #" << endl;
    }
    for (int i = 0; i < cols + 2; i++) cout << "# ";
};
Grid::~Grid()
{
    delete[] arr;
};