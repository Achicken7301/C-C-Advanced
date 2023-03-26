#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *next;
} Node;

Node *createNote(int value)
{
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void pushBack(Node **head, int value)
{
	Node *newNode, *lastNode;
	newNode = createNote(value);
	// if is_node_1
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	lastNode = *head;
	// find lastNode->next == NULL
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
}

int getNode(Node **head, int node_number)
{
	Node *ptr = *head;
	int flag = 0;
	for (int i = 0; i < node_number; i++)
	{
		ptr = ptr->next;
		if (ptr == NULL)
		{
			return -1;
		}
	}
	return ptr->value;
}

void addAtHead(Node **head, int value)
{
	Node *temp, *ptr;
	temp = createNote(value);
	// check 1st condition
	if (*head == NULL)
	{
		*head = temp;
	}
	else
	{
		temp->next = *head;
		*head = temp;
	}
}

// Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector.
void clear(Node **head)
{
	Node *temp;
	while ((*head) != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}

// return size of the linked list
int size(Node **head)
{
	int size = 0;
	Node *lastNode = *head;
	// from head to lastNode
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
		size++;
	}

	return size;
}

// erase node at index in linked list
void erase(Node **head, int pos)
{
	// check if that pos exists
	if (size(head) < pos)
	{
		printf("pos is out of range\n");
		return;
	}

	// find preNode, afterNode and currNode
	Node *preNode, *currNode;
	currNode = *head;

	while (pos > 0)
	{
		preNode = currNode;
		currNode = currNode->next;
		pos--;
	}

	preNode->next = currNode->next;

	// Free currNode and linked preNode and afterNode
	free(currNode);
}

// assign a Node with a given value
void assign(Node **head, int index, int value)
{
	// check if that pos exists
	printf("size of linked list: %d\n", size(head));
	if (size(head) < index)
	{
		printf("pos is out of range\n");
		return;
	}

	// find preNode, afterNode and currNode
	Node *currNode;
	currNode = *head;

	while (index > 0)
	{
		currNode = currNode->next;
		index--;
	}

	currNode->value = value;
}

int main(int argc, char const *argv[])
{
	// Create a NULL pointer
	Node *node1 = NULL;
	pushBack(&node1, 7);
	pushBack(&node1, 2);
	pushBack(&node1, 4);
	pushBack(&node1, 5);
	assign(&node1, 3, 123);
	pushBack(&node1, 1);
	pushBack(&node1, 9);
	erase(&node1, 2);
	// clear(&node1);
	// Get Node
	for (int i = 0; i < size(&node1); i++)
	{
		printf("%d\n", getNode(&node1, i));
	}
	return 0;
}