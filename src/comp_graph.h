
typedef struct adjacencyList_t{
	struct comp_graph_t* node;
	struct adjacencyList_t* next;
}adjList;


typedef struct comp_graph_t {
	int data;
	struct comp_graph_t* left;  //pointers for an auxiliary tree structure
	struct comp_graph_t* right;
	struct adjList* list;
}comp_graph;

adjList* graph_InsertEnd(comp_graph* node, adjList* list);
adjList* graph_RemoveFirst(adjList* list);
adjList* graph_RemoveItem(comp_graph* node, adjList* list);
adjList* graph_CreateList();
adjList* graph_DestroyList(adjList* list);

comp_graph* graph_Add(int data,comp_graph* root, adjList* adj);
comp_graph* graph_Delete(comp_graph* node, comp_graph* root);
comp_graph* graph_Edit(int new_data, comp_graph* node, comp_graph* root, adjList* adj);
comp_graph* graph_FindFatherNode(comp_graph* node, comp_graph* root);
comp_graph* graph_Contains(comp_graph* node, comp_graph* root);
comp_graph* graph_Create();
void graph_Destroy(comp_graph* root);

