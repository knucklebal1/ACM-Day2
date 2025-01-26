#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int maxN=2e5;
int n,m,a[maxN],b[maxN];
bool check(int mid){//mid为可凑成的牌套数
	int cnt=0;//cnt为需要手写的牌数
	for(int i=0;i<n;++i){
		if(a[i]+b[i]<mid) return false;
		if(a[i]<mid) cnt+=mid-a[i];
	}
	return cnt<=m;
}
signed main(){
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	int l=0,r=4e10,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
