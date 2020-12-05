#include <bits/stdc++.h> 
#include <queue>
#include <set>

using namespace std; 
 
vector<bool> isVisited; 
vector<vector<int>> adjList; 

void edge(int a,int b){
	adjList[a].push_back(b);
	
}

void bfs(int u){
	queue<int> q; 
	q.push(u);
	isVisited[u]= true; 


	while(!q.empty()){
		int front  = q.front();
		q.pop(); 
		cout<<front; 

		for(int number: adjList[front]){
			if(!isVisited[number]){
				q.push(number);
				isVisited[number] = true; 
			}
		}

	}
}
int main(){
	int n,e; 
	cin>>n>>e;

	isVisited.assign(n,false); 
	adjList.assign(n,vector<int>());

	int node1,node2;
	for(int i=0; i<e;i++){
		cin>> node1>>node2;
		edge(node1,node2);
	}

	for (int i = 0; i < n; ++i)
	{
		if(!isVisited[i])
			bfs(i);
	}
	return 0; 

}