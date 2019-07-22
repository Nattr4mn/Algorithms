#ifndef MATRIX_OPERATION_REALISATION
#define MATRIX_OPERATION_REALISATION

#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include "Matrix.h"
using namespace mtx;

Matrix::Matrix()
{
	row_size = new int{ 3 };
	column_size = new int{ 3 };
	matrix = new double*[*row_size];
	for (int i = 0; i < *row_size; i++)
		matrix[i] = new double[*column_size];
}

Matrix::Matrix(Matrix& copy)
{
	row_size = new int{ *copy.getRowSize() };
	column_size = new int{ *copy.getColumnSize() };
	matrix = new double*[*row_size];
	for (int i = 0; i < *row_size; i++)
		matrix[i] = new double[*column_size];

	for (int i = 0; i < *row_size; i++)
	{
		for (int j = 0; j < *column_size; j++)
			matrix[i][j] = copy.getValueMatrix(i, j);
	}

}

Matrix::Matrix(const int& size)
{
	row_size = new int{ size };
	column_size = new int{ size };
	matrix = new double*[*row_size];
	for (int i = 0; i < *row_size; i++)
		matrix[i] = new double[*column_size];
}

Matrix::Matrix(const int& rs, const int& cs)
{
	row_size = new int{ rs };
	column_size = new int{ cs };
	matrix = new double*[*row_size];
	for (int i = 0; i < *row_size; i++)
		matrix[i] = new double[*column_size];
}

Matrix::~Matrix()
{
	std::cout << "Вызван деструктор!" << std::endl;
	for (int i = 0; i < *row_size; i++)
		delete[] matrix[i];
	delete[] matrix;
	delete row_size;
	delete column_size;
}

void Matrix::operator=(Matrix& B)
{
	if (*row_size != *B.getRowSize() || *column_size != *B.getColumnSize())
	{
		for (int i = 0; i < *row_size; i++)
			delete[] matrix[i];
		delete[] matrix;
		*row_size = *B.getRowSize();
		*column_size = *B.getColumnSize();
		matrix = new double*[*row_size];
		for (int i = 0; i < *row_size; i++)
			matrix[i] = new double[*column_size];
	}

	for (int i = 0; i < *row_size; i++)
	{
		for (int j = 0; j < *column_size; j++)
			matrix[i][j] = B.getValueMatrix(i, j);
	}
}

int Matrix::rank()
{
	int rank_matrix = 0;
	double** matrix_copy = createCopy();

	for (int i = 0; i < (*row_size) - 1; i++)
	{
		if (!check(matrix_copy, i)) break;

		for (int j = i + 1; j < *row_size; j++)
		{
			double multiplier = -matrix_copy[j][i] / matrix_copy[i][i];
			for (int k = 0; k < *column_size; k++)
			{
				matrix_copy[j][k] += multiplier * matrix_copy[i][k];
			}
		}
	}

	int* count = new int{ 0 };
	for (int i = 0; i < *row_size; i++)
	{
		for (int j = 0; j < *column_size; j++)
			if (matrix_copy[i][j] != 0) (*count)++;
		if ((*count) != 0) rank_matrix++;
		(*count) = 0;
	}

	delete count;
	deleteCopy(matrix_copy, row_size);

	return rank_matrix;
}

void Matrix::transpose()
{
	double** matrix_copy = createCopy();

	for (int i = 0; i < *row_size; i++)
		delete[] matrix[i];
	delete[] matrix;

	int* tmp = new int{ *row_size };
	*row_size = *column_size;
	*column_size = *tmp;
	delete tmp;

	matrix = new double*[*row_size];
	for (int i = 0; i < *row_size; i++)
		matrix[i] = new double[*column_size];

	for (int i = 0; i < *row_size; i++)
		for (int j = 0; j < *column_size; j++)
			matrix[i][j] = matrix_copy[j][i];

	deleteCopy(matrix_copy, column_size);
}

void Matrix::setMatrix()
{
	srand(time(0));
	for (int i = 0; i < *row_size; i++)
		for (int j = 0; j < *column_size; j++)
			matrix[i][j] = rand() % (*row_size + *column_size);
}

void Matrix::setMatrix(const bool& ans)
{
	for (int i = 0; i < *row_size; i++)
		for (int j = 0; j < *column_size; j++)
		{
			std::cout << '[' << i << "][" << j << ']';
			std::cin >> matrix[i][j];
		}
}

int* Matrix::getRowSize() const { return row_size; }

int* Matrix::getColumnSize() const { return column_size; }

double Matrix::getValueMatrix(const int& i, const int& j) { return matrix[i][j]; }

void Matrix::show()
{
	std::cout << std::endl;
	for (int i = 0; i < *row_size; i++)
	{
		for (int j = 0; j < *column_size; j++)
			std::cout << std::setw(10) << matrix[i][j] << ' ';
		std::cout << std::endl;
	}
}

void Matrix::show(double** mtrx)
{
	std::cout << std::endl;
	for (int i = 0; i < *row_size; i++)
	{
		for (int j = 0; j < *column_size; j++)
			std::cout << std::setw(10) << mtrx[i][j] << ' ';
		std::cout << std::endl;
	}
}

int Matrix::check(double** array, const int& i)
{
	int* count = new int{ 0 };
	for (int j = i; j < *row_size; j++)
		for (int k = i; k < *column_size; k++)
			if (array[j][k] != 0) (*count)++;
	if ((*count) == 0)
	{
		delete count;
		return 0;
	}

	for (int j = i; j < *row_size; j++)
	{
		if (array[j][i] != 0)
		{
			swapRow(array, i, j);
			return 1;
		}
	}

	for (int j = i; j < *column_size; j++)
	{
		if (array[i][j] != 0)
		{
			swapClmn(array, i, j);
			return 1;
		}
	}
}

void Matrix::swapRow(double** array, const int& i, const int& j)
{
	for (int k = 0; k < *column_size; k++)
	{
		double tmp = array[i][k];
		array[i][k] = array[j][k];
		array[j][k] = tmp;
	}
}

void Matrix::swapClmn(double** array, const int& i, const int& j)
{
	for (int k = 0; k < *row_size; k++)
	{
		double tmp = array[k][i];
		array[k][i] = array[k][j];
		array[k][j] = tmp;
	}
}

double** Matrix::createCopy()
{
	double** copy;
	copy = new double*[*row_size];
	for (int i = 0; i < *row_size; i++)
		copy[i] = new double[*column_size];

	for (int i = 0; i < *row_size; i++)
		for (int j = 0; j < *column_size; j++)
			copy[i][j] = matrix[i][j];

	return copy;
}

void Matrix::deleteCopy(double** copy, const int* rs)
{
	for (int i = 0; i < *rs; i++)
		delete[] copy[i];
	delete[] copy;
}

#endif
