#ifndef _BINTREE_H_
#define _BINTREE_H_
#define DataType char
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;
typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;

void BinTreeInit(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);
BinTreeNode* _BinTreeCreate_2();
void BinTreeCreate(BinTree *t);
//BinTreeNode* _BinTreeCreateByStr(char *str, int *i);
//void BinTreeCreateByStr(BinTree *t, char *str, int *i);

//¶þ²æÊ÷±éÀú µÝ¹é
void _PreOrder(BinTreeNode *t);
void PreOrder(BinTree *t);
void _InOrder(BinTreeNode *t);
void InOrder(BinTree *t);
void _PostOrder(BinTreeNode *t);
void PostOrder(BinTree *t);
void _LevelOrder(BinTreeNode *t);
void LevelOrder(BinTree *t);

size_t _Height(BinTreeNode* t);
size_t Height(BinTree *t);


void BinTreeInit(BinTree *t)
{
	t->root = NULL;
}
void BinTreeCreate(BinTree *t)
{
	//_BinTreeCreate(&t->root);
	t->root = _BinTreeCreate_2();
}
void _BinTreeCreate_1(BinTreeNode **t)
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		_BinTreeCreate_1(&((*t)->leftChild));
		_BinTreeCreate_1(&((*t)->rightChild));
	}
}
BinTreeNode* _BinTreeCreate_2()
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
	{
		return NULL;
	}
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = _BinTreeCreate_2();
		t->rightChild = _BinTreeCreate_2();
		return t;
	}
}
BinTreeNode* _BinTreeCreateByStr(char *str, int *i)
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		t->data = str[*i];
		(*i)++;
		t->leftChild = _BinTreeCreateByStr(str, i);
		(*i)++;
		t->rightChild = _BinTreeCreateByStr(str, i);
		return t;
	}
}
void BinTreeCreateByStr(BinTree *t, char *str, int *i)
{
	t->root = _BinTreeCreateByStr(str, i);
}
//BinTreeNode* _BinTreeCreateByStr(char *str, int *i)
//{
//	if (str[*i] == '#' || str[*i] == '\0')
//		return NULL;
//	else
//	{
//		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		t->data = str[*i];
//		(*i)++;
//		t->leftChild = _BinTreeCreateByStr(str, i);
//		(*i)++;
//		t->rightChild = _BinTreeCreateByStr(str, i);
//		return t;
//	}
//}


void PreOrder(BinTree *t)
{
	_PreOrder(t->root);
}
void _PreOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		_PreOrder(t->leftChild);
		_PreOrder(t->rightChild);
	}
}
void InOrder(BinTree *t)
{
	_InOrder(t->root);
}
void _InOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		_InOrder(t->leftChild);
		printf("%c ", t->data);
		_InOrder(t->rightChild);
	}
}
void PostOrder(BinTree *t)
{
	_PostOrder(t->root);
}
void _PostOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		_PostOrder(t->leftChild);
		_PostOrder(t->rightChild);
		printf("%c ", t->data);
	}
}

size_t Height(BinTree *t)
{
	return _Height(t->root);
}
size_t _Height(BinTreeNode* t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = _Height(t->leftChild);
		int right_h = _Height(t->rightChild);
		return (left_h>right_h ? left_h : right_h) + 1;
	}
}

#endif