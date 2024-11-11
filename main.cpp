#include <iostream>
#include <vector>
#include <iomanip>
#include <random>

using namespace std;

// Функция для перестановки элементов
void rearrangeRow(vector<int> &row)
{
    int length = row.size();
    int start = 1;        // Начинаем со второго элемента
    int end = length - 1; // Начинаем с последнего элемента

    // Перестановка с помощью XOR
    while (start < end)
    {
        row[start] ^= row[end];
        row[end] ^= row[start];
        row[start] ^= row[end];

        start += 2;
        end -= 2;
    }
}

int main()
{
    int rows, columns;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> columns;

    vector<vector<int>> matrix(rows, vector<int>(columns));

    // Заполнение матрицы случайными числами
    random_device rd;
    mt19937 gen(rd());
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = gen() % (rows * columns) + 1;
        }
    }

    cout << "Оригинальная матрица:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    // Перестановка элементов матрицы
    for (int i = 0; i < rows; ++i)
    {
        rearrangeRow(matrix[i]);
    }

    cout << "Изменённая матрица:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}