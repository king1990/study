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
//-----------------日历时间 time_t 和分解时间 struct tm-------
	struct tm t;
	time_t curtime;
	curtime = time(NULL);
	test();
	printf("test time is %lf\n",difftime(time(NULL),curtime));
//---------------日历时间转化为固定形式的本地时间--------	
	printf("local time is: %s\n",ctime(&curtime));
	
	printf("--------以下为测试固定伪随机数----------\n");
	gepseudoValue_same(10);
	printf("--------以下为测试伪随机数----------\n");
	gepseudoValue_diff(10); 
	return 0;
}