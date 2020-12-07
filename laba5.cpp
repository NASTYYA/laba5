#include "stdafx.h" 
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
using namespace std;


class Mebel {
protected:
	string name;
	int kol;
public:
	Mebel(string name, int kol) {
		(*this).name = name;
		(*this).kol = kol;
	}
	string get_print()
	{
		ostringstream full_name;
		full_name << "�������������: " << (*this).name << " ����������: " << (*this).kol;
		return full_name.str();
	}
	virtual void get_Table(void);
	Mebel() { cout << "�����������" << endl; }
	virtual ~Mebel() { cout << "����������" << endl; }
};
class Table : public Mebel {
protected:
	int lenth, width;
	int high;
public:
	Table(string name, int kol, int lenth, int width, int high)
		: Mebel(name, kol)
	{
		(*this).name = name;
		(*this).kol = kol;
		(*this).lenth = lenth;
		(*this).width = width;
		(*this).high = high;
	}
	void get_Table()
	{
		ostringstream full;
		full << " ������������� �����: " << (*this).name << "\n ���������� ������: " << (*this).kol << "\n ����� �����: " << (*this).lenth << "\n ������ �����: " << (*this).width << "\n ������ �����: " << (*this).high;
		return full.str();
	}


};


class bookcase : public Mebel {
protected:
	string type;
	string material2;
	int high;
public:
	bookcase(string name, int kol, int lenth, int width, string type, string material2, int high)
		: Mebel(name, kol)
	{
		(*this).name = name;
		(*this).kol = kol;
		(*this).type = type;
		(*this).material2 = material2;
		(*this).high = high;
	}
	string get_bookcase()
	{
		ostringstream nam;
		nam << "\n ������������� �����: " << (*this).name << "\n ���������� ������: " << (*this).kol << "\n ��� �����: " << (*this).type << "\n �������� : " << (*this).material2;
		return nam.str();
	}
};
void seeCase()
{
	string name; int kol; int lenth; int width; int high;
	string type; string material2;
	cout << "������� ���������� � �����\n ";
	cout << "�������������: ";
	cin >> name;
	cout << "����������: "; cin >> kol;
	while (kol < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> kol;
	}
	cout << "����� �����: "; cin >> lenth;;
	while (lenth < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> kol;;
	}
	cout << "������ �����: "; cin >> width;
	while (width < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> width;
	}
	cout << "������ �����: "; cin >> high;
	while (high < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> high;
	}
	cout << "��� �����: "; cin >> type;
	cout << "�������� : "; cin >> material2;
	bookcase* st = new bookcase(name, kol, lenth, width, type, material2, high);

	cout << (*st).get_bookcase() << endl;
}

virtual void seeTable()
{
	string name; int kol; int lenth; int width; int high;
	string type; string material2;
	cout << "������� ���������� � �����\n ";
	cout << "�������������: ";
	cin >> name;
	cout << "����������: "; cin >> kol;
	while (kol < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> kol;
	}
	cout << "����� �����: "; cin >> lenth;
	while (lenth < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> lenth;
	}
	cout << "������ �����: "; cin >> width;
	while (width < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> width;
	}
	cout << "������ �����: "; cin >> high;
	while (high < 0)
	{
		cout << "������.������� ������ ��� ���: ";
		cin >> high;
	}
	cout << "���: "; cin >> type;
	cout << "�������� : "; cin >> material2;

	Table* stud = new Table(name, kol, lenth, width, high);


	cout << (*stud).get_Table() << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");

	Mebel *ukazatel[2];
	bookcase b;
	Table t;
	ukazatel[0] = &b; // ������������� ������� ���������� 
	ukazatel[1] = &t;

	
	ukazatel
	int input;

	do {
		cout << "1. ����\n";
		cout << "2. ����\n";
		cout << "3. Exit\n";
		cout << "��� �����: ";
		cin >> input;


		{
			switch (input) {
			case 1:
				seeTable();
				break;
			case 2:
				seeCase();
				break;
			case 3:
				cout << "����������!\n";
				break;
			default:
				cout << "������\n";
				break;
			}

			cin.get();
		}
	} while (input != 3);


	system("pause>>NUL");
	return 0;
}