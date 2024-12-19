#include<bits/stdc++.h>
using namespace std;

struct Congviec{
	string ma;
	string tgbatdau;
	double tgthuchien;
};
struct Nhanvien{
	string ten;
};
struct List{
	int cnt = 0;
	Congviec cv[3];
};

void inds(List L){
	cout<<setw(30)<<"Ma cong viec";
	cout<<setw(30)<<"Thoi gian bat dau";
	cout<<setw(30)<<"Thoi gian can thiet"<<endl;
	for(int i = 0; i < L.cnt; i++){
		cout<<setw(30)<<L.cv[i].ma;
		cout<<setw(30)<<L.cv[i].tgbatdau;
		cout<<setw(30)<<L.cv[i].tgthuchien<<"h"<<endl;
	}
}

void hienthi(List &L, int i){
	if(i < 0) return;
	cout<<setw(30)<<L.cv[i].ma;
	cout<<setw(30)<<L.cv[i].tgbatdau;
	cout<<setw(30)<<L.cv[i].tgthuchien<<"h"<<endl;
	hienthi(L, i - 1);
	return;
}

int cv30p(Congviec cv[], int left, int right){
	if(left == right){
		if(cv[left].tgthuchien <= 0.5){
			return 1;
		}
		else{
			return 0;
		}
	}
	int mid = (left + right) / 2;
	int countLeft = cv30p(cv, left, mid);
	int countRight  = cv30p(cv,mid + 1, right);
	
	return countLeft + countRight;
}

void lietke(Congviec cv[], Nhanvien nv[], int k, int phancong[], bool used[]){
	if(k == 3){
		for(int i = 0; i < 3; i++){
			cout<<cv[phancong[i]].ma<<" - "<<nv[i].ten<<endl;
		}
		cout<<endl;
		return;
	}
	
	for(int i = 0; i < 3; i++){
		if(used[i] == false){
			phancong[k] = i;
			used[i] = true;
			
			lietke(cv,nv,k + 1,phancong,used);
			
			used[i] = false;
		}
	}
}

int main(){
	List L;
	Congviec cv[] = {
		{"001","7.30",4},		
		{"002","13.45",0.5},
		{"003","9.00",1}
	};
	
	Nhanvien nv[] = {
		{"Nhanvien A"}, 
		{"Nhanvien B"}, 
		{"Nhanvien C"}
	};
	
	L.cnt = 3;
	for(int i = 0; i < L.cnt; i++){
		L.cv[i] = cv[i];
	}
	
	cout<<"ds ban dau"<<endl;
	inds(L);
	
	cout<<"\nds nguoc"<<endl;
	hienthi(L, L.cnt - 1);
	
	cout<<cv30p(cv,0, L.cnt - 1);
	
	int phancong[3];
	bool used[3] = {false};
	lietke(cv,nv,0,phancong,used);
	
	return 0;
}
