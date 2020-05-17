#include <stdio.h>
#include "BinaryTree.h"
#include "BinaryTree.c"

void Inorder(BTreeNode* bt)
{
    if(bt==NULL)
        return;
    
    Inorder(bt->left);
    printf("%d \n",bt->data);
    Inorder(bt->right);
}

int main(void)
{
    BTreeNode* bt1 = MakeBTreeNode();
    BTreeNode* bt2 = MakeBTreeNode();
    BTreeNode* bt3 = MakeBTreeNode();
    BTreeNode* bt4 = MakeBTreeNode();

    SetData(bt1,1);
    SetData(bt2,2);
    SetData(bt3,3);
    SetData(bt4,4);

    MakeLeftSubTree(bt1,bt2);
    MakeRightSubTree(bt1,bt3);
    MakeLeftSubTree(bt2,bt4);

    Inorder(bt1);
    return 0;
}