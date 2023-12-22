#include <iostream>
#include <ctime>
#include <chrono>
#include <conio.h>

using namespace std;
using namespace chrono;

const short int n = 100;
int arr[n];
void GenerateArray(int* arr, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 199 - 99;
}
void cloneArray(int arr[], int arr2[])
{
	for (int i = 0; i < 100; i++)
		arr2[i] = arr[i];
}
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n-1; ++i)
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
}
void shakerSort(int arr[], int n)
{
	int count = 0;
	while (true)
	{
		count = 0;
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				count++;
			}
		for (int i = 1; i < n; i++)
		{
			if (arr[n - 1 - i] < arr[n - 1 - i - 1])
			{
				swap(arr[n - 1 - i], arr[n - 1 - i - 1]);
				count++;
			}
		}
		if (count == 0)
			break;
	}
}
void combSort(int arr[], int n)
{
	int swap;
	float k = 1.247, S = n - 1;
	int count = 0;
	while (S >= 1)
	{
		for (int i = 0; i + S < n; i++)
		{
			if (arr[i] > arr[int(i + S)])
			{
				swap = arr[int(i + S)];
				arr[int(i + S)] = arr[i];
				arr[i] = swap;
			}
		}
		S /= k;
	}

	while (true)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = swap;
			}
			else count++;
		}
		if (count == n - 1)
			break;
		else
			count = 0;
	}
}
void insertSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = arr[i];
		int j = i - 1;
		while (j >= 0 and arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = k;
	}
}
void quickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (left < j) 
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}
void inputRandomArray()
{
	system("cls");
	GenerateArray(arr, n);
	cout << "����������������� ������: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n\n������� ����� ������ ��� ����������� � ����";
	_getch();
	system("cls");
}
void sortArray()
{
	system("cls");
	int arr2[n];
	GenerateArray(arr, n);
	cout << "����������������� ������: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cloneArray(arr, arr2);
	auto start1 = steady_clock::now();
	bubbleSort(arr, n);
	auto end1 = steady_clock::now();
	auto result1 = duration_cast<nanoseconds>(end1 - start1);
	cloneArray(arr2, arr);
	auto start2 = steady_clock::now();
	shakerSort(arr, n);
	auto end2 = steady_clock::now();
	auto result2 = duration_cast<nanoseconds>(end2 - start2);
	cloneArray(arr2, arr);
	auto start3 = steady_clock::now();
	combSort(arr, n);
	auto end3 = steady_clock::now();
	auto result3 = duration_cast<nanoseconds>(end3 - start3);
	cloneArray(arr2, arr);
	auto start4 = steady_clock::now();
	insertSort(arr, n);
	auto end4 = steady_clock::now();
	auto result4 = duration_cast<nanoseconds>(end4 - start4);
	cloneArray(arr2, arr);
	auto start5 = steady_clock::now();
	quickSort(arr, 0, n-1);
	auto end5 = steady_clock::now();
	auto result5 = duration_cast<nanoseconds>(end5 - start5);
	cout << "\n\n��������������� ������: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n\n����� buble sort: " << result1.count() << " ����������\n";
	cout << "����� shaker sort: " << result2.count() << " ����������\n";
	cout << "����� comb sort: " << result3.count() << " ����������\n";
	cout << "����� insert sort: " << result4.count() << " ����������\n";
	cout << "����� quick sort: " << result5.count() << " ����������\n";
	cout << "\n������� ����� ������ ��� ����������� � ����";
	_getch();
	system("cls");
}
void findMinMax()
{
	system("cls");
	GenerateArray(arr, n);
	int min = arr[0], max = arr[0];
	auto start1 = steady_clock::now();
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	auto end1 = steady_clock::now();
	auto result1 = duration_cast<nanoseconds>(end1 - start1);
	cout << "����������������� ������:\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n\n����������� �������: " << min << "\n������������ �������: " << max << endl;
	quickSort(arr, 0, n - 1);
	int minSort = arr[0], maxSort = arr[0];
	auto start2 = steady_clock::now();
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxSort)
			maxSort = arr[i];
		if (arr[i] < minSort)
			minSort = arr[i];
	}
	auto end2 = steady_clock::now(); 
	auto result2 = duration_cast<nanoseconds>(end2 - start2);
	cout << "\n����� ������ � �����������������: " << result1.count() << " ����������\n" << "����� ������ � ���������������: " << result2.count() << " ����������\n" << endl;
	cout << "\n������� ����� ������ ��� ����������� � ����";
	_getch();
	system("cls");
}
void avgMinMax()
{
	system("cls");
	int count = 0;
	GenerateArray(arr, n);
	int min = arr[0], max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	int avg = (min + max) / 2;
	cout << "����������������� ������:\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n\n������� �������� ������������ � �������������: " << avg << endl;
	cout << "\n������� ���������, ������ �������� � ������. �������: ";
	auto start1 = steady_clock::now();
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == avg)
		{
			count++;
			cout << i << " ";
		}
	}
	auto end1 = steady_clock::now();
	auto result1 = duration_cast<nanoseconds>(end1 - start1);
	cout << "\n���������� ���������, ������ ��������: " << count;
	cout << "\n����� ������ � ������. �������: " << result1.count() << " ����������";
	cout << "\n\n������� ���������, ������ �������� � ����. �������: ";
	quickSort(arr, 0, n-1);
	auto start2 = steady_clock::now();
	for (int i = 0; i < n && arr[i] <= avg; i++)
	{
		if (arr[i] == avg)
		{
			cout << i << " ";
		}
	}
	auto end2 = steady_clock::now();
	auto result2 = duration_cast<nanoseconds>(end2 - start2);
	cout << "\n����� ������ � ����. �������: " << result2.count() << " ����������";
	cout << "\n\n������� ����� ������ ��� ����������� � ����";
	_getch();
	system("cls");
}
int binarySearch(int arr[], int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == value)
			return mid;
		if (arr[mid] > value)
			return binarySearch(arr, value, start, mid - 1);
		return binarySearch(arr, value, mid + 1, end);
	}
	return -1;
}
void lessThanNumber()
{
	system("cls");
	int a;
	GenerateArray(arr, n);
	cout << "����������������� ������: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	quickSort(arr, 0, n - 1);
	cout << "\n\n��������������� ������: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n\n������� �����, � ������� ����� ����������: ";
	cin >> a;
	int count = binarySearch(arr, a, 0, n - 1);
	cout << "\n���������� ���������, ������� ������ " << a << ": " << count;
	cout << "\n\n������� ����� ������ ��� ����������� � ����";
	_getch();
	system("cls");
}
void moreThanNumber()
{
	system("cls");
	int b;
	GenerateArray(arr, n);
	cout << "����������������� ������: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	quickSort(arr, 0, n - 1);
	cout << "\n\n��������������� ������: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n\n������� �����, � ������� ����� ����������: ";
	cin >> b;
	int count = n - binarySearch(arr, b, n-1, 0) - 1;
	cout << "\n���������� ���������, ������� ������ " << b << ": " << count;
	cout << "\n\n������� ����� ������ ��� ����������� � ����";
	_getch();
	system("cls");
}
void checkBinarySearch()
{
	system("cls");
	int value;
	bool flag = true;
	GenerateArray(arr, n);
	cout << "������� �����, ������� ����� �����: ";
	cin >> value;
	auto start1 = steady_clock::now();
	int result = binarySearch(arr, value, 0, n - 1);
	auto end1 = steady_clock::now();
	auto result1 = duration_cast<nanoseconds>(end1 - start1);
	if (result == -1)
		cout << "\n����� �� �������!\n" << "����� ��������� ������: " << result1.count() << " ����������";
	else cout << "\n����� �������!\n" << "����� ��������� ������: " << result1.count() << " ����������";
	auto start2 = steady_clock::now();
	for (int i = 0; i < n; i++) {
		if (flag) {
			if (arr[i] == value) {
				auto end2 = steady_clock::now();
				auto result2 = duration_cast<nanoseconds>(end2 - start2);
				cout << "\n����� ����������� ������: " << result2.count() << " ����������";
				flag = false;
				break;
			}
		}
	}
	if (flag)
	{
		auto end2 = steady_clock::now();
		auto result2 = duration_cast<nanoseconds>(end2 - start2);
		cout << "\n����� ����������� ������: " << result2.count() << " ����������";
	}
	cout << "\n\n������� ����� ������ ��� ����������� � ����";
	_getch();
	system("cls");
}
void changeValues()
{
	system("cls");
	int firstIndex, secondIndex;
	GenerateArray(arr, n);
	cout << "����������������� ������: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n\n������� ������� ���������: ";
	cin >> firstIndex >> secondIndex;
	auto start = steady_clock::now();
	arr[firstIndex] = arr[firstIndex] + arr[secondIndex];
	arr[secondIndex] = arr[firstIndex] - arr[secondIndex];
	arr[firstIndex] = arr[firstIndex] - arr[secondIndex];
	auto end = steady_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	cout << "\n��������� ������: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n\n����� ���������: " << result.count() << " ����������";
	cout << "\n\n������� ����� ������ ��� ����������� � ����";
	_getch();
	system("cls");
}
void oddElements()
{
	system("cls");
	int count[10] = {0};
	GenerateArray(arr, n);
	cout << "����������������� ������: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n\n������� �����, �� ������� ���������� ������ �������� �������: ";
	int a;
	cin >> a;
	cout << "\n��������� ������:\n";
	for (int i = 0; i < n; i++) {
		if (i % 2 == 1)
			arr[i] = arr[i] - a;
		cout << arr[i] << " ";
	}
	cout << "\n\n������ �������� ������� ��������� �� ��������� �����: \n";
	for (int i = 0; i < n; i++) {
		if (i % 2 == 1)
			arr[i] = arr[i] * (rand() % 9 + 1);
		cout << arr[i] << " ";
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= 9; ++j){
			if (arr[i] % j == 0) {
			++count[j];
			}
		}
	}
	cout << "\n";
	for (int i = 1; i <= 9; ++i)
		cout << "\n���������� �����, ������� ������� �� " << i << ": " << count[i];
	cout << "\n\n������� ����� ������ ��� ����������� � ����";
	_getch();
	system("cls");
}
void menu()
{
	setlocale(0, "");
	int mainMenu;
	{
		cout << "��� ����� ������? \n"
			<< "1 - ������� ������ �� ���������� ���������� � ��������� �� -99 �� 99\n"
			<< "2 - ������������� ������ ����������� (�� �������� � ��������)\n"
			<< "3 - ����� ������������ � ����������� �������� �������\n"
			<< "4 - ������� ������� �������� ������������� � ������������ �������� � �� �����\n"
			<< "5 - ������� ���������� ��������� � ��������������� �������, ������� ������ ��������� �����\n"
			<< "6 - ������� ���������� ��������� � ��������������� �������, ������� ������ ��������� �����\n"
			<< "7 - ���� �� �������� ����� � ��������������� ������� (�������� �����)\n"
			<< "8 - �������� ������� �������� �������\n"
			<< "9 - �������� �������� �������� (idz)\n"
			<< "10 - �����\n\n";
	}
	cin >> mainMenu;

	switch (mainMenu)
	{
	case 1:
		inputRandomArray();
		menu();
		break;
	case 2:
		sortArray();
		menu();
		break;
	case 3:
		findMinMax();
		menu();
		break;
	case 4:
		avgMinMax();
		menu();
		break;
	case 5:
		lessThanNumber();
		menu();
		break;
	case 6:
		moreThanNumber();
		menu();
		break;
	case 7:
		checkBinarySearch();
		menu();
		break;
	case 8:
		changeValues();
		menu();
		break;
	case 9:
		oddElements();
		menu();
		break;
	case 10:
		exit(1);
		break;
	default:
		cout << "������! ���������� �����\n";
		_getch();
		system("cls");
		menu();
		break;
	}
}
int main2()
{
	menu();
	return 0;
}