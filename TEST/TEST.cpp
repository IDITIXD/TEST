//���� TEST.cpp
//_______________����� ���������� �� ����_________________________
#include "TEST.h"//������ � �����"TEST.h"

TEST::TEST() //�����������
{
	fopen_s(&f, "text.txt", "r");
	if (!f) cout << "������ ������ �����!";
	while ((c = fgetc(f)) != '=') title += c;//���� ��������
	while ((c = fgetc(f)) != '=') info += c;//���� ����������
	while ((c = fgetc(f)) != '=') kak += c;//���� ��� ���������
	for (int i = 0; i < 15; i++)while ((c = fgetc(f)) != '=')vopros[i] += c;//���� ������
	while ((c = fgetc(f)) != '=') rezA += c;//���� ��������� �
	while ((c = fgetc(f)) != '=') rezB += c;//���� ��������� �
	while ((c = fgetc(f)) != '=') rezC += c;//���� ��������� �	
	fclose(f);
	out = GetStdHandle(STD_OUTPUT_HANDLE);
	//����������, ��� �������� �  windows.h
	// ������ ���������� ������
	XY.X = 10; XY.Y = 10;
	SetConsoleCursorPosition(out, XY); //��������� ������� ������
};
TEST::~TEST() { };//����������
void TEST::SHOW()//���������� ����������
{

	//_______________��������____________________________________________
	int NotUsed = system("color 70");
	cout << title << endl;
	Sleep(4000);//�������� 
	system("cls");
	SHOWinfa();//�������� ����� ������ ���������� � �����
	OBRABOTCHIK();
	//_________��� ���������_______________________________________		       
	NotUsed = system("color 20");//���� ���� � �������
	cout << kak << endl;
	OBRABOTCHIK();
	//____________________________������______________________________
	NotUsed = system("color 03");//���� ���� � �������
	for (int i = 0; i < 15; i++) {
		cout << vopros[i] << endl;
		OBRABOTCHIKotvetov();//�������� ���������� �������
	}
	NotUsed = system("color 30");//���� ���� � �������
	//__________���������� ������� ��������______
	if ((ans1 >= ans2) && (ans1 >= ans3))cout << rezA;
	if ((ans2 >= ans1) && (ans2 >= ans3))cout << rezB;
	if ((ans3 >= ans2) && (ans3 >= ans1))cout << rezC;

};
void TEST::SHOWinfa() //����� ������ ���������� � �����
{
	//____________���������� � �����__________________
	XY.X = 0; XY.Y = 0;
	SetConsoleCursorPosition(out, XY); //��������� ������� ������
	cout << "      " << title << endl;
	int NotUsed = system("color 80");//���� ���� � �������
	cout << info << endl;
	//������ ��������� ��������� ������� ����-01-20

}
void TEST::OBRABOTCHIK() //���������� �������
{
	cout << "                      ��� ����������� ������� F5\n                      ��� ������ ESC";
	in = GetStdHandle(STD_INPUT_HANDLE);
	while (1) //����������� ����
	{
		ReadConsoleInput(in, &InpR, 1, &count_rec);//������ ���� ������ � ���������
		//��������� ������ ������� �� ����������. 
		if (InpR.EventType == KEY_EVENT)//��� = 1
		{
			if (InpR.Event.KeyEvent.bKeyDown)//������� ������� ����������
			{
				ch = InpR.Event.KeyEvent.uChar.AsciiChar;//����������� Ascii ��� 					
				//����������� ����������� ������
				ch1 = InpR.Event.KeyEvent.wVirtualKeyCode;
				if (ch1 == VK_F5) { system("cls"); break; }
				if (ch1 == 27)exit(7);
			}//����� ������� �������
		}//����� ������� �� ����������
	}
}
void TEST::OBRABOTCHIKotvetov()
{
	cout << "                      ��� ������ ESC";
	in = GetStdHandle(STD_INPUT_HANDLE);
	while (1) //����������� ����
	{
		ReadConsoleInput(in, &InpR, 1, &count_rec);//������ ���� ������ � ���������
		//��������� ������ ������� �� ����������. 
		if (InpR.EventType == KEY_EVENT)//��� = 1
		{
			if (InpR.Event.KeyEvent.bKeyDown)//������� ������� ����������
			{
				ch = InpR.Event.KeyEvent.uChar.AsciiChar;//����������� Ascii ���
				//����������� ����������� ������

				ch1 = InpR.Event.KeyEvent.wVirtualKeyCode;
				if (ch1 == VK_F1) { system("cls"); ans1++; break; }//������� ������� �
				if (ch1 == VK_F2) { system("cls"); ans2++; break; }//������� ������� �
				if (ch1 == VK_F3) { system("cls"); ans3++; break; }//������� ������� �
				if (ch1 == 27) exit(7);
			}//����� ������� �������
		}//����� ������� �� ����������

	}
}
