#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    if(n==m&&a[n-1]==b[m-2])cout<<"YES";
    else cout<<"NO\n";
}