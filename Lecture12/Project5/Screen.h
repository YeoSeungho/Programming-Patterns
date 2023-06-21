#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <thread>
#include "Grid.h"
#include "Snake.h"
#include "Food.h"

#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_RESET    "\x1b[0m"

using namespace std;

namespace MuSoeun
{
    int getRand(int mx)
    {
        return rand() % mx;
    }
    int print_title_screen()
    {
        std::cout << "******************************************" << std::endl;
        std::cout << "*                                        *" << std::endl;
        std::cout << "*                                        *" << std::endl;
        std::cout << "*            F���� �� ���ض�             *" << std::endl;
        std::cout << "*          (Avoid getting an F)          *" << std::endl;
#ifdef DEBUG
        std::cout << "*            - ����� ��� -             *" << std::endl;
#else
        std::cout << "*                                        *" << std::endl;
#endif  
        std::cout << "*   1. ���� ����                         *" << std::endl;
        std::cout << "*   2. ���� ����                         *" << std::endl;
        std::cout << "*   3. ���� ���� (esc)                   *" << std::endl;
        std::cout << "******************************************" << std::endl;
        return 0;
    }

    int print_GameRule_screen()
    {
        std::cout << "******************************************" << std::endl;
        std::cout << "*                                        *" << std::endl;
        std::cout << "*                                        *" << std::endl;
        std::cout << "*             < ���� ���� >              *" << std::endl;
        std::cout << "*           (Game Description)           *" << std::endl;

#ifdef DEBUG
        std::cout << "*            - ����� ��� -             *" << std::endl;
#else
        std::cout << "*                                        *" << std::endl;
#endif  
        std::cout << "*   1. �⺻ �̵�Ű�� (W A S D)           *" << std::endl;
        std::cout << "*                                        *" << std::endl;
        std::cout << "*   2. A�� ������ �����̴� �þ��      *" << std::endl;
        std::cout << "*                                        *" << std::endl;
        std::cout << "*   3. �� 10���� ������ ���� �¸�!!      *" << std::endl;
        std::cout << "*                                        *" << std::endl;
        std::cout << "*   4. ������ ���� �ε�ġ��Game over!!   *" << std::endl;
        std::cout << "*                                        *" << std::endl;
        std::cout << "******************************************" << std::endl;
        return 0;
    }

