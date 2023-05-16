#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ten_x[100],ct_4[100],ct[100],sct[100];     //ct_4[i]: 10^i ~ 10^(i-1)中含有4的个数
int t;
ll k;
int main() {
    ten_x[0]=1;
    for(int i=1;i<=18;i++) ten_x[i] = 10 * ten_x[i-1];
    ct_4[0]=1;
    for(int i=1;i<=18;i++){
        ll s=0;
        for(int j=0;j<i;j++) s+=ct_4[j];
        ct_4[i] = s*8+ten_x[i];
    }
    for(int i=0;i<18;i++) ct[i] = ten_x[i+1]-ten_x[i]-ct_4[i];
    ct[0]=9;
    sct[0]=ct[0];
    for(int i=0;i<18;i++) sct[i]=sct[i-1]+ct[i];
    cin>>t;
    while(t--){
        cin>>k;
        k++;
        ll ans = 0;
        for(int i=17;i>=0;i--){
            if(k<=sct[i]) continue;
            int j=0;
            for(;j<=3;j++) {
                if(k<sct[i]) break;
                k -= sct[i];
                printf("minus: %lld\n",sct[i]);
                ans += ten_x[i+1];
                printf("add: %lld\n",ten_x[i+1]);
            }
            if(k>=ten_x[i+1]){
                k-= ten_x[i+1];
                printf("minus: %lld\n",ten_x[i+1]);
                ans += ten_x[i+1];
            }
            for(j=4;j<=99;j++) {
                if(k<sct[i]) break;
                k -= sct[i];
                ans+=ten_x[i+1];
            }
        }
        if(k<=3) ans+=k;
        else ans+=k+1;
        cout << ans << endl;
    }
}