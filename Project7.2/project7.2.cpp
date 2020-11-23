// Lab_7_2_1.cpp
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


/// <summary>
/// ��������� ������
/// </summary>
/// <param name="rowCount">ʳ������ �����</param>
/// <param name="colCount">ʳ������ ��������</param>
/// <param name="Low">̳������� �������� ��������</param>
/// <param name="High">����������� �������� ��������</param>
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
/// ���� ������
/// </summary>
/// <param name="a">�����</param>
/// <param name="rowCount">ʳ������ �����</param>
/// <param name="colCount">ʳ������ ��������</param>
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
/// ����� ������� ���������� �������� � ����� ������
/// </summary>
/// <param name="a">�����</param>
/// <param name="row">����� �� ������</param>
/// <param name="colCount">ʳ������ ��������</param>
/// <returns>������ ���������� ��������</returns>
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
/// ����� ������� �������������  �������� � ����� ������
/// </summary>
/// <param name="a">�����</param>
/// <param name="row">����� �� ������</param>
/// <param name="colCount">ʳ������ ��������</param>
/// <returns>������ ������������� ��������</returns>
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
/// ���� ���������� � ������������� �������� � ����� 
/// </summary>
/// <param name="a">�����</param>
/// <param name="row">����� �� ������</param>
/// <param name="min_index">������ ���������� ��������</param>
/// <param name="max_index">������ ������������� ��������</param>
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
	// ��������� ������
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int rowCount;
	int colCount;
	cout << "k = "; cin >> rowCount;
	cout << "n = "; cin >> colCount;
	int** arr = CreateArr(rowCount, colCount, Low, High);
	// ���� ������
	Print(arr, rowCount, colCount);
	int min_index;
	int max_index;
	// ��� ������� ����� ������
	for(int row =0; row<rowCount; row++)
	{
		// ����� �������  ���������� ��������
		min_index= find_min_index(arr, row, colCount);
		// �����  ������ ������������� �������� 
		max_index = find_max_index(arr, row, colCount);
		// ���� ���������� � ������������� ��������
		swap(arr, row, min_index, max_index);
	}
	// ���� ����������
	cout << "New matrix" << endl;
	Print(arr, rowCount, colCount);
	// ��������� ������
	destroy_mass(arr, rowCount);
}