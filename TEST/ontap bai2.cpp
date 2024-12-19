#include<iostream>
#include<fstream>

using namespace std;

void nhap(int* &a, int &n)
{
	do
	{
		cout<<"nhap so luong phan tu "; cin>>n;
	}
	while(n <= 0 || n >= 30);
	for(int i = 0; i < n; i++)
	{
	cout<<"a["<<i<<"] = ";
	cin>>a[i];	
	}	
}

void xuat(int *a, int n)
{
	ofstream f("BT2.txt", ios::out);
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i = 0; i < n; i++)
	{
		f<<a[i]<<" ";
	}
	f<<endl;
	f.close();
}

void gt2(int *a, int n)
{
	ofstream f("BT2.txt", ios::app);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] < a[j])
			{
				int tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}	
	for(int i = 0; i < n; i++)
	{
		if(a[i] != a[0])
			{
				cout<<"gia tri lon thu 2 trong mang la "<<a[i]<<endl;
				break;
			}
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i] != a[0])
			{
				f<<"gia tri lon thu 2 trong mang la "<<a[i]<<endl;
				break;
			}
	}
	f.close();
}
	

void giam(int *a, int n)
{
	ofstream f("BT2.txt", ios::app);
	int tg;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] < a[j])
			{
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	for(int i = 0; i < n; i++)
	{
		f<<a[i]<<" ";
	}
	f<<endl;
	f.close();
}

void chen(int *a, int &n, int k, int vt)
{
	cout<<"\nnhap k "; cin>>k;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 != 0)
		{
			vt = i + 1;
			break;
		}
	}
	for(int i = n; i > vt; i--)
	{
		a[i] = a[i - 1];
	}
	n++;
	a[vt] = k;
	cout<<a[3]<<endl;
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
}

int main()
{
	int *a, n, k, vt;
	a = new int[n];
	nhap(a, n);
	xuat(a, n);
	gt2(a, n);
	giam(a, n);

	chen(a, n, k, vt);
	return 0;
}
