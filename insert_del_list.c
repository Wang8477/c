//学习数据结构第二天
//链表的插入与删除
#include <stdio.h>
#include <stdlib.h>

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
    for(int i=0;i<=x-2;i++)
    {
        temp2 = temp2->next;                //找到第x-1个节点
    }                         
    temp->next = temp2->next;                    //插入节点地址
    temp2->next = temp;                           //更换第x-1个节点保存的地址
}


void delete(node** pointohead,int x)      //删除第x个节点
{
    for(int i=0;i<=x-2;i++)
    {
        *pointohead = (*pointohead)->next;   //找到第x-1个节点
    }
    node *temp = (*pointohead)->next;        //保存第x个节点
    (*pointohead)->next = temp->next;        //更换第x-1个节点保存的地址
    free(temp);
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


int main()
{
    node *head = NULL;
    insert(&head,1,1);
    Print(head);    //1
    insert(&head,1,2);
    Print(head);    //1 2
    insert(&head,1,3);
    Print(head);    //1 2 3
    insert(&head,2,4);
    Print(head);    //1 4 2 3
    delete(&head,1);
    Print(head);    //4 2 3
    return 0;
}