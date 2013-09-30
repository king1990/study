#ifndef __HUFFMANTREE_H
#define __HUFFMANTREE_H

#include <string.h>
#include <stdlib.h>
	
typedef struct htnode{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char ** HuffmanCode;

void HuffmanCode(HuffmanTree ht, HuffmanCode hc, int *w, int n);

#endif