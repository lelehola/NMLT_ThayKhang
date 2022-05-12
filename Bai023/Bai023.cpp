#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

string getInputFileName(int);
void Nhap(float[][500], int&, int&, string);
void Xuat(float[][500], int, int);
int ktCucTieu(float[][500], int, int, int, int);
void LietKe(float[][500], int, int);

int main()
{
	float b[500][500];
	int k;
	int l;
	for (int i = 1; i <= 1; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(b, k, l, FileName);

		cout << "\n" << FileName << endl;
		Xuat(b, k, l);

		cout << "\nCac phan tu cuc tieu: ";
		LietKe(b, k, l);
	}
	return 0;
}

void Nhap(float a[][500], int& m, int& n, string filename)
{
	ifstream fi(filename);
	fi >> m;
	fi >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

string getInputFileName(int n)
{
	string fileName = string("floatmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".inp";
	else
		fileName += to_string(n) + ".inp";
	return fileName;
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << "\n";
	}
}
int ktCucTieu(float a[][500], int m, int n, int c, int d)
{
	int flag = 1;
	for (int i = c - 1; i <= c + 1; i++)
		for (int j = d - 1; j <= d + 1; j++)
			if (a[c][d] > a[i][j])
				flag = 0;
	return flag;
}
void LietKe(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucTieu(a, m, n, i, j) == 1)
				cout << setw(8) << "a[" << i << "][" << j << "] = " <<  a[i][j];
}
