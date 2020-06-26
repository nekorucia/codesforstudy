#include <stdio.h>
#include <stdlib.h>

typedef int LData;

typedef struct _node
{
    LData data;
    struct _node* next;
} Node;

typedef struct _linkedList
{
    Node* head;
    Node* cur;
    Node* before;
    int numofData;
    int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));

void ListInit(List* plist)
{
    plist->head=(Node*)malloc(sizeof(Node));
    plist->head->next=NULL;
    plist->comp=NULL;
    plist->numofData=0;
}

void LInsert(List* plist, LData data)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    
}