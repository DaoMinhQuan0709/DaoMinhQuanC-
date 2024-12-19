#include<iostream>
#include<fstream>

using namespace std;

void nhap(float* &a, int &n)
{
	cout<<"nhap so luong phan tu "; cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
	cout<<endl;
}

void xuat(float *a, int n)
{
	ofstream f("BT3.txt", ios::out);
	cout<<"mang ban dau : "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	f<<"mang ban dau : "<<endl;
	for(int i = 0; i < n; i++)
	{
		f<<a[i]<<" ";
	}
	f<<endl;
	f.close();
}

void tong(float *a, int n)
{
	ofstream f("BT3.txt", ios::app);
	int sum = 0;
	for(int i = 0; i < n; i++)
		if(a[i] >= 5 && a[i] <= 10)
		{
			sum = sum + a[i];
		}
	cout<<"tong cac phan tu tm de bai trong mang la : "<<sum<<endl;
	f<<"tong cac phan tu tm de bai trong mang la : "<<sum<<endl;
	f.close();	
}

void xet(float *a, int n)
{
	int x = 1;
	for(int i = 0;i < n; i++)
	{
		if(a[i] <= 6)
		{
			x = 0;
			break;
		}
	}
	if(x == 1)
		cout<<"mang hop le "<<endl;
	else
	{
		cout<<"mang khong hop le"<<endl;
	}
}

void xoa(float *a, int n, int vt)
{
	int x;
	cout<<"nhap x : "; cin>>x;
	int m = 0;
	float *b = new float[n];
	for(int i = 0; i < n; i++)
	{	
		if(a[i] != x)
		{
			b[m] = a[i];
			m++;
		}
	}
	for(int i = 0; i < m; i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	float *a ;
	int n, vt;
	a = new float[n];
	
	nhap(a, n);
	xuat(a, n);
	tong(a, n);
	xet(a, n);
	xoa(a, n, vt);
	return 0;
}
