#include <cstdio>
#include <cstring>
#define endl '\n'
using namespace std;
int n;
double p[1<<8][1<<8], f[8][1<<8];
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    scanf("%d", &n);
    while(n != -1) {
        for(int i=0;i<(1<<n);i++) {
            for(int j=0;j<(1<<n);j++)
                scanf("%lf", &p[i][j]);
        }
        for(int i=0;i<(1<<n);i++) f[0][i] = 1;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<(1<<n);j++) {
                f[i][j] = 0;
                for(int k=0;k<(1<<n);k++) {
                    if((k & (1<<(i-1))) == (j & (1<<(i-1))))
                        continue;
                    int mask = ((1<<n)-1) ^ ((1<<i)-1);
                    if((k & mask) != (j & mask))
                        continue;
                    if(k == j) continue;
                    f[i][j] += f[i-1][k] * p[j][k];
                }
                f[i][j] *= f[i-1][j];
            }
        }
        int ans;
        double mx = 0;
        for(int i=0;i<(1<<n);i++) {
            if(f[n][i] > mx) {
                mx = f[n][i];
                ans = i;
            }
        }
        printf("%d\n", ans+1);
        scanf("%d", &n);
    }
    return 0;
}