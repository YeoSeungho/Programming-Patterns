//#define DEBUG
#include <iostream>
#include <conio.h>
#include <Windows.h>

// game_state == 0 일때
int print_title_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              지렁이 게임               *" << std::endl;
    std::cout << "*             (Snake  Bite)              *" << std::endl;

#ifdef DEBUG
    std::cout << "*            - 디버그 모드 -             *" << std::endl;
#else
    std::cout << "*                                        *" << std::endl;
#endif  
    std::cout << "*   1. 게임 시작                         *" << std::endl;
    std::cout << "*   2. 게임 설명                         *" << std::endl;
    std::cout << "*   3. 게임 랭킹 보기                    *" << std::endl;
    std::cout << "*   4. 게임 종료 (esc)                   *" << std::endl;
    std::cout << "******************************************" << std::endl;

    return 0;
}

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int print_game_screen(int stage_width, int stage_height)
{
   
    std::cout << "스테이지 크기를 입력하세요: ";
    std::cin >> stage_height >> stage_width;

    for (int i = 1; i <= stage_height; i++) {
        for (int j = 1; j <= stage_width; j++) {
            if (i == 1 || i == stage_height || j == 1 || j == stage_width) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    int x = stage_width / 2 - 1;
    int y = stage_height / 2;
    gotoxy(x, y);
    std::cout << "^^";
    return 0;
}


// game_state == 2 일때
int print_introduction_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "타이틀화면으로 돌아갈까요? (Y/N)" << std::endl;
    return 0;
}

int main()
{

    int game_state = 0;
    int is_game_running = 1;

    while (is_game_running)
    {
        char key_input = '0';
        switch (game_state)
        {
        case 0:
            print_title_screen();
            key_input = _getch();
            switch (key_input)
            {
            case '1':
                game_state = 1;
                break;
            case '2':
                game_state = 2;
                break;
            case '3':
                break;
            case '4':
                is_game_running = 0;
                break;
            case 27:
                is_game_running = 0;
                break;
            default:
                break;
            }
            break;
        case 1:
            print_game_screen(30,20);
            key_input = _getch();
            if (key_input) {
                std::cout << std::endl;
                print_title_screen();
            }
        case 2:
            print_introduction_screen();
            key_input = _getch();
            switch (key_input)
            {
            case 'y':
                game_state = 0;
                break;
            case 'n':
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }


    }

    return 0;
}
