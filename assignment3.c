//Created by SwanPyaeThar
#include "stdio.h"
#include "stdlib.h"
void copy_two_charArr(char first[30],char second[30]);
//struct declare
struct DataBase{
    char name[30];
    char email[30];
    char password[20];
    int phone;
};
struct DataBase user[10];


//function declare
void menu();
void registration();
void login();
void  login_checking(char l_mail[30],char l_password[20]);
int compare_two_charArray(char first[30],char second[30]);
int size_of_charArray(char arr[30]);
void logout();

//g-var declare
int g_user_count =0;
int g_login_check = -1;

int main(){
    menu();

    return 0;
}
void menu(){
    while (1){
        printf("\nWelcome to My System!\n");
        int option =0;
        printf("Please choose option\n");
        printf("1 = Register\n2 = Login\n3 = Exit\n  ");
        scanf("%d",&option);
        switch (option) {
            case 1:
                registration();
                break;
            case 2:
                login();
                break;

            case 3:
                exit(1);
                break;
            default:
                exit(1);
                break;
        }
    }
}
void registration(){
    char r_user_name[30];
    char r_email[30];
    char r_password[20];
    int r_phone;
    printf("Enter your name to register:");
    scanf(" %[^\n]",&r_user_name);
    printf("Enter your email to register:");
    scanf(" %[^\n]",&r_email);
    printf("Enter your password to register:");
    scanf(" %[^\n]",&r_password);
    printf("Enter your phone to register:");
    scanf("%d",&r_phone);

    //collecting in DataBase
    copy_two_charArr(user[g_user_count].name,r_user_name);
    printf("\nChecking User name:%s",user[g_user_count].name);

    copy_two_charArr(user[g_user_count].email,r_email);
    printf("\nChecking email:%s",user[g_user_count].email);

    copy_two_charArr(user[g_user_count].name,r_password);
    printf("\nChecking password:%s",user[g_user_count].password);

    user[g_user_count].phone = r_phone;
    printf("\nChecking User Phone:%d\n",user[g_user_count].phone);

    g_user_count++;
}

void copy_two_charArr(char first[30],char second[30]){
    int i=0;
    for(i=0;i<30;i++){
        if(second[i]=='\0'){
            break;
        }else{
            first[i]=second[i];
        }
    }
}
void login(){
    char l_mail[30];
    char l_password[20];
    printf("This is login!\n");
    printf("Enter your email to login!: ");
    scanf(" %[^\n]",&l_mail);
    printf("Enter your password to login!: ");
    scanf(" %[^\n]",&l_password);

    login_checking(l_mail,l_password);
    if(g_login_check!=-1){
        printf("Login Success\n");
        logout();
    }else{
        printf("Login failed\n");
        menu();
    }
}
void  login_checking(char l_mail[30],char l_password[20]){
    int i=0;
    g_login_check=-1;
    for(i=0;i<g_user_count;i++){
        int email_check = compare_two_charArray(user[i].email,l_mail);
        if(email_check==1){
            int pass_check = compare_two_charArray(user[i].password,l_password);
            if(pass_check==1){
                g_login_check=i;
                break;
            }
        }
    }

}
int compare_two_charArray(char first[30],char second[30]){
    int size1= size_of_charArray(first);
    int size2= size_of_charArray(second);
    int sameCount=0;
    if(size1==size2){
        for(int i=0;i<size1;i++){
            if(first[i]==second[i]){
                sameCount++;
            }
        }
    }
    if(size1==sameCount){
        return 1;
    }else{
        return 0;
    }

}
int size_of_charArray(char arr[30]){
    int size=0;
    for(int i=0;i<30;i++){
        if(arr[i]=='\0'){
            break;
        }
        size++;
    }
    return size;
}
void logout(){
    int option=0;
    printf("If you want to logout press:2\n");
    scanf("%d",&option);
    if(option==2){
        printf("Logout Success!\n");
        menu();
    }else{
        while (option!=2){
            logout();
        }
    }
}
