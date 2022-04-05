/*
 ============================================================================
 Name        : 002-c-singleLinkedList.c
 Author      : Carlos Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : Single Linked Listy, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*Linked list declaration*/
typedef struct
{
	void* firstNode; /*Holds the first list node*/
}singleLinkedList;

/*List Node declaration*/
typedef struct
{
	void* nodeData; /*Holds data stored in the node*/
	void* next;     /*Points to next node*/
}Node;

/*Single Linked List functions*/
static singleLinkedList* createList (void); /*Reserves memory for a new linked list*/
static Node* createNode (void);              /*Reserves memory for a new list node*/
static unsigned int getNodeListNumber (singleLinkedList* list); /*Return number of list nodes*/
static void addNodetoList (singleLinkedList* list, Node* node); /*Add a node to a single list*/

int main(void) {
	singleLinkedList* testList = NULL;
	Node* node1 = NULL;
	Node* node2 = NULL;
	Node* node3 = NULL;
	unsigned int nnodes = 0u;
	testList = createList();
	node1 = createNode();
	node2 = createNode();
	node3 = createNode();
	addNodetoList(testList,node1);
	addNodetoList(testList,node2);
	addNodetoList(testList,node3);
	nnodes = getNodeListNumber(testList);
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
	unsigned int nodeCtr = 0u;
	if(NULL != list)
	{
		if(NULL != list->firstNode)
		{
			nodeCtr = nodeCtr + 1u;
			auxNode = list->firstNode;
			while(NULL != auxNode->next)
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
	if(NULL != list)
	{
		if(NULL != node)
		{
			if(NULL != list->firstNode)
			{
				auxNode = list->firstNode;
				while(NULL != auxNode->next)
				{
					auxNode = auxNode->next;
				}
				auxNode->next = node;
			}else
			{
				list->firstNode = node;
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
