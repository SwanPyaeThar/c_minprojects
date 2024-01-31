//
// Created by ASUS on 1/14/2024.
//
#include "stdio.h"
#include "stdlib.h"

#include "stdio.h"
#include "stdlib.h"


// function declare
void copy_two_charArray(char first[30],char second[30]);
void registration();
void menu();
void login();
void login_checking(char l_email[30],char l_pass[20]);
int size_of_charArray(char arr[30]);
int compare_two_char_array(char first[30],char second[30]);
void my_privilege(int user_id);
void user_info_change(int user_id);
void id_finding(int to_find_id);
void email_valid(char to_valid_email[30]);
int email_scanner(char to_check_email[30]);
void email_valid_two(char to_valid_email[30]);
void transfer_point();
void point_transaction(int transmit , int receiver ,  int amount);
void compare_two_charArrayForTransfer(char first[50],char second[50]);


//Global Var

int g_userCount=0;
int g_login_check=-1;
int id_found=-1;
int email_validation=-1;


// structure Declare

struct Db{
    int user_id;
    char user_name[30];
    char user_email[30];
    char user_pass[20];
    int phone_number;
    char address[50];
    int postal_code;
    int current_point;


};

struct Db data[10];

int main(){
//    char first[30]={'a','b','c','d'};
//    char second[30]={'a','b','c','d'};

//    int flag = compare_two_char_array(first,second);
//    printf("%d",flag);
    menu();

    return 0;
}

void menu(){

    while (1) { // 1 true 0 false
        int option = 0;
        printf("Welcome to our System!\n");
        printf("Press:1 To Login!\nPress:2 To Register!\nPress:3 To Exist!:\nEnter:");
        scanf("%d", &option); //

        if (option == 1) {
            login();

        } else if (option == 2) {

            registration();
        } else {

            exit(1);
        }

    }

}
void login(){
    char l_email[30];
    char l_password[20];
    printf("This is login!\n");
    printf("Enter your email to login:");
    scanf(" %[^\n]",&l_email);
    printf("Enter your password to login:");
    scanf(" %[^\n]",&l_password);

    login_checking(l_email,l_password);
    if(g_login_check != -1){

        printf("LoginSuccess!\n Your Id= %d",g_login_check);
        my_privilege(g_login_check);
    } else{
        printf("Login Failed!\n");
        menu();
    }

}

void my_privilege(int user_id){

    int m_option=-1;
    printf("Welcome Sir: %s\n",data[user_id].user_name);
    printf("Your PhoneNumber: %d\n",data[user_id].phone_number);
    printf("What you want to do!\n");
    printf("This is your point:%d\n",data[user_id].current_point);
    printf("Enter 0 To Complete Exist:\nEnter 1 to Menu:\nEnter 2 to change user info:\nEnter 3 to point transfer");
    scanf("%d",&m_option);
    if(m_option == 0){
        exit(1);
    } else if(m_option==1){
        menu();
    } else if(m_option==2){
        user_info_change(user_id);
    } else if(m_option==3){
        transfer_point();
    }
    else{
        printf("Wrong Option Number:\n");
        my_privilege(user_id);
    }


}

void user_info_change(int user_id){
    int change_option=0;
    printf("Press 1: To change Name:\nPress 2: To change Email:\n");
    printf("Press 3: To change Password:\nPress 4: To change PhoneNumber:\n");
    printf("Press 5: To change Address:\nPress 6: To change PostCode:\n");
    printf("Press 7: For your privilege:");
    scanf("%d",&change_option);

    if(change_option==1){
        char newuser_name[30];

        printf("To change name:\n");
        printf("This is your user name: %s\n",data[user_id].user_name);
        printf("Enter your new user name:");
        scanf(" %[^\n]",&newuser_name);
        copy_two_charArray(data[user_id].user_name,newuser_name);
        printf("This is your new user name: %s",data[user_id].user_name);


    }else if(change_option==2){
        char new_email[30];
        printf("To change email:\n");
        printf("This is your email: %s\n",data[user_id].user_email);
        printf("Enter new your email:");
        scanf(" %[^\n]",&new_email);
        copy_two_charArray(data[user_id].user_email,new_email);
        printf("This is your new email: %s",data[user_id].user_email);

    }




}
void login_checking(char l_email[30],char l_pass[20]){
    int i=0;
    g_login_check=-1;
    for(i=0; i<g_userCount ; i++){
        int email_check =compare_two_char_array(data[i].user_email,l_email);

        if(email_check == 1){
            int pass_check =compare_two_char_array(data[i].user_pass,l_pass);
            if(pass_check==1){
                g_login_check=data[i].user_id;
                break;
            }

        }

    }

}

