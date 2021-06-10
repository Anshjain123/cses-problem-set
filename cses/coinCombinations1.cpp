#include<bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007 

int32_t main(){
	int n,x; cin>>n>>x;
	int c[n];
	vector<int>dp(x+1,0);
	dp[0]=1;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}

	for(int i=1;i<=x;i++){
		for(int a:c){
			if(i-a<0){
				continue;
			}
			else{
				dp[i]= dp[i]%mod+dp[i-a]%mod;
			}
		}
	}
	cout<<dp[x];
}