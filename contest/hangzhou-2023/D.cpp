/*
 * Filename: i:\code\cpp\codeforces\gym-104976-hangzhou-2023\D.cpp
 * Path: i:\code\cpp\codeforces\gym-104976-hangzhou-2023
 * Created Date: Thursday, October 3rd 2024, 2:23:16 pm
 * Author: Glerium
 * 
 * Copyright (c) 2024  
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a[n*2+5] = {};
    if(n == 3) {
        cout << "1 -10 6 6 -10 1" << endl;
        return;
    }
    if(n % 2 == 0) {
        a[1] = 1;
        for(int i=2; i+1<=n; i+=2) {
            a[i] = -1;
            a[i+1] = 2;
        }
        a[n] = n - 3;
        for(int i=n+1;i<=2*n;i++) {
            a[i] = a[2*n+1-i];
        }
    } else {
        a[1] = 1;
        for(int i=2;i<=n-1;i+=2) {
            a[i] = -1;
            a[i+1] = 2;
        }
        for(int i=n+1;i+1<=2*n;i+=2) {
            a[i] = 2;
            a[i+1] = -1;
        }
        a[2*n] = 1;
        a[n] = 2*n-5;
    }
    auto calc = [&]() {
        int s = 0, m = a[1] * a[2*n];
        for(int i=1;i<=2*n;i+=2)
            s += a[i] * a[i+1];
        for(int i=2;i+1<=2*n-1;i+=2)
            m *= a[i] + a[i+1];
        cout << s << ' ' << m << endl;
    };
    // calc();
    for(int i=1;i<=2*n;i++)
        cout << a[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}