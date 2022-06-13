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
	struct list_node* next;
	// new new
	struct list_node* prev;
} node ;

// new
//	defining list head node - pointer to the first
//	list element
node* node_list;

int *list;
int list_size;
int median;


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
	node* my_node = list;
	for (i = 0; i < list_size; i ++) {
		printf("%d ", my_node->value);
		my_node = my_node->next;
	}
	printf("\n");
}


// new new
void reverse_print_list() {
	// go to end of list
	node* iterator = list;
	int i;
	for (i = 0; i < list_size - 1; i ++) {
		// NOTE: changing value of iterator pointer variable
		//	--> now iterator points to next node
		iterator = iterator->next;
	}
	// --> now iterator points to last node
	// now we can print
	for (i = 0; i < list_size; i ++) {
		printf("%d ", iterator->value);
		iterator = iterator->prev;
	}
	printf("\n");	
}


void get_list() {
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
	// new
	// creating linked list 
	node* head;
	node* tail;

	// starting with head node: list variable points to this head node
	head = new_node();
	head->value = list[0];
	// NOTE: this is a pointer to memory that is not yet initialized
	head->next = (node*)malloc(sizeof(node));
	// new new
	first_input->prev = NULL;

	// setting up global list variable
	list = first_input;

	int i;
	for (i = 1; i < list_size - 1; i ++) {
		// initialize new node memory for each next input element
		next_input = first_input->next;
		next_input->value = temp_list[i];
		next_input->next = (node*)malloc(sizeof(node));
		// new new
		next_input->prev = first_input;

		// switch head pointer value
		first_input = next_input;
	}
	// initialize last element
	// this element will not point to any new input
	next_input = first_input->next;
	next_input->value = temp_list[i];
	next_input->next = NULL;
	// new new
	next_input->prev = first_input;
	
	return 0;
}

// new
// no longer searching for an index,
// rather, a list node after which to place the
// new entry
node* search(int value) {
	node *iterator = list;
	// first traverse list correctly
	while (iterator != NULL) {
		// then check condition
		if (value <= iterator->value) {
			return iterator;
		}
		iterator = iterator->next;
	}
	return iterator;
/*
	int i;
	for (i = 0; i < list_size; i ++) {
		if (value <= list[i]) {
			return i;
		}
	}
	return i;
*/
}

// new
// now, insert becomes very easy
int insert() {
	int new_entry;
	printf("Enter a new integer:\n");
	scanf("%d", &new_entry);

	// now get list position from search function
	//	here, position is a node pointer
	//	the new entry must be placed before this position
	//	because its value is lower, according to search()
	node *successor_node = search(new_entry);
	node *predecessor_node;

	// now, dynamically allocate a new node
	node *new_node = (node*)malloc(sizeof(node));
	new_node->value = new_entry;

	// place node before successor node and after predecessor node

	// if the position is NULL, this means the entry 
	//	is to be placed at the end of the list
	if (successor_node == NULL) {
		predecessor_node = list;
		while (predecessor_node->next != NULL) {
			predecessor_node = predecessor_node->next;
		}
		// now we are at the end of list
		predecessor_node->next = new_node;
		new_node->prev = predecessor_node;
	} else {
		// this is the case where the new entry is the lowest value
		if (successor_node == list) {
			// note here using the two variables interchangeably
			new_node->next = list;
			list->prev = new_node;
			// note reassigning list pointer
			list = new_node;
		} else {
			// this is the case where the position is
			// in the middle of the list
			predecessor_node = successor_node->prev;

			new_node->next = successor_node;
			// change old list order here
			successor_node->prev = new_node;

			new_node->prev = predecessor_node;
			// change old list order here
			predecessor_node->next = new_node;
		}		
	}

	list_size = list_size + 1;

	printf("New list: ");
	print_list();
}




// new
// reimplementing with changing pointers rather than
// swapping values
int my_sort_list() {
	print_list();

	// use target_node to reference node to be sorted
	// use prev_node to reference nodes to compare target_node to
	node* target_node;
	node* prev_node;

	// starting from second element
	// compare it to all elements in list that precede this target node
	target_node = list->next;

	// new -- using a while loop
	//	--terminating a linked list by NULL ptrs
	// here, target_node starts from the second node
	//	until the last node
	// this is the outer loop
	int x, y;
	while (target_node != NULL) {
		x = target_node->value;
		// new
		// NOTE: needing to traverse linked list backward
		//	-- stop here, update node struct
		//	-- do reverse_print_list to confirm
		prev_node = target_node->prev;
		// here, prev_node traverses the list to its
		// start
		// this is the inner loop
		while (prev_node != NULL) {
			y = prev_node->value;
			// this is the comparison part
			if (x < y) {
				prev_node->value = x;
				prev_node->next->value = y;
				// NOTE here significance of using node pointers
			}
			prev_node = prev_node->prev;
			print_list();
		}
		target_node = target_node->next; 
	}

	return 0;
}


// new
// no more use for indexing
// rather, traverse list from either end until intersection
void get_median() {
	// new
	// need to traverse list to its tail again
	node *tail = list;
	while (tail->next != NULL) {
		tail = tail->next; 
	}
	// now, tail is the last node in the list
	node *head = list;

	// NOTE: significance of using pointer values
	//	- we can just compare the addrs of nodes,
	//	without needing to compare the values

	// now, traverse from both sides
	// until head = tail or tail = head
	while (head != tail) {
		head = head->next;
		// note need to do this
		if (head == tail) break;
		tail = tail->prev;
	}
	// now, head = tail
	median = head->value;
}


int main() {
	get_list();
	printf("Successfully read integer list: ");
	print_list();

	convert_list();

	//printf("List in reverse: ");
	//reverse_print_list();

	my_sort_list();
	printf("Successfully sorted list: "),
	print_list();

	insert();
	printf("Successfully inserted to list: "),
	print_list();

	get_median();
	printf("\n Median: %d\n", median);
	

	return 0;
}
