#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int calc(int x) {
    int ans=0;
    while(x) {
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        while(calc(n)%k) n++;
        cout<<n<<endl;
    }
    return 0;
}