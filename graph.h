#include "node.h"
#include <stdio.h>
#include <limits.h>
#include <queue>
#include <vector>

class Graph
{
	protected:
	int gSize;
	int maxSize;
	List* graph;
	
	public:
	bool isEmpty();
	void createGraph();
	void clearGraph();
	void printGraph();
	void depthFirstTraversal();
	void dftAtVertex(int vertex);
	void breadthFirstTraversal();
	Graph(int size = 0);
	~Graph();

	private:
	void dft(int v, bool visited[]);
};

bool Graph::isEmpty()
{
	return (gSize == 0);
}

Graph::Graph(int size)
{
	maxSize = size;
	gSize = 0;
	graph = new List[size];
}

Graph::~Graph()
{
	clearGraph();
}

void Graph::createGraph()
{
	if(gSize!=0) clearGraph();

	cout<<"enter size of graph: "<<endl;
	cin>>gSize;

	for(int i = 0; i < gSize; i ++)
	{
		int adVertex;
		cout<<"enter adjacent vertex"<<endl;
		cin>>adVertex;
		while(adVertex != -1)
		{
			graph[i].insertLast(adVertex);
			cout<<"enter adjacent vertex"<<endl;
			cin>>adVertex;
		}
	}
}

void Graph::clearGraph()
{
	for(int i = 0; i < gSize; i ++)
	{
		graph[i].DeleteAll();
	}

	gSize=0;
}

void Graph::printGraph()
{
	for(int i = 0; i < gSize; i++)
	{
		graph[i].print();
		cout<<endl;
	}

	cout<<endl;
}

void Graph::depthFirstTraversal()
{
	bool visited[gSize];

	for(int i=0; i < gSize; i ++)
		visited[i] = false;

	for(int i=0; i < gSize; i++)
	{
		if(!visited[i])
		{
			dft(i, visited);
		}
	}
}

void Graph::dft(int v, bool visited[])
{
	visited[v] = true;

	cout<<v<<endl;

	for(int i=0; i < graph[v].length(); i++)
	{
		if(!visited[graph[v][i]])
		{
			dft(graph[v][i], visited);
		}
	}
}

void Graph::breadthFirstTraversal()
{
	bool visited[gSize];

	for(int i=0; i < gSize; i ++)
		visited[i] = false;

	queue<int> Q;

	for(int i = 0; i < gSize; i++)
	{
		if(!visited[i])
		{
			Q.push(i);
			visited[i] == true;
			cout<<i<<endl;
			while(!Q.empty())
			{
				for(int j = 0; j < graph[i].length(); j++)
				{
					Q.push(graph[i][j]);
					visited[j] = true;
					cout<<j<<endl;
				}

				Q.pop();
			}
		}

	}

}


class Wgraph: public Graph
{
	public:
	void createWeightedGraph();
	void shortestPath(int vertex);
	void printShortestDistance(int vertex);
	Wgraph(int size = 0);
	~Wgraph();
	int minDistance(bool visited[]);
	protected:
	vector<vector<int> > weights; //pointer to create weight matrix
	vector<int > smallestWeight;
};

Wgraph::Wgraph(int size)
{
	maxSize = size;
	gSize = 0;
	graph = new List[size];

}

Wgraph::~Wgraph()
{
	clearGraph();
}

void Wgraph::createWeightedGraph()
{
	if(gSize!=0) clearGraph();

	cout<<"enter size of graph: "<<endl;
	cin>>gSize;

	weights.resize(gSize);

	for(int i = 0; i < gSize; i ++)
	{
		weights[i].resize(gSize);
		for(int j = 0; j < gSize; j ++)
		{
			weights[i][j] = INT_MAX;
		}
	}
	smallestWeight.resize(gSize);

	for(int i = 0; i < gSize; i ++)
	{
		int adVertex;
		cout<<"enter adjacent vertex"<<endl;
		cin>>adVertex;
		while(adVertex != -1)
		{
			cout<<"enter distance: "<<endl;
			cin>>weights[i][adVertex];
			graph[i].insertLast(adVertex);
			cout<<"enter adjacent vertex"<<endl;
			cin>>adVertex;
		}
	}


}

int Wgraph::minDistance(bool visited[])
{
	int min(INT_MAX), min_index; 

	for(int i = 0; i < gSize; i ++)
	{
		if((smallestWeight[i] <= min) && (!visited[i]))
		{
			min = smallestWeight[i];
			min_index = i;
		}
	}

	return min_index;
}

void Wgraph::shortestPath(int vertex)
{
	bool visited[gSize];

	for (int i = 0; i < gSize; i ++)
	{
		smallestWeight[i] = INT_MAX;
		visited[i] = false;
 	}

 	smallestWeight[vertex] = 0;

 	for (int i = 0; i < gSize - 1; i++)
 	{
 		int u = minDistance(visited);
 		visited[u] = true;

 		for (int j = 0; j < gSize; j ++)
 		{
 			if (!visited[j])
 			{
 				if(smallestWeight[u] + weights[u][j] < smallestWeight[j])
 				{
 					smallestWeight[j] = smallestWeight[u] + weights[u][j];
 				}
 			}
  		}

 	}

}

void Wgraph::printShortestDistance(int vertex)
{
	shortestPath(vertex);
	cout << "Source Vertex: " << vertex << endl;
	cout << "Shortest distance from source to each vertex." << endl;
	cout << "Vertex Shortest_Distance" << endl;

	for (int j = 0; j < gSize; j++)
	{
		cout << j <<"   " << smallestWeight[j] << endl;
	}

    cout << endl;
}

struct edge
{
	int start;
	int end;
	int distance;
	edge(int s, int e)
	{
		start = s;
		end = e;
	}

	edge()
	{
		start = 0;
		end = 0;
	}
};

class MST: public Wgraph
{
	public:
    	void createSpanningGraph();
		void printTreeAndWeight();
		void prim(int sVertex); 
		MST(int size = 0);
		~MST();

	protected:
    	int source;
   	 	vector<edge> edges;
};

MST::MST(int size)
{
	maxSize = size;
	gSize = 0;
	graph = new List[size];
}

MST::~MST()
{
	clearGraph();
}

void MST::createSpanningGraph()
{
	createWeightedGraph();
}

void MST::printTreeAndWeight()
{
	int treeWeight = 0;
	cout << "source vertex: " << source << endl;
	cout << "Edges     Weight" << endl;
	for (int i = 0; i < edges.size(); i ++)
	{
		treeWeight = treeWeight + edges[i].distance;
		cout << "(" << edges[i].start << ", " << edges[i].end << ")" << edges[i].distance << endl;
	}

	cout << endl;
    cout << "Minimum spanning Tree Weight: " << treeWeight << endl;
}

void MST::prim(int sVertex)
{
	bool visited[gSize];
	int minweight;
	int endvertex;
	source = sVertex;

	for (int i = 0; i < gSize; i ++)
	{
		visited[i] = false;
	}

	visited[sVertex] = true;

	for (int i = 0; i < gSize - 1; i ++)
	{
		minweight = INT_MAX;
		edge E;
		for (int j = 0; j < gSize; j ++)
		{
			if(visited[j])
			{
				for(int k = 0; k < gSize; k ++)
				{
					if(!visited[k] && weights[j][k] < minweight)
					{
						endvertex = k;
						E.start = j;
						E.end = k;
						minweight = weights[j][k];
					}
				}
			}
		}

		visited[endvertex] = true;
		E.distance = minweight;
		edges.push_back(E);
	}


}


