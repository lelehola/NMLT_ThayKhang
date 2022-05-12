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
bool ktDang5M(int);
void LietKe(int[][500], int, int, int);

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

		cout << "Nhap cot c: ";
		cin >> c;
		cout << "\nCac so co dang 5^m tren cot " << c << ": ";
		LietKe(b, k, l, c);
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
bool ktDang5M(int n)
{   
	if (n < 1)
		return false;
	int flag = 1;
	int t = n;
	while (t > 1)
	{
		int dv = t % 5;
		if (dv != 0)
			flag = 0;
		t /= 5;
	}
	if (flag == 1)
		return true;
	return false;
}
void LietKe(int a[][500], int m, int n, int c)
{
	for (int i = 0; i < m; i++)
		if (ktDang5M(a[i][c]) == 1)
			cout << setw(8) << a[i][c];
}
