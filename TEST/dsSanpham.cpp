#include<bits/stdc++.h>
using namespace std;
#define Max 3

struct SanPham{
	string mahang;
	string tenhang;
	string dvt;
	double dongia;
	int soluong;
	double tt(){
		return dongia * soluong;
	}
};
struct List{
	int cnt = 0;
	SanPham sp[Max];
};
void taosp(SanPham &sp){
	cout<<"nhap ma hang : "; getline(cin,sp.mahang);
	cout<<"nhap ten hang : "; getline(cin,sp.tenhang);
	cout<<"nhap don vi tinh : "; getline(cin,sp.dvt);
	cout<<"nhap don gia : "; cin>>sp.dongia;
	cout<<"nhap so luong : "; cin>>sp.soluong;
	cin.ignore();
}
void nhapds(List &L){
	SanPham x;
	cout<<"NHAP SAN PHAM"<<endl;
	taosp(x);
	L.sp[L.cnt] = x;
	L.cnt++;
}
void inds(List L){
	cout<<setw(15)<<"STT";
	cout<<setw(15)<<"MA HANG";
	cout<<setw(15)<<"TEN HANG";
	cout<<setw(15)<<"DVT";
	cout<<setw(15)<<"DON GIA";
	cout<<setw(15)<<"SO LUONG";
	cout<<setw(15)<<"THANH TIEN"<<endl;
	for(int i = 0; i < L.cnt; i++){
		cout<<setw(15)<<i + 1;
		cout<<setw(15)<<L.sp[i].mahang;
		cout<<setw(15)<<L.sp[i].tenhang;
		cout<<setw(15)<<L.sp[i].dvt;
		cout<<setw(15)<<L.sp[i].dongia;
		cout<<setw(15)<<L.sp[i].soluong;
		cout<<setw(15)<<L.sp[i].tt()<<endl;
	}
}

void sapxep(List &L){
	for(int i = 0; i < L.cnt; i++){
		for(int j = L.cnt - 1; j >= i; j--){
			float tt1 = L.sp[j].dongia * L.sp[j].soluong;
			float tt2 = L.sp[j - 1].dongia * L.sp[j - 1].soluong;
			if(tt1 < tt2){
				SanPham tg = L.sp[j];
				L.sp[j] = L.sp[j - 1];
				L.sp[j - 1] = tg;
			}
		}
	}
}

int main(){
	List L;
	for(int i = 0; i < Max; i++){
		nhapds(L);	
	}
	inds(L);
	sapxep(L);
	cout<<"danh sach sau khi dc sap xep \n";
	inds(L);
	return 0;
}
