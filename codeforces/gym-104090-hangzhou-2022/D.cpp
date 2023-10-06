#include <iostream>
#include <iomanip>
using namespace std;

constexpr size_t MAXN = 1E5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    size_t n;
    cin >> n;
    double sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        double a;
        cin >> a;
        sum += a;
    }
    double ans = sum / (n + 1);
    cout << fixed << setprecision(8) << 2 * ans << ' ';
    for (size_t i = 2; i <= n; i++)
    {
        cout << fixed << setprecision(8) << ans << ' ';
    }
    return 0;
}