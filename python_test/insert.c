#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/time.h>
typedef struct information
{
  int data;
  struct information *next;
} *S;
//得到一组随机数
S get_rand(int m,int t)
{
        S head=NULL,p=NULL,a;
        int i=0;
	int data;
	for (i = 0; i < m; i++)
	    {
		data=rand()%t+1;
	        a = (S)malloc(sizeof(struct information));
	        a->data = data;
	        a->next = NULL;
	        if (i == 0)
	        {
	            head = a;
	        }
	        else
	        {
	            p->next = a;
	        }
	        p = a;
	    }
		free(a);
  

	return head;
}

S LinkInsertSort(S head)
{
    //current指向当前待插入的结点。
    S head2, current, p, q;

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

int PrintLink(S head)
{
    S p;
    for (p = head; p ;p = p->next)
    {
        printf("%d ", p->data);
    }
    return 0;
}


int main()
{
	S head;
	int m,n;
	struct timeval start, end;

	printf("please input you need how many numbers:");
	scanf("%d",&m);
	printf("please input rand number range:");
	scanf("%d",&n);
	
	head=get_rand(m,n);
	printf("sort before is:");
	PrintLink(head);
	printf("\n");

	gettimeofday( &start, NULL );
	head = LinkInsertSort(head);
	gettimeofday( &end, NULL );
	int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
	printf("sort after is:");
	PrintLink(head);
	printf("\n");
	printf("time: %d us\n", timeuse);
	
	return 0;
}
