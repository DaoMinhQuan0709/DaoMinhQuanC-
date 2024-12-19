#include<bits/stdc++.h>
using namespace std;

// ctruc sinh vien
struct Sinhvien{
  string masv;
  string ho;
  string ten;
  string namsinh;
  double diem;
};

// ctruc node 
struct Node{
  Sinhvien infor;
  Node *next;
};

typedef Node* TRO;

TRO tao(string masv, string ho, string ten, string namsinh, double diem){
	TRO newNode = new Node;
	newNode->infor.masv = masv;
	newNode->infor.ho = ho;
	newNode->infor.ten = ten;
	newNode->infor.namsinh = namsinh;
	newNode->infor.diem = diem;
	newNode->next = NULL;
	return newNode;
}

void xoaptdautien(TRO &L ){
    if(L == NULL){
        cout<<"danh sach rong "<<endl;
        return;
    }
    TRO Q = L;
    L = L->next;
    delete Q;
}

void chenthu3(TRO &L){
    int d = 1;
    TRO Q = L;
    while(Q != NULL && d < 3){
        Q = Q->next;
        d++;
    }
    if(Q == NULL || d < 3){
        cout<<"khong the chen vao danh sach co it hon 3 pt"<<endl;
        return;
    }
    TRO P = new Node;
    P->infor.masv =  "1006";
    P->infor.ho =  "Le Thi";
    P->infor.ten = "Doan";
    P->infor.namsinh = "2001";
    P->infor.diem = 6.9;
    P->next = Q->next;
    Q->next = P;
}

void sapxep(TRO &L){
	Sinhvien tg;
	TRO M, Q, R;
	
	R = L; // Con tro bat dau
	while(R != NULL){
		M = R;			// M giu node nho nhat hien tai
		Q = R->next;	// Duyet tu node tiep theo
		while(Q != NULL){
			if(Q->infor.ten < M->infor.ten){
				M = Q;		// Cap nhat M khi thay node nho hon
			}
			Q = Q->next;
		}
		tg = R->infor;
		R->infor = M->infor;
		M->infor = tg;
		
		R = R->next;
	}
}

void inds(TRO L){
    if(L == NULL){
        cout<<"danh sach rong "<<endl;
        return;
    }
    TRO Q = L;
    while(Q != NULL){
        cout<<Q->infor.masv<<" - "<<Q->infor.ho<<" "<<Q->infor.ten
			<<" - "<<Q->infor.namsinh<<" - "<<Q->infor.diem<<endl;
        Q = Q->next;
    }
}

int main(){
    TRO danhsach = NULL;
    // tao danh sach ban dau
    TRO node1 = tao("1001", "Tran Van", "Thanh", "1998", 8.3);
    TRO node2 = tao("1002", "Nguyen Thi", "Huong", "1999", 7.5);
    TRO node3 = tao("1003", "Nguyen Van", "Binh", "2000", 7.3);
    TRO node4 = tao("1004", "Bui Thi", "Hong", "1998", 6.4);
    TRO node5 = tao("1005", "Duong Van", "Giang", "2000", 5.8);
    
    danhsach = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
	// hien thi danh sach ban dau
    cout<<"Danh sach sinh vien"<<endl;
    inds(danhsach);
    
    cout<<"\nChen sinh vien vao vi tri thu 3"<<endl;
    chenthu3(danhsach);
    inds(danhsach);
    
    cout<<"\nXoa pt dau tien "<<endl;
    xoaptdautien(danhsach);
    inds(danhsach);
    
    cout<<"\nDanh sach sinh vien sau sap xep"<<endl;
    sapxep(danhsach);
    inds(danhsach);
    return 0;
}
