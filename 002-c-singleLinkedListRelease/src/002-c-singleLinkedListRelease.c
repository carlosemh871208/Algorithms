/*
 ============================================================================
 Name        : 002-c-singleLinkedListRelease.c
 Author      : Carlos Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : This is a generic single linked list Ansi-style.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* Boolean type declaration*/
typedef unsigned char boolean;
#define FALSE (boolean)0u
#define TRUE  (boolean)1u

/* List type declaration*/
/* This is a generic way to create a single linked list, void* can hold
 * different datatype memory addresses */
typedef struct
{
	void* node; /*Holds the memory address of the list first node*/
}SLList;

/* Node type declaration*/
/* This is a generic way to create a single linked list node, "void*" can hold
 * different datatype memory addresses */
typedef struct
{
	void* data; /*Holds the memory address of the node data*/
	void* next; /*Holds the memory address of the next node*/
}Node;

/*Single linked list status flags*/
/*Following flags helps to verifyu single linked list status*/
typedef enum
{
	UNKNOWN_ERROR      = (unsigned char) 0u,
	SUCCESS            = (unsigned char) 1u,
	NOT_SUCCESS        = (unsigned char) 2u,
	NODE_DUPLICATED    = (unsigned char) 3u,
	ERROR_NO_LIST      = (unsigned char) 4u,
	ERROR_NO_NODE      = (unsigned char) 5u,
	NO_BASE_NODE       = (unsigned char) 6u,
	LIST_EMPTY         = (unsigned char) 7u,
	SAME_NODE          = (unsigned char) 8
}SLLstatus;

/* Single linked list funcionalities declaration*/
/* This function reserves memory address that will hold single linked list*/
static SLList* createSLList (void);
/* This function reserves memory address that will hold a node*/
static Node* createNode (void);
/* This function adds a node to the list begin*/
static SLLstatus addNodetoListBegin (SLList* list,Node* node);
/* This function adds a node to the list end*/
static SLLstatus addNodetoListEnd (SLList* list, Node* node);
/* This function adds a node to the list after another node*/
static SLLstatus addNodetoListMiddle (SLList* list, Node* baseNode, Node* node);
/* This function checks if node already exist in the list*/
static boolean checkIfNodeExist (SLList* list, Node* node);
/* This function returns list number of nodes*/
static unsigned int getNumberOfListNodes (SLList* list);
/* This function return the previous node from parameter node*/
static Node* getPreviousNode (SLList* list, Node* node);
/* This function swap two nodes positions*/
static SLLstatus swapListNodes (SLList* node, Node* node1, Node* node2);


int main(void) {
	SLList* list1 = NULL;
	Node* node1 = NULL;
	Node* node2 = NULL;
	Node* node3 = NULL;
	Node* node4 = NULL;
	Node* node5 = NULL;
	SLLstatus listSts = UNKNOWN_ERROR;
	unsigned int nodes = 0u;
	list1 = createSLList ();
	node1 = createNode ();
	node2 = createNode ();
	node3 = createNode ();
	node4 = createNode ();
	node5 = createNode ();
	listSts = addNodetoListBegin (list1,node1);
	listSts = addNodetoListEnd (list1,node2);
	listSts = addNodetoListEnd (list1,node3);
	listSts = addNodetoListEnd (list1,node4);
	listSts = addNodetoListEnd (list1,node5);
	nodes = getNumberOfListNodes(list1);
	listSts = swapListNodes (list1,node3,node5);
 	listSts = swapListNodes (list1,node5,node3);
	return EXIT_SUCCESS;
}

/*Single linked list functionalties implementation*/
static SLList* createSLList (void)
{
	SLList* list = NULL;
	list = (SLList*)malloc(sizeof(SLList)); /*Allocates memory for the data type*/
	if(NULL != list) /*Check if memory was allocated for "list"*/
	{
		list->node = NULL;
	}else
	{
		/*Do nothing*/
	}
	return list;
}

