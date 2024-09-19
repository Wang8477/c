#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void insert(node** pointohead,int x,int data)   //在第x个节点插入
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;                          //插入节点数据
    temp->next = NULL;
    if(x==1)
    {
        temp->next = *pointohead;
        *pointohead = temp;
        return;
    }
    node *temp2 = *pointohead; //保存头节点地址(不保存head会丢失,插入的节变为第一个)
    for(int i=0;i<x-2;i++)                 //i<x-2是因为要找到第x-1个节点
    {
        temp2 = temp2->next;                //找到第x-1个节点
    }                         
    temp->next = temp2->next;                    //插入节点地址
    temp2->next = temp;                           //更换第x-1个节点保存的地址
}


void Reverse(node** pointohead)
{
    node *current,*prev,*next;
    current = *pointohead;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *pointohead = prev;
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
//递归
void Reverse_s(node** pointohaead)
{
    node *first,*rest;
    if(*pointohaead == NULL)return;
    first = *pointohaead;
    rest = first->next;
    if(rest == NULL)return;
    Reverse_s(&rest);
    first->next->next = first;
    first->next = NULL;
    *pointohaead = rest;
}
/*   //head是全局变量
node *head = NULL;
void Reverse__s(node* p)
{
    if(p->next == NULL)
    {
        head=p;
        return;
    }
    Reverse__s(p->next);
    p->next->next = p;
    //node q = p->next;
    //q->next = p;
    p->next = NULL;
}
*/
void Print_s(node *head)
{
    if(head == NULL)return;
    printf("%d  ",head->data);
    Print_s(head->next);
}
void ReversePrint(node *head)     //递归后输出,反向输出
{
    if(head == NULL)return;
    ReversePrint(head->next);
    printf("%d  ",head->data);
}
int main()
{
    node *head = NULL;
    insert(&head,1,1);
    insert(&head,1,2);
    insert(&head,1,3); //3 2 1
    insert(&head,2,4); //3 4 2 1
    Reverse_s(&head);
    Print_s(head);
}