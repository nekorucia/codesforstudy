#include <stdio.h>
#include "ListBaseStack.h"
#include "ListBaseStack.c"

int main(void)
{
    //stack�������ʱ�ȭ//
    Stack stck;
    StackInit(&stck);

    //������ �ֱ�//
    SPush(&stck,1); SPush(&stck,2);
    SPush(&stck,3); SPush(&stck,4);
    SPush(&stck,5); SPush(&stck,6);

    //������ ������//
    while(!SIsEmpty(&stck))
        printf("%d ",SPop(&stck));

    return 0;
}