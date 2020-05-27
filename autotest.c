#include "q.h"
void autotest(void){
    int y=0;
    int t;
    int** arr1;
    arr1=(int**)malloc((3)*sizeof(int*));
    arr1[0]=(int*)malloc((3)*sizeof(int));
    arr1[1]=(int*)malloc((3)*sizeof(int));
    arr1[2]=(int*)malloc((3)*sizeof(int));
    
    arr1[0][0]=0;
    arr1[0][1]=1;
    arr1[0][2]=2;
    arr1[1][0]=3;
    arr1[1][1]=4;
    arr1[1][2]=5;
    arr1[2][0]=6;
    arr1[2][1]=7;
    arr1[2][2]=8;
    t=sarf(arr1,1,3,3);
    if(t==4){
        printf("Autotest 1 passed\n");
    }
    else{
        printf("Autotest 1 failed\n");
    }
    y=search(arr1,3,3);
    if(y==1){
        printf("autotest passed\n");
    }
    else{
        printf("autotest failed\n");
    }
    
    
}
