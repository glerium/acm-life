#include <bits/stdc++.h>
#define int long long
using namespace std;
int l,k;
string n;
bool prime(int x){
    if(x<2) return false;
    if(x==2) return true;
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) return false;
    }
    return true;
}
signed main() {
    cin>>l>>k>>n;
    bool found=false;
    l=n.size();
    for(int i=0; i<l&&i+k-1<l; i++) {
        int ima = 0;
        string imas;
        for(int j=0;j<k;j++){
            ima = ima*10 + n[j+i] -'0';
            imas += n[j+i];
        }
        if(prime(ima)){
            cout<<imas<<endl;
            found=true;
            break;
        }
    }
    if(!found) cout<<404<<endl;
}
