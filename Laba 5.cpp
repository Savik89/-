#include <iostream>
#include "laba1.cpp"
#include "laba2.cpp"
#include "laba3.cpp"
#include "laba 4.cpp"

using namespace std;

int main()
{
	setlocale(0, "");
	int choice;
	cout << "Введите номер практической работы: " << endl;
	cin >> choice;
	system("cls");
	switch (choice) {
	case 1:
		main1();
		main();
		break;
	case 2:
		main2();
		main();
		break;
	case 3:
		main3();
		main();
		break;
	case 4:
		main4();
		main();
		break;
	}
}