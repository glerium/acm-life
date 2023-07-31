#include <bits/stdc++.h>
using namespace std;
int q,k,c,n;
set<int> fact;
void get_fact(int c) {
    int end=sqrt(c);
    for(int i=1;i<=end;i++) {
        if(c%i==0) {
            fact.insert(i);
            fact.insert(c/i);
        }
    }
}
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
int main() {
    cin>>q;
    while(q--) {
        cin>>k>>c>>n;
        fact.clear();
        get_fact(c);
        int ans=0;
        for(auto b : fact) {
            if((c-b)%k!=0) continue;
            if(c==b) continue;
            int a = (c-b)/k;
            // cout<<a<<' '<<b<<endl;
            if(gcd(a,b)>=n) ans++;
        }
        cout<<ans<<endl;
    }
}