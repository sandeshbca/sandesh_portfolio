#include<stdio.h>
int main(){
    int a[5] = {80,20,90,40,50};
    int i,j,temp;
    for(i=0; i<5;  i++){
        for(j=0; j<5; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("after sorted :");
    for(i=0; i<5; i++){
        printf("%d",a[i]);
    }
    return 0;

}