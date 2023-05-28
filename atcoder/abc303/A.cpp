#include <bits/stdc++.h>
using namespace std;
bool check(char x,char y) {
    return x=='1'&&y=='l'||x=='0'&&y=='o'||x==y;
}
int main() {
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    bool yes=true;
    for(int i=0;i<n;i++) {
        if(!check(a[i],b[i])&&!check(b[i],a[i])){
            yes=false;
            break;
        }
    }
    cout<<(yes?"Yes":"No")<<endl;
    return 0;
}