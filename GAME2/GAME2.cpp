// GAME2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "GAME2.h"

#define MAX_LOADSTRING 100





//поле

#define N 20
#define M 20

int a[N][M] = {
{ 8, 8, 8, 8, 8,	8, 8, 8, 8, 8,	8, 8, 8, 8, 8,   8, 8, 8, 8, 8 },
{ 8, 3, 0, 0, 2,	2, 2, 0, 2, 0,	0, 0, 2, 0, 2,   2, 2, 0, 0, 8 },
{ 8, 0, 8, 8, 0,	2, 2, 0, 2, 8,	8, 0, 2, 0, 4,   0, 8, 8, 0, 8 },
{ 8, 2, 8, 8, 2,	2, 0, 0, 8, 8,	8, 8, 0, 0, 0,   0, 8, 8, 0, 8 },
{ 8, 0, 4, 2, 2,	2, 0, 8, 2, 0,	0, 2, 0, 0, 0,   2, 2, 0, 0, 8 },

{ 8, 2, 0, 2, 0,	2, 8, 2, 2, 2,	0, 2, 2, 8, 0,	 0, 0, 2, 0, 8 },
{ 8, 2, 2, 2, 0,	8, 0, 2, 2, 2,	2, 2, 2, 2, 8,	 0, 0, 2, 0, 8 },
{ 8, 2, 2, 0, 0,	0, 0, 2, 2, 2,	2, 0, 2, 2, 2,	 8, 2, 2, 2, 8 },
{ 8, 2, 2, 8, 2,	0, 0, 0, 2, 2,	2, 0, 0, 0, 2,	 0, 8, 0, 0, 8 },
{ 8, 2, 8, 8, 2,	2, 0, 0, 0, 8,	8, 0, 0, 0, 0,	 0, 8, 8, 0, 8 },

{ 8, 0, 8, 8, 2,	2, 0, 2, 2, 8,	8, 0, 0, 2, 0,	 0, 8, 8, 0, 8 },
{ 8, 0, 0, 8, 0,	2, 0, 2, 2, 0,	0, 2, 2, 0, 2,	 2, 8, 2, 2, 8 },
{ 8, 2, 0, 2, 0,	0, 0, 0, 0, 2,	0, 2, 0, 0, 2,	 8, 0, 2, 2, 8 },
{ 8, 2, 4, 2, 2,	8, 2, 2, 2, 0,	0, 2, 0, 2, 8,	 2, 4, 2, 2, 8 },
{ 8, 2, 0, 2, 0,	2, 8, 2, 2, 0,	0, 0, 0, 8, 2,	 2, 0, 2, 2, 8 },

{ 8, 0, 0, 2, 0,	2, 2, 8, 2, 0,	0, 0, 0, 2, 2,   2, 0, 0, 2, 8 },
{ 8, 0, 8, 8, 0,	0, 0, 0, 8, 8,	8, 8, 0, 2, 2,   2, 8, 8, 0, 8 },
{ 8, 0, 8, 8, 0,	0, 0, 0, 0, 8,	8, 0, 0, 0, 0,   0, 8, 8, 0, 8 },
{ 8, 2, 2, 2, 2,	0, 0, 2, 2, 2,	2, 2, 2, 0, 0,   0, 0, 0, 0, 8 },
{ 8, 8, 8, 8, 8,	8, 8, 8, 8, 8,	8, 8, 8, 8, 8,   8, 8, 8, 8, 8,}
};

int steps = 0;
int gold = 0;

int ManHealt = 0;

int finish = 0;










// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Разместите код здесь.

	// Инициализация глобальных строк
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_GAME2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAME2));

	MSG msg;

	// Цикл основного сообщения:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAME2));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_GAME2);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


void moveToLeft() {
	int i, j;
	i = 0;
	while (i < N) {
		j = 1;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i][j - 1] == 0) {
					a[i][j - 1] = 3;
					a[i][j] = 0;
					steps++;
				}
				else if (a[i][j - 1] == 1) {
					a[i][j - 1] = 3;
					a[i][j] = 0;
					steps++;
					//gold++;
				}
			}
			j++;
		}
		i++;
	}

}

