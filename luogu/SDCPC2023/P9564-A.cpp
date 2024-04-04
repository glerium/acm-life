#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    bool red[] = {0, 1, 0, 0, 1, 0, 0};
    for(int i=1;i<=6;i++) {
        for(int j=1;j<=6;j++) {
            for(int k=1;k<=6;k++) {
                int redcnt = red[i] * i + red[j] * j + red[k] * k;
                int blackcnt = !red[i] * i + !red[j] * j + !red[k] * k;
                if(a == redcnt && b == blackcnt) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}