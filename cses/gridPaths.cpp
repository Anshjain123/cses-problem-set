#include<bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007

int32_t main(){
	int n; cin>>n;
	vector<vector<char>>grid(n+1,vector<char>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>grid[i][j];
		}
	}

	int dp[n+1][n+1];
	bool check=false;
	for(int j=n;j>=1;j--){
		if(grid[n][j]=='*'){
			check=true;
		}
		if(check==true){
			dp[n][j]=0;
		}
		else{
			dp[n][j]=1;
		}
	}

	check=false;
	for(int j=n;j>=1;j--){
		if(grid[j][n]=='*'){
			check=true;
		}
		if(check==true){
			dp[j][n]=0;
		}
		else{
			dp[j][n]=1;
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int j=n-1;j>=1;j--){
		    if(grid[i][j]=='*'){
		        dp[i][j]=0;
		        continue;
		    }
			dp[i][j]=(dp[i+1][j]+dp[i][j+1])%mod;
		}
	}
// 	for(int i=1;i<=n;i++){
// 	    for(int j=1;j<=n;j++){
// 	        cout<<dp[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	cout<<dp[1][1];
}