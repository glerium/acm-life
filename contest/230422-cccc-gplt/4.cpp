#include <iostream>
#include <string>
#include <vector>
using namespace std;
int t,a,b,c;
int main(){
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        if(c==a*b) cout<<"Lv Yan"<<endl;
        else if(c==a+b) cout<<"Tu Dou"<<endl;
        else cout<<"zhe du shi sha ya!"<<endl;
    }
    return 0;
}
