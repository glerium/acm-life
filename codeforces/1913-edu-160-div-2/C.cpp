#include <bits/stdc++.h>
using namespace std;
int m,cnt[30];
int main() {
    ios::sync_with_stdio(false);
    cin>>m;
    while(m--) {
        int op,x; cin>>op>>x;
        if(op==1) cnt[x]++;
        else {
            for(int i=29;i>=0;i--) {
                int mk=min(cnt[i],x/(1<<i));
                x-=mk*(1<<i);
            }
            cout<<(!x?"YES":"NO")<<endl;
        }
    }
    return 0;
}