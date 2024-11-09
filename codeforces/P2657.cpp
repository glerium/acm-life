#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[20][10];
void dp() {
    for(int i=0;i<=9;i++)
        f[1][i] = 1;
    for(int i=2;i<=15;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=9;k++) {
                if(abs(j-k) < 2)
                    continue;
                f[i][j] += f[i-1][k];
            }
        }
    }
}
ll getf(int x) {
    int a[20] = {};
    int len = 0;
    while(x) {
        a[++len] = x % 10;
        x /= 10;
    }
    ll ret = 0;
    // < len
    for(int i=1;i<len;i++) {
        for(int j=1;j<=9;j++) {
            ret += f[i][j];
        }
    }
    // == len && i < a[len]
    for(int i=1;i<a[len];i++)
        ret += f[len][i];
    // == len && abc???
    for(int i=len-1;i>=1;i--) {
        for(int j=0;j<a[i];j++) {
            if(abs(a[i+1] - j) < 2)
                continue;
            ret += f[i][j];
        }
        if(abs(a[i+1] - a[i]) < 2)
            break;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    dp();
    cout << getf(b+1) - getf(a) << endl;
    return 0;
}