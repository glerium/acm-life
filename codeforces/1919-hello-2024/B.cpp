#include <iostream>
#include <string>
using namespace std;
int t,n;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>s;
        int ct=0;
        for(auto i:s) ct+=i=='+';
        cout<<abs(ct*2-n)<<endl;
    }
}