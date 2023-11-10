#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int ct=0;
    for(auto i:s) ct+=bool(isprint(i)&&!isspace(i));
    cout<<ct<<endl;
    return 0;
}