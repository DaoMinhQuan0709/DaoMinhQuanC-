#include<bits/stdc++.h>
using namespace std;
#define Max 5

struct Chuyenbay{
	string ma;
	double giave;
	int soghe;
};

struct List{
	int cnt = 0;
	Chuyenbay b[Max];
};

void inds(List L){
	for(int i = 0; i < L.cnt; i++){
		cout<<setw(15)<<L.b[i].ma;
		cout<<setw(15)<<L.b[i].giave;
		cout<<setw(15)<<L.b[i].soghe<<endl;
	}
}

void tim(List &L, int i){
	if(i >= Max) return;
	if(L.b[i].giave > 700){
		cout<<setw(15)<<L.b[i].ma;
		cout<<setw(15)<<L.b[i].giave;
		cout<<setw(15)<<L.b[i].soghe<<endl;
		}
		
	tim(L, i + 1);
}

Chuyenbay cbthapnhat(List &L, int left, int right){

	if(left == right){
		return L.b[left];
	}
	int mid = (left + right) / 2;
	Chuyenbay leftmin = cbthapnhat(L,left,mid);
	Chuyenbay rightmin = cbthapnhat(L,mid + 1,right);
	
	return (leftmin.giave < rightmin.giave) ? leftmin : rightmin;
}

void lietke(Chuyenbay b[], Chuyenbay chon[], int n, int index, int start){
	if(index == 4){
		for(int j = 0; j < 4; j++){
			cout<<chon[j].ma<<" -  "<<chon[j].soghe<<", ";
		}
		cout<<endl;
		return;
	}
	for (int i = start; i < n; i++) {
        chon[index] = b[i];  // them chuyen bay vao tap hop
        lietke(b, chon, n, index + 1, i + 1);  // de quy chon ptu tiep theo
    }
}

int main(){
	List L;
	Chuyenbay b[] = {
		{"VN01",300,60},
		{"VN02",750,30},
		{"VN03",800,12},
		{"VN04", 500, 45},
    	{"VN05", 400, 50}	
	};
	
	L.cnt = 5;
	for(int i = 0; i < L.cnt; i++){
		L.b[i] = b[i];
	}
	cout<<"ds chuyen bay ban dau"<<endl;
	inds(L);
	
	cout<<"\nds chuyen bay co gia ve hon 700"<<endl;
	tim(L,0);
	
	cout<<"\nchuyen bay co gia ve thap nhat"<<endl;
	Chuyenbay k = cbthapnhat(L,0,L.cnt - 1);
	cout<<setw(15)<<k.ma;
	cout<<setw(15)<<k.giave;		
	cout<<setw(15)<<k.soghe<<endl;
	
	cout<<"\nLiet ke"<<endl;
	Chuyenbay chon[4];
	lietke(b, chon, L.cnt, 0, 0);
	
	return 0;
}
