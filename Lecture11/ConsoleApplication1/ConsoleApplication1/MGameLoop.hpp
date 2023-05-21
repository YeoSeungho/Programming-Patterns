#define Key_ESC 27
#define Key_RIGHT 'd'
#define Key_LEFT 'a'
#define Key_ENTER 13

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

namespace MuSoeun
{
	void gotoxy(int x, int y) {
		//x, y 좌표 설정
		COORD pos = { x,y };
		//커서 이동
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	class MGameLoop
	{
	public:

		bool isGameRunning = false;

		MGameLoop() {}
		~MGameLoop() {}

		void Initialize()
		{
			isGameRunning = true;
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "초기화 완료" << std::endl;
		}

		void Release()
		{
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "시스템 해제 완료" << std::endl;
		}

		void Update()
		{
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "업데이트중 완료" << std::endl;
			if (_kbhit())
			{

				keyEvent(_getch());
			}

		}
		void Render()
		{
			gotoxy(0, 10);
			std::cout << ANSI_COLOR_MAGENTA "렌더링 완료" << std::endl;
		}

		void Run()
		{
			Initialize();

			while (isGameRunning)
			{
				Update();
				Render();
			}

			Release();

		}

		void keyEvent(char KeyInput)
		{
			int a, b;
			switch (KeyInput)
			{
			case Key_LEFT:	//왼쪽 화살표키
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"왼쪽이 눌렸다!  " << std::endl;
				break;
			case Key_RIGHT:	//오른쪽 화살표키
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"오른쪽이 눌렸다!" << std::endl;
				break;
			case Key_ESC:
				/*
				 *  학번 : 202034014 이름 : 여승호
				 *	방향 키 왼쪽[예] 오른쪽[아니오] 이고
				 *	활성화 된 메뉴는 노란색으로 비활성화된 메뉴는 원래 색상으로
				 *	예를 누른 뒤 Enter 키를 누르면  빠져 나오는 프로그램입니다.
				 */
				 // 메뉴 출력
				system("cls");// 콘솔 화면을 지우고 새로운 내용을 출력하기
				std::cout << ANSI_COLOR_RESET << "종료하시겠습니까?\n\n";
				std::cout << ANSI_COLOR_RESET << " [ 예 ] " << ANSI_COLOR_RESET << "   [ 아니오 ]" << std::endl;
				std::cout << " " << ANSI_COLOR_RESET << "   " << "     " << std::endl;

				while (isGameRunning) // 메뉴 선택
				{
					int ch = _getch();
					switch (ch)// 왼쪽 화살표(75) 또는 오른쪽 화살표(77) 입력 처리
					{
					case 75:
						system("cls");// 콘솔 화면을 지우고 새로운 내용을 출력하기
						std::cout << "종료하시겠습니까?\n\n";
						std::cout << ANSI_COLOR_YELLOW << " [ 예 ] " << ANSI_COLOR_RESET << "   [ 아니오 ]" << std::endl;
						std::cout << " " << ANSI_COLOR_RESET << "   " << "     " << std::endl;
						ch = _getch();
						if (ch == 13)// Enter 키를 입력했는지 확인
						{
							isGameRunning = false;// 프로그램 종료
						}
						break;
					case 77:
						system("cls");// 콘솔 화면을 지우고 새로운 내용을 출력하기
						std::cout << "종료하시겠습니까?\n\n";
						std::cout << ANSI_COLOR_RESET << " [ 예 ] " << "   " << ANSI_COLOR_YELLOW << " [ 아니오 ]" << ANSI_COLOR_RESET << std::endl;
						std::cout << "     " << "   " << " " << std::endl;
						break;
					default:
						break;
					}
				}
				break;

			case Key_ENTER:
				gotoxy(2, 5);
				std::cout << ANSI_COLOR_YELLOW"엔터가 눌렸다!  " << std::endl;
				break;

			default:
				gotoxy(2, 5);
				break;
			}
		}
	};
}