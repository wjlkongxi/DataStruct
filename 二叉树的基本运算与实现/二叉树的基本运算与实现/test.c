#define _CRT_SECURE_NO_WARNINGS 1
#include"bintree.h"
int main()
{
	char *str = "ABC##DE##F##G#H##";
	//char *str1 = "ABC##D#F##GE##H##";
	/*char *vlr = "ABCDEFGH";
	char *lvr = "CBEDFAGH";
	char *lrv = "CEFDBHGA";
	int n = strlen(lvr);*/
	int i = 0, j = 0;
	BinTree bt, bt1;
	BinTreeInit(&bt);
	BinTreeInit(&bt1);
	/*BinTreeCreate(&bt);*/
	BinTreeCreateByStr(&bt, str, &i);
	//BinTreeCreateByStr(&bt1, str1, &j);
	//BinTreeCreateBy_VLR_LVR(&bt, vlr, lvr, n);
	
	printf("VLR   :");
	PreOrder(&bt);
	printf("\n");
	/*printf("VLR NR:");
	PreOrderNoR(&bt);
	printf("\n");*/
	printf("\n");
	printf("LVR   :");
	InOrder(&bt);
	printf("\n");
	/*printf("LVR NR:");
	InOrderNoR(&bt);
	printf("\n");*/
	printf("\n");
	printf("LRV   :");
	PostOrder(&bt);
	printf("\n");
	/*printf("LRV NR:");
	PostOrderNoR(&bt);
	printf("\n");*/
	/*printf("\n");
	printf("Level:");
	LevelOrder(&bt);
	printf("\n");*/
	/*printf("Size = %d\n", Size(&bt));*/
	printf("Hegith = %d\n", Height(&bt));
	//BinTreeNode *p = Find(&bt, 'B');
	//p = Parent(&bt, 'H');
	//
	return 0;
}