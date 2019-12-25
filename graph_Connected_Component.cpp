#include<bits/stdc++.h>
using namespace std;
template<typename i> 
class graph{
	int v;


public:
		map<i, list<i>> adjlist;
	graph(int V)
	{
		v= V;
	}

    void addEdge(int u, int v, bool bidirec=true)
    {
    	if(bidirec==true)
    	{
    		adjlist[u].push_back(v);
    	}
    	adjlist[v].push_back(u);
    }
void printgraph()
{
	for(auto p: adjlist){
		auto k = p.first;
		cout<<k<<" ->";
		for(auto neighbour: p.second)
		{
			cout<<neighbour<<" ";
		}
		cout<<endl;
	}
}

     void dfs(i src)
     {
     	map<i, bool> visited;
        dfshelper(src,visited); 
        cout<<endl;
     	int component=1;
     	for(auto p :adjlist)
     	{   
     		auto city = p.first;
     		if(!visited[city])
     		{
     			dfshelper(city,visited);
     			component++;
     		}
     	}

     	cout<<"The connected component of the graph are  -> "<<component<<endl;
     }
     void dfshelper(i src, map<i,bool> &visited)
     {
     	visited[src] = true;
     	cout<<src<<" "; 
     	for(auto neighbour:adjlist[src])
     	{
     		if(!visited[neighbour])
     		{
     			dfshelper(neighbour, visited);
     		}
     	}
     }

};
int main()
{

graph<int> g(5);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,5);
  g.addEdge(1,4);
  g.addEdge(1,3);
  g.addEdge(4,5);
  g.addEdge(4,3);
   g.addEdge(7,9);

  g.printgraph();
  g.dfs(1);
	return 0;
}