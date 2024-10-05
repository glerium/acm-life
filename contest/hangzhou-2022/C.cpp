#include <iostream>
#include <algorithm>
using namespace std;
#define size_t unsigned long long

constexpr size_t MAXN = 3005;
using ull = unsigned long long;
using ll = long long;

ll dp[MAXN][MAXN][2];
bool is_legal[MAXN][MAXN][2];

size_t p[MAXN];
ll w[MAXN][11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    size_t n, c;
    size_t total = 0, sum = 0;
    cin >> n >> c;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> p[i];
        for (size_t j = 1; j <= p[i]; j++)
        {
            cin >> w[i][j];
        }
        total += p[i];
        sum += w[i][p[i]];
    }
    if (total <= c)
    {
        cout << sum;
        return 0;
    }
    if (c == 0)
    {
        cout << "0";
        return 0;
    }
    size_t diff = total - c;
    is_legal[0][0][0] = true;
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 0; j <= c; j++)
        {
            if (is_legal[i - 1][j][0])
            {
                is_legal[i][j][0] = true;
                dp[i][j][0] = dp[i - 1][j][0];
            }
            if (is_legal[i - 1][j][1])
            {
                is_legal[i][j][1] = true;
                dp[i][j][1] = dp[i - 1][j][1];
            }
            if (j >= p[i])
            {
                if (is_legal[i - 1][j - p[i]][0])
                {
                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - p[i]][0] + w[i][p[i]]);
                    is_legal[i][j][0] = true;
                }
                if (is_legal[i - 1][j - p[i]][1])
                {
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - p[i]][1] + w[i][p[i]]);
                    is_legal[i][j][1] = true;
                }
            }
            for (size_t k = p[i]; k >= (ull) max(1ll, (long long) p[i] - (long long) diff); k--)
            {
                if (j >= k && is_legal[i - 1][j - k][0])
                {
                    is_legal[i][j][1] = true;
                    dp[i][j][1] = max(dp[i - 1][j - k][0] + w[i][k], dp[i][j][1]);
                }
            }
            // cout << "i = " << i << ", j = " << j << ", dp = " << dp[i][j][0] << ' ' << dp[i][j][1] << "\n";
        }
    }
    cout << dp[n][c][1];
    return 0;
}