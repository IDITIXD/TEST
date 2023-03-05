//ФАЙЛ TEST.cpp
//_______________КЛАСС ОТВЕЧАЮЩИЙ ЗА ТЕСТ_________________________
#include "TEST.h"//Доступ к файлу"TEST.h"

TEST::TEST() //конструктор
{
	fopen_s(&f, "text.txt", "r");
	if (!f) cout << "ошибка чтения файла!";
	while ((c = fgetc(f)) != '=') title += c;//ищет название
	while ((c = fgetc(f)) != '=') info += c;//ищет информацию
	while ((c = fgetc(f)) != '=') kak += c;//ищет как проходить
	for (int i = 0; i < 15; i++)while ((c = fgetc(f)) != '=')vopros[i] += c;//ищет вопрос
	while ((c = fgetc(f)) != '=') rezA += c;//ищет результат А
	while ((c = fgetc(f)) != '=') rezB += c;//ищет результат Б
	while ((c = fgetc(f)) != '=') rezC += c;//ищет результат В	
	fclose(f);
	out = GetStdHandle(STD_OUTPUT_HANDLE);
	//координаты, тип объявлен в  windows.h
	// задать координаты вывода
	XY.X = 10; XY.Y = 10;
	SetConsoleCursorPosition(out, XY); //установка позиции курсор
};
TEST::~TEST() { };//деструктор
void TEST::SHOW()//показывает информацию
{

	//_______________НАЗВАНИЕ____________________________________________
	int NotUsed = system("color 70");
	cout << title << endl;
	Sleep(4000);//задержка 
	system("cls");
	SHOWinfa();//вызывает метод показа информации о тесте
	OBRABOTCHIK();
	//_________КАК ПРОХОДИТЬ_______________________________________		       
	NotUsed = system("color 20");//цвет фона и символа
	cout << kak << endl;
	OBRABOTCHIK();
	//____________________________ВОПРОС______________________________
	NotUsed = system("color 03");//цвет фона и символа
	for (int i = 0; i < 15; i++) {
		cout << vopros[i] << endl;
		OBRABOTCHIKotvetov();//ВЫЗЫВАЕТ ОБРАБОТЧИК ОТВЕТОВ
	}
	NotUsed = system("color 30");//цвет фона и символа
	//__________РЕЗУЛЬТАТЫ выводит максимум______
	if ((ans1 >= ans2) && (ans1 >= ans3))cout << rezA;
	if ((ans2 >= ans1) && (ans2 >= ans3))cout << rezB;
	if ((ans3 >= ans2) && (ans3 >= ans1))cout << rezC;

};
void TEST::SHOWinfa() //метод показа информации о тесте
{
	//____________ИНФОРМАЦИЯ О ТЕСТЕ__________________
	XY.X = 0; XY.Y = 0;
	SetConsoleCursorPosition(out, XY); //установка позиции курсор
	cout << "      " << title << endl;
	int NotUsed = system("color 80");//цвет фона и символа
	cout << info << endl;
	//работу выполнила Васильева Татьяна ФВБО-01-20

}
void TEST::OBRABOTCHIK() //ОБРАБОТЧИК ОТВЕТОВ
{
	cout << "                      ДЛЯ ПРОДОЛЖЕНИЯ НАЖМИТЕ F5\n                      ДЛЯ ВЫХОДА ESC";
	in = GetStdHandle(STD_INPUT_HANDLE);
	while (1) //бесконечный цикл
	{
		ReadConsoleInput(in, &InpR, 1, &count_rec);//читаем одну запись в структуру
		//обработка только события от клавиатуры. 
		if (InpR.EventType == KEY_EVENT)//код = 1
		{
			if (InpR.Event.KeyEvent.bKeyDown)//нажатие клавиши клавиатуры
			{
				ch = InpR.Event.KeyEvent.uChar.AsciiChar;//отлавливаем Ascii код 					
				//определение виртуальных клавиш
				ch1 = InpR.Event.KeyEvent.wVirtualKeyCode;
				if (ch1 == VK_F5) { system("cls"); break; }
				if (ch1 == 27)exit(7);
			}//конец нажатия клавиши
		}//конец события от клавиатуры
	}
}
void TEST::OBRABOTCHIKotvetov()
{
	cout << "                      ДЛЯ ВЫХОДА ESC";
	in = GetStdHandle(STD_INPUT_HANDLE);
	while (1) //бесконечный цикл
	{
		ReadConsoleInput(in, &InpR, 1, &count_rec);//читаем одну запись в структуру
		//обработка только события от клавиатуры. 
		if (InpR.EventType == KEY_EVENT)//код = 1
		{
			if (InpR.Event.KeyEvent.bKeyDown)//нажатие клавиши клавиатуры
			{
				ch = InpR.Event.KeyEvent.uChar.AsciiChar;//отлавливаем Ascii код
				//определение виртуальных клавиш

				ch1 = InpR.Event.KeyEvent.wVirtualKeyCode;
				if (ch1 == VK_F1) { system("cls"); ans1++; break; }//счётчик ответов А
				if (ch1 == VK_F2) { system("cls"); ans2++; break; }//счётчик ответов Б
				if (ch1 == VK_F3) { system("cls"); ans3++; break; }//счётчик ответов В
				if (ch1 == 27) exit(7);
			}//конец нажатия клавиши
		}//конец события от клавиатуры

	}
}
