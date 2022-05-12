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
bool ktDang3M(int);
int Tong3M(int[][500], int, int);

int main()
{
	int b[500][500];
	int k;
	int l;
	for (int i = 1; i <= 1; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(b, k, l, FileName);

		cout << "\n" << FileName << endl;
		Xuat(b, k, l);

		int S = Tong3M(b, k, l);
		cout << "\nCac so co dang 3^m: " << S;
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
bool ktDang3M(int n)
{
	if (n < 1)
		return false;
	int flag = 1;
	int t = n;
	while (t > 1)
	{
		int dv = t % 3;
		if (dv != 0)
			flag = 0;
		t /= 3;
	}
	if (flag == 1)
		return true;
	return false;
}
int Tong3M(int a[][500], int m, int n)
{
	int sum = 0;
	for (int i = 0; i < m; i++)
		for(int j = 0 ; j < n; j++)
		  if(ktDang3M(a[i][j]) == 1)
			 sum+= a[i][j];
	return sum;
}