    void screen()
    {
        print_title_screen();
        int i = 0;
        bool Rulesonoff = true;
        bool Rulesonoff1 = true;
        bool isGameRunning = true;
        bool isGame = true;
        bool isGame2 = true;
        bool isGame3 = true;
        bool onoff = true;
        int x_max = 20, y_max = 20;
        int t1 = 0, t2 = -1;
        int score = -1, speed = 500;
        bool food_available = 0;
        int ch = _getch();
        char mov = 'a';
        Grid* board = new Grid(x_max, y_max);
        Snake* python = new Snake(x_max / 2, y_max / 2);
        Food* food = nullptr;
        board->addSnake(python);
        srand(time(NULL));
        while (isGameRunning)
        {
            int ch = _getch();
            switch (ch)
            {
            case '1':  
                python->Snake::Snake(9, 9);
                isGame = true;
                while (isGame)
                {  
                    isGame3 = true;
                    system("cls");
                    if (!food_available)
                    {
                        food = new Food(getRand(x_max), getRand(y_max), 'A');
                        board->addFood(food);
                        food_available = 1;
                        score++;
                    }
                    system("CLS");
                    if (board->clearGrid() == 0)
                    {
                        system("CLS");
                        std::cout << "GAME OVER" << std::endl;
                        std::cout << "SCORE: " << score << std::endl;
                        ch = _getch();
                        if (ch == 27)
                        {
                            system("CLS");
                            print_title_screen();
                            isGame = false;
                            isGame3 = false;
                            score = 0;
                        } 
                    }
                    if (isGame3) 
                    {
                        board->print();
                        cout << endl << "SCORE: " << score ;
                        Sleep(speed - (score * 5));
                        if (_kbhit())
                        {
                            switch (_getch())
                            {
                            case 'w': mov = 'w';
                                t1 = -1;
                                t2 = 0;
                                break;
                            case 'a': mov = 'a';
                                t1 = 0;
                                t2 = -1;
                                break;
                            case 's': mov = 's';
                                t1 = 1;
                                t2 = 0;
                                break;
                            case 'd': mov = 'd';
                                t1 = 0;
                                t2 = 1;
                                break;
                            case 'x':
                            default: break;
                            }
                        }
                        if (python->head->x_pos + t1 == (food->x_pos) && python->head->y_pos + t2 == (food->y_pos))
                        {
                            python->eat(food);
                            food_available = 0;
                            time_t create_time = time(nullptr);
                        }
                        else python->moveSnake(t1, t2);
                    }                  
                    if (score >= 10)
                    {
                        system("CLS");
                        std::cout << "   CLEAR   " << std::endl;
                        std::cout << "SCORE: " << score << std::endl;
                        ch = _getch();
                        if (ch == 27)
                        {
                            system("CLS");
                            print_title_screen();
                            isGame = false;
                            isGame3 = false;
                            score = 0;
                        }                        
                    }                    
                }
                break;
            case '2':
                Rulesonoff1 = true;
                system("CLS");
                print_GameRule_screen();
                while (Rulesonoff1)
                {
                    ch = _getch();
                    if (ch == 27)
                    {
                        system("cls");
                        Rulesonoff = true;
                        std::cout << ANSI_COLOR_RESET << "Ÿ��Ʋ ȭ������ ���� ���ðڽ��ϱ�?\n\n";
                        std::cout << ANSI_COLOR_RESET << " [ �� ] " << ANSI_COLOR_RESET << "   [ �ƴϿ� ]" << std::endl;
                        std::cout << " " << ANSI_COLOR_RESET << "   " << "     " << std::endl;
                        while (Rulesonoff) {
                            ch = _getch();
                            switch (ch)
                            {
                            case 75:
                                system("cls");
                                std::cout << "Ÿ��Ʋ ȭ������ ���� ���ðڽ��ϱ�?\n\n";
                                std::cout << ANSI_COLOR_YELLOW << " [ �� ] " << ANSI_COLOR_RESET << "   [ �ƴϿ� ]" << std::endl;
                                std::cout << " " << ANSI_COLOR_RESET << "   " << "     " << std::endl;
                                ch = _getch();
                                if (ch == 13)
                                {
                                    system("cls");
                                    print_title_screen();
                                    Rulesonoff = false;
                                    Rulesonoff1 = false;
                                } break;
                            case 77:
                                system("cls");
                                std::cout << "Ÿ��Ʋ ȭ������ ���� ���ðڽ��ϱ�?\n\n";
                                std::cout << ANSI_COLOR_RESET << " [ �� ] " << "   " << ANSI_COLOR_YELLOW << " [ �ƴϿ� ]" << ANSI_COLOR_RESET << std::endl;
                                std::cout << "     " << "   " << " " << std::endl;
                                ch = _getch();
                                if (ch == 13)
                                {
                                    system("cls");
                                    print_GameRule_screen();
                                    Rulesonoff = false;
                                } break;                                
                            default:
                                break;
                            }
                        }
                    }
                } break;
            case 27:
                onoff = true;
                system("cls");
                std::cout << ANSI_COLOR_RESET << "�����Ͻðڽ��ϱ�?\n\n";
                std::cout << ANSI_COLOR_RESET << " [ �� ] " << ANSI_COLOR_RESET << "   [ �ƴϿ� ]" << std::endl;
                std::cout << " " << ANSI_COLOR_RESET << "   " << "     " << std::endl;
                while (onoff) {
                    ch = _getch();
                    switch (ch)
                    {
                    case 75:
                        system("cls");
                        std::cout << "�����Ͻðڽ��ϱ�?\n\n";
                        std::cout << ANSI_COLOR_YELLOW << " [ �� ] " << ANSI_COLOR_RESET << "   [ �ƴϿ� ]" << std::endl;
                        std::cout << " " << ANSI_COLOR_RESET << "   " << "     " << std::endl;
                        ch = _getch();
                        if (ch == 13)
                        {
                            onoff = false;
                            isGameRunning = false;
                        }
                        break;
                    case 77:
                        system("cls");
                        std::cout << "�����Ͻðڽ��ϱ�?\n\n";
                        std::cout << ANSI_COLOR_RESET << " [ �� ] " << "   " << ANSI_COLOR_YELLOW << " [ �ƴϿ� ]" << ANSI_COLOR_RESET << std::endl;
                        std::cout << "     " << "   " << " " << std::endl;
                        ch = _getch();
                        if (ch == 13)
                        {
                            system("cls");
                            print_title_screen();
                            onoff = false;
                        }
                        break;
                    default:
                        break;
                    }
                }
                break;
            default:
                break;
            }

        }
    }
}
