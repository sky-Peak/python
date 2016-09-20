/*
 * 链表插入排序，由小到大
 */
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TOTAL 10        //链表长度

//链表的存储表示
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//LinkList CreatLink(int num);
//LinkList LinkInsertSort(LinkList head);
//int PrintLink(LinkList head);

/*
 * 创建链表。
 * 形参num为链表的长度，函数返回链表的头指针。
 */
LinkList CreatLink(int num)
{
    int i, data;

    //p指向当前链表中最后一个结点，q指向准备插入的结点。
    LinkList head = NULL, p = NULL, q;

    for (i = 0; i < num; i++)
    {
        data=rand()%50+1;
	//scanf("%d", &data);
        q = (LinkList)malloc(sizeof(LNode));
        q->data = data;
        q->next = NULL;
        if (i == 0)
        {
            head = q;
        }
        else
        {
            p->next = q;
        }
        //p = q;
    }
    return head;
}

/*
 * 链表插入排序(由小到大)。
 * 输入：链表的头指针，
 * 输出：排序后链表的头指针。
 * 实现方法：将原链表拆成两部分：链表1仍以head为头指针，链表结点有序。链表2以head2为头指针，链表结点无序。
 * 将链表2中的结点依次插入到链表1中，并保持链表1有序。
 * 最后链表1中包含所有结点，且有序。
 */
LinkList LinkInsertSort(LinkList head)
{
    //current指向当前待插入的结点。
    LinkList head2, current, p, q;

    if (head == NULL)
        return head;

    //第一次拆分。
    head2 = head->next;
    head->next = NULL;

    while (head2)
    {
        current = head2;
        head2 = head2->next;

        //寻找插入位置，插入位置为结点p和q中间。
        for (p = NULL, q = head; q && q->data <= current->data; p = q, q = q->next);

        if (q == head)
        {
            //将current插入最前面。
            head = current;
        }
        else
        {
            p->next = current;
        }
        current->next = q;
    }
    return head;
}

/*
 * 输出链表结点值。
 */
int PrintLink(LinkList head)
{
    LinkList p;
    for (p = head; p ;p = p->next)
    {
        printf("%-3d ", p->data);
    }
    return 0;
}

int main()
{
    LinkList head;

    printf("输入Total个数以创建链表：\n");
    head = CreatLink(TOTAL);
    
    head = LinkInsertSort(head);
    printf("排序后：\n");
    PrintLink(head);
    putchar('\n');
    return 0;
}
