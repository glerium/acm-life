#include <bits/stdc++.h>
using namespace std;
int t;
string s;
bool check(int l,int r,const string& s) {
    l--,r--;
    for(int i=l,j=r;i<=j;i++,j--){
        if(s[i]!=s[j]) return false;
    }
    return true;
}
int main(){
    cin>>t;
    while(t--){
        cin>>s;
        int ans=-1;
        for(int i=1;i<=s.size();i++){
            for(int j=i;j<=s.size();j++) {
                if(!check(i,j,s)) {
                    ans=max(ans,j-i+1);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}