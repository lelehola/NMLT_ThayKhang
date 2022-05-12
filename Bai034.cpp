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
bool ktNguyenTo(int);
int TongDong(int[][500], int, int, int);

int main()
{
	int b[500][500];
	int k;
	int l;
	int d;
	for (int i = 1; i <= 1; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(b, k, l, FileName);

		cout << "\n" << FileName << endl;
		Xuat(b, k, l);

		cout << "Nhap dong d: ";
		cin >> d;
		int s = TongDong(b, k, l, d);
		cout << "\nTong so nguyen to tren dong " << d << ": " << s;
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
bool ktNguyenTo(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}
int TongDong(int a[][500], int m, int n, int d)
{
	int sum = 0;
	for (int j = 0; j < n; j++)
		if (ktNguyenTo(a[d][j]))
			sum+= a[d][j];
	return sum;
}
