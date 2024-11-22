#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5+10;
constexpr int inf = maxn;
int n,a[maxn],f1[maxn],f2[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tmp;
    while(cin >> tmp)
        a[++n] = tmp;
    for(int i=1;i<=n;i++)
        f1[i] = f2[i] = 0;
    f1[0] = inf;
    for(int i=1;i<=n;i++) {
        int l = 0, r = i-1, mid, ans;
        while(l <= r) {
            mid = (l + r) >> 1;
            if(f1[mid] >= a[i]) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        f1[ans + 1] = a[i];
    }
    for(int i=n;i>=1;i--) {
        if(f1[i] != 0) {
            cout << i << endl;
            break;
        }
    }
    f2[0] = 0;
    for(int i=1;i<=n;i++)
        f2[i] = inf;
    for(int i=1;i<=n;i++) {
        int l = 0, r = i-1, mid, ans;
        while(l <= r) {
            mid = (l + r) >> 1;
            if(f2[mid] < a[i]) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        f2[ans + 1] = a[i];
    }
    for(int i=n;i>=1;i--) {
        if(f2[i] != inf) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}