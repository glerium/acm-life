#include <iostream>
#include <string>
#include <vector>
using namespace std;
int t,a,b;
int getsum(int x){
    int s=0;
    while(x) s+=x%10,x/=10;
    return s;
}
int main(){
    cin>>t;
    while(t--){
        cin>>a>>b;
        int aa=getsum(a), bb=getsum(b);
        bool aaa=(a%bb==0), bbb=(b%aa==0);
        if(aaa^bbb) cout<<(aaa?'A':'B')<<endl;
        else cout<<(a>b?'A':'B')<<endl;
    }
    return 0;
}
