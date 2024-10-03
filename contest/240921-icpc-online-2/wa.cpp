#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0;
    cin>>ans;
    for(int i=-2147483648;i<=2147483647;i++)
        ans^=i;
    cout<<ans;
    return 0;
}