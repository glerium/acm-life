#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        int a[30]={};
        for(auto i:s) a[i-'A']++;
        int ans=0;
        for(int i=0;i<26;i++) ans+=a[i]>i;
        cout<<ans<<endl;
    }
}