void BombLeft() {
	int i, j;
	i = 0;
	while (i < N) {
		j = 1;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i][j - 1] == 0) {
					a[i][j - 1] = 1;
				}
			}
			j++;
		}
		i++;
	}
}





void moveToRight() {
	int i = 0;
	while (i < N) {
		int j = M - 2;
		while (j >= 0) {
			if (a[i][j] == 3) {
				if (a[i][j + 1] == 0) {
					a[i][j + 1] = 3;
					a[i][j] = 0;
					steps++;
				}
				else if (a[i][j + 1] == 1) {
					a[i][j + 1] = 3;
					a[i][j] = 0;
					steps++;
					//gold++;
				}
			}
			j--;
		}
		i++;
	}
}

void BombRight() {
	int i = 0;
	while (i < N) {
		int j = M - 2;
		while (j >= 0) {
			if (a[i][j] == 3) {
				if (a[i][j + 1] == 0) {
					a[i][j + 1] = 1;
					
				}
			}
			j--;
		}
		i++;
	}
}

//---------------------------------------------
void moveUp() {
	int i = 1;
	while (i < N) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i - 1][j] == 0) {
					a[i - 1][j] = 3;
					a[i][j] = 0;
					steps++;
				}
				else if (a[i - 1][j] == 1) {
					a[i - 1][j] = 3;
					a[i][j] = 0;
					steps++;
					//gold++;
				}
			}
			j++;
		}
		i++;
	}
}

void BombUp() {
	int i = 1;
	while (i < N) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i - 1][j] == 0) {
					a[i - 1][j] = 1;				
				}
			}
			j++;
		}
		i++;
	}
}

//----------------------------------------------
void moveDown() {
	int i = N;
	while (i >= 0) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i + 1][j] == 0) {
					a[i + 1][j] = 3;
					a[i][j] = 0;
					steps++;
				}
				else if (a[i + 1][j] == 1) {
					a[i + 1][j] = 3;
					a[i][j] = 0;
					steps++;
					
				}
			}
			j++;
		}
		i--;
	}
}

void BombDown() {
	int i = N;
	while (i >= 0) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 3) {
				if (a[i + 1][j] == 0) {
					a[i + 1][j] = 1;
				}
			}
			j++;
		}
		i--;
	}
}

//---------------------------

void BombSplashDown() {
	int i = N;
	while (i >= 0) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 1) {
				// 0

				if (a[i + 1][j] == 0) {
					a[i + 1][j] = 9;
					a[i][j] = 5;
				}
				if (a[i - 1][j] == 0) {
					a[i - 1][j] = 9;
					a[i][j] = 5;
				}
				if (a[i][j - 1] == 0) {
					a[i][j - 1] = 9;
					a[i][j] = 5;
				}
				if (a[i + 1][j - 1] == 0) {
					a[i + 1][j - 1] = 9;
					a[i][j] = 5;
				}
				if (a[i + 1][j + 1] == 0) {
					a[i + 1][j + 1] = 9;
					a[i][j] = 5;
				}
				// 4
	
				if (a[i - 1][j] == 4) {
					a[i + 1][j] = 9;
					a[i][j] = 5;
					gold++;
				}
				
				if (a[i + 1][j + 1] == 4) {
					a[i + 1][j + 1] = 9;
					a[i][j] = 5;
					gold++;
				}
				if (a[i + 1][j - 1] == 4) {
					a[i + 1][j - 1] = 9;
					a[i][j] = 5;
					gold++;
				}
				if (a[i + 1][j] == 4) {
					a[i + 1][j] = 9;
					a[i][j] = 5;
					gold++;
				}
				// 8

				if (a[i + 1][j] == 8) {
					a[i + 1][j] = 8;
					a[i][j] = 5;
				}
				if (a[i + 1][j + 1] == 8) {
					a[i + 1][j + 1] = 8;
					a[i][j] = 5;
				}
				if (a[i + 1][j - 1] == 8) {
					a[i + 1][j - 1] = 8;
					a[i][j] = 5;
				}
				if (a[i - 1][j] == 8) {
					a[i - 1][j] = 8;
					a[i][j] = 5;
				}
				if (a[i][j + 1] == 8) {
					a[i][j + 1] = 8;
					a[i][j] = 5;
				}
				if (a[i][j - 1] == 8) {
					a[i][j - 1] = 8;
					a[i][j] = 5;
				}
				if (a[i - 1][j - 1] == 8) {
					a[i - 1][j - 1] = 8;
					a[i][j] = 5;
				}
				if (a[i - 1][j + 1] == 8) {
					a[i - 1][j + 1] = 8;
					a[i][j] = 5;
				}
				// 2 -->

				if 
					(a[i + 1][j] == 2) {
					a[i + 1][j] = 9;
					a[i][j] = 5;
				}
				
				if (a[i + 1][j + 1] == 2) {
					a[i + 1][j + 1] = 9;
					a[i][j] = 5;
				}
				if (a[i + 1][j - 1] == 2) {
					a[i + 1][j - 1] = 9;
					a[i][j] = 5;
				}
				if (a[i][j - 1] == 2) {
					a[i][j - 1] = 9;
					a[i][j] = 5;
				}
				if (a[i][j + 1] == 2) {
					a[i][j + 1] = 9;
					a[i][j] = 5;
				}
				
				
				
				// 4				
				if (a[i][j - 1] == 4) {
					a[i][j - 1] = 9;
					a[i][j] = 5;
					gold++;
				}
				if (a[i][j + 1] == 4) {
					a[i][j + 1] = 9;
					a[i][j] = 5;
					gold++;
				}
				// 3
				else if (a[i][j - 1] == 3) {
					a[i][j - 1] = 9;
					a[i][j] = 5;
					ManHealt++;
				}
				else if (a[i][j + 1] == 3) {
					a[i][j + 1] = 9;
					a[i][j] = 5;
					ManHealt++;
				}
			}
			j++;
		}
		i--;
	}
	
}

