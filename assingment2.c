//
// Created by ASUS on 12/16/2023.
//
#include "stdio.h"

int adding(int num1,int num2);
int sub(int num1,int num2);
int multiply(int num1,int num2);
int divide(int num1,int num2);
int main(){
   int addNum1 = 0;
   int addNum2 = 0;
   int subNum1 = 0;
   int subNum2 =0;
   int multiNum1=0 ;
   int multiNum2=0 ;
   int divideNum1 = 0;
   int divideNum2 = 0;
   int operation = 0;
    printf("Please choose operation\n1 is plus\n2is minus\n3is multiply\n4 is divide\n");
    scanf("%d",&operation);
    if(operation==1){
        printf("please enter firstNumber\n");
        scanf("%d",&addNum1);
        printf("Please enter secondNumber\n");
        scanf("%d",&addNum2);
        int add = adding(addNum1,addNum2);
        printf("%d",add);
    }else if(operation==2){
        printf("please enter firstNumber\n");
        scanf("%d",&subNum1);
        printf("Please enter secondNumber\n");
        scanf("%d",&subNum2);
        int subResult = sub(subNum1,subNum2);
        printf("%d",subResult);
    }else if(operation==3){
        printf("Please enter first Number\n");
        scanf("%d",&multiNum1);
        printf("Please enter second Number\n");
        scanf("%d",&multiNum2);
        int multiResult = multiply(multiNum1,multiNum2);
        printf("%d",multiResult);
    }else if(operation==4){
        printf("Please enter FirstNumber\n");
        scanf("%d",&divideNum1);
        printf("Please enter SecondNumber\n");
        scanf("%d",&divideNum2);
        int divideResult = divide(divideNum1,divideNum2);
        printf("%d",divideResult);
    }else{
        printf("Error!,Something Wrong");
    };


}
int adding(int num1,int num2){
    int total = num1 + num2;
    return total;
}
int sub(int num1,int num2){
    int total = num1 - num2;
    return total;
}
int multiply(int num1,int num2){
    int total = num1*num2;
    return total;
}
int divide(int num1,int num2){
    int total = num1 / num2;
    return total;
}