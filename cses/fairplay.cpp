#include<bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		//vector<int>a(n);
		vector<int>even;
		vector<int>odd;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x%2==0){
				even.push_back(x);
			}
			else{
				odd.push_back(x);
			}
		}
		int i=0;
		int ans=0;
		while(i<even.size()){
			//a[i]=even[i];
			ans+=(n-i-1);
			i++;
		}
		sort(odd.begin(),odd.end());
		for(int j=0;j<odd.size();j++){
		    for(int k=j+1;k<odd.size();k++){
		        int x=gcd(odd[j],odd[k]);
		        if(x>1){
		            ans++;
		        }
		    }
		}
		cout<<ans<<"\n";

	}
}