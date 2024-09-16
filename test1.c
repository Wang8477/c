//学习数据结构第一天
//链表的创建和遍历
#include <stdio.h>
#include <stdlib.h>
#define mode 1      //0:全局变量 1:传参 2:传指针

typedef struct node
{
	int data;
	struct node *next;
}node;

#if mode==0
struct node *head = NULL;
void insert(int data)  //头插法
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = head; 
	head = temp;
}

void Print()
{
	printf("List is:");
	struct node *temp = head;
	while(temp != NULL)
	{
		printf("%d  ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
#elif mode==1
node* insert(int data,node *head)   	//从函数返回指针
{
	node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = head; 
	head = temp;
	return head;
}

void Print(node *head)
{
	printf("List is:");
	while(head != NULL)
	{
		printf("%d  ",head->data);
		head = head->next;
	}
	printf("\n");
}
#else
void insert(int data,node ** pointertohead)    //传递指针给函数
{
	node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = *pointertohead; 
	*pointertohead = temp;
}

void Print(node *head)
{
	printf("List is:");
	while(head != NULL)
	{
		printf("%d  ",head->data);
		head = head->next;
	}
	printf("\n");
}

#endif
int main()
{
#if mode==0
	insert(2);
	Print();
	insert(3);
	Print();
	insert(5);
	Print();
	insert(6);
	Print();

#elif mode==1
	node *head = NULL;
	head=insert(2,head);    //head的值变为新插入的节点的地址
	Print(head);
	head=insert(3,head);
	Print(head);
	head=insert(9,head);
	Print(head);
	head=insert(6,head);
	Print(head);

#else
	node *head = NULL;
	insert(2,&head);
	Print(head);
	insert(3,&head);
	Print(head);
	insert(5,&head);
	Print(head);
	insert(6,&head);
	Print(head);

#endif

	return 0;
}
