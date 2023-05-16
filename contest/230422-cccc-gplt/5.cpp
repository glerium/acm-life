#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,a[107],k;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>k;
    while(k--){
        bool guessed=false, wrong=false;
        int tmp;
        for(int i=1;i<=n;i++) {
            cin>>tmp;
            if(tmp) {
                guessed=true;
                if(tmp!=a[i]) wrong=true;
            }
        }
        if(!guessed || wrong) cout<<"Ai Ya"<<endl;
        else cout<<"Da Jiang!!!"<<endl;
    }
    return 0;
}
