#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin>>n;
    int ct=0;
    while(n%2==0) {
        n/=2;
        ct++;
    }
    cout<<ct<<endl;
    return 0;
}