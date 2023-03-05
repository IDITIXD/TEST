//ФАЙЛ СONSOL.cpp
#include "CONSOL.h"//Доступ к файлу"CONSOL.h"
CONSOL::CONSOL()
{
	//переменные - размер для будущей консоли
	int kolX = 110;	//по ширине
	int kolY = 20;	//по высоте

	// определение дескриптор канала вывода
	HANDLE  out; //вывод
	out = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//освобождение системную консоль
	FreeConsole();
	//запрос у системы свою консоль  - это ресурс	
	AllocConsole();

	//Изменение название консольи
	SetConsoleTitle(L"ТЕСТ");

	//размеры окна консоли
	SMALL_RECT windowSize = { 0, 0, kolX, kolY };
	// и установка их для своей  консоли
	SetConsoleWindowInfo(out, TRUE, &windowSize);

	//размер координатной сетки (буфера)
	COORD bufferSize = { kolX + 1, kolY + 1 };
	// измение размера буфера консольного окна:
	SetConsoleScreenBufferSize(out, bufferSize);

	//Вывод в окно
	TEST test;//запуск теста
	test.SHOW();

	//Ввод символа для окончания работы
	printf_s("для выхода нажмите Enter.");
	char ch;
	ch = getchar();

	//отдать ресурс
	FreeConsole();

}
CONSOL::~CONSOL() {};
