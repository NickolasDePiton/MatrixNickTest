#include <matrix.h>
#include <catch.hpp>
#include <fstream>
#include <iostream>
using namespace std;

SCENARIO("Matrix init", "[init]") {

	GIVEN("The number of lines and columns") {

		auto lines = 5;
		auto columns = 5;

		WHEN("Create instansce of Matrix") {
			Matrix matrix(lines, columns);
			THEN("The number of lines and columns must be preserved") {

				REQUIRE(matrix.cout_lines() == lines);
				REQUIRE(matrix.cout_columns() == columns);
			}
		}
	}
}
SCENARIO("Matrix +", "[addition]") {
	Matrix matrix = Matrix(5, 5);
	matrix.read_matrix("1.txt");
	Matrix matrixg = Matrix(5, 5);
	matrixg.read_matrix("2.txt");
	Matrix expected = Matrix(5, 5);
	expected.read_matrix("1+2.txt");
	Matrix result = matrix + matrixg;
	REQUIRE(result == expected);
}

SCENARIO("Matrix *", "[addition]") {
	Matrix matrix = Matrix(5, 5);
	matrix.read_matrix("1.txt");
	Matrix matrixg = Matrix(5, 5);
	matrixg.read_matrix("2.txt");
	Matrix expected = Matrix(5, 5);
	expected.read_matrix("1_2.txt");
	Matrix result = matrix * matrixg;
	REQUIRE(result == expected);
}

SCENARIO("Matrix: operator ==", "[equal]") {
	Matrix matrix, matrixg;
	matrix.read_matrix("1.txt");
	matrixg.read_matrix("1.txt");
	bool f = (matrix == matrixg);
	REQUIRE(f);
}

SCENARIO("Matrix operator [](int)", "[s]") 
{
	Matrix matrix(5,5);
	matrix.read_matrix("1.txt");
	int* s = matrix[1];
	REQUIRE(s[0]==1);
}
