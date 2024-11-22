#include <bits/stdc++.h>
#define endl '\n'

#define rep(i, o, p) for(int i = o ; i <= p; i ++)
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int cnt=0;
    s+='0';
    vector<int> v;
    for(auto it:s)
    {
        if(it=='1')cnt++;
        else
        {
            if(cnt)v.push_back(cnt);
            cnt=0;
        }
    }
    double ans=0;
    for(auto it:v)
    {
        if(it%2==1)
        {
            ans+=(it+1)/2;
        }
        else
        {
            ans+=sqrt(2);
            it-=3;
            if(it>0)ans+=(it+1)/2;
        }
    }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}
