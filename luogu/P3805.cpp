#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2.2e7+10;
char s[maxn];
struct Manacher {
    int N, lc[maxn];
    char t[maxn];
    void init(char * s) {
        int n = strlen(s+1);
        t[0] = '^';
        t[n*2+1] = '#';
        t[n*2+2] = '\0';
        for(int i=1;i<=n;i++) {
            t[i*2] = s[i];
            t[i*2-1] = '#';
        }
        N = 2 * n + 1;
    }
    void manacher() {
        lc[1] = 1;
        int k = 1;
        for(int i=2;i<=N;i++) {
            int p = k + lc[k] - 1;          // 当前中心点所覆盖的最右侧位点
            if(i <= p) {                    // i位于当前最右回文串内
                lc[i] = min(lc[2*k-i], p-i+1);
            } else {                        // i超出回文串范围，准备重新计算
                lc[i] = 1;
            }
            while(t[i+lc[i]] == t[i-lc[i]]) lc[i]++;
            if(i+lc[i] > k+lc[k])           // 若找到更优回文串，则更新k
                k = i;
        }
    }
    void debug() {
        puts(t+1);
        for(int i=1;i<=N;i++)
            printf("lc[%d]=%d\n",i,lc[i]);
    }
} manacher;
int main() {
    cin >> (s+1);
    manacher.init(s);
    manacher.manacher();
    manacher.debug();
    int ans = 0;
    for(int i=1;i<=manacher.N;i++)
        ans = max(ans, manacher.lc[i] - 1);
    cout << ans << endl;
}