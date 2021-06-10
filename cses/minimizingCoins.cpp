#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n,x; cin>>n>>x;
	int c[n];
	vector<int>dp(x+1,1000001);
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]<=x)
			dp[c[i]]=1;
	}

	for(int i=1;i<=x;i++){
		for(int a:c){
			if(i-a<0){
				continue;
			}
			else{
				dp[i]=min(dp[i],1+dp[i-a]);
			}
		}
	}
	if(dp[x]!=1000001){
		cout<<dp[x];
	}
	else{
		cout<<"-1";
	}
	
}