#include<bits/stdc++.h>
#include<string>

//class
//thuoc tinh : attribute
//phuong thuc : method
//object : doi tuong
//constructor : ham khoi tao 
//destructor : ham huy
//This pointer 
//setter getter
//static

using namespace std;

class sinhvien
{
    private:
        string id, ten, tuoi;
        double gpa;
        static int dem; 
    public:
        sinhvien(); //constructor
        sinhvien(string, string, string, double); //constructor
        void xinchao();
        void dihoc()
        {
            cout<<"di hoc"<<endl;
        };
        ~sinhvien(); //ham huy
        double getGpa();
		void nhap();
        void xuat();
        void tangDem();
        int getDem();
};

int sinhvien::dem = 0; //implemetation

void sinhvien::tangDem()
{
	dem++;
}

sinhvien::sinhvien()
{
    id = ten = tuoi = "";
    gpa = 0; 
}

sinhvien::sinhvien(string ma, string name, string age, double diem)
{
    id = ma;
    ten = name;
    tuoi = age;
    gpa = diem;
}

sinhvien::~sinhvien()
{

}

void sinhvien::xinchao()
{
	cout<<"xin chao"<<endl;
}

void sinhvien::nhap()
{
	dem++;
	this->id = "SV" + string(3-to_string(dem).length(), '0') + to_string(dem);
    cout<<"nhap ten : "; getline(cin, ten);
    cout<<"nhap tuoi : "; cin>>tuoi;
    cout<<"nhap gpa : "; cin>>gpa;
    cin.ignore();
}

void sinhvien::xuat()
{
    cout<<id<<" "<<ten<<" "<<tuoi<<" "<<fixed<<setprecision(2)<<gpa<<endl;
}

double sinhvien::getGpa()
{
	return gpa;
}

int sinhvien::getDem()
{
	return dem;
}

bool cmp(sinhvien a, sinhvien b)
{
	return a.getGpa() > b.getGpa();
}

int main()
{
    sinhvien x;
    x.nhap();
    x.xuat();
    return 0;
}
