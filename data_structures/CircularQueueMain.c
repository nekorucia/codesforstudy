#include <stdio.h>
#include "CircularQueue.h"
#include "CircularQueue.c"

int main(void)
{
    //Queue���� �� �ʱ�ȭ
    Queue q;
    QueueInit(&q);

    // ������ �ֱ�
    Enqueue(&q,1); Enqueue(&q,2);
    Enqueue(&q,3); Enqueue(&q,4);
    Enqueue(&q,5);

    // ������ ������
    while(!QIsEmpty(&q))
        printf("%d ",Dequeue(&q));

    printf("\n");

    printf("front: %d, rear:%d \n",q.front,q.rear);
    
    for(int i=0;i<10;i++)
        printf("%d ",q.queArr[i]);

    return 0;
}