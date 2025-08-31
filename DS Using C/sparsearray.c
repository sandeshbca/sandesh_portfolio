#include<stdio.h>
int main() {
    int arr[4][4]={
        {0,7,0,0},
        {0,0,9,0},
        {0,8,7,0},
        {1,0,0,0}
    };
    int i,j;
   /* printf("enter matix: ");
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            scanf("%d",&arr[i][j]);
        }
    }*/
    printf("sparse matrix representation : ");
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(arr[i][j]=!0){

                printf("%d\n",arr[i][j]);
                
            }
        }
    }
    return 0;
}