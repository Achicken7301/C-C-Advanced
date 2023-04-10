#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

/**
 * @brief
 *
 * @param head
 * @param value
 */
void addSortedNode(Node **head, int value)
{
    Node *newNode = createNode(value);

    // check if new node
    if (*head == NULL)
    {
        (*head) = newNode;
        return;
    }

    Node *temp, *preTemp;

    // if newNode.value < head.value => switch headNode to newNode
    if (newNode->data < (*head)->data)
    {
        temp = *head;

        *head = newNode;

        (*head)->next = temp;
    }
    // if greater than head.value then find the node.value > newNode.value
    else
    {
        temp = *head;

        // Find node.value > newNode.value
        while (newNode->data > temp->data)
        {
            preTemp = temp;
            temp = temp->next;

            // if temp is lastNode
            if (temp == NULL)
            {
                preTemp->next = newNode;
                return;
            }
        }

        // Add newNode between 2 nodes
        preTemp->next = newNode;
        newNode->next = temp;
    }
}

int getNode(Node *head, int node_number)
{
    Node *ptr = head;
    for (int i = 0; i < node_number; i++)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            return -1;
        }
    }
    return ptr->data;
}

// return size of the linked list
int linkedListSize(Node *head)
{
    int size = 0;
    // from head to lastNode
    while (head->next != NULL)
    {
        head = head->next;
        size++;
    }

    return size + 1;
}

int size(Node *head, Node *lastNode)
{
    int count = 0;
    while (head->next != lastNode)
    {
        count++;
    }
    return count;
}

int binarySearch(Node *head, int value, int size)
{
    if (size > 0)
    {
        // stop condition
        Node *mid = head;
        int count = size / 2;

        while (count > 0)
        {
            mid = mid->next;
            count--;
        }

        if (mid->data == value)
        {
            return value;
        }

        if (mid->data > value)
        {
            return binarySearch(head, value, size / 2);
        }
        else
        {
            return binarySearch(mid->next, value, size / 2);
        }
    }

    return -1;
}

int main()
{
    Node *n = NULL;
    addSortedNode(&n, 7);
    addSortedNode(&n, 4);
    addSortedNode(&n, 11);
    addSortedNode(&n, 12);
    addSortedNode(&n, 151);
    addSortedNode(&n, 256);
    addSortedNode(&n, 1);
    addSortedNode(&n, 5);
    addSortedNode(&n, 3);

    for (size_t i = 0; i < linkedListSize(n); i++)
    {
        printf("%d\n", getNode(n, i));
    }

    printf("binarySearch: %d\n", binarySearch(n, 121, linkedListSize(n)));

    return 0;
}