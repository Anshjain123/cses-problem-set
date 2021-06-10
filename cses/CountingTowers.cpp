#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007


int32_t main(){
	int dp[10000001][2];
	dp[1000001][0] = dp[1000001][1] = 1;

	// 1 -> there was block of width 2 on prev position.
	// 0 -> there were 2 block of width 1 each on prev position. 
	for(int i=1000000;i>=2;i--){
		int op1 = dp[i+1][0] ; //extend both possible only when current has is dp[i][0]. exten both when current block has 2 of width 1.
		int op2 = (dp[i+1][0] + dp[i+1][1]) % mod;//extend none means i am making new blocks on i+1 th position and this can happen both when there were two single blocks or 1 single bloc of width two.
										  //can happen for both 0 and 1 as blocks end here at i and new blocks are formed in  i+1 th.
		
		int op3 = (2 * dp[i+1][0]) % mod; // only happens when ith position has two blocks of width 1.
		int op4 = dp[i+1][1] ; //extend both when current is a single block of width 2.

		dp[i][0] = (op1 + op2 + op3) % mod;
		dp[i][1] = (op2 + op4) % mod;
	}	
	int t; cin>>t;
	for(int i=0;i<t;i++){
		int n; cin>>n;
		cout<<(dp[1000000-n+2][1] % mod + dp[1000000-n+2][0] % mod) % mod<<"\n";
	}
}