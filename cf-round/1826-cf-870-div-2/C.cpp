#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int t,n,m;
bitset<maxn> ispri;
int pri[maxn],ct;
void init(){
    ispri.set();
    ispri[1]=false;
    for(int i=1;i<=1e6;i++) {
        if(ispri[i]) {
            pri[++ct]=i;
            for(int j=i*2;j<=1e6;j+=i) 
                ispri[j]=false;
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n==1) cout<<"YES"<<endl;
        else if(n<=m) cout<<"NO"<<endl;
        else {
            if(n%2==0&&m>=2) cout<<"NO"<<endl;
            else {
                bool yes=false;
                for(int i=3;i*i<=n&&i<=m;i+=2) if(n%i==0) {
                    cout<<"NO"<<endl;
                    yes=true;
                    break;
                }
                if(!yes) cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}