void registration(){

    char r_username[30];
    char r_useremail[30];
    char r_userpassword[20];
    int r_phoneNumber=0;
    char r_address[50];
    int r_postal_code=0;
    int r_user_point = 0;
    int free_point_recieve = 0;
    printf("This is Registration Option:\n");
    printf("Enter your user name to Register:");
    scanf(" %[^\n]",&r_username);
    printf("Enter your user email to Register:");
    scanf(" %[^\n]",&r_useremail);
    printf("Enter your user password to Register:");
    scanf(" %[^\n]",&r_userpassword);
    printf("Enter your PhoneNumber to Register:");
    scanf("%d",&r_phoneNumber);

    printf("Enter your Address to Register:");
    scanf(" %[^\n]",&r_address);
    printf("Enter your Postal code to Register:");
    scanf("%d",&r_postal_code);
    printf("Press 1 to recieve free point\n");
    scanf("%d",&free_point_recieve);
    if(free_point_recieve==1){
        r_user_point=500;
    }


    // collecting
    copy_two_charArray(data[g_userCount].user_name,r_username);
    printf("\nChecking for username: %s",data[g_userCount].user_name);

    copy_two_charArray(data[g_userCount].user_email,r_useremail);
    printf("\nChecking for userEmail: %s",data[g_userCount].user_email);

    copy_two_charArray(data[g_userCount].user_pass,r_userpassword);
    printf("\nChecking for Password: %s",data[g_userCount].user_pass);


    data[g_userCount].phone_number = r_phoneNumber;
    printf("\nChecking for PhoneNUmber: %d",data[g_userCount].phone_number);


    copy_two_charArray(data[g_userCount].address,r_address);
    printf("\nChecking for Address  %s",data[g_userCount].address);

    data[g_userCount].postal_code = r_postal_code;
    printf("\nChecking for postal_code: %d",data[g_userCount].postal_code);

    data[g_userCount].current_point=r_user_point;
    printf("\nChecking for free point: %d\n",data[g_userCount].current_point);

    data[g_userCount].user_id = g_userCount;
    g_userCount++;

}
void copy_two_charArray(char first[30],char second[30]){
    for(int x=0; x<30; x++){
        first[x]=='\0';
    }
    int i=0;
    for(i=0; i<30; i++){

        if(second[i]=='\0'){

            break;
        } else{
            first[i] = second[i];

        }
    }
}

int compare_two_char_array(char first[30],char second[30]){

    int size1= size_of_charArray(first);
    int size2= size_of_charArray(second);
    int sameCount=0;
    if( size1 == size2){
        for(int i=0; i<size1; i++){

            if(first[i]==second[i]){
                sameCount++;
            }
        }
    }
    if(size1 == sameCount){
        return 1;
    } else{
        return 0;
    }
}

int size_of_charArray(char arr[30]){
    int size=0;
    for(int i=0; i<30 ;i++){

        if(arr[i]=='\0'){
            break;
        }
        size++;
    }

    return size;
}





