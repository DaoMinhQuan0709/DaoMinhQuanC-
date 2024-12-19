#include<iostream>
#include<math.h>

using namespace std;

void nhap(int a[], int n)
{
	for(int i = 0;i < n; i++)
    {
        cin>>a[i]; //nhap gia tri cua mang
    }
}

void xuat(int a[], int n)
{
	cout<<"mang ban dau :"<<endl;
    for(int i = 0;i < n; i++)
    {
        cout<<"a["<<i<<"] = "<<a[i]<<endl;
    }
}

void max(int a[], int n)
{
    int max = a[0];
    for(int i = 1; i < n; i++)
        if(max < a[i])
        max = a[i];
    cout<<max<<endl;
}

void min(int a[], int n)
{
    int min = a[0];
    for(int i = 1; i < n; i++)
        if(min > a[i])
        min = a[i];
    cout<<min<<endl;
}

void tang(int a[], int n)
{
    cout<<"\nmang sau sap xep"<<endl;
	int trunggian;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
               trunggian = a[i];
               a[i] = a[j];
               a[j] = trunggian;
            }
        }
    }
    for(int i = 0; i < n; i++)
	{
	cout<<"a["<<i<<"] = "<<a[i]<<endl;
	}
}

int tich(int a[], int b[], int n)
{
	int tich = 0;
    for(int i = 0; i < n; i++)
    {
        tich = tich + a[i]*b[i];
    }
    return tich;
}

int main()
{
    int n;
	 cout<<"nhap n : "; cin>>n; 
    int a[100], b[100];
    
    nhap(a, n);
    xuat(a, n);
    
    max(a, n);
    min(a, n);
    
	tang(a, n);
	
	//tich vo huong
    nhap(b, n);
    cout<<tich(a, b, n);
    
    return 0;
}
