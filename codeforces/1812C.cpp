#include <bits/stdc++.h>
using namespace std;
const int n[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9, 5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7, 5, 1, 0, 5, 8};
int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int ans = 1;
        for(int j=0;j<n[i];j++){
            int k;
            cin >> k;
            ans *= k;
        }
        cout << ans << endl;
    }
    return 0;
}