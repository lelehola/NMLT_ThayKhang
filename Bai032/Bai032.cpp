#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

string getInputFileName(int);
string getOutputFileName(int);
void Nhap(float[][500], int&, int&, string);
void Xuat(float[][500], int, int, string);
void Xuat(float[][500], int, int);
float Tong(float[][500], int, int, float, float);

int main()
{
	float b[500][500];
	int k;
	int l;
	float x, y;
	for (int i = 1; i <= 1; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(b, k, l, FileName);

		cout << "\n" << FileName << endl;
		Xuat(b, k, l);

		cout << "Nhap x: ";
		cin >> x;
		cout << "Nhap y: ";
		cin >> y;
		float kq = Tong(b, k, l, x, y);
		cout << setw(8) << setprecision(5);
		cout << "\n" << "Tong cac so:" << kq << endl;

		FileName = getOutputFileName(i);
		Xuat(b, k, l, FileName);
	}
	return 1;
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

string getOutputFileName(int n)
{
	string fileName = string("floatmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".out";
	else
		fileName += to_string(n) + ".out";
	return fileName;
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

void Xuat(float a[][500], int m, int n, string filename)
{
	ofstream fo(filename);
	fo << setw(8) << n;
	fo << setw(8) << m;
	fo << "\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			fo << setw(8) << setprecision(5) << a[i][j];
		fo << "\n";
	}
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(3);
			cout << a[i][j];
		}
		cout << "\n";
	}
}

float Tong(float a[][500], int m, int n, float x, float y)
{
	float s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] <= y && a[i][j] >= x)
				s = s + a[i][j];
	return s;
}