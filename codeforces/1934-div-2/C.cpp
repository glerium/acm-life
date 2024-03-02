// query：四个角
// method: 解析方法求出四个点的坐标，然后m^2分别枚举点对，判断是否满足要求

#include <iostream>
#include <array>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef array<int,2> point;

int query(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ans; 
    scanf("%d", &ans);
    return ans;
}
void answer(int x, int y) {
    printf("! %d %d\n", x, y);
    fflush(stdout);
}

void solve() {
    int n,m; scanf("%d%d", &n, &m);
    int d = query(1,1);
    int lx=max(1,2+d-m);
    
}
int main() {
    int t; cin>>t;
    while(t--) solve();
    return 0;
}