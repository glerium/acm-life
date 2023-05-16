#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main() {
    cin>>a>>b;
    long long ans=0;
    while(a!=b) {
        if(a>b) {
            if(a%b==0) {
                ans+=(a-b)/b;
                break;
            }
            ans+=a/b;
            a%=b;
        }else{
            if(b%a==0) {
                ans+=(b-a)/a;
                break;
            }
            ans+=b/a;
            b%=a;
        }
    }
    cout<<ans<<endl;
    return 0;
}