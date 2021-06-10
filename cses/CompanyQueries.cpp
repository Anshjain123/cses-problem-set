#include<bits/stdc++.h>
#define int long long 
using namespace std;


void binaryLifting(int u,int e,vector<vector<int>>&parent,vector<vector<int>>&adj,int n){
	parent[u][0]=e;
	for(int i=1;i<=n;i++){
		parent[u][i]=parent[parent[u][i-1]][i-1];
		//cout<<parent[u][i]<<"\n";
	}
	for(auto a:adj[u]){
		if(a==e) continue;

		binaryLifting(a,u,parent,adj,n);
	}
}
int32_t main(){
	int n,q;
	cin>>n>>q;
	vector<int>e(n+1,0);
	for(int i=2;i<=n;i++){
		cin>>e[i];
	}
	vector<vector<int>>adj(n+1);
	for(int i=2;i<=n;i++){
		adj[e[i]].push_back(i);
		adj[i].push_back(e[i]);
	}
// 	for(int i=1;i<=n;i++){
// 	    for(int a:adj[i]){
// 	        cout<<a<<" "; 
// 	    }
// 	    cout<<"\n";
// 	}
    int x=(int)ceil(log2(n));
	vector<vector<int>>parent(n+1,vector<int>(x+1,0));
	binaryLifting(1,0,parent,adj,x);
	for(int i=0;i<q;i++){
		int a,k;
		cin>>a>>k;
		for(int i=0;i<=x;i++){
		    if((k>>i)&1){
		        a=parent[a][i];
		    }
		    
		}
		int x=(a==0)?-1:a;
		cout<<x<<"\n";
	}
    // for(int i=0;i<=x;i++){
    //     cout<<parent[7][i]<<" ";
    // }
}