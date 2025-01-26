#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5;
int a[maxN];
int N,C;
long long result;
int main(){
	int l=1,r=1;
	cin>>N>>C;
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];//循环输入,将数据输入数组,a[0]不要从1开始方便算
	}
	sort(a+1,a+N+1);//排序,保证数据单调性，前包后不包
	for(int i=1;i<=N;i++){//循坏历遍A的取值，算出对应值a[i]-C,然后找数据中是否有这个值
		while(r<=N&&a[r]<=a[i]-C)r++;//右指针指向最后一个满足条件的数字的后一位；因为右指针移动条件是<=，左指针只有<，所以左指针移动条件受限，当序列出现重复数字时，左指针会滞后
		while(l<r&&a[l]<a[i]-C)l++;//左指针指向第一个满足条件的数字
		result+=r-l;//算出有多少个相同的对应值
	}
	cout<<result;
	return 0;
}
