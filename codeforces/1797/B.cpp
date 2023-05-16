#include <iostream>
using namespace std;
const int maxn=1e3+10;
int t,n,k,a[maxn][maxn];
int main(){
    // freopen("out.csv","w",stdout);
    cin>>t;
    int ttt=1;
    while(t--){
        cin>>n>>k;
        // if(ttt++==21) cout << "HERE!!!" << endl;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
        int ct=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ct+=(a[i][j]!=a[n+1-i][n+1-j]);
        ct>>=1;
        // cout<<"dbg:"<<ct<<' '<<k<<endl;
        if(n==0) cout<<(k==0?"YES":"NO")<<endl;
        else {
            if(n&1) cout<<(k>=ct?"YES":"NO")<<endl;
            else cout<<(k>=ct && (k-ct)%2==0 ? "YES" :"NO")<<endl;
        }
    }
    return 0;
}