#define _CRT_SECURE_NO_WARNINGS 1
#include "bintree.h"
//
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
void BinTreeCreateByStr(BinTree *t, char *str, int *i)
{
	t->root = _BinTreeCreateByStr(str, i);
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

BinTreeNode* _BinTreeCreateBy_LVR_LRV(char *lvr, char *lrv, int n)
{
   
}
void BinTreeCreateBy_LVR_LRV(BinTree *t, char *lvr, char *lrv, int n)
{
	t->root = _BinTreeCreateBy_LVR_LRV(lvr, lrv, n);
}
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
//#include"queue.h"
//void LevelOrder(BinTree *t)
//{
//	_LevelOrder(t->root);
//}
//void _LevelOrder(BinTreeNode *t)
//{
//	if (t != NULL)
//	{
//		LinkQueue Q;
//		LinkQueueInit(&Q);
//		LinkQueueEn(&Q, t);
//		while (!LinkQueueEmpty(&Q))
//		{
//			BinTreeNode *p = LinkQueueFront(&Q);
//			LinkQueueDe(&Q);
//			printf("%c ", p->data);
//			if (p->leftChild != NULL)
//				LinkQueueEn(&Q, p->leftChild);
//			if (p->rightChild != NULL)
//				LinkQueueEn(&Q, p->rightChild);
//		}
//	}
//}
size_t Size(BinTree *t)
{
	return _Size(t->root);
}
size_t _Size(BinTreeNode* t)
{
	if (t == NULL)
		return 0;
	else
		return _Size(t->leftChild) + _Size(t->rightChild) + 1;
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
BinTreeNode* Find(BinTree *t, DataType key)
{
	return _Find(t->root, key);
}
BinTreeNode* _Find(BinTreeNode *t, DataType key)
{
	BinTreeNode *p;
	if (t == NULL)
		return NULL;
	if (t->data == key)
		return t;
	p = _Find(t->leftChild, key);
	if (p != NULL)
		return p;
	return _Find(t->rightChild, key);
}
BinTreeNode* Parent(BinTree *t, DataType key)
{
	return _Parent(t->root, key);
}
BinTreeNode* _Parent(BinTreeNode *t, DataType key)
{
	BinTreeNode *pr;
	BinTreeNode *p = _Find(t, key);
	if (t == NULL || p == NULL || p == t)
		return NULL;
	if (t->leftChild == p || t->rightChild == p)
		return t;
	pr = _Parent(t->leftChild, key);
	if (pr != NULL)
		return pr;
	return _Parent(t->rightChild, key);
}
void Clone(BinTree *t1, BinTree *t2)
{
	t2->root = _Clone(t1->root);
}
BinTreeNode* _Clone(BinTreeNode *t)
{
	if (t == NULL)
		return NULL;
	else
	{
		BinTreeNode *p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		p->data = t->data;
		p->leftChild = _Clone(t->leftChild);
		p->rightChild = _Clone(t->rightChild);
		return p;
	}
}
bool Equal(BinTree *t1, BinTree *t2)
{
	return _Equal(t1->root, t2->root);
}
bool _Equal(BinTreeNode *t1, BinTreeNode *t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	return (t1->data == t2->data)
		&& _Equal(t1->leftChild, t2->leftChild)
		&& _Equal(t1->rightChild, t2->rightChild);
}
//#include"stack.h"
//void PreOrderNoR(BinTree *t)
//{
//	_PreOrderNoR(t->root);
//}
//void _PreOrderNoR(BinTreeNode *t)
//{
//	if (t != NULL)
//	{
//		BinTreeNode *p;
//		ListStack st;
//		ListStackInit(&st);
//		ListStackPush(&st, t);
//		while (!ListStackEmpty(&st))
//		{
//			p = ListStackTop(&st);
//			ListStackPop(&st);
//			printf("%c ", p->data);
//			if (p->rightChild != NULL)
//				ListStackPush(&st, p->rightChild);
//			if (p->leftChild != NULL)
//				ListStackPush(&st, p->leftChild);
//		}
//	}
//}
//void _InOrderNoR(BinTreeNode *t);
//void InOrderNoR(BinTree *t);
//void _PostOrderNoR(BinTreeNode *t);
//void PostOrderNoR(BinTree *t);
/*
typedef BinTreeNode* BinTree;
void BinTreeInit(BinTree *t);
void BinTreeCreate_1(BinTree *t);
BinTreeNode* BinTreeCreate_2();
void BinTreeInit(BinTree *t)
{
*t = NULL;
}
void BinTreeCreate_1(BinTree *t)
{
DataType item;
scanf("%c", &item);
if(item == '#')
{
*t = NULL;
}
else
{
*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
assert(*t != NULL);
(*t)->data = item;
BinTreeCreate_1(&((*t)->leftChild));
BinTreeCreate_1(&((*t)->rightChild));
}
}
BinTreeNode* BinTreeCreate_2()
{
DataType item;
scanf("%c", &item);
if(item == '#')
{
return NULL;
}
else
{
BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
assert(t != NULL);
t->data = item;
t->leftChild = BinTreeCreate_2();
t->rightChild = BinTreeCreate_2();
return t;
}
}
*/