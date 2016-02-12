#include <iostream>
#include <time.h>
using namespace std;
const int X = 59, Y = 80;

void copy(int a1[X][Y], int a2[X][Y])
{
	for (int j = 0; j < X; j++)
	{
		for (int i = 0; i < Y; i++)
			a2[j][i] = a1[j][i];
	}
}

void life(int array[X][Y], char wybor)
{
	int temp[X][Y];
	copy(array, temp);
	for (int j = 1; j < X - 1; j++)
	{
		for (int i = 1; i < Y - 1; i++)
		{
			int licz = 0;
			if (wybor == 'm')
			{
				licz = array[j - 1][i] +
					array[j - 1][i - 1] +
					array[j][i - 1] +
					array[j + 1][i - 1] +
					array[j + 1][i] +
					array[j + 1][i + 1] +
					array[j][i + 1] +
					array[j - 1][i + 1];
			}
			else
			{
				licz = array[j - 1][i] +
					array[j][i - 1] +
					array[j + 1][i] +
					array[j][i + 1];
			}
			if (licz < 2 || licz > 3)
				temp[j][i] = 0;
			if (licz == 2)
				temp[j][i] = array[j][i];
			if (licz == 3)
				temp[j][i] = 1;
		}
	}
	copy(temp, array);
}

void print(int array[X][Y])
{
	for (int j = 1; j < X - 1; j++)
	{
		for (int i = 1; i < Y - 1; i++)
		{
			if (array[j][i] == 1)
				cout << 'O';
			else
				cout << ' ';
		}
		cout << endl;
	}
}

int main()
{
	int gen0[X][Y];
	int todo[X][Y];
	int backup[X][Y];
	char alg;
	char again;
	char cont;

	do
	{
		cout << "Algorytm Moore'a czy von Neumann'a? (m lub n) ";
		cin >> alg;
	} while (alg != 'm' && alg != 'n');
	system("cls");
	int i = 0;
	srand(time(NULL));
	while (1)
	{
		for (int j = 1; j < X - 1; j++)
		{
			for (int i = 1; i < Y - 1; i++)
				gen0[j][i] = rand() % 2;
		}
		cout << "Pokolenie: " << i << endl;
		if (i == 0)
			copy(gen0, todo);
		copy(todo, backup);
		print(todo);
		life(todo, alg);
		i++;
		system("cls");
	}
}
