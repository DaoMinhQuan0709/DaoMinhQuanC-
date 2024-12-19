#include<iostream>
#include<math.h>

using namespace std;

void nhap(float a[], int n)
{
    for(int i = 0; i < n; i++)
        {
            cout<<"a["<<i<<"] = ";
            cin>>a[i];
        }
}

void xuat(float a[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}

void sap(float a[], int n)
{
    cout<<"\nmang sau sap xep la : "<<endl;
    float tg;
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
    int I = 0, J = n - 1;
    while(a[I] == a[0]) 
    I++;
    while(a[J] == a[n - 1])
    J--;
       float tg1;
        for(int i = I; i <= J; i++)
            for(int j = i + 1; j <= J; j++)
            {
                if(a[i] > a[j])
                {
                    tg1 = a[i];
                    a[i] = a[j];
                    a[j] = tg1;
                }
            }
}

int c1(float a[], int n)
{
    int t = 0;
    for(int i = 0; i < n; i++)
        t = t + abs(a[i]);
    return t;
}

float c2(float a[], int n)
{
    int t = 0;
    for(int i = 0; i < n; i++)
        {
            t = t + a[i]*a[i];
        }
    float s = 1.0*sqrt(t);    
    return s;
}

int cvc(float a[], int n)
{
    int t = a[0];
    for(int i = 0; i < n; i++)
    {
        if(a[i] > t)
            t = a[i];
    }
    return t;
}

int c0(float a[], int n)
{
    int t = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != 0)
            t++;
    }
    return t;
}

int main()
{
    float a[100];
    int n;
    cout<<"nhap n : "; cin>>n;
    nhap(a, n);
    xuat(a, n);
    //sap(a, n);
    //xuat(a, n);
    cout<<"\n"<<c1(a, n)<<endl;
    cout<<c2(a, n)<<endl;
    cout<<cvc(a, n)<<endl;
    cout<<c0(a, n)<<endl;
    return 0;
}
