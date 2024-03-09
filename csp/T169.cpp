#include <bits/stdc++.h>
using namespace std;
struct Matrix {
    int n, m;
    vector<vector<int>> v;
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        v.resize(n + 1);
        for(int i=1;i<=n;i++) {
            v[i] = vector<int>();
            v[i].resize(m + 1);
        }
    }
    void read() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++)
                cin>>v[i][j];
        }
    }
    void write() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++)
                cout<<v[i][j]<<' ';
            cout<<endl;
        }
    }
};
Matrix matmul(const Matrix& lhs, const Matrix& rhs) {
    assert(lhs.m == rhs.n);
    Matrix ret;
    ret.init(lhs.n, rhs.m);
    for(int i=1; i<=lhs.n; i++) {
        for(int j=1; j<=rhs.m; j++) {
            for(int k=1; k<=lhs.m; k++)
                ret.v[i][j] += lhs.v[i][k] * rhs.v[k][j];
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    int n, d; cin>>n>>d;
    Matrix q, k, kt, v, w;
    q.init(n, d); q.read();
    k.init(n, d); k.read();
    v.init(n, d); v.read();
    w.init(1, n); w.read();
    kt.init(d, n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=d;j++)
            kt.v[j][i] = k.v[i][j];
    }
    auto tmp = matmul(q, kt);   // n*n
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            tmp.v[i][j] *= w.v[1][i];
    }
    auto ret = matmul(tmp, v);
    ret.write();
    return 0;
}