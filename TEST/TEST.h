//���� TEST.h
#pragma once
//___________________________________����������_________________________
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
//����� ���������� �� ����
class TEST
{
public:
	char c;//������ ��� ������������ 
	string title, rezA, rezB, rezC;//�������� ����� � ��� ����������(�,�,�)
	string info, kak, vopros[15];//���������� � �����, ��� ��������� ����, ������ ��������(15)
	FILE* f;
	HANDLE  out;
	COORD XY;
	int ans1 = 0, ans2 = 0, ans3 = 0;//��������� ��������� �������
	INPUT_RECORD InpR;
	DWORD count_rec;
	HANDLE in;
	char ch;				//������ ��� ��������� ���� ������
	WORD ch1;				//������ ��� ��������� ���� ����� �� ������

	TEST(); //�����������
	~TEST();//����������
	void SHOW();//���������� ����������
	void SHOWinfa(); //����� ������ ���������� � �����
	void OBRABOTCHIK(); //���������� (1)
	void OBRABOTCHIKotvetov();//���������� �������(2)
};

