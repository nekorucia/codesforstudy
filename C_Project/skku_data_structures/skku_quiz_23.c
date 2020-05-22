#include <stdio.h>
#include <stdlib.h>

/* Base data structure */
typedef struct listNode* listPointer;
typedef struct listNode
{
    int data;
    listPointer link;
};

/*�־��� ����Ʈ�� ī���ϰ� ����� ��ȯ*/

listPointer invertedCopyList(listPointer ptr)
{
    listPointer copy_ptr, middle, trail, copy_start;
    copy_ptr=(listPointer)malloc(sizeof(*ptr));

    copy_ptr->data=ptr->data;
    copy_start=copy_ptr;

    while(ptr->link)
    {
        copy_ptr->data=ptr->data;
        ptr=ptr->link;
        copy_ptr=copy_ptr->link;
    } // ���� �ڵ� 

    copy_ptr=copy_start;

    middle=NULL;
    while(copy_ptr)
    {
        trail=middle;
        middle=copy_ptr;
        copy_ptr=copy_ptr->link;
        middle->link=trail;
    }

    return middle; // ����� ��ȯ �ڵ� 
    free(copy_ptr);
}

