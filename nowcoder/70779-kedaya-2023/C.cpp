#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,m; cin>>n>>m;
    long long mx=1ll<<(n-1);
    puts(mx>=m?"Yes":"No");
}