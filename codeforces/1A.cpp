#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,a;
    cin>>n>>m>>a;
    cout<<1ll*(n/a+bool(n%a))*(m/a+bool(m%a))<<endl;
}