#include <stdio.h>
#include "ArrayList.h"
#include "ArrayList.c"

int main(void)
{
    //ArrayList�� ������ �ʱ�ȭ//
    List list;
    int data;
    ListInit(&list);

    //5���� ������ ����//
    LInsert(&list, 11); LInsert(&list, 22); 
    LInsert(&list, 44); LInsert(&list, 55); 
    LInsert(&list, 33); 

    //����� �������� ��ü ���//
    printf("���� �������� �� : %d \n",LCount(&list));

    if(LFirst(&list,&data));
    {
        printf("%d ",data);
        
        while(LNext(&list,&data))
            printf("%d ",data);
    }
    printf("\n\n");

    //���� 22 Ž���� ����//
    
    if(LFirst(&list,&data))
    {
        if(data==22)
            LRemove(&list);

            while(LNext(&list,&data))
                {
                    if(data==22)
                        LRemove(&list);
                }
    }

    //���� �� ���� ������ ��ü ���//
    printf("�������� �� : %d \n",LCount(&list));

    if(LFirst(&list,&data))
    {
        printf("%d ",data);

        while(LNext(&list,&data))
            printf("%d ",data);
    }
    printf("\n\n");
    return 0;
}
