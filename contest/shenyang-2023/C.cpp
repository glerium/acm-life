/*
 * Filename: i:\code\cpp\contest\shenyang-2023\C.cpp
 * Path: i:\code\cpp\contest\shenyang-2023
 * Created Date: Saturday, October 5th 2024, 1:09:31 pm
 * Author: 温泽林
 * 
 * Copyright (c) 2024  
 */

#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    int ans = 0;
    while(a < 3) {
        if(a == 2 || b == 2) {
            ans += 2;
            a++;
        } else {
            ans += 1;
            a++;
        }
    }
    cout << ans << endl;
    return 0;
}