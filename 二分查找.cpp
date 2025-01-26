#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int> &a,int target){
	int l=0,r=a.size()-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]==target){
			return true;
		}else if(a[mid]<target){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return false;
}

int main(){
	int n,q,x;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	cin>>q;
	for(int i=0;i<q;++i){
		cin>>x;
		if(search(a,x)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
