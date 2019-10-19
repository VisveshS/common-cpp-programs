#include<bits/stdc++.h>
#define LL long long int
#define N int(1e5+1)
using namespace std;
vector<int> adj[10];
vector<bool> visited;
vector<int> path;
bool hamilton(int length,int root)
{
	visited[root]=true;
	path.push_back(root);
	if(length==1)
		return true;
	for(int child:adj[root])
		if(not visited[child])
			if(hamilton(length-1,child))
				return true;
	visited[root]=false;
	path.pop_back();
	return false;
}
int main()
{
	int i,n,m,v1,v2;
	cin>>n>>m;
	for(i=0;i<n;i++)
		visited.push_back(false);
	for(i=0;i<m;i++)
	{
		cin>>v1>>v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	for(i=0;i<n;i++)
	{
		path.clear();
		if(hamilton(n,i))
		{
			// cout<<"YES\n";
			// return 0;
			for(int j:path)
				cout<<j<<" ";
			cout<<endl;
		}
	}
	cout<<"NO\n";
	return 0;
}