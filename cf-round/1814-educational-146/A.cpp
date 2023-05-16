#include <bits/stdc++.h>
using namespace std;
int t;
long long n,k;
int main() {
    cin>>t;
    while(t--){
        cin>>n>>k;
        if((n-k)%2==0 || n%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}