#include<bits/stdc++.h>
using namespace std;
#define int long long

//int ans=0;
void bfs(int i,vector<vector<int>>& graph,vector<int>&visit){
	queue<int>q;
	q.push(i);
	visit[i]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int a:graph[x]){
			if(visit[a]==0){
				q.push(a);
				visit[a]=1;
			}
		}
	}
}

int32_t main(){
	int n,m; cin>>n>>m;
	vector<vector<int>>graph(n+1);
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int>p;
	int ans=0;
	vector<int> visit(n+1,0);
	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			p.push_back(i);
			bfs(i,graph,visit);
			ans++;
		}
	}
	cout<<ans-1<<"\n";
	for(int i=0;i<p.size()-1;i++){
		cout<<p[i]<<" "<<p[i+1]<<"\n";
	}
}