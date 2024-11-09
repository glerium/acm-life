#include <bits/stdc++.h>
using namespace std;
int main() {
    int m; cin >> m;
    int c2=0, c5=0;
    bool in = false;
    vector<int> ans;
    for(int i=1;;i++) {
        int ii = i;
        while(ii%2==0) {
            ii/=2;
            c2++;
        }
        while(ii%5==0) {
            ii/=5;
            c5++;
        }
        if(!in) {
            if((c2 == m || c5 == m) && (c2 >= m && c5 >= m)) {
                in = true;
                ans.push_back(i);
            }
            if(c2 > m && c5 > m)
                break;
        }else{
            if(c2 != m && c5 != m) {
                break;
            }
            else
                ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << ' ';
}