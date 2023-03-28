#include "vector.h"

/**
 * @brief Create a Vector object
 *
 * @param value
 * @return Vector*
 */
Vector *createVector(int value)
{

    Vector *newVector = (Vector *)malloc(sizeof(Vector));
    newVector->value = value;
    newVector->next = NULL;
    return newVector;
}

/**
 * @brief initation a new Vector
 *
 * @param vector
 */
void vectorInit(Vector **vector)
{
    (*vector)->value = 0;
    (*vector)->next = NULL;
    (*vector)->pushBack = &pushBack;
}

/**
 * @brief Create a Note object
 * 
 * @param value 
 * @return Vector* 
 */
Vector *createNote(int value)
{
	Vector *temp;
	temp = (Vector *)malloc(sizeof(Vector));
	temp->value = value;
	temp->next = NULL;
	return temp;
}

/**
 * @brief push a int value to the last element of the vector
 *
 * @param vector
 * @param value
 */
void pushBack(Vector **vectorHead, int value)
{
    Vector *newNode, *lastNode;
    newNode = createNote(value);
    // if is 1st Node
    if (*vectorHead == NULL)
    {
        *vectorHead = newNode;
        return;
    }

    lastNode = *vectorHead;
    // find lastNode->next == NULL
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

/**
 * @brief Get value of the Node object at the given index
 * 
 * @param vectorHead 
 * @param nodeNumber 
 * @return int 
 */
int getNode(Vector **vectorHead, int nodeNumber)
{
	Vector *ptr = *vectorHead;
	int flag = 0;
	for (int i = 0; i < nodeNumber; i++)
	{
		ptr = ptr->next;
		if (ptr == NULL)
		{
			return -1;
		}
	}
	return ptr->value;
}

/**
 * @brief Remove all elements from the vector
 * 
 * @param vectorHead 
 */
void clear(Vector **vectorHead)
{
	Vector *temp;
	while ((*vectorHead) != NULL)
	{
		temp = *vectorHead;
		*vectorHead = (*vectorHead)->next;
		free(temp);
	}
	*vectorHead = NULL;
}

/**
 * @brief Get the vector size
 * 
 * @param vectorHead 
 * @return int 
 */
static int size(Vector *vectorHead)
{
	int size = 0;
	// from head to lastNode
	while (vectorHead->next != NULL)
	{
		vectorHead = vectorHead->next;
		size++;
	}

	return size;
}

/**
 * @brief erase a element from the vector given a position
 * 
 * @param head 
 * @param pos 
 */
void erase(Vector **head, int pos)
{
	// check if that pos exists
	if (size((*head)) < pos)
	{
		printf("pos is out of range\n");
		return;
	}

	// find preNode and currNode
	Vector *preNode, *currNode;
	currNode = *head;

	while (pos > 0)
	{
		preNode = currNode;
		currNode = currNode->next;
		pos--;
	}

    // Linked preNode->next to currNode->next (afterNode's address)
	preNode->next = currNode->next;

	// Free currNode
	free(currNode);
}

/**
 * @brief update a vector index a new value
 * 
 * @param head 
 * @param index 
 * @param value 
 */
void assign(Vector **head, int index, int value)
{
	// check if that pos exists
	if (size((*head)) < index)
	{
		printf("pos is out of range\n");
		return;
	}

	// find currNode
	Vector *currNode;
	currNode = *head;

	while (index > 0)
	{
		currNode = currNode->next;
		index--;
	}

    // update currNode value
	currNode->value = value;
}