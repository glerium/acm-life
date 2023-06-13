#include <bits/stdc++.h>
using namespace std;
int main () {
    int T;
    int x[3], y[3];
    int base;
    bool flag = 0;
    cin>>T;
    for(int i=1; i<=T; i++)
    {
        cin>>x[0]>>x[1]>>x[2]>>y[0]>>y[1]>>y[2];
        base = y[0] - x[0] + y[1] - x[1] + y[2] - x[2];
        if(base % 2 == 0)
        {
            cout<<base / 2;
        }
        else{
            sort(y, y+3);
            flag = 0;
            for(int j = 0; j <= 2; j++)
            {
                //cout<<y[j]<<' ';
                if(y[j] % 2 == 1)
                {
                    cout<<(base + y[j]) / 2;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}