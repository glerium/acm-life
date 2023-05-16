#include <bits/stdc++.h>
using namespace std;
bool ans[] = {0,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,0,1,1,1,1,0,
                0,1,1,1,1};
int main() {
    int a;
    cin>>a;
    cout<<(ans[a]?"Yes":"No")<<endl;
    return 0;
}