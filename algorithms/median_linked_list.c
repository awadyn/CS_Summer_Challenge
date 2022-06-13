#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


// NOTE: - now, list is no longer a dynamically sized array of ints
//	 - it is now a dynamically sized array of nodes
//		- i.e. a linked list

// new
//	defining a new data type - struct
//	naming it node
typedef struct Node {
	int value;
	struct Node *next;
} node ;

// new
//	defining list head node - pointer to the first
//	list element
node* node_list;

int *list;
int list_size;
int median;
int median_index;

int print_list() {
	int i;
	for (i = 0; i < list_size; i ++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}



// new
// printing linked list => traversing linked list
void print_node_list() {
	int i;
	node *tail = node_list;
	for (i = 0; i < list_size; i ++) {
		printf("%d ", tail->value);
		tail = tail->next;
	}
	printf("\n");
}



int get_list() {
	list = (int *)malloc(5 * sizeof(int));
	printf("Enter 5 integers:\n");
	int num_inputs = scanf("%d %d %d %d %d", list, &list[1], &list[2], &list[3], &list[4]); 
	list_size = num_inputs;
	if ( num_inputs == 5) return 0;
	else return -1;
}



// NOTE: to decrease size of source code
//	--> ask: why is this not very good practice?
node *new_node() {
	return (node *)malloc(sizeof(node));
}



// NOTE: converting array type list to linked list
void convert_list() {
	// starting with head node: list variable points to this head node
	node_list = new_node();
	node_list->value = list[0];

	node* tail;
	tail = node_list;
	int i;
	for (i = 1; i < list_size; i ++) {
		// initialize new node memory for each next input element
		tail->next = new_node();
		tail = tail->next;
		tail->value = list[i];
	}
}



// new converting back to list after insert
void convert_node_list() {
	int *new_list = (int *)malloc(list_size * sizeof(int));
	node *tail = node_list;
	int i;
	for (i = 0; (i < list_size) && (tail != NULL); i ++) {
		new_list[i] = tail->value;
		tail = tail->next;
	}
	list = new_list;
}

void sort_list() {
	int i, j, x, y;
	for (i = 1; i < list_size; i ++) {
		x = list[i];
		for (j = i - 1; j >= 0; j--) {
			y = list[j];
			if (x < y) {
				list[j] = x;
				list[j+1] = y;
			}
			print_list();
		}
	}
}




// new
// no longer searching for an index,
// rather, a list node after which to place the
// new entry
node* search(int value) {
	// traverse node list from start to end
	node *tail = node_list;
	node *index;
	// NOTE: ease of using while loop for dynamically
	// sized linked list
	//	--> a linked list always ends with a null pointer
	while (tail != NULL) {
		if (value <= tail->value) {
			return index;
		}
		index = tail;
		tail = tail->next;
	}
	// if index = NULL here, then element goes at the start
	// of the node list
	return index;
}



// new
// now, insert becomes very easy
void insert() {
	int new_entry;
	printf("Enter a new integer:\n");
	scanf("%d", &new_entry);

	// allocate memory for this node
	// now the node exists, and we need to place it in the 
	// node list without disturbing the order
	node *input_node = new_node();
	input_node->value = new_entry;

	// get list position from search function
	//	here, position is a node pointer
	//	the new entry must be placed before this position
	//	because its value is lower, according to search()
	node *index_node = search(new_entry);
	if (index_node == NULL) {
		// add new entry to start of node list
		input_node->next = node_list;
		// reassign node_list pointer to start of list
		node_list = input_node;
	} else {
		// add new entry after the index node
		// NOTE: importance of assigning input_node first
		//	before disturbing the list order
		input_node->next = index_node->next;
		index_node->next = input_node;
	}
	
	list_size = list_size + 1;
}



void get_median() {
	median_index = list_size/2;
	median = list[median_index];
}



int main() {
	get_list();
	printf("Successfully read integer list: ");
	print_list();
	
	sort_list();
	printf("Successfully sorted list: "),
	print_list();

	convert_list();
	printf("Successfully converted to node list: ");
	print_node_list();

	insert();
	printf("Successfully inserted to node list: "),
	print_node_list();

	convert_node_list();
	printf("Successfully converted to list: ");
	print_list();
		
	get_median();
	printf("\n Median: %d\n", median);	

	return 0;
}
