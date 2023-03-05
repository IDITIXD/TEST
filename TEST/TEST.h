//ФАЙЛ TEST.h
#pragma once
//___________________________________БИБЛИОТЕКИ_________________________
#include <iostream>
#include <windows.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
//КЛАСС ОТВЕЧАЮЩИЙ ЗА ТЕСТ
class TEST
{
public:
	char c;//символ для исследования 
	string title, rezA, rezB, rezC;//название теста и его результаты(а,б,в)
	string info, kak, vopros[15];//информация о тесте, как проходить тест, массив вопросов(15)
	FILE* f;
	HANDLE  out;
	COORD XY;
	int ans1 = 0, ans2 = 0, ans3 = 0;//обнуление счётчиков ответов
	INPUT_RECORD InpR;
	DWORD count_rec;
	HANDLE in;
	char ch;				//символ для получения кода выхода
	WORD ch1;				//символ для получения скан кодов от клавиш

	TEST(); //конструктор
	~TEST();//деструктор
	void SHOW();//показывает информацию
	void SHOWinfa(); //метод показа информации о тесте
	void OBRABOTCHIK(); //ОБРАБОТЧИК (1)
	void OBRABOTCHIKotvetov();//ОБРАБОТЧИК ОТВЕТОВ(2)
};

