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
bool ktToanChan(int);
int TongToanChan(int[][500], int, int);

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

		int S = TongToanChan(b, k, l);
		cout << "\nTong cac so toan chan: " << S;
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
bool ktToanChan(int n)
{
	bool flag = 1;
	int t = n = abs(n);
	while (t != 0)
	{
		int dv = t % 10;
		if (dv % 2 != 0)
			flag = 0;
		t /= 10;
	}
	return flag;
}
int TongToanChan(int a[][500], int m, int n)
{
	cout << endl;
	int sum = 0;
	for (int i = 0; i < m; i++)
		for (int j = 1; j < n; j++)
			if (ktToanChan(a[i][j]))
				sum+= a[i][j];
	return sum;
}