void BombSplashUP() {
	int i = 1;
	Sleep(100);
	while (i < N) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 5) {
				if (a[i - 1][j] == 0) {
					a[i - 1][j] = 9;
					a[i][j] = 9;
				}
				if (a[i][j] == 5) {
					a[i][j] = 9;
					//a[i][j] = 9;
				}

				// 8
				if (a[i - 1][j] == 8) {
					a[i - 1][j] = 8;
					a[i][j] = 9;
				}
				if (a[i - 1][j - 1] == 8) {
					a[i - 1][j - 1] = 8;
					a[i][j] = 9;
				}
				if (a[i - 1][j + 1] == 8) {
					a[i - 1][j + 1] = 8;
					a[i][j] = 9;
				}
				if (a[i + 1][j] == 8) {
					a[i + 1][j] = 8;
					a[i][j] = 9;
				}
				if (a[i + 1][j + 1] == 8) {
					a[i + 1][j + 1] = 8;
					a[i][j] = 9;
				}
				if (a[i + 1][j - 1] == 8) {
					a[i + 1][j - 1] = 8;
					a[i][j] = 9;
				}
				if (a[i][j - 1] == 8) {
					a[i][j - 1] = 8;
					a[i][j] = 9;
				}
				if (a[i][j + 1] == 8) {
					a[i][j + 1] = 8;
					a[i][j] = 9;
				}

				// 3
				else if (a[i - 1][j] == 3) {
					a[i - 1][j] = 9;
					a[i][j] = 9;
					ManHealt++;
				}
				
				//  4 -->
				if (a[i - 1][j] == 4) {
					a[i - 1][j] = 9;
					a[i][j] = 9;
					gold++;
				}
				if (a[i - 1][j + 1] == 4) {
					a[i - 1][j + 1] = 9;
					a[i][j] = 9;
					gold++;
				}
				
				if (a[i - 1][j - 1] == 4) {
					a[i - 1][j - 1] = 9;
					a[i][j] = 9;
					gold++;
				}

				//0
				if (a[i + 1][j] == 0) {
					a[i + 1][j] = 9;
					a[i][j] = 9;
				}
				if (a[i - 1][j] == 0) {
					a[i - 1][j] = 9;
					a[i][j] = 9;
				}
				if (a[i - 1][j + 1] == 0) {
					a[i - 1][j + 1] = 9;
					a[i][j] = 9;
				}
				if (a[i - 1][j - 1] == 0) {
					a[i - 1][j - 1] = 9;
					a[i][j] = 9;
				}
				if (a[i][j - 1] == 0) {
					a[i][j - 1] = 9;
					a[i][j] = 9;
				}
				if (a[i][j + 1] == 0) {
					a[i][j + 1] = 9;
					a[i][j] = 9;
				}
				if (a[i + 1][j - 1] == 0) {
					a[i + 1][j - 1] = 9;
					a[i][j] = 9;
				}
				if (a[i + 1][j + 1] == 0) {
					a[i + 1][j + 1] = 9;
					a[i][j] = 9;
				}

				// 2 <--

				if
					(a[i - 1][j] == 2) {
					a[i - 1][j] = 9;
					a[i][j] = 9;
				}
				if
					(a[i][j + 1] == 2) {
					a[i][j + 1] = 9;
					a[i][j] = 9;
				}
				if
					(a[i][j - 1] == 2) {
					a[i - 1][j] = 9;
					a[i][j] = 9;
				}
				if
					(a[i - 1][j - 1] == 2) {
					a[i - 1][j - 1] = 9;
					a[i][j] = 9;
				}

				if
					(a[i - 1][j - 1] == 2) {
					a[i - 1][j - 1] = 9;
					a[i][j] = 9;
				}
				if
					(a[i - 1][j + 1] == 2) {
					a[i - 1][j + 1] = 9;
					a[i][j] = 9;
				}


			}
			j++;
		}
		i++;
	}
}

