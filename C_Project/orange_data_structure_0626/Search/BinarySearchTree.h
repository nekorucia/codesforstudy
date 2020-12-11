#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

typedef BTData BSTData;

// BST�� ���� �� �ʱ�ȭ
void BSTMakeAndNodeData(BTreeNode** pRoot);

//��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst);

// BST ������ ���� (��� ������)
void BSTInsert(BTreeNode** pRoot, BSTData data);

// BST ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

#endif