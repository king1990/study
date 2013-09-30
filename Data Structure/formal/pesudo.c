#include <stdlib.h>
#include "Pesudo.h"

int gepseudoValue_same(int lenght){
	
	int i;
	printf("(randmax in system = %d)\n",RAND_MAX);
	for (i = 0; i < lenght; i++){
		printf("%d ",rand());
	}
	printf("\n");	
//------------test if srand(1) equals to rand()-------
	srand(1);
	for (i = 0; i < lenght; i++){
		printf("%d ",rand());
	}
	printf("\n");
}

int gepseudoValue_diff(int lenght){
	
	int i;
	srand(time(NULL));
	for (i = 0; i < lenght; i++){
		printf("%d ",rand());
	}
	printf("\n");
}