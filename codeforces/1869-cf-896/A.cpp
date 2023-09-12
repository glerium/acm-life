#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int t,n,a[maxn];
int main() {
    cin>>t;
    while(t--){
        vector<pair<int,int>> ans;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n%2==0){
            cout<<2<<endl;
            cout<<"1 "<<n<<endl;
            cout<<"1 "<<n<<endl;
        }else{
            cout<<4<<endl;
            cout<<"1 "<<n-1<<endl;
            cout<<"1 "<<n-1<<endl;
            cout<<n-1<<" "<<n<<endl;
            cout<<n-1<<" "<<n<<endl;
        }
    }
}