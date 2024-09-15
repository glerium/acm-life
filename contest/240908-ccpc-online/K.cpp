#include <bits/stdc++.h>
using namespace std;
long long lowbit(long long n)
{
    return n&(-n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        if(k>=n)
        {
            cout<<"Alice\n";
        }
        else if(lowbit(n)<=k)
        {
            cout<<"Alice\n";
        }
        else
        {
            cout<<"Bob\n";
        }
    }
}