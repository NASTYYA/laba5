#include "stdafx.h" 
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include "ConsoleApplication7 laba5.h"
using namespace std;


class Mebel {

public:
	virtual void get_print(void);
	virtual void get_print2() = 0;

	Mebel() { cout << "Конструктор" << endl; }
	virtual ~Mebel() { cout << "Диструктор" << endl; }
};
class Table : public Mebel {
protected:
	int lenth, width;
	int high;	string name;
	int kol;
public:
	Table(string name, int kol, int lenth, int width, int high)

	{
		(*this).name = name;
		(*this).kol = kol;
		(*this).lenth = lenth;
		(*this).width = width;
		(*this).high = high;


	}

	void get_print(void)
	{

		cout << " Производитель стола: " << (*this).name << "\n Количество столов: " << (*this).kol << "\n Длина стола: " << (*this).lenth
			<< "\n Ширина стола: " << (*this).width << "\n Высота стола: " << (*this).high;

	}
	void get_print2()
	{

		cout << " Производитель стола: " << (*this).name << "\n Количество столов: " << (*this).kol << "\n Длина стола: " << (*this).lenth
			<< "\n Ширина стола: " << (*this).width << "\n Высота стола: " << (*this).high;

	}
};


class bookcase : public Mebel {
protected:
	string type;
	string material2;
	string name;
	int kol;

public:
	bookcase(string name, int kol, string type, string material2)
	{
		(*this).name = name;
		(*this).kol = kol;
		(*this).type = type;
		(*this).material2 = material2;


	}

	void get_print(void)
	{

		cout << "\n Производитель шкафа: " << (*this).name << "\n Количество: " << (*this).kol << "\n Тип шкафа: "
			<< (*this).type << "\n Материал : " << (*this).material2;
	}

	string get_bookcase()
	{
		ostringstream nam;
		nam << "\n Производитель стола: " << (*this).name << "\n Количество столов: " << (*this).kol << "\n Тип шкафа: "
			<< (*this).type << "\n Материал : " << (*this).material2;
		return nam.str();
	}
	void get_print2()
	{
		cout << "\n Производитель шкафа: " << (*this).name << "\n Количество: " << (*this).kol << "\n Тип шкафа: "
			<< (*this).type << "\n Материал : " << (*this).material2;
	}
};
void seeCase()
{
	string name; int kol; int lenth; int width; int high;
	string type; string material2;
	cout << "Введите информацию о шкафе\n ";
	cout << "Производитель: ";
	cin >> name;
	cout << "Количество: "; cin >> kol;
	while (kol < 0)
	{
		cout << "Ошибка.Введите данные ещё раз: ";
		cin >> kol;
	}

	cout << "Тип шкафа: "; cin >> type;
	cout << "Материал : "; cin >> material2;
	bookcase* st = new bookcase(name, kol, type, material2);
	cout << (*st).get_bookcase() << endl;
	Mebel *p[2];//масси указателей
	bookcase obj1(name, kol, type, material2);//объекты
	p[0] = &obj1; // инициализация массива указателей 

	cout << "Шкафы   ";
	p[0]->get_print2();

}

void seeTable()
{
	string name; int kol; int lenth; int width; int high;
	string type; string material2;
	cout << "Введите информацию о столе\n ";
	cout << "Производитель: ";
	cin >> name;
	cout << "Количество: "; cin >> kol;
	while (kol < 0)
	{
		cout << "Ошибка.Введите данные ещё раз: ";
		cin >> kol;
	}
	cout << "Длина стола: "; cin >> lenth;
	while (lenth < 0)
	{
		cout << "Ошибка.Введите данные ещё раз: ";
		cin >> lenth;
	}
	cout << "Ширина стола: "; cin >> width;
	while (width < 0)
	{
		cout << "Ошибка.Введите данные ещё раз: ";
		cin >> width;
	}
	cout << "Высота стола: "; cin >> high;
	while (high < 0)
	{
		cout << "Ошибка.Введите данные ещё раз: ";
		cin >> high;
	}
	cout << "Тип: "; cin >> type;
	cout << "Материал : "; cin >> material2;

	Mebel *p[2];//масси указателей
	bookcase obj1(name, kol, type, material2);//объекты
	Table obj2(name, kol, lenth, width, high);
	p[0] = &obj1; // инициализация массива указателей 
	p[1] = &obj2;

	cout << "Шкафы   ";
	p[0]->get_print();
	cout << "Столы   ";
	p[1]->get_print();
}

int main() {
	setlocale(LC_ALL, "Russian");


	int input;

	do {
		cout << "1. Стол\n";
		cout << "2. Шкаф\n";
		cout << "3. Exit\n";
		cout << "Ваш ответ: ";
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
				cout << "Досвиданья!\n";
				break;
			default:
				cout << "ОШИБКА\n";
				break;
			}

			cin.get();
		}
	} while (input != 3);


	system("pause>>NUL");
	return 0;
}


