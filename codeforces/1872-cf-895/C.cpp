#include <bits/stdc++.h>
using namespace std;
int t,l,r;
int get_factor(int x) {
    if(x<=2) return -1;
    int mx=sqrt(x);
    for(int i=2;i<=mx;i++) {
        if(x%i==0)
            return i;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>l>>r;
        if(l==1&&r==2||l==1&&r==3||l==2&&r==3) {
            puts("-1");
            continue;
        }
        if(r-l>=1) {
            int tot = (r&1)?r-1:r;
            printf("%d %d\n",tot/2, tot/2);
        }else{
            int fact = get_factor(l);
            if(fact==-1) puts("-1");
            else printf("%d %d\n", fact, l-fact);
        }
    }
    return 0;
}