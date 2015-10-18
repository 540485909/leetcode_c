turn the problem of courese schedule to topological order
we only to deal with the easy problem that decide if a cycle exit in a graph
algorithm:
L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edges
while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
    	remove edge e from the graph
	if m has no other incoming edges then
        	insert m into S
if graph has edges then
	return error (graph has at least one cycle
else 
	return L (a topologically sorted order