static Node* createNode (void)
{
	Node* node = NULL;
	node = (Node*)malloc(sizeof(Node)); /*Allocates memory for the data type*/
	if(NULL != node) /*Check if memory was allocated for "NULL"*/
	{
		node->data = NULL;
		node->next = NULL;
	}else
	{
		/*Do nothing*/
	}
	return node;
}

static SLLstatus addNodetoListBegin (SLList* list,Node* node)
{
	SLLstatus listSts = UNKNOWN_ERROR;
	boolean nodeSts = FALSE;
	if(NULL != list)
	{
		if(NULL != node)
		{
			if(NULL != list->node)
			{
				nodeSts = checkIfNodeExist (list,node);
				if(TRUE != nodeSts)
				{
					node->next = list->node;
					list->node = node;
					listSts = SUCCESS;
				}
				else
				{
					listSts = NODE_DUPLICATED;
				}
			}
			else
			{
				list->node = node;
				listSts = SUCCESS;
			}
		}
		else
		{
			listSts = ERROR_NO_NODE;
		}
	}
	else
	{
		listSts = ERROR_NO_LIST;
	}
	return listSts;
}

static SLLstatus addNodetoListEnd (SLList* list, Node* node)
{
	Node* nodeAux = NULL;
	SLLstatus listSts = UNKNOWN_ERROR;
	boolean flagSts = FALSE;
	if(NULL != list)
	{
		nodeAux = list->node;
		if(NULL != node)
		{
			if(NULL != nodeAux)
			{
				for(;TRUE != flagSts;)
				{
					if(nodeAux != node)
					{
						if(NULL != nodeAux->next)
						{
							nodeAux = nodeAux->next;
						}else
						{
							nodeAux->next = node;
							listSts = SUCCESS;
							flagSts = TRUE;
						}
					}
					else
					{
						listSts = NODE_DUPLICATED;
						flagSts = TRUE;
					}
				}
			}
			else
			{
				list->node = node;
				listSts = SUCCESS;
			}
		}
		else
		{
			listSts = ERROR_NO_NODE;
		}
	}
	else
	{
		listSts = ERROR_NO_LIST;
	}
	return listSts;
}

static SLLstatus addNodetoListMiddle (SLList* list, Node* baseNode, Node* node)
{
	SLLstatus listSts = UNKNOWN_ERROR;
	if(NULL != list)
	{
		if(NULL != baseNode)
		{
			if(NULL != node)
			{
				if(NULL != list->node)
				{
					if(FALSE != checkIfNodeExist(list,baseNode))
					{
						if(TRUE != checkIfNodeExist(list,node))
						{
							node->next = baseNode->next;
							baseNode->next = node;
							listSts = SUCCESS;
						}else
						{
							listSts = NODE_DUPLICATED;
						}
					}else
					{
						listSts = NO_BASE_NODE;
					}
				}else
				{
					list->node = node;
					listSts = SUCCESS;
				}
			}else
			{
				listSts = ERROR_NO_NODE;
			}
		}else
		{
			listSts = ERROR_NO_NODE;
		}
	}else
	{
		listSts = ERROR_NO_LIST;
	}
	return listSts;
}

static boolean checkIfNodeExist (SLList* list, Node* node)
{
	Node* nodeAux = NULL;
	boolean flagSts = FALSE;
	boolean flagLoop = FALSE;
	if(NULL != list)
	{
		nodeAux = list->node;
		if(NULL != node)
		{
			if(NULL != nodeAux)
			{
				for(;TRUE != flagLoop;)
				{
					if(node != nodeAux)
					{
						if(NULL != nodeAux->next)
						{
							nodeAux = nodeAux->next;
						}else
						{
							flagLoop = TRUE;
							flagSts  = FALSE;
						}
					}else
					{
						flagLoop = TRUE;
						flagSts  = TRUE;
					}
				}
			}else
			{
				/*Do nothing*/
			}
		}else
		{
			/*Do nothing*/
		}
	}else
	{
		/*Do nothing*/
	}
	return flagSts;
}

