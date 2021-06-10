#include<bits/stdc++.h>
using namespace std;
#define int long long

void binaryLifting(int u,int e,vector<vector<int>>&adj,vector<int>&lvl,vector<vector<int>>&parent,int x){
	parent[u][0]=e;
	for(int i=1;i<=x;i++){
		parent[u][i]=parent[parent[u][i-1]][i-1];
	}

	for(int a:adj[u]){
		if(a==e) continue;
        lvl[a]=lvl[u]+1;
		binaryLifting(a,u,adj,lvl,parent,x);
	}
}


int lca(int a,int b,vector<int> &lvl,vector<vector<int>>&parent,int x){
	if(lvl[a]<lvl[b]){
		swap(a,b);
	}
	int k=lvl[a]-lvl[b];
    //cout<<k<<"\n";
	for(int i=x;i>=0;i--){
		if((k>>i)&1){
			a=parent[a][i];
			//cout<<a<<" ";
		}
	}
	if(a==b){
	    return a;
	}
    int ans=1;
	for(int i=x;i>=0;i--){
		int x=parent[a][i];
		int y=parent[b][i];
		if(x!=y){
			a=parent[a][i];
			b=parent[b][i];
		}
	}
	return parent[a][0];
}


int32_t main(){
	int n,q;
	cin>>n>>q;
	vector<vector<int>>adj(n+1);
	for(int i=2;i<=n;i++){
		int a;
		cin>>a;
		adj[a].push_back(i);
		adj[i].push_back(a);
	}
	int x=(int)ceil(log2(n));
	vector<vector<int>>parent(n+1,vector<int>(x+1,-1));

	vector<int>lvl(n+1,0);

	binaryLifting(1,1,adj,lvl,parent,x);
// 	for(int i=1;i<=n;i++){
// 	    cout<<lvl[i]<<" ";
// 	}
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;

		cout<<lca(a,b,lvl,parent,x)<<"\n";
	}
}