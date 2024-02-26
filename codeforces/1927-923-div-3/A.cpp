#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        int mi=100,mx=-1;
        for(int i=0;i<n;i++) {
            if(s[i]=='B') {
                mi=min(mi,i);
                mx=max(mx,i);
            }
        }
        cout<<mx-mi+1<<endl;
    }
}