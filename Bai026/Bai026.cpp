#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

string getInputFileName(int);
void Nhap(int[][500], int&, int&, string);
void Xuat(int[][500], int, int);
bool ktChinhPhuong(int);
int TongChinhPhuong(int[][500], int, int);

int main()
{
	int b[500][500];
	int k;
	int l;
	int c;
	for (int i = 1; i <= 1; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(b, k, l, FileName);

		cout << "\n" << FileName << endl;
		Xuat(b, k, l);

		int S = TongChinhPhuong(b, k, l);
		cout << "\nTong cac so chinh phuong tren cot le: " << S;
	}
	return 0;
}

void Nhap(int a[][500], int& m, int& n, string filename)
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
	string fileName = string("intmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".inp";
	else
		fileName += to_string(n) + ".inp";
	return fileName;
}

void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << "\n";
	}
}
bool ktChinhPhuong(int n)
{
	for (int i = 0; i < n; i++)
		if (i * i == n)
			return true;
	return false;
}
int TongChinhPhuong(int a[][500], int m, int n)
{
	int sum = 0;
	for (int i = 0; i < m; i ++)
		for (int j = 1; j < n; j += 2)
			if (ktChinhPhuong(a[i][j]) )
				sum += a[i][j];
	return sum;
}