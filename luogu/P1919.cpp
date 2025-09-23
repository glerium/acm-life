#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
typedef complex<double> cpx;
constexpr int maxt = 1 << 21;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
cpx A[maxt], B[maxt], T[maxt];
void fft(cpx A[], cpx B[], int n, int inv) {
    const double pi = acos(-1); 
    if(n == 1) return;
    int half = n >> 1;
    for(int i = 0; i < half; i++) {
        B[i] = A[i * 2];
        B[i + half] = A[i * 2 + 1];
    }
    rep(i, 0, n-1) {
        A[i] = B[i];
    }
    fft(A, B, half, inv);
    fft(A + half, B + half, half, inv);

    cpx omega[n];
    const cpx omega_n(cos(2 * pi / n), inv * sin(2 * pi / n));
    omega[0] = {1, 0};
    rep(i,1,n-1) omega[i] = omega[i-1] * omega_n;
    rep(i,0,half-1) {
        B[i] = A[i] + omega[i] * A[i + half];
        B[i + half] = A[i] - omega[i] * A[i + half];
    }
    rep(i,0,n-1)
        A[i] = B[i];
}
void solve() {
    string a,b; cin >> a >> b;
    int n = a.size() - 1, m = b.size() - 1;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    rep(i,0,n) {
        A[i].real(a[i] - '0');
    }
    rep(i,0,m) {
        B[i].real(b[i] - '0');
    }
    fft(A, T, maxt, 1);
    fft(B, T, maxt, 1);
    rep(i,0,maxt-1) {
        A[i] *= B[i];
    }
    fft(A, T, maxt, -1);

    vector<ll> ans(n+m+10);
    int last = 0;
    rep(i,0,n+m+3) {
        // cout << A[i].real() / maxt << endl;
        ans[i] += round(A[i].real() / maxt);
        ans[i+1] += ans[i] / 10;
        ans[i] %= 10;
        if(ans[i]) last = i;
    }
    string out;
    rep(i,0,last) out += ans[i] + '0';
    reverse(out.begin(), out.end());
    cout << out << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}