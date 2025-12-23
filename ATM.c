#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int pin,choice;
struct account {
    char name[50];
    int pin;
    float balance;
};
struct account ac[5] = {
    {"Muhammad",1243, 25000}, {"Shoaib", 1244, 35000}, {"Ali", 1245, 30000}, {"Adbullah", 1246, 40000}, {"Abubakar", 1247, 50000}};

void login(int pin);
void main_menu();
void Check_Balance(int pin);
void Deposit_Money();
void Withdraw_Money();
void transfer_Money();

int main(){
system("color 0B");
int count = 0;
int isTrue = 1;
int isFalse = 0;
int found;

do {
    system("cls");
    printf("\n\n");
    printf("\t\t\t===============================================\n");
    printf("\t\t\t         Welcome to MY ATM Machine\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\tEnter Pin: ");
    scanf("%d", &pin);
    
    found = 0;  
    
    for (int i = 0; i < 5; i++) {
        if (pin == ac[i].pin) {
            found = 1;
            login(pin);           
            isTrue = isFalse;  
            break;
        }
    }
    
    if (!found ) {
        count++;
        
        if (count == 3) {
            printf("\n\t\t\tYou Entered Wrong Pin For three times..\n");
            printf("\t\t\tYour Account is Locked.Please Contact Your Bank.\n\n");
            isTrue = isFalse;  
        }
    }
    
} while (isTrue != isFalse);
    return 0;
}
void login(int pin){
   
    for (int i=0;i<5;i++){
        if (pin == ac[i].pin){
            system("cls");
            printf("\n\n\t\t\t===============================================\n");
            printf("\t\t\t        Login Successful! Welcome %s\n", ac[i].name);
            printf("\t\t\t===============================================\n");
            printf("\n\t\t\tPress Enter to continue...");
            getchar();
            getchar();
            main_menu(); 
            break;
        } 
    }    
}
void main_menu(){;
    system("cls");
    printf("\n\n");
    printf("\t\t\t===============================================\n");
    printf("\t\t\t              MAIN MENU\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\t  1. Check Balance\n");
    printf("\t\t\t  2. Deposit Money\n");
    printf("\t\t\t  3. Withdraw Money\n");
    printf("\t\t\t  4. Transfer Money\n");
    printf("\t\t\t  5. Exit\n\n");
    printf("\t\t\t===============================================\n");
    printf("\t\t\tEnter your choice: ");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            Check_Balance(pin);
            printf("\n\t\t\tPress Enter to return to menu...");
            getchar();
            getchar();
            main_menu();
            break;
        case 2:
            Deposit_Money();
            printf("\n\t\t\tPress Enter to return to menu...");
            getchar();
            getchar();
            main_menu();
            break;
        case 3:
            Withdraw_Money();
            printf("\n\t\t\tPress Enter to return to menu...");
            getchar();
            getchar();
            main_menu();
            break;
        case 4:
            transfer_Money();
            printf("\n\t\t\tPress Enter to return to menu...");
            getchar();
            getchar();
            main_menu();
            break;
        case 5:
            system("cls");
            printf("\n\n\t\t\t===============================================\n");
            printf("\t\t\t   Thank You For Using Our Services!\n");
            printf("\t\t\t===============================================\n\n");
            break;
        default:
            printf("\n\t\t\t[!] Invalid choice. Please try again.\n");
            printf("\t\t\tPress Enter to continue...");
            getchar();
            getchar();
            main_menu();
    }
}


