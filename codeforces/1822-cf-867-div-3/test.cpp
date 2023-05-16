#include <iostream>
using namespace std;
long long ans;
int main(){
    ans=26;
    for(int i=5;i<=179179179;i++) ans+=i*2+1;
    cout<<ans;
}