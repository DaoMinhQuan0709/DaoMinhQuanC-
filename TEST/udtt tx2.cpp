#include<bits/stdc++.h>
using namespace std;
#define Max 3

struct Quat{
  string hang;
  string mau;
  double gia;
};

struct List{
  int cnt = 0;
  Quat q[Max];
};

void tao(Quat &q){
    cout<<"nhap hang : "; getline(cin,q.hang);
    cout<<"nhap mau : "; getline(cin, q.mau);
    cout<<"nhap gia : "; cin>>q.gia;
    cin.ignore();
}

void nhapds(List &L){
    Quat x;
    cout<<"NHAP QUAT "<<endl;
    tao(x);
    L.q[L.cnt] = x;
    L.cnt++;
}

void inds(List L){
    cout<<setw(15)<<"Hang";
    cout<<setw(15)<<"Mau";
    cout<<setw(15)<<"Gia";
    cout<<endl;
    for(int i = 0; i < L.cnt; i++){
        cout<<setw(15)<<L.q[i].hang;
        cout<<setw(15)<<L.q[i].mau;
        cout<<setw(15)<<L.q[i].gia<<endl;
    }
}

void sapxep(List &L){
	for(int i = 0; i < L.cnt - 1; i++){
		for(int j = L.cnt - 1; j > i; j--){
			if(L.q[j].gia < L.q[j - 1].gia){
				swap(L.q[j], L.q[j - 1]);
			}
		}
	}	
}

void greedy(List &L, int p){
	sapxep(L);
	List kq;
	int dem = 0;
	int conlai = p;
	for(int i = 0; i < L.cnt; i++){
		if(conlai < L.q[i].gia){
			break;
		}
		conlai -= L.q[i].gia;
		kq.q[kq.cnt] = L.q[i];
		kq.cnt++;
		
	}
	cout<<"Danh sach mua dc "<<endl;
	inds(kq);
	cout<<"So luong quat mua dc "<<kq.cnt<<endl;
}

int main(){
    int p = 11;
	List L;
    for(int i = 0; i < Max; i++){
        nhapds(L);
    }
    inds(L);
    greedy(L, p);
  
    return 0;
}
