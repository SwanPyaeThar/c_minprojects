//
// Created by ASUS on 12/6/2023.
//
#include<stdio.h>
int main(){

 int i = 0;
 int x = 0;
 int ii=0;
 int size0 = 10;
 int size1 = 8;
 int j=0;
 int jj=0;

    printf("This is Assignment_1\n");
    for(i=0;i<size0;i++){
        for(x=0;x<=size0-i;x++){
            printf(" ");
        }

        for(ii=1;ii<i*2;ii++){
            printf("*");
        }
        for(j=0;j<=size1-i;j++){
            printf("  ");
        }
        for(jj=1;jj<i*2;jj++){
            printf("*");
        }

        printf("\n");

    }



    return 0;
}