#include<bits/stdc++.h>
using namespace std;
template<typename i>
class graph{
	int v;

public:
	map<i,list<i>> adjlist;
	graph(int V)
	{
		v = V;
	}
   void addEdge(int u,int v, bool bidirec=true)
   {
   	if(bidirec==true)
   		adjlist[u].push_back(v);
   	  adjlist[v].push_back(u);

   }
   void printgraph()
   {
   	for(auto r:adjlist){
   		i p= r.first;
   	    cout<<p<<"->";
   	    for(auto row_ele:r.second)
   	    {
   	    	cout<<row_ele<<" ";
   	    }
   	    cout<<endl;
   	  }  
   }

   // void bfs(int src)
   // {
   // 	queue<int> q;
   // 	bool *visited = new bool[v]{0};
   // 	q.push(src);
   //  visited[src] =true;
   //  while(!q.empty())
   //  {
   //    int k = q.front();
   //    cout<<k<<" ";
   //    q.pop();
   //    for(int neighbour:adjlist[k])
   //    {
   //    	if(!visited[neighbour])
   //    	{
   //    		q.push(neighbour);
   //    		visited[neighbour] =true;
   //    	}
   //    }

   //  }

   // }

  void  bfs(int src)
  {

  	//Algorithm ka logic:
    //Create a queue, add the first element into the queue;
    //Create a boolean array with numbers of nodes in the graph and intialize it to false;
    //make the first element visited true, once you push the element into the queue;
    // Unitll the queue is empty, take the first element and print it, and pop the element from the queue;
    // iterate thought the adjacency  list and push the element in the list and make the visited true;
    queue<int> q;
    
    bool *visited = new bool[v]{0};

    q.push(src);
    visited[src] =true;
    while(!q.empty())
    {
    	int k= q.front();
    	cout<<k<<" ";
    	q.pop();
    	for(int neighbour:adjlist[k])
    	{
    		if(!visited[neighbour])
    		{
    			q.push(neighbour);
    			visited[neighbour]=true;
    		}
    	}
    }

    


  }
//Algorithm for DFS, its an recursive implemtation,in which we go till the end of the fucntion call.
//Create A  Function called as dfs in which we do have to make a map which consist of interger and boolean values.
// Call the dfshelper function with source node and visited map;
// Create a dfshelper fucntion in which we do have to sent source node and map values with references;
// Make the source node value visited in the boolean Array.
// We need to call the dfshelper function recursively.

  void dfs(int src)
  {
  	map<i,bool> visited;
  	dfshelper(src,visited);
  }
  void dfshelper(int src, map<i,bool> &visited)
  {
     visited[src] =true;
     cout<<src<<" ";
     for(int neighbour: adjlist[src])
     {
     	if(!visited[neighbour])
     	{
     		dfshelper(neighbour,visited);
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

  g.printgraph();
  g.bfs(1);
  cout<<endl;
  g.dfs(3);
  return 0;

}