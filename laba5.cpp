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
		full_name << "Производитель: " << (*this).name << " Количество: " << (*this).kol;
		return full_name.str();
	}
	virtual void get_Table(void);
	Mebel() { cout << "Конструктор" << endl; }
	virtual ~Mebel() { cout << "Диструктор" << endl; }
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
		full << " Производитель стола: " << (*this).name << "\n Количество столов: " << (*this).kol << "\n Длина стола: " << (*this).lenth << "\n Ширина стола: " << (*this).width << "\n Высота стола: " << (*this).high;
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
		nam << "\n Производитель стола: " << (*this).name << "\n Количество столов: " << (*this).kol << "\n Тип шкафа: " << (*this).type << "\n Материал : " << (*this).material2;
		return nam.str();
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
	cout << "Длина шкафа: "; cin >> lenth;;
	while (lenth < 0)
	{
		cout << "Ошибка.Введите данные ещё раз: ";
		cin >> kol;;
	}
	cout << "Ширина шкафа: "; cin >> width;
	while (width < 0)
	{
		cout << "Ошибка.Введите данные ещё раз: ";
		cin >> width;
	}
	cout << "Высота шкафа: "; cin >> high;
	while (high < 0)
	{
		cout << "Ошибка.Введите данные ещё раз: ";
		cin >> high;
	}
	cout << "Тип шкафа: "; cin >> type;
	cout << "Материал : "; cin >> material2;
	bookcase* st = new bookcase(name, kol, lenth, width, type, material2, high);

	cout << (*st).get_bookcase() << endl;
}

virtual void seeTable()
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

	Table* stud = new Table(name, kol, lenth, width, high);


	cout << (*stud).get_Table() << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");

	Mebel *ukazatel[2];
	bookcase b;
	Table t;
	ukazatel[0] = &b; // инициализация массива указателей 
	ukazatel[1] = &t;

	
	ukazatel
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