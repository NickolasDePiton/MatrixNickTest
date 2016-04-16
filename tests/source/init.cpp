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
SCENARIO("Matrix operator >>", "[Fill]") 
{
	std::ifstream input("1.txt");
	Matrix matrix = Matrix(5, 5);
	REQUIRE( input >> matrix );
	REQUIRE( matrix[0][0] == 1 );
	REQUIRE( matrix[2][1] == 12 );
	REQUIRE( matrix[3][2] == 18 );
	REQUIRE( matrix[4][3] == 24 );
}
SCENARIO("Matrix operator <<", "[out]") 
{
	Matrix matrix(5,5);
	Matrix matrixg(5,5);
	std::ifstream("1.txt") >> matrix;
	fstream out; 
	out.open("out.txt");
	REQUIRE(out << matrix);
	std::ifstream("out.txt") >> matrixg;
	out.close();
	REQUIRE(matrix==matrixg);
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
	REQUIRE(s[1]==7);
	REQUIRE(s[2]==13);
	REQUIRE(s[3]==19);
	REQUIRE(s[4]==25);
}

