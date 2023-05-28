#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n,k;
char s[maxn];
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k>>(s+1);
        int ct[30][2]={};
        for(int i=1;i<=n;i++) {
            if(islower(s[i])) ct[s[i]-'a'][0]++;
            else ct[s[i]-'A'][1]++;
        }
        int ans=0;
        for(int i=0;i<26;i++) {
            ans+=min(ct[i][0],ct[i][1]);
            ans+=min(k,int(abs(ct[i][0]-ct[i][1])/2));
            k-=min(k,int(abs(ct[i][0]-ct[i][1])/2));
        }
        cout<<ans<<endl;
    }
    return 0;
}