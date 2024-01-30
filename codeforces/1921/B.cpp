#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
int _,n;
string a,b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>_;
    while(_--) {
        cin>>n>>a>>b;
        int ca=0,cb=0;
        rep(i,0,n) {
            if(a[i]==b[i]) continue;
            else if(a[i]=='1') ca++;
            else cb++;
        }
        cout<<min(ca,cb)+abs(ca-cb)<<endl;
    }
    return 0;
}