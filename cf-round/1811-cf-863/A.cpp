#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 +10;
int t, n, d;
char a[maxn];
int main() {
    cin >> t;
    while(t--) {
        cin >> n >> d >> a;
        bool inserted = false;
        for(int i=0;i<n;i++) {
            if(!inserted && a[i]<d+'0'){
                putchar(d+'0');
                inserted = true;
            } 
            putchar(a[i]);
        }
        if(!inserted) putchar(d+'0');
        putchar('\n');
    }
    return 0;
}