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

void bubbleSort(int* a, int n){
	for(int i = 1; i < n; i++){
		for(int j = n - 1; j >= i; j--){
			if(a[j] < a[j - 1])
			{
				int tg = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tg; 
			}
		}
	}	
}

int main(){
	int *a;
	int n;
	a = new int[n];
	nhap(a, n);
	xuat(a, n);
	bubbleSort(a, n);
	xuat(a, n);
	return 0;
}
