#include<bits/stdc++.h>
using namespace std;
#define int long long

//int ans=0;
// oid bfs(int i,vector<vector<int>>& graph,vector<int>&visit){
// 	queue<int>q;
// 	q.push(i);
// 	vvisit[i]=1;
// 	while(!q.empty()){
// 		int x=q.front();
// 		q.pop();
// 		for(int a:graph[x]){
// 			if(visit[a]==0){
// 				q.push(a);
// 				visit[a]=1;
// 			}
// 		}
// 	}
// }
struct fun{
	int x;
	string s;
	fun(int a,string c){
		this->x=a;
		this->s=c;
	}
};

int32_t main(){
	int n,m; cin>>n>>m;
	vector<vector<int>>graph(n+1);
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	//vector<int>p;
	string ans="";
	vector<int> visit(n+1,0);
	queue<fun>q;
	q.push(fun(1,"1 "));
	visit[1]=1;
	bool check=false;
	int h=-1;
	while(true){
		int cnt=q.size();
		if(cnt==0){
		    break;
		}
		h++;
	while(cnt>0){
		auto x=q.front();
		q.pop();
		//cout<<x.x<<" "<<x.s<<"\n";
		if(x.x==n){
			ans=x.s;
			check=true;
			break;
		}
		for(auto a:graph[x.x]){
			if(visit[a]==0){
				//check=true;
				q.push(fun(a,x.s+to_string(a)+" "));
				visit[a]=1;
			}
		}
		cnt--;
	}
	if(check==true){
		break;
	}
	}
	if(check==true){
	cout<<h+1<<"\n";
	cout<<ans<<"\n";
	}
	else{
		cout<<"IMPOSSIBLE";
	}
	// for(int i=0;i<p.size()-1;i++){
	// 	cout<<p[i]<<" "<<p[i+1]<<"\n";
	// }
}