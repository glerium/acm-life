#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    map<string,int> mp;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        mp[s]++;
    }
    for(auto it:mp)
    {
        if(2*it.second>n)
        {
            cout<<it.first;
            return 0;
        }
    }
    cout<<"uh-oh";
}