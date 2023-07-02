#include <bits/stdc++.h>
using namespace std;
int t,m;
string s,l,r;
vector<int> dig[13];
int mx[13];
int main() {
    cin>>t;
    while(t--) {
        cin>>s>>m>>l>>r;
        for(int i=0;i<=9;i++) dig[i].clear();
        for(int i=0;i<s.size();i++) dig[s[i]-'0'].push_back(i);
        for(int i=0;i<10;i++) {
            mx[i]=-1;
            for(int j=0;j<dig[i].size();j++)
                mx[i]=max(mx[i],dig[i][j]);
        }
        int pos=-1;
        for(int i=0;i<m;i++) {
            // cout<<"pos="<<pos<<endl;
            int tmp=pos;
            for(int j=l[i]-'0';j<=r[i]-'0';j++) {
                // cout<<"mx["<<j<<"]="<<mx[j]<<endl;
                if(mx[j]<=pos) {
                    // cout<<":"<<mx[j]<<' '<<pos<<endl;
                    cout<<"YES"<<endl;
                    goto end;
                }else{
                    int ll=0,rr=dig[j].size()-1,mid,ans;
                    while(ll<=rr) {
                        mid=ll+rr>>1;
                        if(dig[j][mid]>pos) {
                            ans=mid;
                            rr=mid-1;
                        }else ll=mid+1;
                    }
                    tmp=max(tmp,dig[j][ans]);
                }
            }
            pos=tmp;
        }
        cout<<"NO"<<endl;
        end:;
    }
    return 0;
}