#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void shellSort(int* array, const int& size);
void insertSort(int* array, const int& size, int& start, int& step);
void showArray(int* a, const int& size);

int main(){
    
	system("chcp 1251>nul");

    const int SIZE = 15;
    int *a = new int[SIZE];

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) a[i] = (rand() % 100);

    cout<<"Дано:"<<endl;
    showArray(a, SIZE);

    shellSort(a, SIZE);

    cout<<endl<<"Итог:"<<endl;
    showArray(a, SIZE);

    delete [] a;
	system("pause>nul");
}

void shellSort(int* array, const int& size)
{
    int step;
	for (step = 1; 2 * step < size; step *= 2);
	while (step >= 1)
	{
		for (int start = 0; start < step; start++) insertSort(array, size, start, step);
		step /= 2;
    }
}

void insertSort(int* array, const int& size, int& start, int& step)
{
	for (int j = start + step; j < size; j += step)
	{
		int min_value_number = j;
		for (int k = j - step; k >= start; k -= step)
		{
			if (array[j] < array[k])
				min_value_number = k;
		}
		int tmp = array[j];
		for (int k = j; k > min_value_number; k -= step) array[k] = array[k - step];
		array[min_value_number] = tmp;
    }
}

void showArray(int *a, const int& size)
{
	for (int c = 0; c < size; c++) cout << setw(4) << a[c];
    cout<<endl;
}
