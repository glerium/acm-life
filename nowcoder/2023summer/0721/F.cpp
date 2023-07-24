#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n,r,g,b;
    cin>>t;
    while(t--){
        cin>>n>>r>>g>>b;
        bool ans = (n==2);
        
        bool chg = (abs(r-g)+abs(g-b))%2;
        puts((ans^chg)?"Alice":"Bob");
    }
    return 0;
}