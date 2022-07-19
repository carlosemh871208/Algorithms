/*
 ============================================================================
 Name        : 003-c-sigleCircularLinkedList.c
 Author      : Carlos Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : Single circular linked list in C, Ansi-style
               This list has the difference with single linked list that the
               last member of the list points to the first member.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char boolean;
#define FALSE (boolean)0u
#define TRUE  (boolean)1u

/*Linked list declaration*/
typedef struct
{
	void* firstNode; /*Holds the first list node*/
}singleLinkedList;

/*List Node declaration*/
typedef struct
{
	void* nodeData; /*Holds data stored in the node*/
	void* next;     /*Points to next node, */
}Node;

/*Generic data struct to be added to the linked list */
typedef struct
{
	unsigned int dummyData; /*Add datatypes required for your implementation*/
}Data; /*Change name data according your needs or requirements*/

/*Single Linked List functions*/
static singleLinkedList* createList (void); /*Reserves memory for a new linked list*/
static Node* createNode (void);              /*Reserves memory for a new list node*/
static unsigned int getNodeListNumber (singleLinkedList* list); /*Return number of list nodes*/
static void addNodetoList (singleLinkedList* list, Node* node); /*Add a node to a single list*/
static void addNodetoListIndex (singleLinkedList* list, Node* node, unsigned int index); /*Add a node at any specific index in the list*/
static void delNodefromList (singleLinkedList* list, Node* node); /*Remove an specifc node from list*/
static void delNodefromListIndex (singleLinkedList* list, unsigned int index); /*Remove a Node from an specific index*/
static void deleteList (singleLinkedList* list); /*Deletes a complete list and all its nodes*/
static void addDatatoNode (Node* node, Data* data); /*Add generic data to one Node*/
static Data* getNodeData (Node* node); /*Returns date from node*/


int main(void) {
	singleLinkedList* testList = NULL;
	Node* node1 = NULL;
	Node* node2 = NULL;
	Node* node3 = NULL;
	Node* node4 = NULL;
	Node* node5 = NULL;
	Node* node6 = NULL;
	Data a,b,c,d,e;
	unsigned int arrSize = 0u;
	testList = createList();
	node1 = createNode();
	node2 = createNode();
	node3 = createNode();
	node4 = createNode();
	node5 = createNode();
	node6 = createNode();
	a.dummyData = 1u;
	b.dummyData = 2u;
	c.dummyData = 3u;
	d.dummyData = 4u;
	e.dummyData = 5u;
	addDatatoNode(node1,&a);
	addDatatoNode(node2,&b);
	addDatatoNode(node3,&c);
	addDatatoNode(node4,&d);
	addDatatoNode(node5,&e);
	addNodetoListIndex(testList,node1,1);
	addNodetoListIndex(testList,node2,2);
	addNodetoListIndex(testList,node3,3);
	addNodetoListIndex(testList,node4,4);
	addNodetoListIndex(testList,node5,4);
	return EXIT_SUCCESS;
}


static singleLinkedList* createList (void)
{
	singleLinkedList* list = NULL;
	list = (singleLinkedList*)malloc(sizeof(singleLinkedList));
	if(NULL != list)
	{
		list->firstNode = NULL;
	}
	return list;
}

static Node* createNode (void)
{
	Node* node = NULL;
	node = (Node*)malloc(sizeof(Node));
	if(NULL != node)
	{
		node->nodeData = NULL;
		node->next = NULL;
	}
	return node;
}

static unsigned int getNodeListNumber (singleLinkedList* list)
{
	Node* auxNode = NULL;
	Node* fstNode = NULL;
	unsigned int nodeCtr = 0u;
	if(NULL != list)
	{
		if(NULL != list->firstNode)
		{
			nodeCtr = nodeCtr + 1u;
			auxNode = list->firstNode;
			fstNode = list->firstNode;
			while(fstNode != auxNode->next)
			{
				auxNode = auxNode->next;
				nodeCtr = nodeCtr + 1u;
			}

		}else
		{
			/*Do nothing*/
		}
	}else
	{
		/*Do nothing*/
	}
	return nodeCtr;
}


static void addNodetoList (singleLinkedList* list, Node* node)
{
	Node* auxNode = NULL;
	Node* fstNode = NULL;
	if(NULL != list)
	{
		if(NULL != node)
		{
			if(NULL != list->firstNode)
			{
				auxNode = list->firstNode;
				fstNode = list->firstNode;
				while(fstNode != auxNode->next)
				{
					auxNode = auxNode->next;
				}
				node->next = fstNode;
				auxNode->next = node;
			}else
			{
				list->firstNode = node;
				auxNode = list->firstNode;
				auxNode->next = list->firstNode;
			}
		}else
		{
			/*Do nothing*/
		}
	}else
	{
		/*Do nothing*/
	}
}

static void addNodetoListIndex (singleLinkedList* list, Node* node, unsigned int index)
{
	Node* auxNode = NULL;
	Node* fstNode = NULL;
	unsigned int listNodes = getNodeListNumber(list);
	unsigned int nodeCtr = 0u;
	if(NULL != list)
	{
		if(NULL != node)
		{
			if(NULL != list->firstNode)
			{
				auxNode = list->firstNode;
				fstNode = list->firstNode;
				if(1u >= index)
				{
					node->next = list->firstNode;
					list->firstNode = node;
					auxNode->next = list->firstNode;
				}else
				{
					if(index > listNodes)
					{
						while(fstNode != auxNode->next)
						{
							auxNode = auxNode->next;
						}
						node->next = fstNode;
						auxNode->next = node;
					}else
					{
						for(nodeCtr = 2u; nodeCtr < index; nodeCtr++)
						{
							auxNode = auxNode->next;
						}
						node->next = auxNode->next;
						auxNode->next = node;
					}
				}
			}else
			{
				list->firstNode = node;
				auxNode = list->firstNode;
				auxNode->next = list->firstNode;
			}
		}else
		{
			/*Do nothing*/
		}
	}else
	{
		/*Do nothing*/
	}
}

static void delNodefromList (singleLinkedList* list, Node* node)
{
	Node* auxNode = NULL;
	unsigned int nodeCtr = 0u;
	unsigned int listNodes = getNodeListNumber(list);
	if(NULL != list)
	{
		if(NULL != node)
		{
			if(NULL != list->firstNode)
			{
				auxNode = list->firstNode;
				if(auxNode != node)
				{
					for(nodeCtr = 2;nodeCtr<=listNodes;nodeCtr++)
					{
						if(auxNode->next != node)
						{
							auxNode = auxNode->next;
						}else
						{
							auxNode->next = node->next;
							nodeCtr = listNodes + 1u;
						}
					}
				}else
				{
					list->firstNode = auxNode->next;
				}
				free(node);
			}else
			{
				/*Do nothing*/
			}
		}
		else
		{
			/*Do nothing*/
		}
	}else
	{
		/*Do nothing*/
	}
}


static void addDatatoNode (Node* node, Data* data)
{
	if(NULL != node)
	{
		node->nodeData = data;
	}else
	{
		/*Do nothing*/
	}
}
