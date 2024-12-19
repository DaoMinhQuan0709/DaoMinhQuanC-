#include<iostream>
#include<math.h>

using namespace std;

void nhap(int &n)
{
	do
	{
		cout<<"nhap so nguyen duong : "; cin>>n;
	}
	while(n <= 3);	
}

int tich(int n)
{
	if(n <= 0)
	{
		return 1;
	}
	int T = 1;
	for(int i = 1; i <= n; i++)
	{
		T = T*i;
	}
	return T;
}

int tong(int n)
{
	if(n <= 0)
	{
		return 0;
	}
	int S = 0;
	for(int  i = 1; i<= n; i++)
	{
		S = S + tich(i);
	}
	return S;
}

int main()
{
	int n, m;
	nhap(n);
	nhap(m);
	cout<<tong(2*n) + tong(m);
	return 0;
}
