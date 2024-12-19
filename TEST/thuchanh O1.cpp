#include<iostream>
#include<math.h>
#include<conio.h>

using namespace std;

int gt(int n)
{
    int x = 1;
    for(int i = 1; i <= n; i++)
    {
        x = x * i;
    }
    return x;
}

float F(float x, int n)
{
    int giaithua;
    float f = 1.0*pow(x, n) / giaithua;
    return f;
}

float ham(float x, int n)
{
    float f = 0;
    for(int i = 1; i <= n; i++)
    {
       f = f + pow(x, i); 
    }
    f = f + 2017;
    return f;
}

int songuyen(int n)
{
    int sodem = 1; 
    for(int a = 10;a <= n; a *= 10)
    {
            sodem++;
    }
    return sodem;
}

int catalan(int n)
{
	int cata = gt(2n) / (gt(n+1) * gt(n));
	return cata;
}

int main()
{
    //O1.1
	int a, b;
    cout<<"nhap so nguyen a "; cin>>a;
    cout<<"nhap so nguyen b "; cin>>b;
    float p = 1.0*( gt(a) + gt(b) ) / gt(a + b);
    cout<<"Gia tri bieu thuc la : "<<p<<endl;
    
	//O1.2
	float x;
    int n, giaithua;
    cout<<"nhap so thuc x "; cin>>x;
    do
    {
        cout<<"nhap so nguyen n "; cin>>n;
    }
        while(n <= 0);

	giaithua = gt(n);  
    cout<<"Gia tri bieu thuc la : "<<F(x, n)<<endl;
    
    //O1.3
	cout<<"Gia tri bieu thuc la : "<<ham(x, n)<<endl;
    
    //O1.4
	cout<<"So nguyen "<<n<<" co "<<songuyen(n)<<" chu so."<<endl;
    
	//O1.5
	cout<<"So CataLan thu "<<n<<" la : "<<catalan(n)<<endl;
	return 0;
}

