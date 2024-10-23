#include <iostream>
#include <iomanip>
using namespace std;

void InputRows(int** a, const int rowCount, const int colCount, int rowNo = 0);
void InputRow(int** a, const int rowNo, const int colCount, int colNo = 0);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo = 0);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo = 0);
int CountRowsWithoutZero(int** a, const int rowCount, const int colCount, int rowNo = 0);
bool RowHasZero(int** a, const int rowNo, const int colCount, int colNo = 0);
void FindMaxRepeated(int** a, const int rowCount, const int colCount, int& maxRepeated, int rowNo = 0, int colNo = 0);

int main()
{
    int Low = -10;
    int High = 10;
    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // CreateRows(a, rowCount, colCount, Low, High);
    InputRows(a, rowCount, colCount);
    PrintRows(a, rowCount, colCount);

    int count = CountRowsWithoutZero(a, rowCount, colCount);
    cout << "Кількість рядків без нульових елементів: " << count << endl;

    int maxRepeated = INT_MIN;
    FindMaxRepeated(a, rowCount, colCount, maxRepeated);
    if (maxRepeated != INT_MIN)
        cout << "Максимальне число, що зустрічається більше одного разу: " << maxRepeated << endl;
    else
        cout << "Немає чисел, що зустрічаються більше одного разу." << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    if (rowNo < rowCount)
    {
        InputRow(a, rowNo, colCount);
        InputRows(a, rowCount, colCount, rowNo + 1);
    }
}

void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
    if (colNo < colCount)
    {
        cout << "a[" << rowNo << "][" << colNo << "] = ";
        cin >> a[rowNo][colNo];
        InputRow(a, rowNo, colCount, colNo + 1);
    }
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    if (rowNo < rowCount)
    {
        PrintRow(a, rowNo, colCount);
        PrintRows(a, rowCount, colCount, rowNo + 1);
    }
    else
        cout << endl;
}

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    if (colNo < colCount)
    {
        cout << setw(5) << a[rowNo][colNo];
        PrintRow(a, rowNo, colCount, colNo + 1);
    }
    else
        cout << endl;
}

int CountRowsWithoutZero(int** a, const int rowCount, const int colCount, int rowNo)
{
    if (rowNo < rowCount)
    {
        if (!RowHasZero(a, rowNo, colCount))
            return 1 + CountRowsWithoutZero(a, rowCount, colCount, rowNo + 1);
        else
            return CountRowsWithoutZero(a, rowCount, colCount, rowNo + 1);
    }
    else
        return 0;
}

bool RowHasZero(int** a, const int rowNo, const int colCount, int colNo)
{
    if (colNo < colCount)
    {
        if (a[rowNo][colNo] == 0)
            return true;
        else
            return RowHasZero(a, rowNo, colCount, colNo + 1);
    }
    else
        return false;
}

void FindMaxRepeated(int** a, const int rowCount, const int colCount, int& maxRepeated, int rowNo, int colNo)
{
    if (rowNo < rowCount)
    {
        if (colNo < colCount)
        {
            int current = a[rowNo][colNo];
            int count = 0;

            // Перевірка повторень
            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < colCount; j++)
                {
                    if (a[i][j] == current)
                        count++;
                }
            }

            if (count > 1 && current > maxRepeated)
                maxRepeated = current;

            FindMaxRepeated(a, rowCount, colCount, maxRepeated, rowNo, colNo + 1);
        }
        else
        {
            FindMaxRepeated(a, rowCount, colCount, maxRepeated, rowNo + 1, 0);
        }
    }
}