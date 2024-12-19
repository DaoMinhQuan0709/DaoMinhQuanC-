#include<bits/stdc++.h>
using namespace std;
#define Max 6

struct ChuyenBay{
	string sohieu;
	float giave;
	int soghe;
};
struct List{
	int cnt = 0;
	ChuyenBay cb[Max];
};
void taocb(ChuyenBay &cb){
	cout<<"nhap so hieu : "; getline(cin,cb.sohieu);
	cout<<"nhap gia ve : "; cin>>cb.giave;
	cout<<"nhap so ghe : "; cin>>cb.soghe;
	cin.ignore();
}
void nhapds(List &L){
	ChuyenBay x;
	cout<<"NHAP CHUYEN BAY"<<endl;
	taocb(x);
	L.cb[L.cnt] = x;
	L.cnt++;
}
void inds(List L){
	cout<<setw(15)<<"SO HIEU";
	cout<<setw(15)<<"GIA VE";
	cout<<setw(15)<<"SO GHE"<<endl;
	for(int i = 0; i < L.cnt; i++){
		cout<<setw(15)<<L.cb[i].sohieu;
		cout<<setw(15)<<L.cb[i].giave;
		cout<<setw(15)<<L.cb[i].soghe<<endl;
	}
}
void lietkegiave(List L, int i){
	if(i >= L.cnt) return;
	if(L.cb[i].giave > 100){
		cout<<setw(15)<<L.cb[i].sohieu;
		cout<<setw(15)<<L.cb[i].giave;
		cout<<setw(15)<<L.cb[i].soghe<<endl;	
	}
	lietkegiave(L, i + 1);
}

ChuyenBay vethapnhat(ChuyenBay cb[], int left, int right){
	if(left == right) return cb[left];
	int mid = (left + right) / 2;
	ChuyenBay leftmin = vethapnhat(cb,left,mid);
	ChuyenBay rightmin = vethapnhat(cb,mid + 1, right);
	if(leftmin.giave < rightmin.giave) return leftmin;
	else{
		return rightmin;
	}
}
  
void lietKeToHop4ChuyenBay(ChuyenBay cb[], ChuyenBay chon[], int n, int index, int start) {
    if (index == 4) {  // dieu kien dung khi du 4 chuyen bay
        for (int j = 0; j < 4; j++) {
            cout << chon[j].sohieu << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i < n; i++) {
        chon[index] = cb[i];  // them chuyen bay vao tap hop
        lietKeToHop4ChuyenBay(cb, chon, n, index + 1, i + 1);  // de quy chon ptu tiep theo
    }
}

int main(){
	List L;
	ChuyenBay cb[Max];
	for(int i = 0; i < Max; i++){
		nhapds(L);
	}
	cout<<"Danh sach chuyen bay"<<endl;
	inds(L);
	cout<<"\nDanh sach cac chuyen bay gia ve tren 100"<<endl;
	cout<<setw(15)<<"SO HIEU";
	cout<<setw(15)<<"GIA VE";
	cout<<setw(15)<<"SO GHE"<<endl;
	lietkegiave(L,0);
	
//	cout<<"\nChuyen bay co ve thap nhat "<<endl;
//	ChuyenBay k = vethapnhat(L.cb,0,L.cnt-1); // goi thaut toan
//	cout<<setw(15)<<"SO HIEU";
//	cout<<setw(15)<<"GIA VE";
//	cout<<setw(15)<<"SO GHE"<<endl;
//		cout<<setw(15)<<k.sohieu;
//		cout<<setw(15)<<k.giave;
//		cout<<setw(15)<<k.soghe<<endl;

	cout << "\nCac to hop chon 4 chuyen bay: "<<endl;
    ChuyenBay chon[4];  // Mang luu tam thoi 4 chuyen bay dc chon
    lietKeToHop4ChuyenBay(L.cb, chon, L.cnt, 0, 0);
	return 0;
}
