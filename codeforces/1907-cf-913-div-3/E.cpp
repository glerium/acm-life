#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int t,a[12];
long long n;
int main() {
    ios::sync_with_stdio(false);
    for(int i=0;i<=9;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=9;k++) {
                if(i+j+k>=10) continue;
                a[i+j+k]++;
            }
        }
    }
    cin>>t;
    while(t--) {
        cin>>n;
        long long ans=1;
        while(n) {
            ans*=a[n%10];
            n/=10;
        }
        cout<<ans<<endl;
    }
    return 0;
}