#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int _;
ll n,p,l,t;
int main() {
    cin>>_;
    while(_--) {
        cin>>n>>p>>l>>t;
        ll tasks=(n-1)/7+1,done=0,days=0;
        if((tasks/2)*(l+2*t)>=p) {
            days=p/(l+2*t)+bool(p%(l+2*t));
            cout<<n-days<<endl;
            continue;
        }else{
            days=tasks/2;
            done=tasks/2*(l+2*t);
        }
        if(tasks&1) {
            if(done+(l+t)>=p) {
                days++;
                cout<<n-days<<endl;
                continue;
            }else{
                days++;
                done+=l+t;
            }
        }
        days+=(p-done)/l+bool((p-done)%l);
        cout<<n-days<<endl;
    }
    return 0;
}