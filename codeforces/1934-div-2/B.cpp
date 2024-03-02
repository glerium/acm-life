#include <iostream>
using namespace std;
const int coins[5] = {1, 3, 6, 10, 15};
int f[533];
int main() {
    f[0]=0;
    for(int i=1;i<=500;i++) {
        f[i]=0x3f3f3f3f;
        for(auto j:coins) {
            if(i-j<0) continue;
            f[i]=min(f[i], f[i-j]+1);
        }
    }
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        if(n<=500) cout<<f[n]<<endl;
        else {
            int ct = (n-500)/15+1;
            if(n-15*ct<0) ct--;
            cout << ct + f[n-15*ct] << endl;
        }
    }
    return 0;
}