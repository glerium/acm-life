#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,b[maxn];
bitset<maxn*2> isp;
void init(){
    isp.set();
    isp[1]=false;
    for(int i=1;i<=2e5;i++) {
        if(isp[i]) {
            for(int j=i+i;j<=2e5;j+=i)
                isp[j]=false;
        }
    }
}
bool check(int x, int y) {
    return isp[x+y] || isp[int(abs(x-y))];
}
int main() {
    init();
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        if(n==1) cout<<-1<<endl;
        else{
            for(int i=1;i<=n;i++) {
                if(i==1) {
                    b[i]=1;
                    continue;
                }
                if(check(i,b[i-1]))
                    b[i]=i;
                else{
                    if(i%2==1) {
                        if(check(b[2],i)&&check(b[1],b[i-1])) {
                            b[i]=b[1];
                            b[1]=i;
                        }else{
                            for(int j=3;j<i;j+=2) {
                                if(check(b[j-1],i)&&check(b[j+1],i)&&check(b[i-1],b[j])){
                                    b[i]=b[j];
                                    b[j]=i;
                                    break;
                                }
                            }
                        }
                    }else{
                        for(int j=2;j<i;j+=2) {
                            if(check(b[j-1],i)&&check(b[j+1],i)&&check(b[i-1],b[j])){
                                b[i]=b[j];
                                b[j]=i;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) cout<<b[i]<<' ';
        cout<<endl;
        // bool yes=true;
        // for(int i=1;i<n;i++){
        //     if(!check(b[i],b[i+1])) {
        //         yes=false;
        //         break;
        //     }
        // }
        // cout<<yes<<endl;
    }
    return 0;
}