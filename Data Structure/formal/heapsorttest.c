#include "Pesudo.h"

void test(){
	int i;
	for (i = 0; i < 10000; i++){
		for (i = 0; i < 10000; i++){
			;
		}
	}
}

int main(void){
//---------------clock time-------------
	int a[6] = {0,7,3,5,2,9};
	clock_t start2;
	clock_t start1 = clock();
	buildHeap(a,5);
	printf("buildHeap use time of %lf\n",(double)(clock()-start1)/CLOCKS_PER_SEC);
	start2 = clock();
	heapSort(a,5);
	printf("heapSort use time of %lf\n",(double)(clock()-start2)/CLOCKS_PER_SEC);
//-----------------����ʱ�� time_t �ͷֽ�ʱ�� struct tm-------
	struct tm t;
	time_t curtime;
	curtime = time(NULL);
	test();
	printf("test time is %lf\n",difftime(time(NULL),curtime));
//---------------����ʱ��ת��Ϊ�̶���ʽ�ı���ʱ��--------	
	printf("local time is: %s\n",ctime(&curtime));
	
	printf("--------����Ϊ���Թ̶�α�����----------\n");
	gepseudoValue_same(10);
	printf("--------����Ϊ����α�����----------\n");
	gepseudoValue_diff(10); 
	return 0;
}