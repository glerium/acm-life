#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mx=-1,mx2=-1,ans=0,minn=114514;
    void mk(int maxx,int minn) {
        mx2=mx;
        mx=maxx;
        if(mx!=-1&&mx2!=-1) ans+=min(mx,mx2)-minn;
    }
    int trap(vector<int>& h) {
        for(int i=0;i<h.size();i++) {
            if(i==0) minn=min(h[i],minn);
            else if(h[i]>=h[i-1]&&h[i]>=h[i+1]) 
                mk(h[i], minn);
        }
        return ans;
    }
};