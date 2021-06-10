#include<bits/stdc++.h>
using namespace std;
#define int long long
#define  mod 1000000007

int32_t main(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<vector<int>>dp(m+2,vector<int>(n+2,0));
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
		    if(i>1)
			    dp[a[i]][i]=dp[a[i]-1][i-1]%mod+dp[a[i]][i-1]%mod+dp[a[i]+1][i-1]%mod;
			if(i==1)
			    dp[a[i]][i]=1;
			continue;
		}
		for(int j=1;j<=m;j++){
			if(i==1){
				dp[j][i]=1;
			}
			else{
				dp[j][i]=(dp[j-1][i-1]%mod+dp[j][i-1]%mod)%mod+dp[j+1][i-1]%mod;
			}
		}
	}
// 	for(int i=1;i<=n;i++){
// 	    for(int j=1;j<=m;j++){
// 	        cout<<dp[j][i]<<" ";
// 	    }
// 	    cout<<"\n";
// 	}
	int ans=0;
	for(int i=1;i<=m;i++){
		ans=(ans%mod+dp[i][n]%mod)%mod;		
	}
	cout<<ans;
}