int email_scanner(char to_check_email[30]){
    int exit_or_not=-1;
    if(g_userCount==0){
        return 1;
    } else{
        for(int i=0; i<g_userCount ; i++){
            // we got 1 if same , 0
            exit_or_not=compare_two_char_array(data[i].user_email,to_check_email);
            if(exit_or_not==1){
                return -1; // already register
            }
        }
    }

    return 1;// you can register

}
void email_valid_two(char to_valid_email[30]){
    // number , small letter ယူမယ် ကျန်တာ အကုန် ဘန်း // num = 48-57 , small = 97-122
    // to_valid_email[30] = {w,i,n,a,s,m,@,n,1,c,.,c,o,m};
    int first_count=0;
    char one_char;
    char first_valid=0;
    int arr_size =  size_of_charArray(to_valid_email);

    for (int i = 0; i < arr_size; ++i) {
        if(to_valid_email[i]=='@'){
            break;
        } else{
            first_count++;
        }
    }
    for(int x=0; x<first_count; x++){
        one_char = to_valid_email[x];
        if((one_char>=48 && one_char<=57)||(one_char>=97 &&one_char<=122)){
            first_valid++;
        } else{
            first_valid=-1;
        }
    }

    if(first_count!=first_valid || first_count==arr_size || first_count==0){
        email_validation=-1;
        return;
    } else{
        email_validation=1;
        printf("\n\n [+]First Part checking complete!\n");
    }

    printf("Arr Size: %d\n",arr_size);
    printf("first_count %d\n",first_count);
    printf("First count index value %c\n",to_valid_email[first_count]);

    // @gmail.com , @yahoo.com , @outlook.com , @apple.com , @n1c.com
    char gmail[11]={'@','g','m','a','i','l','.','c','o','m'};
    char yahoo[11]={'@','y','a','h','o','o','.','c','o','m'};
    char outlook[12]={'@','o','u','t','l','o','o','k','.','c','o','m'};
    char apple[11]={'@','a','p','p','l','e','.','c','o','m'};
    char n1c[11]={'@','n','1','c','.','c','o','m'};
    int second_count=0;
    char arr_sec_part[13];
    int for_sec_index=0;

    second_count = arr_size-first_count;
    printf("second count value : %d\n",second_count);
    printf("Second Data :");
    for(int xxx=first_count; xxx<arr_size; xxx++){
        arr_sec_part[for_sec_index] = to_valid_email[xxx];
        printf("%c",arr_sec_part[for_sec_index]);
        for_sec_index++;

    }
    printf("\n");

    int g = compare_two_char_array(arr_sec_part,gmail);
    int y = compare_two_char_array(arr_sec_part,yahoo);
    int o = compare_two_char_array(arr_sec_part,outlook);
    int a = compare_two_char_array(arr_sec_part,apple);
    int n = compare_two_char_array(arr_sec_part,n1c);

    if(g||y||o||a||n){
        email_validation=1;
        printf("\n\n [+]Second Part checking complete!\n");

    } else{
        printf("Second email validatino failed!\n");
        email_validation=-1;
    }

}
void transfer_point(){
    int amount_to_tran=0;
    int receiver_id=0;
    char trans_pass[20];
    id_found=-1;
    while (id_found==-1){
        printf("Enter receiver ID number::\n");
        scanf("%d",&receiver_id);
        id_finding(receiver_id);

        if(id_found==-1){
            printf("This ID number is not found in our system!\n");
        }



    }
    while (1){
        printf("Enter your point to send for %s : %s:",data[id_found].user_name,data[id_found].user_email);
        scanf("%d",&amount_to_tran);

        if(amount_to_tran >= data[id_found].current_point-500){
            break;
        }
    }
    g_login_check=-1;
    int wrong_counter = 0;
    while (g_login_check==-1){
        printf("Your current point %d\nTransfer point %d:\n",data[id_found].current_point,amount_to_tran);
        point_transaction(data[g_login_check].current_point,id_found,amount_to_tran);
        my_privilege(data[g_login_check].user_id);
    }


}
void id_finding(int to_find_id){
    for(int i=0;i<g_userCount;i++){
        if(to_find_id==data[i].user_id){
            id_found=i;
            break;
        }
    }

}
void point_transaction(int transmit , int receiver , int amount){
    printf("This is point transfer!\n");
    data[transmit].current_point = data[transmit].current_point - amount;
    data[receiver].current_point = data[receiver].current_point + amount;
    printf("transcation complete\n");
    printf("Your current point: %s : %d\n",data[transmit].user_name,data[transmit].current_point);
    printf("Enter press 3 to go menu!\n");
    int option = 0;
    scanf("%d",&option);
    if(option==3){
        menu();
    }

}




