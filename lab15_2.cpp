#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double d[][N])
{
	for(int i = 0; i < N; i++)
    {
		cout << "Row " << i + 1 << ": ";
		for (int j = 0; j < N; j++)
		{
			cin >> d[i][j];
		}
	}
}

void findLocalMax(const double d1[][N], bool d2[][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
        {
			if ((i > 0 && i <= N - 2) && (j > 0 && j <= N - 2))
			{
				if ((d1[i][j] >= d1[i - 1][j]) && (d1[i][j] >= d1[i][j - 1]) && (d1[i][j] >= d1[i][j + 1]) && (d1[i][j] >= d1[i + 1][j]))
				{
					d2[i][j] = 1;
				}
				else d2[i][j] = 0;
			}
			else d2[i][j] = 0;
		}
	}
}

void showMatrix(const bool d[][N])
{
	for(int i = 0; i < N; i++)
    {
		for (int j = 0; j < N; j++)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
}