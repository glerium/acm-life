#include <bits/stdc++.h>
using namespace std;
double n;
int main() {
    cin >> n;
    while(n > -0.5) {
        int ct = 0;
        for(int i = 0; i <= 11; i++) {
            for(int j = 0; j <= 59; j++) {
                for(int k = 0; k <= 59; k++) {
                    double ang1 = i * 30.0 + j * 30.0/60 + k * 30.0/60/60,
                           ang2 = j * 6.0 + k * 6.0/60,
                           ang3 = k * 6.0;
                    vector<double> v{ang1, ang2, ang3, ang1+360, ang2+360, ang3+360};
                    sort(v.begin(), v.end());
                    bool flag = true;
                    for(int i=0;i<v.size()-1;i++) {
                        if(n-(v[i+1]-v[i]) > 1e-6) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                        ct++;
                }
            }
        }
        cout << fixed << setprecision(3) << ct * 1.0 / (12*60*60) * 100 << endl;
        cin >> n;
    }
}