void BoomUP() {
	int i = 1;
	//Sleep(1000);
	while (i < N) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 9) {
				if (a[i][j] == 9) {
					a[i][j] = 0;
				}
				/*if (a[i][j] == 0) {
					a[i][j] = 0;
					a[i][j] = 0;
				}*/			
			}
			j++;
		}
		i++;
	}
}

void MoveMonsters() {
	int i = 0;
	while (i < N) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == 4) {
				int di = rand() % 3 - 1; // от -1 до +1
				int dj = 0;

				if (di == 0) {
					dj = rand() % 3 - 1; // от -1 до +1
				}

				if (di != 0 || dj != 0) {
					if (i + di >= 0 && i + di < N
						&& j + dj >= 0 && j + dj < M)
					{
						a[i][j] = 0;
						a[i + di][j + dj] = -4;
					}
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < N) {
		int j = 0;
		while (j < M) {
			if (a[i][j] == -4) {
				a[i][j] = 4;
			}
			j++;
		}
		i++;
	}

}

int sizeX = 36;
int sizeY = 30;

void DrawField(HDC hdc) {

	HBRUSH hBrushEmptyCell; //создаём кисть для пустого поля
	hBrushEmptyCell = CreateSolidBrush(RGB(100, 200, 100)); // серый

	HBRUSH hBrushBomb; //создаём кисть для поля с bomb
	hBrushBomb = CreateSolidBrush(RGB(0, 0, 0)); // black
	HBRUSH hBrushBoom; //создаём кисть для поля с bomb
	hBrushBoom = CreateSolidBrush(RGB(255, 200, 0)); // black

	HBRUSH hBrushWall; //создаём кисть для стены
	hBrushWall = CreateSolidBrush(RGB(255, 140, 0)); // черный
	HBRUSH hBrushWall2; //создаём кисть для стены
	hBrushWall2 = CreateSolidBrush(RGB(155, 155, 155)); // черный

	HBRUSH hBrushMan; //создаём кисть для игрока
	hBrushMan = CreateSolidBrush(RGB(0, 0, 255)); // синий

	HBRUSH hBrushMonster; //создаём кисть 
	hBrushMonster = CreateSolidBrush(RGB(255, 0, 0));//red

	int i, j;
	i = 0;
	while (i < N) {
		j = 0;
		while (j < M) {
			RECT rect = { j * sizeX, i * sizeY,  (j + 1) * sizeX,(i + 1) * sizeY };
			if (a[i][j] == 0) {
				FillRect(hdc, &rect, hBrushEmptyCell);
			}
			else if (a[i][j] == 1) {
				FillRect(hdc, &rect, hBrushBomb);
			}
			else if (a[i][j] == 2) {
				FillRect(hdc, &rect, hBrushWall);
			}
			else if (a[i][j] == 3) {
				FillRect(hdc, &rect, hBrushMan);
			}
			else if (a[i][j] == 4) {
				FillRect(hdc, &rect, hBrushMonster);
			}
			else if (a[i][j] == 5) {
				FillRect(hdc, &rect, hBrushBomb);
			}
			else if (a[i][j] == 6) {
				FillRect(hdc, &rect, hBrushBomb);
			}
			else if (a[i][j] == 7) {
				FillRect(hdc, &rect, hBrushBomb);
			}
			else if (a[i][j] == 8) {
				FillRect(hdc, &rect, hBrushWall2);
			}
			else if (a[i][j] == 9) {
				FillRect(hdc, &rect, hBrushBoom);
			}
			else {
				// тут никогда не должны оказаться
			}
			j++;
		}
		i++;
	}
	HFONT hFont;
	hFont = CreateFont(20,
		0, 0, 0, 0, 0, 0, 0,
		DEFAULT_CHARSET,
		0, 0, 0, 0,
		L"Courier New"
	);
	SelectObject(hdc, hFont);
	SetTextColor(hdc, RGB(0, 128, 128));

	TCHAR  string1[] = _T("сделано ходов:");
	TCHAR  string2[] = _T("Взорвано монстров:");
	TCHAR  string3[] = _T("W,A,S,D - установка бомбы в разных  направлениях");
	TCHAR  string4[] = _T("Пробел - взорвать бомбу");
	TextOut(hdc, 800, sizeY * (N - 1), (LPCWSTR)string1, _tcslen(string1));
	TextOut(hdc, 800, sizeY * (N - 1) - 50, (LPCWSTR)string2, _tcslen(string2)); char sSteps[5];
	TextOut(hdc, 800, 50, (LPCWSTR)string3, _tcslen(string3));
	TextOut(hdc, 800, 100, (LPCWSTR)string4, _tcslen(string4));
	TCHAR  tsSteps[5];
	sprintf(sSteps, "%d", steps);
	OemToChar(sSteps, tsSteps);
	TextOut(hdc, 1020, sizeY * (N - 1), (LPCWSTR)tsSteps, _tcslen(tsSteps));

	char sGold[5];
	TCHAR  tsGold[5];
	sprintf(sGold, "%d", gold);
	OemToChar(sGold, tsGold);
	TextOut(hdc, 1020, sizeY * (N - 1) - 50, (LPCWSTR)tsGold, _tcslen(tsGold));

	DeleteObject(hFont);
	DeleteObject(hBrushEmptyCell);
	DeleteObject(hBrushBomb);
	DeleteObject(hBrushWall);
	DeleteObject(hBrushMan);

} // конец функции void DrawField(HDC hdc) 




