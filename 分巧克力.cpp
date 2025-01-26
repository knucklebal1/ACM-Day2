#include<iostream>
using namespace std;
const int maxN=1e5+5;
struct Node{//一个node代表一个大巧克力
	int x,y;
}arr[maxN];//数组arr存放多个大巧克力
int N,K;
bool check(int mid){//mid是小巧克力块的最长可取边长
	int cnt=0;
	for(int i=0;i<N;i++)
		cnt+=(arr[i].x/mid)*(arr[i].y/mid);//cnt代表总共能分出多少小巧克力
	if(cnt>=K)	return true;//cnt>=K，分出的小巧克力数大等于预期
	else	return false;
}
int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++)	cin>>arr[i].x>>arr[i].y;
	int l=0,r=maxN;
	while(r-l>1){ //只有当r>l+1才有中间值mid ，确保mid为整型
		int mid=(l+r)>>1;//>> 右移操作，>>n相当于/2^n，所以>>1相当于/2
		if(check(mid))	l=mid;
		else	r=mid;//由于maxN>N，所以实际上先执行这个语句，把右指针往回缩
	}
	cout<<l;
	return 0;
}
