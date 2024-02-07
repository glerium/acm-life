#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e6+10;
int t,b,r,s1[maxn],s2[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>b>>r;
        if(r%2!=0||b%2==0) {
            cout<<"No"<<endl;
            continue;
        }
        set<int> b0,r0;
        b0.insert(1);
        int ct=1;
        b--;
        s1[1]=s2[1]=-1;
        while(b||r) {
            if(r&&!b0.empty()) {
                auto sel=b0.begin();
                int csel = *sel;
                b0.erase(sel);
                s1[csel]=++ct; r0.insert(ct); s1[ct]=s2[ct]=-1;
                s2[csel]=++ct; r0.insert(ct); s1[ct]=s2[ct]=-1;
                r-=2;
            }else if(b&&!r0.empty()) {
                auto sel=r0.begin();
                int csel = *sel;
                r0.erase(sel);
                s1[ct]=s2[ct]=-1;
                s1[csel]=++ct; b0.insert(ct); s1[ct]=s2[ct]=-1;
                s2[csel]=++ct; b0.insert(ct); s1[ct]=s2[ct]=-1;
                b-=2;
            }else{
                cout<<"No"<<endl;
                goto end;
            }
        }
        cout<<"Yes"<<endl;
        for(int i=1;i<=ct;i++) cout<<s1[i]<<' '<<s2[i]<<endl;
end:    ;
    }
}