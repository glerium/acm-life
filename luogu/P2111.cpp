#include <bits/stdc++.h>
using namespace std;
int n,a,q;
string s;
double p;
double f[10007];
int main() {
    cin >> n >> a >> q >> s;
    p = a*0.01;
    s = ' ' + s;
    f[0] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=i;j>=0;j--) {
            if(s[i] == '1') {
                f[j] = f[j] * (1-p) + f[j-1] * p;
            }else{
                f[j] = f[j] * p + f[j-1] * (1-p);
            }
        }
    }
    double ans = 0;
    for(int i=q;i<=n;i++)
        ans += f[i];
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}