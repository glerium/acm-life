#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
int t,n,a[maxn];
int main() {
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n-1;i++) cin >>a[i];
        cout<<a[1]<<" ";
        for(int i=1;i<=n-2;i++) cout<<min(a[i],a[i+1])<<' ';
        cout<<a[n-1]<<endl;
    }
}