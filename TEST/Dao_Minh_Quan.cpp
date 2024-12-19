#include<iostream>
#include<math.h>
#include<conio.h>

using namespace std;

float nhapsothuc(float x)
{
    return x;
}

int nhapsonguyen(int n)
{
    return n;
}

int tanggiatri(int n)
{
    n++;
    return n;
}

int giamgiatri(int n)
{
    n--;
    return n;
}

float ham(float &x, int &n)
{
    float p = 0;
    for(int i = 1; i <= n; i++)
    {
        p = p + pow(x, i)/pow(3, (i - 1));
    }
    p = p + 2018*pow(x, n);
    return p;
}

int tong(int n)
{
        int x = 0;
        for(int i = 6; i <= n; i += 2)
        {
            x = x + i;
        }
        return x;
}

int main()
{
    int n, m;
    float x;
    cout<<"nhap so thuc bat ki : "; cin>>x;
    cout<<"nhap so nguyen n bat ki : "; cin>>n;
    cout<<"nhap so nguyen m bat ki : "; cin>>m;
    cout<<"\ngia tri cua n sau tang la : "<<tanggiatri(n);
    cout<<"\ngia tri cua m sau tang la : "<<tanggiatri(m);
    cout<<"\ngia tri cua p(x, n)la :"<<ham(x, n)<<endl;
    int tongsochan = tong(m) - tong(n - 1);
    cout<<"\ngia tri tong cac so chan lon hon 5 trong doan ["<<n<<", "<<m<<"] la : "<<tongsochan<<endl;
    return 0;
}