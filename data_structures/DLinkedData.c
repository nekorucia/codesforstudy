#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next;
} Node;

int main(void)
{
    Node* head = NULL;
    Node* tail = NULL;
    Node* cur = NULL;

    Node* newnode = NULL;
    int readData;

    // ������ �Է� ����

    head=(Node*)malloc(sizeof(Node));
    tail=head;

    while(1)
    {
        printf("�ڿ��� �Է� : ");
        scanf("%d",&readData);
        if(readData<1)
            break;

        // ��� �߰�����
        newnode = (Node*)malloc(sizeof(Node));
        newnode->data=readData;
        newnode->next=NULL;
        /*
        if(head==NULL)
        {
            head=newnode;
        }
        else 
        {
            tail->next=head;
        }
        */
        tail->next=newnode;

        tail=newnode;
    }
    printf("\n");

    //�Է¹��� �������� ��°���
    printf("�Է¹��� ������ ��ü��� \n");
    if(head==NULL)
        printf("����� ������ ���� \n");
    else 
    {
        cur = head;
        //printf("%d ",cur->data);

        while(cur->next!=NULL)
        {
            cur=cur->next;
            printf("%d ",cur->data);
        }
    }
    printf("\n");

    //�޸� ��������
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        Node* delNode = head;
        Node* delNextNode = head->next;

        //printf("%d�� �����մϴ� \n",head->data);
        //free(delNode);

        while(delNextNode!=NULL)
        {
            delNode=delNextNode;
            delNextNode=delNextNode->next;

            printf("%d�� �����մϴ�\n",delNode->data);
            free(delNode);
        }
    }
    
    return 0;
}
