#include "matrix.h"
#include <iostream>
#include <fstream>
using namespace std;

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
