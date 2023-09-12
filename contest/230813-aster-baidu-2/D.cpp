#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-5;
ll p,q,n1,n2,n3;
ll ax,ay;
bool isint(double x) {
    return abs(x-round(x)) < eps;
}
bool getans(int mi,int ma) {
    bool ok=false;
    if(n2!=n1) {
        for(ll z=mi;z<=ma;z++) {
            double x = ((n3-n2)*z+n2*p-q)/(n2-n1),
                y = (q-n1*p+(n1-n3)*z)/(n2-n1);
            // cout<<x<<' '<<y<<' '<<z<<endl;
            if(isint(x)&&isint(y)&&x>=0&&x<=p&&y>=0&&y<=p){
                ok=true;
                ax = min(ax,z);
                ay = max(ay,z);
            }
        }
    }else{
        for(ll z=mi;z<=ma;z++) {
            if(n1*(p-z)==q-n3*z) {
                ok=true;
                ax = min(ax,z);
                ay = max(ay,z);
            }
        }
    }
    return ok;
}
int main() {
    cin>>p>>q>>n1>>n2>>n3;
    if(n3==n2) {
        if(n3==n1){
            if(n1*p==q) cout<<0<<' '<<p<<endl;
            else cout<<-1<<endl;
        }else{
            double yz = 1.0*(q-n1*p)/(n2-n1);
            if(isint(yz)&&yz>=0&&yz<=p) cout<<0<<' '<<int(yz)<<endl;
            else cout<<-1<<endl;
        }
    }else{
        ll ma = min(floor((q-n1*p)/(n3-n1)),1.0*p);
        ll mi = max(ceil((q-n2*p)/(n3-n2)),0.0);
        if(ma < 0) cout<<-1<<endl;
        else if(ma<mi) cout<<-1<<endl;
        else {
            bool ok = getans(mi,ma);
            if(ok) cout<<ax<<' '<<ay<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}