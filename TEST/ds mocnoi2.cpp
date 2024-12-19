#include<bits/stdc++.h>
using namespace std;

struct Hocphan{
	string ma;
	string ten;
	int sotc;
};

struct Node{
	Hocphan infor;
	Node* next;
};

typedef Node* TRO;
TRO L;

TRO tao(string ma, string ten, int sotc){
	TRO newNode = new Node;
	newNode->infor.ma = ma;
	newNode->infor.ten = ten;
	newNode->infor.sotc = sotc;
	newNode->next = NULL;
	return newNode;
}

void chenvt3(TRO &L){
	int d = 1;
	TRO Q = L;
	while(Q != NULL && d < 2){
		Q = Q->next;
		d++;
	}
	TRO P = new Node;
	P->infor.ma = "132";
	P->infor.ten = "sinh";
	P->infor.sotc = 3;
	P->next = Q->next;
	Q->next = P;
}

void chentrcvt2(TRO &L){
	TRO Q = L;

	TRO M = new Node;
	M->infor.ma = "133";
	M->infor.ten = "hoa";
	M->infor.sotc = 3;
	M->next = Q->next;
	Q->next = M;
}

void chendau(TRO &L){
	TRO N = new Node;
	N->infor.ma = "131";
	N->infor.ten = "nhac";
	N->infor.sotc = 1;
	
	N->next = L;
	L = N;
}

void xoa1(TRO &L){
	if(L == NULL){
		cout<<"danh sach rong";
		return;
	}
	while(L != NULL && L->infor.ma == "123"){
		TRO N = L;
		L = L->next;
		delete N;
	}
	
	TRO Q  = L;
	while(Q != NULL && Q->next != NULL){
		if(Q->next->infor.ma == "123"){
			TRO N = Q->next;
			Q->next = Q->next->next;
			delete N;
		}
		Q = Q->next;
	}
}

void xoa2(TRO &L){
	TRO M = NULL;
	TRO N = L;
	TRO P = L->next;
	while(P != NULL){
		if(P->infor.ma == "123"){
			if(M == NULL){
				L = N->next;
				delete N;
			}
			else{
				M->next = N->next;
				delete N;
			}
			return;
		}
		M = N;
		N = P;
		P = P->next;
	}
} 

void xoa3(TRO &L){
	int max = L->infor.sotc;
	TRO Q = L;
	while(Q != NULL){
		if(Q->infor.sotc > max){
			max = Q->infor.sotc;
		}
		Q = Q->next;
	}
	TRO M = NULL;
	TRO N = L;
	while(N != NULL){
		if(N->infor.sotc == max){
			if(M == NULL){
				L = N->next;
			}
			else{
				M->next = N->next;
			}
			delete N;
			return;
		}
		M = N;
		N = N->next;
	}
}

void inds(TRO L){
	if(L == NULL){
		cout<<"danh sach rong";
		return;
	}
	TRO Q = L;
	while(Q != NULL){
		cout<<"Ma hoc phan : "<<Q->infor.ma<<" - "<<"Ten hoc phan : "<<Q->infor.ten<<" - "<<"So tin chi : "<<Q->infor.sotc<<endl;
		Q = Q->next;
	} 
}

int main(){
	TRO danhsach = NULL;
	
	TRO node1 = tao("111", "toan", 3);
	TRO node2 = tao("112", "van", 2);
	TRO node3 = tao("113", "anh", 2);
	TRO node4 = tao("122", "su", 1);
	TRO node5 = tao("123", "dia", 2);
	
	danhsach = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	
	cout<<"\nDanh sach hoc phan ban dau"<<endl;
	inds(danhsach);
	
	cout<<"\nDanh sach sau khi chen"<<endl;
	chenvt3(danhsach);
	inds(danhsach);
	
	cout<<"\nDanh sach sau chen 2"<<endl;
	chentrcvt2(danhsach);
	inds(danhsach);
	
	cout<<"\nDanh sach sau khi chen dau"<<endl;
	chendau(danhsach);
	inds(danhsach);
	
	cout<<"\nDanh sach sau khi xoa ptu co sotc lon nhat"<<endl;
	xoa3(danhsach);
	inds(danhsach);
	
	cout<<"\nDanh sach sau xoa ptu trc 123"<<endl;
	xoa2(danhsach);
	inds(danhsach);
	
//	cout<<"\nDanh sach sau khi xoa hp co ma 123. "<<endl;
//	xoa1(danhsach);
//	inds(danhsach);
	
	return 0;
}
