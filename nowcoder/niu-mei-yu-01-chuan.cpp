#include <bits/stdc++.h>
using namespace std;
char s[100007];
int main() {
    cin>>(s+1);
    bool one=false,zero=false;
    int n=strlen(s+1);
    int ct=0;
    for(int i=1;i<=n;i++) {
        if(s[i]=='0') zero=true;
        else one=true;
        if(one&&zero) {
            ct++;
            one=zero=false;
        }
    }
    cout<<ct<<endl;
    
}