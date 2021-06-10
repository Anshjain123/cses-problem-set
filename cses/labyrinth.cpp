#include<bits/stdc++.h>
using namespace std;
#define int long long
struct triple{
	int a;
	int b;
	string s;
	triple(int a,int b,string c){
		this->a=a;
		this->b=b;
		this->s=c;
	}
};
bool isValid(int i,int j,vector<string>&grid,vector<vector<int>>&visit,int n,int m){
	if(i>=0 && j>=0 && i<n && j<m && (grid[i][j]=='.' || grid[i][j]=='B') && visit[i][j]==0){
		return true;
	}
	return false;
}
void bfs(int i,int j,vector<string>&grid,vector<vector<int>>&visit,int n,int m){
	int x[4]={-1,0,0,1};
	int y[4]={0,-1,1,0};
	string s[4]={"U","L","R","D"};
	queue<triple> q;
	q.push(triple(i,j,""));
	visit[i][j]=1;
	string ans="";
	bool check=false;
	while(!q.empty()){
		auto p=q.front();
		q.pop();
		//cout<<p.a<<" "<<p.b<<" "<<p.s<<endl;
		if(grid[p.a][p.b]=='B'){
			ans+=p.s;
			check=true;
			break;
		}
		for(int k=0;k<4;k++){
			int dx=p.a+x[k];
			int dy=p.b+y[k];
			string v=p.s+s[k];
			if(isValid(dx,dy,grid,visit,n,m)){
				q.push(triple(dx,dy,v));
				visit[dx][dy]=1;
			}
		}
	}
	if(check==true){
		cout<<"YES\n";
		cout<<ans.size()<<"\n";
		cout<<printf("%s\n",ans);

	}
	else{
		cout<<"NO\n";
	}
	return;
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
			if(grid[i][j]=='A'){
				bfs(i,j,grid,visit,n,m);
				ans=1;
				break;
			}
		}
		if(ans==1){
		    break;
		}
	}
}