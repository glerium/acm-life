#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n;
bitset<maxn> ans;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>s;
        int beg=0, ct1=0, ct2=0;
        for(int l=0,r=n-1;l<r;l++,r--) {
            if(s[l]==s[r]) ct2++;
            else beg++;
        }
        if(n&1) ct1++;
        ans.reset();
        for(int i=0;i<=ct2;i++) {
            for(int j=0;j<=ct1;j++) {
                ans[beg+i*2+j]=true;
            }
        }
        for(int i=0;i<=n;i++) putchar(ans[i]?'1':'0');
        putchar('\n');
    }
    return 0;
}