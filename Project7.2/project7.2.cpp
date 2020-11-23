// Lab_7_2_1.cpp
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


/// <summary>
/// Створення масиву
/// </summary>
/// <param name="rowCount">Кількість рядків</param>
/// <param name="colCount">Кількість стовбців</param>
/// <param name="Low">Мінімальне значення елемента</param>
/// <param name="High">Максимальне значення елемента</param>
/// <returns></returns>
int** CreateArr(const int rowCount, const int colCount, const int Low, const int High)
{
	int** a = new int* [rowCount];
	for (int row = 0; row < rowCount; row++)
		a[row] = new int[colCount];
	for (int row = 0; row < rowCount; row++)
		for (int col = 0; col < colCount; col++)
			a[row][col] = Low + rand() % (High - Low + 1);
	return a;
}
/// <summary>
/// Вивід масива
/// </summary>
/// <param name="a">масив</param>
/// <param name="rowCount">Кількість рядків</param>
/// <param name="colCount">Кількість стовбців</param>
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int row = 0; row < rowCount; row++)
	{
		for (int col = 0; col < colCount; col++)
			cout << setw(4) << a[row][col];
		cout << endl;
	}
	cout << endl;
}
/// <summary>
/// Пошук індекса мінімального значення в рядку масива
/// </summary>
/// <param name="a">масив</param>
/// <param name="row">рядок де шукаємо</param>
/// <param name="colCount">Кількість стовбців</param>
/// <returns>індекс мінімального значення</returns>
int find_min_index(int** a, const int row, const int colCount)
{
	int min_index = 0;
	int min_value = a[row][min_index];
	for (int col = 0; col < colCount; col++)
	{
		if (min_value>a[row][col])
		{
			min_value = a[row][col];
			min_index = col;
		}
	}
	return min_index;
}
/// <summary>
/// Пошук індекса максимального  значення в рядку масива
/// </summary>
/// <param name="a">масив</param>
/// <param name="row">рядок де шукаємо</param>
/// <param name="colCount">Кількість стовбців</param>
/// <returns>індекс максимального значення</returns>
int find_max_index(int** a, const int row, const int colCount)
{
	int max_index = 0;
	int max_value = a[row][max_index];
	for (int col = 0; col < colCount; col++)
	{
		if (max_value < a[row][col])
		{
			max_value = a[row][col];
			max_index = col;
		}
	}
	return max_index;
}
/// <summary>
/// Обмін мінімального і максимального значення в рядку 
/// </summary>
/// <param name="a">масив</param>
/// <param name="row">рядок де міняємо</param>
/// <param name="min_index">індекс мінімального значення</param>
/// <param name="max_index">індекс максимального значення</param>
void swap(int** a, const int row, const int min_index, const int max_index)
{
	 int tmp = a[row][min_index];
	 a[row][min_index] = a[row][max_index];
	 a[row][max_index] = tmp;

}
void destroy_mass(int** a, const int rowCount)
{
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
}

int main()
{
	// Створення масива
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int rowCount;
	int colCount;
	cout << "k = "; cin >> rowCount;
	cout << "n = "; cin >> colCount;
	int** arr = CreateArr(rowCount, colCount, Low, High);
	// Вивід масива
	Print(arr, rowCount, colCount);
	int min_index;
	int max_index;
	// Для кожного рядку масиву
	for(int row =0; row<rowCount; row++)
	{
		// Пошук індекса  мінімального значення
		min_index= find_min_index(arr, row, colCount);
		// Пошук  індекс максимального значення 
		max_index = find_max_index(arr, row, colCount);
		// Обмін мінімального і максимального значення
		swap(arr, row, min_index, max_index);
	}
	// Вивід результату
	cout << "New matrix" << endl;
	Print(arr, rowCount, colCount);
	// Видалення масиву
	destroy_mass(arr, rowCount);
}