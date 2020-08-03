#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next;
} Node;

int main(void)
{
    Node* head=NULL;
    Node* tail=NULL;
    Node* cur=NULL;

    Node* newNode = NULL;
    int readData;

    //������ �Է�//
    while(1)
    {
        printf("�ڿ��� �Է� : ");
        scanf("%d",&readData);
        if(readData<1)
            break;
        
        //��� �߰�//
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next=NULL;

        if(head==NULL)
            head=newNode;
        else 
            tail->next=newNode;
        
        tail=newNode; // ������ ���� ����Ʈ�� ���� ����Ŵ 
    }
    printf("\n");

    //������ ���//
    if(head==NULL)
        printf("����� ������ ����\n");
    else 
    {
        cur=head;
        printf("%d ",cur->data);

        while(cur->next)
        {
            cur=cur->next;
            printf("%d ",cur->data);
        }
    }
    printf("\n\n");

    //�޸� ��ü//
    if(head==NULL)
    {
        printf("��ü�� ��� ����\n");
        return 0;
    }
    else
    {
        Node * delNode = head;
        Node * delNextNode = head->next;

        printf("%d ���� \n",head->data);
        free(delNode);

        while(delNextNode)
        {
            delNode=delNextNode;
            delNextNode=delNextNode->next;

            printf("%d ���� \n",delNode->data);
            free(delNode);
        }
    }
    
    return 0;
}