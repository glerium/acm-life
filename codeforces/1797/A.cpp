#include <iostream>
#include <algorithm>
using namespace std;
int t,m,n,x1,y1,x2,y2;
int compute(int x,int y){
	if(x==1&&y==1 || x==1&&y==n || x==m&&y==1 || x==m&&y==n) return 2;
	else if(x==1 || y==1 || x==m || y==n) return 3;
	else return 4;
}
int main(){
	cin>>t;
	while(t--){
		cin>>m>>n;
		cin>>x1>>y1>>x2>>y2;
		int ans=min(compute(x1,y1), compute(x2,y2));
		cout<<ans<<endl;
	}
	return 0;
}