#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e5+10;
int t,sum[maxn][2];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>s;
        int n=s.size();
        s = 'a' + s;
        sum[0][0]=sum[0][1]=0;
        rep(i,1,n) {
            sum[i][0]=sum[i-1][0];
            sum[i][1]=sum[i-1][1];
            sum[i][s[i]-'0']++;
        }
        for(int i=n;i>=0;i--) {
            if(sum[n][0]>=sum[i][1]&&sum[n][1]>=sum[i][0]) {
                cout<<n-i<<endl;
                break;
            }
        }
    }
    return 0;
}