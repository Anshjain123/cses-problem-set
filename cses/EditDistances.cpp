#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dp[5001][5001];

int solve(int i,int j,string s1,string s2){
// 	if(i==s1.size() && j==s2.size()){
// 		return 0;
// 	}
	if(i==s1.size() || j==s2.size()){
		int k=0;
	    return max(s1.size()-i,s2.size()-j);
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int ans;
    if(s1[i] == s2[j]){
        ans=solve(i+1,j+1,s1,s2);
    }
    else{
		ans=1+min(solve(i+1,j,s1,s2),min(solve(i+1,j+1,s1,s2),solve(i,j+1,s1,s2)));
	}
	return dp[i][j]=ans;
}


int32_t main(){
	memset(dp,-1,sizeof dp);
	string s1,s2;
	cin>>s1;
	cin>>s2;
	cout<<solve(0,0,s1,s2);
    

}