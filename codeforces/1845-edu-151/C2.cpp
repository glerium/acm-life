#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t,m,nxt[12];
string s,l,r;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>s>>m>>l>>r;
        for(int i=0;i<=9;i++) {
            nxt[i]=-1;
            for(int j=0;j<s.size();j++) {
                if(s[j]==i+'0') {
                    nxt[i]=j;
                    break;
                }
            }
        }
        for(int i=0;i<m;i++) {
            int mx=-1,sel=-1;
            for(int j=l[i]-'0';j<=r[i]-'0';j++) {
                if(nxt[j]==-1) {
                    cout<<"YES"<<endl;
                    goto end;
                }
                if(nxt[j]>mx) {
                    mx=nxt[j];
                    sel=j;
                }
            }
            // cout<<":"<<sel<<' '<<mx<<endl;
            for(int i=0;i<=9;i++) nxt[i]=-1;
            for(int k=0;k<=9;k++) {
                for(int j=mx+1;j<s.size();j++){
                    if(s[j]==k+'0'){
                        nxt[k]=j;
                        break;
                    }
                }
            }
        }
        cout<<"NO"<<endl;
    end:;
    }
    return 0;
}