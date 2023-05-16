#include <bits/stdc++.h>
using namespace std;
int t;
string pwd;
int main() {
    cin>>t;
    getchar();
    while(t--){
        getline(cin,pwd);
        if(pwd.length()<6) cout<<"Your password is tai duan le."<<endl;
        else {
            bool alp=false, dig=false, good=true;
            for(auto i : pwd) {
                if(isdigit(i)) dig=true;
                else if(isalpha(i)) alp=true;
                else if(i=='.') continue;
                else {
                    good=false;
                    break;
                }
            }
            if(!good) cout<<"Your password is tai luan le."<<endl;
            else if(!dig) cout<<"Your password needs shu zi."<<endl;
            else if(!alp) cout<<"Your password needs zi mu."<<endl;
            else cout<<"Your password is wan mei."<<endl;
        }
    }
    return 0;
}
