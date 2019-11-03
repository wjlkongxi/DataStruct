#define _CRT_SECURE_NO_WARNINGS 1
#include"bintree.h"
int main()
{
	char *str = "ABC##DE##f##G#H##";
	BinTree bt;
	BinTreeInit(&bt);
	//BinTreeCreate(&bt);
	BinTreeCreate(&bt, str);
	printf("VLR:");
	PreOrder(&bt);
	printf("\n");
	printf("LVR:");
	InOrder(&bt);
	printf("\n");
	printf("LRV:");
	PostOrder(&bt);
	printf("\n");
	return 0;
}
