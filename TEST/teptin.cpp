
#include<iostream>
#include<fstream>

using namespace std;

void nhap(int* &a, int &n)
{
	do
	{
		cout<<"nhap so luong ptu : ";
		cin>>n;
	}
	while(n <= 0 || n >= 30);
	for(int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}

void xuat(int* &a, int &n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void taofile(int *a, int n)
{
	ofstream f("BT2.txt", ios::out);
	f<<"mang a : "<<endl;
	for(int i = 0; i < n; i++)
		f<<a[i]<<" ";
	f.close();
}

void giam(int *a, int n)
{
	ofstream f("BT2.txt", ios::app);
	f<<"\nmang theo thu tu giam dan "<<endl;
	for(int i = 0; i < n; i++)
		for(int j = i + 1;j < n; j++)
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
			f<<a[i]<<" ";
		}
		f<<"\nso lon thu 2 trong mang la "<<a[1]<<endl;
		f.close();
}

void chen(int *a, int &n, int vt, int k)
{
	cout<<"nhap k : ";
	cin>>k;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 != 0)
		{
			vt = i + 1 ;
		}
	}
	
	for(int i = n ; i > vt ; i--)
		{
			a[i] = a[i-1];
		}
	a[vt] = k;
	n++;
	for(int i = 0; i < n; i++)
		{
			cout<<a[i]<<" ";
		}
	cout<<endl;
}

int main()
{
	int n, k, vt;
	int *a = new int[n];
	nhap(a,n);
	xuat(a,n);
	taofile(a, n);
	//giam(a, n);
	//xuat(a,n);
	cout<<"\nso lon thu 2 trong mang la "<<a[1]<<endl;
	chen(a, n,vt, k);
	return 0;
}


