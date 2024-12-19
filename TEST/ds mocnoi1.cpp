#include<bits/stdc++.h>
using namespace std;

struct Canbo{
	string ma;
	string hodem;
	string ten;
	string gt;
	double hesoLuong;
	long luong; 		// = hesoLuong * 1490000;
};

struct Node{
	Canbo infor;
	Node* next;
};

typedef Node* TRO;

TRO tao(string ma, string hodem, string ten, string gt, double hesoLuong){
	TRO newNode = new Node;
	newNode->infor.ma = ma;
	newNode->infor.hodem = hodem;
	newNode->infor.ten = ten;
	newNode->infor.gt = gt;
	newNode->infor.hesoLuong = hesoLuong;
	newNode->infor.luong = hesoLuong * 1490000;
	newNode->next = NULL;
	return newNode;
}

void them(TRO &L, TRO newNode){
	if(L == NULL){
		L = newNode; // danh sach rong , tao moi
	}
	else{
		TRO Q = L;
		while(Q != NULL){
			Q = Q->next;
		}
		Q->next = newNode;
	}
}

void inds(TRO L){
	if(L == NULL){
		cout<<"danh sach rong"<<endl;
		return;
	}
	TRO Q = L;
	while(Q != NULL){
		cout<<Q->infor.ma<<" - "<<Q->infor.hodem<<" "<<Q->infor.ten<<" - "<<Q->infor.gt<<" - "<<Q->infor.hesoLuong<<" - "<<Q->infor.luong<<" VND"<<endl;
		Q = Q->next;
	}
}

void canboNu(TRO L){
	if(L == NULL){
		cout<<"danh sach rong "<<endl;
		return ;
	}
	TRO Q = L;
	while(Q != NULL){
		if(Q->infor.gt == "Nu"){
			cout<<Q->infor.ma<<" - "<<Q->infor.hodem<<" "<<Q->infor.ten<<" - "<<Q->infor.gt<<" - "<<Q->infor.hesoLuong<<" - "<<Q->infor.luong<<" VND"<<endl;
		}
		Q = Q->next;
	}
}

void canboTung(TRO L){
	if(L == NULL){
		cout<<"danh sach rong"<<endl;
		return;
	}
	TRO Q = L;
	while(Q != NULL){
		if(Q->infor.ten == "Tung"){
			cout<<Q->infor.ma<<" - "<<Q->infor.hodem<<" "<<Q->infor.ten<<" - "<<Q->infor.gt<<" - "<<Q->infor.hesoLuong<<" - "<<Q->infor.luong<<" VND"<<endl;
		return;
		}
		Q = Q->next;
	}
}

void themsaupt3(TRO L){
		TRO Q = L;
		int dem = 1;
		
		while(Q != NULL && dem < 3){
			dem++;
			Q = Q->next;	
		}
		if(Q == NULL || dem < 3){
			cout<<"khong the chen ds co it hon 3 pt"<<endl;
			return;
		}
		TRO P = new Node;
		P->infor.ma = "CB00";
		P->infor.hodem = "Tran Van";
		P->infor.ten = "Tu";
		P->infor.gt = "Nam";
		P->infor.hesoLuong = 2.2;
		P->infor.luong = P->infor.hesoLuong * 14900000;
		P->next = Q->next;
		Q->next = P;
}

int main(){
	TRO danhsach = NULL;
	
	TRO node1 = tao("CB01", "Nguyen Van", "An", "Nam", 3.2);
	TRO node2 = tao("CB02", "Tran Thi", "Binh", "Nu", 2.8);
	TRO node3 = tao("CB03", "Le Van", "Tung", "Nam", 3.5);
	TRO node4 = tao("CB04", "Pham Thi", "Hoa", "Nu", 2.5);
	
	danhsach = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	
	cout<<"Danh sach ban dau "<<endl;
	inds(danhsach);
	
	cout<<"\nDanh sach can bo nu"<<endl;
	canboNu(danhsach);
	
	cout<<"\nThong tin can bo ten Tung"<<endl;
	canboTung(danhsach);
	
	cout<<"\nDanh sach sau khi chen"<<endl;
	themsaupt3(danhsach);
	inds(danhsach);
	return 0;
}
