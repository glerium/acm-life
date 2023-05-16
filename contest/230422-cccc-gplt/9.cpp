#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
deque<int> a,b;
size_t cnt,len;
int main(){
    cin>>n;
    while(n--) {
        int nw; cin>>nw;
        if(a.empty()||a.back()>nw)
            a.push_back(nw);
        else if(b.empty()||b.back()>nw)
            b.push_back(nw);
        else {
            cnt++;
            len=max(len,a.size());
            while(!a.empty()) a.pop_back();
            //cout<<endl;
            while(b.front()>nw) {
                a.push_back(b.front());
                b.pop_front();
            }
            a.push_back(nw);
        }
    }
    /*
    if(!a.empty()) {
        while(!a.empty()) {
            cout<<a.back()<<' ', a.pop_back();
        }
        cout<<endl;
        cnt++;
        len=max(len,a.size());
    }*/
    if(!b.empty()) {
        while(!b.empty()) {
            b.pop_back();
        }
        //cout<<endl;
        cnt++;
        len=max(len,b.size());
    }
    cout<<cnt<<' '<<len<<endl;
    return 0;
}
