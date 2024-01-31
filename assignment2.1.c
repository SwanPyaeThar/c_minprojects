//
// Created by ASUS on 12/17/2023.
//
#include "stdio.h"
int checkStudent1();
int checkStudent2();
int checkStudent3();
int main(){
    int x = 0;
    printf("If you know exam information,\n1 is for student1\n2 is for student2\n3 is for student3\n");
    scanf("%d",&x);
    if(x==1){
        checkStudent1();
    }else if(x==2){
        checkStudent2();
    }else if(x==3){
        checkStudent3();
    }else{
        printf("Please correct number 1 to 3");
    }

    return 0;

}
int checkStudent1(){
    int student1[6]={40,50,40,70,80,90};
    int subject = 6;
    int i=0;
    int total = student1[0]+student1[1]+student1[2]+student1[3]+student1[4]+student1[5];
    for(i=0;i<6;i++){
        if(student1[i]==40){
            printf("Student1 is pass %d subject\n",i+1);
        }else if(student1[i]<40){
            printf("Student1 is fail exam");
        }else if(student1[i]>40){
            printf("Student1  %d subject has got distinction ");
        }
    }
    printf("Student's total marks = %d",total);
    return 10;
}
int checkStudent2(){
    int student2[6]={80,100,90,40,80,90};
    int subject = 6;
    int i=0;
    int total = student2[0]+student2[1]+student2[2]+student2[3]+student2[4]+student2[5];
    for(i=0;i<6;i++){
        if(student2[i]==40){
            printf("Student2 is pass %d subject\n",i+1);
        }else if(student2[i]<40){
            printf("Student2 is fail exam");
        }else if(student2[i]>40){
            printf("Student2  %d subject has got distinction\n",i+1);
        }
    }
    printf("Student's total marks = %d",total);
    return 20;
}
int checkStudent3(){
    int student3[6]={30,100,90,40,80,90};
    int subject = 6;
    int i=0;
    int total = student3[0]+student3[1]+student3[2]+student3[3]+student3[4]+student3[5];
    for(i=0;i<6;i++){
        if(student3[i]==40){
            printf("Student3 is pass  subject %d\n",i+1);
        }else if(student3[i]<40){
            printf("Student3 is %d subject fail \n",i+1);
        }else if(student3[i]>40){
            printf("Student3  subject %d has got distinction\n ",i+1);
        }
    }
    printf("Student's total marks = %d",total);
    return 30;
}







