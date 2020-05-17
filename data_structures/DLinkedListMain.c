#include <stdio.h>
#include "DLinkedList.h"
#include "DLinkedList.c"

int main(void)
{
    //����Ʈ ���� �� �ʱ�ȭ
    List list;
    int data;
    ListInit(&list);

    LInsert(&list,11); LInsert(&list,11);
    LInsert(&list,33); LInsert(&list,33);
    LInsert(&list,55); 

    //����� ������ ��ü ���
    printf("���� �������� �� : %d \n",LCount(&list));

    if(LFirst(&list,&data))
    {   
        printf("%d ",data);

        while(LNext(&list,&data))
            printf("%d ",data);
    }
    printf("\n\n");

    // ���� 33 ��� ���� 
    if(LFirst(&list,&data))
    {
        if(data==33)
            LRemove(&list);

        while(LNext(&list,&data))
        {
            if(data==33)
                LRemove(&list);
        }
    }

    //���� �� ������ ���
    printf("���� �������� �� : %d \n",LCount(&list));

    if(LFirst(&list,&data))
    {
        printf("%d ",data);

        while(LNext(&list,&data))
            printf("%d ",data);
    }
    printf("\n\n");
    return 0;
}