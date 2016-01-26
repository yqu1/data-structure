#include "graph.h"

int main()
{
	MST mst(7);
	mst.createSpanningGraph();
	mst.prim(0);
	mst.printTreeAndWeight();
}