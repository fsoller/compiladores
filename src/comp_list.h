
typedef struct comp_list_t{
	int data;
	struct comp_list_t *next;
	struct comp_list_t *prev;
}comp_list;


comp_list* list_Create();
comp_list* list_Add(int data, comp_list* first);
comp_list* list_Search(int data, comp_list* first);
void list_Remove(comp_list* node);
comp_list* list_Concat(comp_list* list1, comp_list* list2);
