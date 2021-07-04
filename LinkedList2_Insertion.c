#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head = NULL;

void createLinkedlist(int n);
void displayList();
int getLength();
void insertAtbeg();
void insertAtend();
void insertAtpos();

int main()
{
	int n ,insertion,choice=1;
	printf("Enter the number of nodes you want to insert: ");
	scanf("%d",&n);
	createLinkedlist(n);
	displayList();
	while(choice)
	{
		printf("\n Insertion Position --- \n 1- Insertion at Beginning. \n 2- Insertion at End. \n 3- Insertion at Specific position \n 4- Exit");
		printf("\n Choose from the above option: ");
		scanf("%d", &insertion);
		switch(insertion)
		{
			case 1 : insertAtbeg();
					 displayList();
			break;
			case 2 : insertAtend();
					 displayList();
			break;
			case 3 : insertAtpos();
				     displayList();
			break;
			default: exit(0);
		}
	}	
	return 0;
}

void createLinkedlist(int n)
{
	struct node *newnode, *temp;
	int i=0;
	head = 0;
	while(i<n)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter Data for Node %d: ",i+1);
		scanf("%d",&newnode->data);
		newnode->next = 0;
		if(head == 0) 
		{
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
		i++;
	}
}

void displayList()
{
	struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
		printf("\nLinked list: ");
		while(temp != 0)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
    }
}

int getLength()
{
	struct node *temp;
	int count = 1;
	temp = head;
	while(temp->next != 0)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void insertAtbeg()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&newnode->data);
	newnode->next = head;
	head = newnode;
}

void insertAtend()
{
	struct node *newnode, *temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&newnode->data);
	newnode->next = 0;
	temp=head;
	while(temp->next != 0)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}

void insertAtpos()
{   
	int c = getLength();
	struct node *newnode, *temp;
	int pos,i=1;	
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the position where you want to enter the data: ");
	scanf("%d",&pos);
	if(pos > c)
	{
		printf("Invalid position");
	}
	else
	{
		temp = head;
		while(i<pos-1)
		{
			temp = temp->next;
			i++;
		}
		printf("Enter data: ");
		scanf("%d",&newnode->data);
		newnode->next = temp->next;
		temp->next = newnode;
	}
}