void Check_Balance(int pin){
    time_t now = time(NULL);
    struct tm *date = localtime(&now);
    system("cls");
    printf("\n\n");
    printf("\t\t\t===============================================\n");
    printf("\t\t\t            BALANCE INQUIRY\n");
    printf("\t\t\t===============================================\n\n");
    for (int i = 0;i<5;i++){
        if (pin == ac[i].pin){
            printf("\t\t\tAccount Name     : %s\n", ac[i].name);
            printf("\t\t\tAvailable Balance: PKR %.2f\n\n", ac[i].balance);
            printf("\t\t\tDate : %d-%d-%d\t\t\n", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
            printf("\t\t\tTime : %d:%d\t\t\t\n", date->tm_hour, date->tm_min, date->tm_hour);
        }
    }
    printf("\t\t\t===============================================\n");
}

void Deposit_Money(){
    system("cls");
    float deposit;
    char name[50];
    int i, new_balance,pin1;
    time_t now = time(NULL);
    struct tm *date = localtime(&now);
    printf("\n\n");
    printf("\t\t\t===============================================\n");
    printf("\t\t\t            DEPOSIT MONEY\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\tEnter amount to deposit: ");
    scanf("\t\t\t%f", &deposit);
    for ( i = 0;i<5;i++){   
    if(pin == ac[i].pin){
        ac[i].balance += deposit;
        new_balance = ac[i].balance;
        pin1 = ac[i].pin;
        strcpy(name, ac[i].name);
    }
    }
    printf("\n\t\t\t    Deposit Successful!\n\n");
    printf("\t\t\t===============================================\n");
    printf("\t\t\t            ATM RECEIPT\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\tAccount Holder   : %s\n", name);
    printf("\t\t\tAmount Deposited : PKR %.2f\n", deposit);
    printf("\t\t\tNew Balance      : PKR %d\n\n", new_balance);
    printf("\t\t\tDate : %d-%d-%d\t\t\n", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
    printf("\t\t\tTime : %d:%d\t\t\t\n", date->tm_hour, date->tm_min, date->tm_hour);


    printf("\t\t\t===============================================\n");
}

void Withdraw_Money(){
    system("cls");
    float withdraw;
    int remaining_balance,pin1;
    char name[30];
    time_t now = time(NULL);
    struct tm *date = localtime(&now);

    printf("\n\n");
    printf("\t\t\t===============================================\n");
    printf("\t\t\t            WITHDRAW MONEY\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\tEnter amount to withdraw: ");
    scanf("%f", &withdraw);
    

    for (int i =0;i<5;i++){
        if(pin == ac[i].pin){
            if (withdraw > ac[i].balance){
                printf("\n\t\t\t    Insufficient Balance!\n");
                printf("\t\t\tPress Enter to try again...");
                getchar();
                getchar();
                Withdraw_Money();
            }
            else if (withdraw <= ac[i].balance){
                ac[i].balance -= withdraw;
                remaining_balance = ac[i].balance;
                pin1 = ac[i].pin;
                strcpy(name, ac[i].name);
            }
        }
    }
    printf("\n\t\t\t    Withdrawal Successful!\n\n");
    printf("\t\t\t===============================================\n");
    printf("\t\t\t            ATM RECEIPT\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\tAccount Holder    : %s\n", name);
    printf("\t\t\tAmount Withdrawn  : PKR %.2f\n", withdraw);
    printf("\t\t\tRemaining Balance : PKR %d\n\n", remaining_balance);
    printf("\t\t\tDate : %d-%d-%d\t\t\n", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
    printf("\t\t\tTime : %d:%d\t\t\t\n", date->tm_hour, date->tm_min, date->tm_hour);


    printf("\t\t\t===============================================\n");

}
void transfer_Money(){
    system("cls");
    int target_pin;
    float transfer_amount;
    char name[30];
    int pin1,sender_balance,receiver_balance;
    time_t now = time(NULL);
    struct tm *date = localtime(&now);

    printf("\n\n");
    printf("\t\t\t===============================================\n");
    printf("\t\t\t            TRANSFER MONEY\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\tEnter target account PIN: ");
    scanf("%d", &target_pin);

    int sender_index = -1, receiver_index = -1;

    for (int i = 0; i < 5; i++) {
        if (pin == ac[i].pin) {
            sender_index = i;
        }
        if (target_pin == ac[i].pin) {
            receiver_index = i;
        }
    }

    if (sender_index == -1) {
        printf("\n\t\t\t    Sender account not found.\n");
        return;
    }
    if (receiver_index == -1) {
        printf("\n\t\t\t    Target account not found.\n");
        return;
    }
   if (sender_index == receiver_index) {
        printf("\n\t\t\t    Cannot transfer to yourself!\n");
        return;
    }

    printf("\t\t\tEnter amount to transfer: ");
    scanf("%f", &transfer_amount);

    if (transfer_amount > ac[sender_index].balance) {
         printf("\n\t\t\t    Insufficient Balance!\n");
        return;
    }
    
    ac[sender_index].balance -= transfer_amount;
    ac[receiver_index].balance += transfer_amount;

    sender_balance = ac[sender_index].balance;
    receiver_balance = ac[receiver_index].balance;
    pin1 = ac[sender_index].pin;
    strcpy(name, ac[sender_index].name);

    printf("\n\t\t\t    Transfer Successful!\n\n");
    printf("\t\t\t===============================================\n");
    printf("\t\t\t            ATM RECEIPT\n");
    printf("\t\t\t===============================================\n\n");
    printf("\t\t\tAccount Holder            : %s\n", name);
    printf("\t\t\tAmount Transferred        : PKR %.2f\n", transfer_amount);
    printf("\t\t\tYour Remaining Balance    : PKR %d\n", sender_balance);
    printf("\t\t\tDate : %d-%d-%d\t\t\n", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
    printf("\t\t\tTime : %d:%d\t\t\t\n", date->tm_hour, date->tm_min, date->tm_hour);


    printf("\t\t\t===============================================\n");
 }
