//���� �ONSOL.cpp
#include "CONSOL.h"//������ � �����"CONSOL.h"
CONSOL::CONSOL()
{
	//���������� - ������ ��� ������� �������
	int kolX = 110;	//�� ������
	int kolY = 20;	//�� ������

	// ����������� ���������� ������ ������
	HANDLE  out; //�����
	out = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//������������ ��������� �������
	FreeConsole();
	//������ � ������� ���� �������  - ��� ������	
	AllocConsole();

	//��������� �������� ��������
	SetConsoleTitle(L"����");

	//������� ���� �������
	SMALL_RECT windowSize = { 0, 0, kolX, kolY };
	// � ��������� �� ��� �����  �������
	SetConsoleWindowInfo(out, TRUE, &windowSize);

	//������ ������������ ����� (������)
	COORD bufferSize = { kolX + 1, kolY + 1 };
	// ������� ������� ������ ����������� ����:
	SetConsoleScreenBufferSize(out, bufferSize);

	//����� � ����
	TEST test;//������ �����
	test.SHOW();

	//���� ������� ��� ��������� ������
	printf_s("��� ������ ������� Enter.");
	char ch;
	ch = getchar();

	//������ ������
	FreeConsole();

}
CONSOL::~CONSOL() {};
