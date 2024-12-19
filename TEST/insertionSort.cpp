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

void insertionSort(int* a, int n){
	for(int i = 1; i < n; i++){
		int tam = a[i];
		int j = i - 1;
		while(j > -1 && a[j] > tam){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tam;
	}
}

int main(){
	int *a;
	int n;
	a = new int[n];
	nhap(a, n);
	xuat(a, n);
	insertionSort(a, n);
	xuat(a, n);
	return 0;
}
