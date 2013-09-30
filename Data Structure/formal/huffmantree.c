#include "huffmantree.h"

staic void Select(HuffmanTree ht, int position, int* sn1, int* sn2){
	int i;
	int index[2];
	for (i = 1; i<= position; i++){
		if (ht[i] 
	}
}

void HuffmanCode(HuffmanTree ht, HuffmanCode hc, int *w, int n){
	
	HTNode* p;
	int i;
	char *cd;	
	if (n <= 1){
		return;
	}
	m = 2*n - 1;
	ht = (HuffmanTree)malloc((m+1)*sizeof(HTNode))//0号单元未用
	for (p = ht+1,i = 1; i <= n; i++, p++, w++){
		p->weight = *w;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for (; i <= m; i++){
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;		
	}
	for (i = n+1; i<= m; i++){
		//在[1...i-1]中选择parent为0且weight最小的两个结点 
		Select(ht, i-1, sn1, sn2);
		ht[sn1].parent = i;
		ht[sn2].parent = i;
		ht[i].lchild = sn1;
		ht[i].rchild = sn2;
		ht[i].weight = ht[sn1].weight + ht[sn2].weight;
	}
	//从叶子到根逆向求每个字符的哈夫曼编码
	hc = (HuffmanCode)malloc((n+1)*sizeof(char));
	cd = (char *)malloc(n*sizeof(char));
	cd[n-1] = '\0';
	for (i = 1; i <= n; i++){
		int start = n - 1;
		int c,f;
		for (c = i, f = ht[i].parent; f != 0; c = f, f = ht[f].parent){
			if (ht[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
		}
		hc[i] = (char *)malloc(sizeof(char)*(n-start));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
}