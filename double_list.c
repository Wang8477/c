#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

struct node* GetNewNode(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}
void InsertAtHead(int x)
{
    struct node *temp = GetNewNode(x);
    if(head != NULL)
    {
        temp->next = head;
        head->prev = temp;     //这两行顺序可变  
    }
    head = temp;
}
void Print()
{
    struct node *temp = head;
	printf("List is:");
	while(temp != NULL)
	{
		printf("%d  ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void ReversePrint()
{
    struct node *temp = head;
    if(temp == NULL) return;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
    printf("Reverse list is:");
    while(temp != NULL)
    {
        printf("%d  ",temp->data);
        temp = temp->prev;
    }
	printf("\n");
}
int main()
{
    head = NULL;
    InsertAtHead(2);Print();ReversePrint();
    InsertAtHead(4);Print();ReversePrint();
    InsertAtHead(6);Print();ReversePrint();
    return 0;
}