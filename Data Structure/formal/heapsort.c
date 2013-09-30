#include "AllHead.h"
#include "heapSort.h"

void adjustHeap(int *sqlist, int node, int lenght){
	
	int largest = node;
	int left = 2*node;
	int right = 2*node+1;
	
	if (lenght == 0){
		return;
	}
	if ((left <= lenght) && (sqlist[node] < sqlist[left])){
		largest = left;
	}
	if ((right <= lenght) && (sqlist[largest] < sqlist[right])){
		largest = right;
	}
	if (largest != node){
		sqlist[0] = sqlist[node];
		sqlist[node] = sqlist[largest];
		sqlist[largest] = sqlist[0];
		adjustHeap(sqlist, largest, lenght);
	}
	
}

void buildHeap(int *sqlist, int lenght){
	int i;
	for (i = lenght/2; i >= 1; i--){
		int largest = i;
		int left = 2*i;
		int right = 2*i+1;
		if ((left <= lenght) && (sqlist[i] < sqlist[left])){
			largest = left;
		}
		if ((right <= lenght) && (sqlist[i] < sqlist[right])){
			largest = right;
		}
		if (largest != i){
			sqlist[0] = sqlist[i];
			sqlist[i] = sqlist[largest];
			sqlist[largest] = sqlist[0];
		}
	}
}

void heapSort(int *sqlist, int lenght){

	int i;
	for (i = lenght; i >= 1; i--){
		int temp;
		temp = sqlist[1];
		sqlist[1] = sqlist[i];
		sqlist[i] = temp;
		adjustHeap(sqlist, 1, i-1);
		printf("%d,",sqlist[i]);
	}
	printf("\n");	
}
