#include<bits/stdc++.h>
using namespace std;

int n, a[100], used[100];

void in(){
    for(int i = 1 ; i<= n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void nhiphan(int i){
    for(int j = 0; j <= 1; j++){
        a[i] = j;
        if(i == n){
            in();
        }
        else{
            nhiphan(i + 1);
        }
    }
}

void Try(int i){
    for(int j = 1; j <= n; j++){
        // xem set xem gan dc kh?
        if(used[j] == 0){
            a[i] = j;
            used[j] = 1; //danh dau
            if(i == n){
                in();
            }
            else{
                Try(i + 1);
            }
            // backtrack
            used[j] = 0;
        }
        
    }
}

int main(){
    cin>> n;
    Try(1);
    return 0;
}
