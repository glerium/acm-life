#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int x,y;
        cin>>x>>y;
        puts(((x+y)%2==0)?"Bob":"Alice");
    }
    return 0;
}