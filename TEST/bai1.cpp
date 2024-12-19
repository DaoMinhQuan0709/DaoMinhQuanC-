#include<iostream>
#include<math.h>
#include<conio.h>

using namespace std;

float ham(float &x, int &n)
{
    float p = 2018*pow(x, n);
    for(int i = 1; i <= n; ++i)
    {
        p = p + 1.0*(pow(x, i)/pow(3, (i - 1)));
    }
    
    return p;
}

int main()
{
    int n, m;
    float x, p, k;
    cout<<"nhap so thuc bat ki : "; cin>>x;
    cout<<"nhap so nguyen bat ki : "; cin>>n;
    ham(x, n);
    cout<<p;
    return 0;
}
