#include <stdio.h> 
#include <stdlib.h> 

struct Node {
	int data;
	struct Node *next;
};

void push(struct Node** head_ref, int new_data) {
	//Allocate node
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	//put data in node
	new_node->data = new_data;

	//Make next of new node as head
	new_node->next = (*head_ref);

	//Move the head to point to the new node
	(*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data) {
	//Check if the given node is null
	if (prev_node == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}
	/* 2. allocate new node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* 3. put in the data  */
	new_node->data = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref;
	new_node->data = new_data;

	new_node->next = NULL;

	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;
}

// This function prints contents of linked list starting from head 
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}


/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	// Insert 6.  So linked list becomes 6->NULL 
	append(&head, 6);

	// Insert 7 at the beginning. So linked list becomes 7->6->NULL 
	push(&head, 7);

	// Insert 1 at the beginning. So linked list becomes 1->7->6->NULL 
	push(&head, 1);

	// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL 
	append(&head, 4);

	// Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL 
	insertAfter(head->next, 8);

	printf("\n Created Linked list is: ");
	printList(head);

	return 0;
}