#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
		int data;
		struct node *next;
} Node;

//Creating head a as a global Node*
Node *head;

/* Given a node prev_node, insert a new node after the given  
   prev_node */
void insertAfter( Node* prev_node, int new_data) 
{ 
		/*1. check if the given prev_node is NULL */
		if (prev_node == NULL) 
		{ 
				printf("the given previous node cannot be NULL"); 
				return; 
		} 

		/* 2. allocate new node */
		Node* new_node =( Node*) malloc(sizeof(Node)); 

		/* 3. put in the data  */
		new_node->data  = new_data; 

		/* 4. Make next of new node as next of prev_node */
		new_node->next = prev_node->next; 

		/* 5. move the next of prev_node as new_node */
		prev_node->next = new_node; 
} 


// Given an int, appends a new node at the end  
void append(int new_data) 
{ 
		/* allocate node */
		Node* new_node = (Node*) malloc(sizeof( Node)); 

		Node *last = head; 

		/* put in the data  */
		new_node->data  = new_data; 

		/* This new node is going to be the last node, so make next of it as NULL */
		new_node->next = NULL; 

		/* If the Linked List is empty, then make the new node as head */
		if (head == NULL) 
		{ 
				head = new_node; 
				return; 
		} 

		/*  Else traverse till the last node */
		while (last->next != NULL) 
				last = last->next; 

		/* Change the next of last node */
		last->next = new_node; 
		return; 
} 

/* Given an int, inserts a new node on the front of the list. */
void push(int new_data) 
{ 
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->data=new_data;
	if(head == NULL)
	{
		new_node->next=NULL;
	}
	else
	{
		new_node->next=head;
	}
	head=new_node;
	return;
}  


// This function prints contents of linked list starting from head 
void printList() 
{ 
		Node* node;
		node = head;
		while (node != NULL) 
		{ 
				printf(" %d ", node->data); 
				node = node->next; 
		}
		printf("\n"); 

} 

// This function deletes the first occurance of num in the linked list starting from head
// Delete function returns 1 if the num is in the list and deleted othewise returns  0
int delete(int num)
{
	int onList=0;
	Node *curr = head;
	Node *prev = NULL;
	while (curr != NULL)
	{
		if (curr->data ==num)
		{
		onList=1;
		break;
		}
	prev = curr;
	curr = curr->next;
	}
	if (onList==1)
	{
		if(prev)
		{
			prev->next=curr->next;
		}
		else
		{
			head =curr->next;
		}
		free(curr);
		return 1;
	}
		return 0;
}


// This function counts the number of elements in the linked list and returns the count   
int count()
{
		struct node* temporary = head;
		int count = 0;
		while (temporary != NULL)
			{
			temporary = temporary->next;
			count++;
			}
			//Implement count
		return count;
}

void Exit()
{
	Node *curr=head;
	Node *prev=NULL;

	if(curr==NULL)
	{
		return;
	}
	while(curr != NULL)
	{
		prev = curr;
		curr=curr->next;
		free(prev);
	}
}

int  main()
{
		int i,num;
		Node *n;
		head=NULL;
		while(1)
		{
				printf("\nList Operations\n");
				printf("===============\n");
				printf("1.Append\n");
				printf("2.Push\n");
				printf("3.Display\n");
				printf("4.Size\n");
				printf("5.Delete\n");
				printf("6.Exit\n");
				printf("Enter your choice : ");
				if(scanf("%d",&i)<=0){
						printf("Enter only an Integer\n");
						exit(0);
				} else {
						switch(i)
						{
								case 1:  printf("Enter the number to append : ");
										 scanf("%d",&num);
										 append(num);
										 break;

								case 2:  printf("Enter the number to push : ");
										 scanf("%d",&num);
										 push(num);
										 break;

								case 3: if(head==NULL)
										{
												printf("List is Empty\n");
										}
										else
										{
												printf("Element(s) in the list are : ");
												printList();
										}
										break;

								case 4: printf("Size of the list is %d\n",count());
										break;

								case 5: if(head==NULL)
												printf("List is Empty\n");
										else{
												printf("Enter the number to delete : ");
												scanf("%d",&num);
												if(delete(num))
														printf("%d deleted successfully\n",num);
												else
														printf("%d not found in the list\n",num);
										}
										break;

								case 6: Exit();    
								return 0;

								default:    printf("Invalid option\n");
						}
				}
		}
		return 0;
}

