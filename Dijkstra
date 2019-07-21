#include <iostream>
using namespace std;

const int n = 6;
void dijkstra(int** e, int* dstc, int* last, int& st);

int main() {
	system("chcp 1251>nul");
	int st = 0, end = n - 1;				//переменные первой и последней вершины
	int** e = new int* [n];				//матрица весов
	for (int i = 0; i < n; i++) e[i] = new int[n];
	int E[] =
	{
		//v0 v1 v2 v3 v4 v5
		  0, 4, 7, 0, 0, 0,	//v0
		  4, 0, 1, 0, 4, 0,	//v1
		  7, 1, 0, 1, 0, 0,	//v2
		  0, 0, 1, 0, 1, 0,	//v3
		  0, 4, 0, 1, 0, 3,	//v4
		  0, 0, 0, 0, 3, 0	//v5
	};
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			e[i][j] = E[k++];
	int* dstc = new int[n];
	int* last = new int[n];				//последнее изменение метки

	dijkstra(e, dstc, last, st);

	cout << "Введите вершину (от 0 до " << n - 1 << "), до которой необходимо найти путь:";
	cin >> end;
	if (end >= 0 && end < n)
	{
		for (int i = 1; i <= end; i++)
		{
			if (last[i] != last[i + 1])
				cout << "v[" << last[i] << "] -> ";
		}
		cout << "v[" << end << ']' << endl << "Дистанция пути равна " << dstc[end] << endl;
	}
	else
		cout << "Данной вершины не существует!";
	delete[]e;
	delete[]dstc;
	delete[]last;

	return 0;
}

void dijkstra(int** e, int* dstc, int* last, int& st)
{
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		dstc[i] = INT_MAX;
		last[i] = INT_MAX;
		visited[i] = false;
	}
	dstc[0] = e[0][st];
	last[0] = 0;
	int ind;
	for (int i = 0; i < n; i++)
	{
		int mtk = INT_MAX;
		for (int j = 0; j < n; j++)
			if (!visited[j] && dstc[j] < mtk)
			{
				mtk = dstc[j];
				ind = j;
			}
		visited[ind] = true;
		for (int j = 0; j < n; j++)
		{
			if (e[ind][j] != 0 && !visited[j] && dstc[ind] + e[ind][j] <= dstc[j])
			{
				dstc[j] = dstc[ind] + e[ind][j];
				last[j] = ind;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << dstc[i] << ' ';
	cout << endl;
	for (int i = 0; i < n; i++) cout << last[i] << ' ';
	cout << endl;
	delete[]visited;
}
