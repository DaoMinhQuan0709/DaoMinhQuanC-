#include<bits/stdc++.h>
using namespace std;
#define Max 4

struct Hocsinh{
	string ten;
	string hodem;
	int namsinh;
	string diachi;
};

struct List{
	int cnt = 0;
	Hocsinh hs[Max];
};


// ham de tron 2 mang da sap xep
void tron(Hocsinh a[], int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	// tao cac mang tam
	Hocsinh L[n1], R[n2];
	
	// sao chep vao cac mang tam
	for(int i = 0; i < n1; i++){
		L[i] = a[left + i];
	} 
	for(int i = 0; i < n2; i++){
		R[i] = a[mid + 1 + i];
	} 
	
	// tron cac mang tam tro lai mang a[]
	int i = 0, j = 0, k = left;
	while(i < n1 && j < n2){
		if(L[i].ten <= R[j].ten){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	
	// Sao chép các ph?n t? còn l?i c?a L[], n?u có
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các ph?n t? còn l?i c?a R[], n?u có
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void chiadc(Hocsinh a[], int left, int right){
	if(left < right){
		int mid = left + (right - left) / 2;
	
	// de quy 2 nua
	chiadc(a, left, mid);
	chiadc(a, mid + 1, right);
	
	// tron 2 nua da sap xep
	tron(a, left, mid, right);
	
	}	
}

void tim(Hocsinh a[], int left , int right, string x){
	if(left <= right){
		int mid = left + (right - left) / 2;
	
	// neu tim dc o vtri mid
		if(a[mid].ten == x){
			cout<<setw(15)<<a[mid].hodem;
			cout<<setw(15)<<a[mid].ten;
			cout<<setw(15)<<a[mid].namsinh;
			cout<<setw(15)<<a[mid].diachi<<endl;
			return;
		}
		
		// tim o 2 nua
		if(x < a[mid].ten){
			tim(a, left, mid, x);
		}
		else{
			tim(a, mid + 1, right, x);
		}	
	}
	else{
		cout<<"\nKhong tin thay hs"<<endl;
	}
}

// Hàm hi?n th? danh sách s?p x?p gh?
void indsg(List L, int seat[]) {
    for (int i = 0; i < L.cnt; i++) {
        int idx = seat[i];
        cout << setw(15) << L.hs[idx].hodem
             << setw(15) << L.hs[idx].ten
             << setw(15) << L.hs[idx].namsinh
             << setw(15) << L.hs[idx].diachi << endl;
    }
    cout << endl;
}

void backtrack(List &L, int index, int seat[], int used[]){
	for(int i = 0; i < L.cnt; i++){
		if(used[i] == 0){
			seat[index] = i;
			used[i] = 1;
			if(index == L.cnt - 1){
				indsg(L,seat);
			}
			else{
				backtrack(L, index + 1, seat,used);
			}
			// backtrack
			used[i] = 0;
		}
	}
}

void inds(List L){
	for(int i = 0; i < L.cnt; i++){
		cout<<setw(15)<<L.hs[i].hodem;
		cout<<setw(15)<<L.hs[i].ten;
		cout<<setw(15)<<L.hs[i].namsinh;
		cout<<setw(15)<<L.hs[i].diachi<<endl;
	}
}

int main(){
	List L;
	Hocsinh hs[] = {
		{"An","Nguyen Van",2002,"Ha Noi"},
		{"Tri","Tran Duc",2004,"Hai Duong"},
		{"Linh","Pham Thi",2006,"Nam Dinh"},
		{"Long","Pham Duc",2000,"Hai Phong"}
	};
	
	L.cnt = 4;
	for(int i = 0; i < L.cnt; i++){
		L.hs[i] = hs[i];
	}
	
	
	cout<<"ds trc khi sap xep"<<endl;
	inds(L);
	
	
//	cout<<"\nds sau khi sap xep"<<endl;
//	chiadc(L.hs, 0, L.cnt - 1);
//	inds(L);

	
	cout<<"\nNhap ten hs can tim"<<endl;
	string x; cin>>x;
	tim(L.hs , 0, L.cnt - 1, x);
	
//	int seat[4];
//	int used[4];
//	fill(used, used + L.cnt, 0); 
//	cout<<"\nsap xep cho "<<endl;
//	backtrack(L, 0,seat,used);
	
	return 0;
}
