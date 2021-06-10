#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isValid(int i,int j,vector<string>&grid,vector<vector<int>>&visit,int n,int m){
	if(i>=0 && j>=0 && i<n && j<m && grid[i][j]=='.' && visit[i][j]==0){
		return true;
	}
	return false;
}

void bfs(int i,int j,vector<string>&grid,vector<vector<int>>&visit,int n,int m){
	int x[4]={-1,0,0,1};
	int y[4]={0,-1,1,0};
	queue<pair<int,int>> q;
	q.push({i,j});
	visit[i][j]=1;
	while(!q.empty()){
		auto p=q.front();
		q.pop();
		for(int k=0;k<4;k++){
			int dx=p.first+x[k];
			int dy=p.second+y[k];
			if(isValid(dx,dy,grid,visit,n,m)){
				q.push({dx,dy});
				visit[dx][dy]=1;
			}
		}
	}
}
int32_t main(){
	int n,m;  cin>>n>>m;
	vector<string>grid(n);
	for(int i=0;i<n;i++){
		cin>>grid[i];
	}
	int ans=0;
	vector<vector<int>>visit(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]=='.'){
				if(isValid(i,j,grid,visit,n,m)){
					bfs(i,j,grid,visit,n,m);
					ans++;
				}
			}
		}
	}
	cout<<ans;
}