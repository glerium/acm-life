#include <bits/stdc++.h>
using namespace std;
int t,n;
int s;
map<int,string> mp;
int main(){
    ios::sync_with_stdio(false);
    for(char i='z';i>='a';i--) {
        for(char j='z';j>='a';j--) {
            for(char k='z';k>='a';k--) {
                int got=i+j+k-'a'*3+3;
                string ss = {i,j,k};
                mp[got]=ss;
            }
        }
    }
    cin>>t;
    while(t--) {
        cin>>s;
        cout<<mp[s]<<endl;
    }
}