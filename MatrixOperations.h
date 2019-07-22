#ifndef MATRIX_OPERATION
#define MATRIX_OPERATION

namespace mtx
{

	class Matrix
	{
	public:
		Matrix();
		Matrix(Matrix& copy);
		Matrix(const int& size);
		Matrix(const int& rs, const int& cs);
		~Matrix();

		void setMatrix();
		void setMatrix(const bool& ans);

		void show();

		int* getRowSize() const;
		int* getColumnSize() const;
		double getValueMatrix(const int& i, const int& j);

		int rank();
		void transpose();

		void operator=(Matrix& B);
	private:
		double** matrix;
		int* row_size;
		int* column_size;

		int check(double** array, const int& i);

		void swapRow(double** array, const int& i, const int& j);
		void swapClmn(double** array, const int& i, const int& j);

		double** createCopy();
		void deleteCopy(double** copy, const int* rs);

		void show(double** mtrx);
	};

}	//namespace mtx

#endif

