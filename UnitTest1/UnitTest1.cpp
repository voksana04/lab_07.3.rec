#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\admin\source\repos\Project_7.3_rec\Project_7.3_rec\lab_7.3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;

			// Створюємо та заповнюємо тестову матрицю 3x3
			int** testMatrix = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				testMatrix[i] = new int[colCount];

			// Матриця без нульових елементів у 2-х рядках
			testMatrix[0][0] = 1; testMatrix[0][1] = 2; testMatrix[0][2] = 3;
			testMatrix[1][0] = 0; testMatrix[1][1] = 5; testMatrix[1][2] = 6;
			testMatrix[2][0] = 7; testMatrix[2][1] = 8; testMatrix[2][2] = 9;

			// Викликаємо функцію CountRowsWithoutZero
			int rowsWithoutZero = CountRowsWithoutZero(testMatrix, rowCount, colCount);

			// Очікуємо 2 рядки без нульових елементів (рядки 0 і 2)
			Assert::AreEqual(2, rowsWithoutZero);

			// Звільняємо пам'ять
			for (int i = 0; i < rowCount; i++)
				delete[] testMatrix[i];
			delete[] testMatrix;
		}
	};
}
