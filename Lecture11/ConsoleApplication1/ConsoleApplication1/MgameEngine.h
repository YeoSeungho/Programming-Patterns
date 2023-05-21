#pragma once
#include <vector>
#include <Windows.h>

using namespace std;

namespace Musoeun
{
	
	void gotoxy(int x, int y) {
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	void SetCursorState(bool state)
	{
		CONSOLE_CURSOR_INFO consoleCursorInfo;
		consoleCursorInfo.bVisible = state;
		consoleCursorInfo.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
	}
	class Component
	{
	public:
		void Start();
		void Update();
	};

	class Object
	{
	public:

		int Object_position_x = 0;
		int Object_position_y = 0;

		int Object_scale_x = 1;
		int Object_scale_y = 1;

		bool SetActive = true;

		Object(int x, int y)
		{
			SetPosition(x, y);
		}
		~Object() {}

		void SetPosition(int x, int y)
		{
			Object_position_x = x;
			Object_position_y = y;
		}
		void Render(char* ScreenBuffer)
		{
			if (SetActive)
			{
				ScreenBuffer[(Object_position_x + 1) * Object_position_y] = '^';
			}
		}

		vector<class Component> components;
	};

	class Scene
	{
	public:
		int width;
		int height;


		std::vector<std::vector<char>> screenBuf;
		std::vector<Object> objList;

		char* ScreenBuf;
		void InitScreenBuf()
		{

			screenBuf.resize(height, std::vector<char>(width, '#'));
			for (int i = 1; i < height - 1; i++)
			{
				gotoxy(0, 0);
				for (int j = 1; j < width - 1; j++)
				{
					screenBuf[i][j] = ' ';
				}
			}
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					std::cout << screenBuf[i][j];
				}
				std::cout << std::endl;
			}
		}
		void ReleaseScreenBuf()
		{
			if (ScreenBuf != nullptr)
			{
				delete(ScreenBuf);
			}
		}

		void DrawScreenBuf()
		{
			
			
		}
	};

	void MGame()
	{
		Scene scene;
		scene.width = 22;
		scene.height = 20;
		Object obj(1, 1);

		while (true)
		{
			system("cls");
			scene.InitScreenBuf();
			scene.ReleaseScreenBuf();
			scene.DrawScreenBuf();
		}
	};
}