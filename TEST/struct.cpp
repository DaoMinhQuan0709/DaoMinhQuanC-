#include<bits/stdc++.h>
using namespace std;

struct SinhVien{
    string msv;
    string ten;
    double gpa;
    
    bool operator < (const SinhVien other){
    	return gpa < other.gpa;
	}
};

int main(){
    int n; cin>>n;
    SinhVien ds[n];
    for(int i = 0; i< n; i++){
    	cin>>ds[i].msv; cin.ignore();
    	getline(cin, ds[i].ten);
    	cin>>ds[i].gpa;
	}
	sort(ds, ds + n);
	for(SinhVien s : ds){
		cout<<s.msv<<" "<<s.ten<<" "<<s.gpa<<endl;
	}
    return 0;
}
