#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
void solve()
{
    vector<int> a(32);
    for(int i=0;i<32;i++)cin>>a[i];
    int gz=a[0];
    sort(a.begin(),a.end());
    if(gz<=a[1])
    {
        cout<<32<<'\n';
        return;
    }
    if(gz<=a[5])
    {
        cout<<16<<'\n';
        return;
    }
    if(gz<=a[12])
    {
        cout<<8<<'\n';
        return;
    }
    if(gz<=a[26])
    {
        cout<<4<<'\n';
        return;
    }
    if(gz>=a[31])
    {
        cout<<1<<'\n';
        return;
    }
    cout<<2<<'\n';
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;while(t--)solve();
    return 0;
}