static unsigned int getNumberOfListNodes (SLList* list)
{
	Node* nodeAux = NULL;
	unsigned int nodes = 0u;
	if(NULL != list)
	{
		nodeAux = list->node;
		if(NULL != nodeAux)
		{
			for(nodes=1u;NULL != nodeAux->next;nodes++)
			{
				nodeAux = nodeAux->next;
			}
		}else
		{
			/*Do nothing*/
		}
	}else
	{
		/*Do nothing*/
	}
	return nodes;
}

static Node* getPreviousNode (SLList* list, Node* node)
{
	Node* nodeAux = NULL;
	boolean nodeSts  = FALSE;
	boolean flagLoop = FALSE;
	if(NULL != list)
	{
		if(NULL != list->node)
		{
			if(NULL != node)
			{
				nodeSts = checkIfNodeExist(list,node);
				if(FALSE != nodeSts)
				{
					if(node != list->node)
					{
						nodeAux = list->node;
						for(;TRUE != flagLoop;)
						{
							if(node != nodeAux->next)
							{
								nodeAux = nodeAux->next;
							}else
							{
								flagLoop = TRUE;
							}
						}
					}else
					{
						nodeAux = list->node;
					}
				}else
				{
					/*do nothing*/
				}
			}else
			{
				/*Do nothing*/
			}
		}else
		{
			/*Do nothing*/
		}
	}else
	{
		/*Do nothing*/
	}
	return nodeAux;
}

static SLLstatus swapListNodes (SLList* list, Node* node1, Node* node2)
{
	Node* nodeAux   = NULL;
	Node* nodeAux1  = NULL;
	Node* nodeNxt   = NULL;
	Node* nodeNxt1  = NULL;
	SLLstatus listSts = UNKNOWN_ERROR;
	boolean nodeSts = FALSE;
	if(NULL != list)
	{
		if(NULL != list->node)
		{
			if(NULL != node1)
			{
				if(NULL != node2)
				{
					nodeSts = checkIfNodeExist(list,node1);
					if(FALSE != nodeSts)
					{
						nodeSts = checkIfNodeExist(list,node2);
						if(FALSE != nodeSts)
						{
							if(node1 != node2)
							{
								if(node1 != list->node)
								{
									if(node2 != list->node)
									{
										if(node2 != node1->next)
										{
											if(node1 != node2->next)
											{
												nodeAux = getPreviousNode(list,node1);
												nodeAux1 = getPreviousNode(list,node2);
												nodeNxt = node1->next;
												nodeNxt1 = node2->next;
												nodeAux->next = node2;
												nodeAux1->next = node1;
												node1->next = nodeNxt1;
												node2->next = nodeNxt;
												listSts = SUCCESS;
											}else
											{
												nodeAux = getPreviousNode(list,node2);
												nodeNxt = node1->next;
												nodeAux->next = node1;
												node2->next = nodeNxt;
												node1->next = node2;
												listSts = SUCCESS;
											}
										}else
										{
											nodeAux = getPreviousNode(list,node1);
											nodeNxt1 = node2->next;
											nodeAux->next = node2;
											node1->next = nodeNxt1;
											node2->next = node1;
											listSts = SUCCESS;
										}

									}else
									{
										nodeAux = list->node;
										nodeAux->next = node1->next;
										node1->next = node2;
										list->node = node1;
										listSts = SUCCESS;
									}
								}else
								{
									nodeAux = list->node;
									nodeAux->next = node2->next;
									node2->next = node1;
									list->node = node2;
									listSts = SUCCESS;
								}
							}else
							{
								listSts = SAME_NODE;
							}
						}else
						{
							listSts = ERROR_NO_NODE;
						}
					}else
					{
						listSts = ERROR_NO_NODE;
					}
				}else
				{
					listSts = ERROR_NO_NODE;
				}
			}else
			{
				listSts = ERROR_NO_NODE;
			}
		}else
		{
			listSts = LIST_EMPTY;
		}
	}else
	{
		listSts = ERROR_NO_LIST;
	}
	return listSts;
}
