#include "q.h"
 
double  sarf(int**arr,int i, int a, int b){    //среднее арифметическое для i-той строки
    double  s=0;
        for (int j=0;j<b;j++){
            s=s+arr[i][j];
}
return (double)s/b;
}
int search(int **arr,int a,int b){     //поиск номера столбца 
    int l=a+1;
    int p=b+1;
    double s=0;
    double t;
    for(int i=0;i<a;i++){
        s=0;
        if(i>=l){
            break;
        }
        t=sarf(arr,i,a,b);
        for(int j=0;j<b;j++){
            if(j>=p){
                break;
            }
            if(arr[i][j]==t){
                l=i;
                p=j;
            }
        }
    }
    return p;
}
void pechat_1(int** arr,int a,int b){    //если нет нужного эл-та
    FILE*output_file;
    output_file=fopen("asd.txt","w");
        printf("Эл-т не найден\n");
        for (int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                fprintf(output_file, "%d ",arr[i][j]);
                if(j==b-1){
                    fprintf(output_file,"\n");
                }
            }
        }
        fclose(output_file);
}
void pechat_2(int** arr,int a,int b){  //если есть нужный эл-т
    FILE*output_file;
    output_file=fopen("asd.txt","w");
    for(int i=0;i<a;i++){
        for(int j=0;j<b-1;j++){
            fprintf(output_file,"%d ",arr[i][j]);
            if(j==b-2){
                fprintf(output_file,"\n");
            }
         }
    }
    fclose(output_file);
    
}
void pererasp(int** arr,int a ,int b,int k){ //новый массив
    for(int i=0;i<a;i++){ 
        for(int j=k;j<b;j++){
        arr[i][j]=arr[i][j+1];
        }
    }
   for(int i=0;i<a;i++){
   arr[i]=(int*)realloc(arr[i],(b-1)*sizeof(int));
   if(arr[i]==NULL){
       printf("Ne pereraspredelilas\n");
       for(int y=0;y<i;y++){
           free(arr[y]);
           exit(5);
       }
   }
   }
}

void osvobozhdenie(int** arr,int a){ //освобождение памяти
     for(int i=0;i<a;i++){
        free(arr[i]);
    }
}


            

int ff(const char* filename){
    int** arr;
    int a,b,i,j;
    double s;
    int p;
    int l;
    FILE*input_file;
    input_file=fopen(filename,"r");
    if(!input_file){
        printf("Oshibka\n");
        return 9;
    }
    fscanf(input_file,"%d",&a);
    fscanf(input_file,"%d",&b);
    l=a+1; //для определения строки
    p=b+1; //для определения столбца
    if((a<=0)||(b<=0)){
        printf("Oshibka 1\n");
        return 3;
    }
    arr=(int**)malloc(a*sizeof(int*));
    if(arr==NULL){
        printf("Oshibka s pamyatiu\n");
        exit(1);
    }
    for(i=0;i<a;i++){
        arr[i]=(int*)malloc(b*sizeof(int));
        if(arr[i]==NULL){
            printf("Oshibka s pamyatiu1\n");
            for(int m=0;m<i;i++){
                free (arr[m]);
            }
            exit(3);
        }
    }
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            fscanf(input_file, "%d",&(arr[i][j]));
        }
    }
   int  k=search(arr,a,b);// ищем номер столбца
    printf("k =%d\n",k);
    
    if(k==b+1){
        pechat_1(arr,a,b);//случай когда нет нужного элемента
        exit(0);
    }
     else{
    pererasp(arr,a,b,k);// перераспределение памяти
    pechat_2(arr,a,b);//случай когда есть
     }
   osvobozhdenie(arr,a);
   fclose(input_file);
    return 8;
}

int main(void){
    autotest();
    ff("zxc.txt");
    return 0;
}
