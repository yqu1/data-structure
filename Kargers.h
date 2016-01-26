struct subset
{
	int parent;
	int rank;
};

void Union(subset subsets[], int x, int y)
{
	int xroot = Find(subsets, x);
	int yroot = Find(subsets, y);

	if(subsets[xroot].rank > subsets[yroot].rank) subsets[xroot].parent = yroot;

	else if(subsets[xroot].rank < subsets[yroot].rank) subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank ++;
	}
}

int Find(subset subsets[], int i)
{
	if(subsets[i].parent != i)
	{
		subsets[i].parent = Find(subsets, subsets[i].parent);
	} 

	return subsets[i].parent;
}

struct edge
{
	int src;
	int dest;
};

struct graph
{
	int V, E;
	edge* edge
};

int Karger(graph* G)
{
	int V = G -> V;
	int E = G -> E;
	edge* edge  = G -> edge;

	subset* subsets = new subset[V];
	for(int i = 0; i < V; i++)
	{
		subsets[i].parent = i;
	}

	while(V > 2)
	{
		int i = rand % E;

		int subset1 = find(subsets, edge[i].src)
		int subset2 = find(subsets, edge[i].dest)

		if(subset1 == subset2) continue;

		V--;
		Union(subsets, subset1, subset2);
	}

	int min_cut(0);

	for(int i = 0; i < E; i++)
	{
		int subset1 = find(subsets, edge[i].src);
		int subset2 = find(subsets, edge[i].dest);

		if(subset1 != subset2)
		{
			min_cut ++;
		}
	}

	return min_cut;
}