void DrawFinalScreen(HDC hdc) {
	HBRUSH hBrushEmptyCell; //создаём кисть для пустого поля
	hBrushEmptyCell = CreateSolidBrush(RGB(255, 255, 255)); // серый
	RECT rect = { 0, 0,  600, 720};
	FillRect(hdc, &rect, hBrushEmptyCell);
	
	HFONT hFont;
	hFont = CreateFont(100, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
	SelectObject(hdc, hFont);
	SetTextColor(hdc, RGB(255, 0, 0));

	TCHAR  string1[] = _T("Победа!");
	TextOut(hdc, 200, 300 , (LPCWSTR)string1, _tcslen(string1)   );
}






//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 700, 0); // Запускаем таймер
		srand(time(NULL)); // Перезапуск генератора случайных чисел
		break;

	case WM_TIMER:

		MoveMonsters(); // перемещаем монстров
		//BombSplashDown();
		//BombSplashUP();
		BoomUP();
		if (gold == 4) {
			finish = 1;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;


	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_DOWN:
			moveDown();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_LEFT:
			moveToLeft();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_UP:
			moveUp();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_RIGHT:
			moveToRight();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x41:
			BombLeft();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x44:
			BombRight();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x57:
			BombUp();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x53:
			BombDown();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x20:
			BombSplashDown();
			BombSplashUP();
			//BoomUP();
			//BomSplashbLeft();
			//BombSplashRight();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		////0x20 пробел
		
		}
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Добавьте сюда любой код прорисовки, использующий HDC...

		if (finish == 1) {

			DrawFinalScreen(hdc);
		}
		else {
			DrawField(hdc);

		}

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
