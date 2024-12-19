#include<bits/stdc++.h>

using namespace std;

void nhap(int* &a, int &n){
	cout<<"Nhap so luong phan tu : "; cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"] = "; cin>>a[i];
	}
	cout<<endl;
}

void xuat(int* a, int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void selectionSort(int* a, int n)
{
	for(int i = 0; i < n; i++){
		int m = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[m])
			m = j;
		}
		int tg = a[m];
		a[m] = a[i];
		a[i] = tg;
	}
}

int main(){
	int *a;
	int n;
	a = new int[n];
	nhap(a, n);
	xuat(a, n);
	selectionSort(a, n);
	xuat(a, n);
	return 0;
}
