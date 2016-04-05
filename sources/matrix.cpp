#include "stdafx.h" 
#include <iostream> 
#include <stdio.h> 
#include <string> 
#include <conio.h> 
#include <windows.h> 
#include <stdlib.h> 
#include <fstream> 
#include "matrix.h"
using namespace std;

Matrix::Matrix() : lines(0), columns(0), massiv(nullptr)
{}

Matrix::Matrix(const Matrix &a)
{
	lines = a.lines;
	columns = a.columns;
	massiv = new int*[lines];

	for (int i = 0; i < lines; i++)
	{
		massiv[i] = new int[columns];
		for (int j = 0; j < columns; j++)
			massiv[i][j] = a.massiv[i][j];
	}

}

Matrix::Matrix(int _lines, int _columns) : lines(_lines), columns(_columns)
{
	massiv = new int*[lines];
	for (int i = 0; i < lines; i++)
	{
		massiv[i] = new int[columns];
		for (int j = 0; j < columns; j++)
			massiv[i][j] = 0;
	}

}

void Matrix::read_matrix(const std::string s)
{
	ifstream fin(s);
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			fin >> massiv[i][j];
	fin.close();

}
void Matrix::print_matrix() const
{
	for (int i = 0; i < lines; i++) {

		for (int j = 0; j < columns; j++)
			cout << massiv[i][j] << " ";
		cout << endl;
	}
}
Matrix & Matrix::operator = (Matrix &a)
{
	for (int i = 0; i < lines; i++)

		delete[] massiv[i];
	delete[] massiv;
	lines = a.lines;
	columns = a.columns;
	massiv = new int*[lines];
	for (int i = 0; i < lines; i++)
	{
		massiv[i] = new int[columns];
		for (int j = 0; j < columns; j++)
			massiv[i][j] = a.massiv[i][j];
	}
	return *this;
}


Matrix Matrix::operator + (const Matrix &array)
{

	Matrix result(*this);
	for (int i = 0; i < result.lines; i++)
		for (int j = 0; j < result.columns; j++)
			result.massiv[i][j] += array.massiv[i][j];
	return(result);
}

Matrix Matrix::operator * (const Matrix &array)
{

	Matrix result(lines, array.columns);
	result.reset();
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < array.columns; j++)
			for (int t = 0; t < columns; t++)
				result.massiv[i][j] += massiv[i][t] * array.massiv[t][j];
	return result;
}

int* Matrix::operator [] (int i) const
{
	if ((i - 1) < 0) exit(0);
	int *temp = new int[columns];
	for (int j = 0; j < columns; j++)
		temp[j] = massiv[i - 1][j];
	return(temp);

}
int Matrix::cout_columns() const
{
	return(columns);


}

int Matrix::cout_lines() const
{
	return(lines);
}
void Matrix::reset()
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			massiv[i][j] = 0;
}
Matrix::~Matrix()
{
	for (int i = 0; i < lines; i++)

		delete[] massiv[i];
	delete[] massiv;

}
int main(void)
{
	setlocale(LC_ALL, "Russian"); 
	int a;
	cout << "Àâòîìàòè÷åñêîå ñîçäàíèå ïåðâîé è âòîðîé ìàòðèöû" << endl;

		Matrix matrix(5, 5), matrixg(5,5), expected(5, 5), result(5, 5);
		cout << "Íàïèøèòå ïóòü ôàéëà äëÿ ïåðâîé ìàòðèöû: ";
		std::string s;
		std::getline(std::cin, s);
		matrix.read_matrix(s);
		cout << "Íàïèøèòå ïóòü ôàéëà äëÿ âòîðîé ìàòðèöû: ";
		std::string x;
		std::getline(std::cin, x);
		matrixg.read_matrix(x);
		cout << "1-ÿ Ìàòðèöà: " << endl;
		matrix.print_matrix();
		cout << "2-ÿ Ìàòðèöà: " << endl;
		matrixg.print_matrix();
		cout << "Ðåçóëüòàò óìíîæåíèÿ ìàòðèö: " << endl;
		matrix1 = matrix*matrixg;
		matrix1.print_matrix();
		cout << "Ðåçóëüòàò ñëîæåíèÿ ìàòðèö: " << endl;
		matrix1 = matrix + matrixg;
		matrix1.print_matrix();
		cout << "Ââåäèòå íîìåð ñòðîêè èç ïîñëåäíåé ìàòðèöû. (Ñòðîêà áóäåò âûâåäåíà): ";
		cin >> a;
		int *line_matrix1;
		line_matrix1 = matrix1[a];
		for (int i = 0; i < matrix1.cout_columns(); i++)
		cout << line_matrix1[i] << " ";

		cout << endl;
		int b = matrix.cout_lines();
		cout << "Êîëè÷åñòâî ñòðîê â ïåðâîé ìàòðèöå: " << b;
		b = matrix.cout_columns();
		cout << endl;
		cout << "Êîëè÷åñòâî ñòîëáöîâ â ïåðâîé ìàòðèöå: " << b;
		cout << endl;
	system("pause");

}
