#ifndef _BINTREE_H_
#define _BINTREE_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
typedef enum { FALSE, TRUE }BOOL;
#define DataType char
////ABC##DE##F##G#H##
//typedef struct BinTreeNode//二叉树结点
//{
//	DataType data;
//	struct BinTreeNode *leftChild;
//	struct BinTreeNode *rightChild;
//}BinTreeNode;
//typedef struct BinTree
//{
//	BinTreeNode *root;
//}BinTree;
//ABC##DE##F##G#H##
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
//二叉树创建
void BinTreeInit(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);
BinTreeNode* _BinTreeCreate_2();
void BinTreeCreate(BinTree *t);
BinTreeNode* _BinTreeCreateByStr(char *str, int *i);
void BinTreeCreateByStr(BinTree *t, char *str, int *i);
//二叉树遍历 递归
void _PreOrder(BinTreeNode *t);
void PreOrder(BinTree *t);
void _InOrder(BinTreeNode *t);
void InOrder(BinTree *t);
void _PostOrder(BinTreeNode *t);
void PostOrder(BinTree *t);
void _LevelOrder(BinTreeNode *t);
void LevelOrder(BinTree *t);
//二叉树遍历 非递归
void _PreOrderNoR(BinTreeNode *t);
void PreOrderNoR(BinTree *t);
void _InOrderNoR(BinTreeNode *t);
void InOrderNoR(BinTree *t);
void _PostOrderNoR(BinTreeNode *t);
void PostOrderNoR(BinTree *t);
//二叉树实现
size_t _Size(BinTreeNode* t);
size_t Size(BinTree *t);
size_t _Height(BinTreeNode* t);
size_t Height(BinTree *t);
BinTreeNode* _Find(BinTreeNode *t, DataType key);
BinTreeNode* Find(BinTree *t, DataType key);
BinTreeNode* _Parent(BinTreeNode *t, DataType key);
BinTreeNode* Parent(BinTree *t, DataType key);
BinTreeNode* _Clone(BinTreeNode *t);
void Clone(BinTree *t1, BinTree *t2);
bool _Equal(BinTreeNode *t1, BinTreeNode *t2);// true false
bool Equal(BinTree *t1, BinTree *t2);// true false
void BinTreeInit(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);
BinTreeNode* _BinTreeCreate_2();
void BinTreeCreate(BinTree *t);
void _PreOrder(BinTreeNode *t);
void PreOrder(BinTree *t);
void _InOrder(BinTreeNode *t);
void InOrder(BinTree *t);
void _PostOrder(BinTreeNode *t);
void PostOrder(BinTree *t);
void BinTreeCreateBy_LVR_LRV(char *lvr, char *lrv, int n);

#endif
