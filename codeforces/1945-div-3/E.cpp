#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
int t, n, x, a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin >> n >> x;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        vector<array<int,2>> ans;
        int l = 1, r = n+1;
        while(l < r) {
            if(r - l == 1)
                break;
            int mid = (r + l) / 2;
            if(a[mid] == x) {
                ans.push_back({mid, 1});
                swap(a[mid], a[1]);
            }
            if(a[mid] <= x) {
                l = mid;
            }else{
                r = mid;
            }
        }
        if(a[l] != x) {
            int tmp = 0;
            for(int i=1;i<=n;i++) {
                if(a[i] == x) {
                    tmp = i;
                    break;
                }
            }
            ans.push_back({l, tmp});
        }
        cout << ans.size() << endl;
        for(auto [x,y] : ans) {
            cout << x << ' ' << y << endl;
        }
    }
}