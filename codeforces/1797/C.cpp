#include <iostream>
using namespace std;
int t,n,m;
inline int ask(int x, int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int ans; scanf("%d" ,&ans);
    return ans;
}
inline void answer(int x,int y){
    printf("! %d %d\n",x,y);
    fflush(stdout);
}
struct Point{
    int x,y;
};
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int pos1=ask(1,1),
            pos2=ask(n,m);
        if(n==1) {
            answer(1,1+pos1);
            continue;
        }
        if(m==1) {
            answer(1+pos1,1);
            continue;
        }
        Point a,b;
        // if()
        a = (Point){1+pos1,m-pos2};
        b = (Point){n-pos2,1+pos1};
        printf("%d %d %d %d\n",a.x,a.y,b.x,b.y);
        if(a.x>=1&&a.x<=n&&a.y>=1&&a.y<=m){
            int kkk=ask(a.x,a.y);
            if(kkk==0) answer(a.x,a.y);
            else answer(b.x,b.y);
        } else answer(b.x,b.y);
    }
    return 0;
}