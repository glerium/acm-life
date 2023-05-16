#include <iostream>
using namespace std;
int main(){
    freopen("in.txt","w",stdout);
    cout<<1<<endl;
    int n=2e5;
    cout<<n<<' '<<3<<endl;
    for(int i=1;i<=n;i++) cout<<i%10;
    cout<<endl;
    return 0;
}