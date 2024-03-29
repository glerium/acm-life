#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=107;
int n, a[maxn];

int main() {
    cin >> n;
    while(n) {
        for(int i=1;i<=n;i++) cin >> a[i];
        int pos[maxn] = {};
        for(int i=1;i<=n;i++) {
            int ans;
            for(int j=1;j<=2000;j++) {
                if(j < a[i]) continue;
                bool ok = true;
                for(int k=1;k<i;k++) {
                    if(pos[k] > j - 2 * a[i] && pos[k] + 2 * a[k] > j) {
                        ok = false;
                        break;
                    }
                }
                if(!ok) continue;
                ans = j;
                break;
            }
            pos[i] = ans;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++) {
            bool found=false;
            for(int j=pos[i]-a[i]; j<=pos[i]+a[i]; j++) {
                bool ok=true;
                for(int k=1;k<=n;k++) {
                    if(k==i) continue;
                    if(pos[k]-a[k] <= j && j <= pos[k]+a[k]) {
                        ok=false;
                        break;
                    }
                }
                found |= ok;
            }
            if(found)   
                ans.push_back(i);
        }
        for(auto i : ans) cout << i << ' ';
        cout << endl;
        cin >> n;
    }
    return 0;
}