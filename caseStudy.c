#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


struct account {
    char account_No[10];
    char account_Name[25];
    int PIN;
    double deposit;
    char transaction_code;
    double amount;
    double account_Balance;
};


struct account user;
char string[6];
int pin;

void createAccount();
void openAccount();
void balanceInquiry(char accountNumber[]);
void deposit(char accountNumber[]);
void withdrawal(char accountNumber[]);
void transactionMenu(char accountNumber[]);
char mainMenu();
void printRecord();
bool checkAvailability(char accountNo[]);
void removeAccount();
void checkFile(FILE *accountsFP);


int main() {
    char option;
    printf("\n\t\tW E L C O M E   T O   C   B A N K\n\n");
    printf("*Note: please press the respective number of option for your action\n\n");
    do {
        option = mainMenu(); // Capture the return value of mainMenu
    } while(toupper(option) != 'E');


    return 0;
}


void createAccount() {
    FILE *accountsFP = fopen("ACCOUNTS.dat", "ab");
    char accountNo[25];
    checkFile(accountsFP);
   
    printf("Enter Account Number: ");
    scanf("%s", accountNo);
    if (checkAvailability(accountNo)) {
        printf("\nAccount number already registered!\n");
        fclose(accountsFP);
        return;
    }
    strcpy(user.account_No, accountNo); // copy the value from temporary variable into the user accounts' account number
    printf("Enter Account Name: ");
    scanf("%s", user.account_Name);
    printf("\nPIN length should be equal to 6\n\n");
    do{
        printf("Enter PIN: ");
        scanf("%d", &user.PIN);
        sprintf(string, "%d", user.PIN); // convert user.PIN data type from int into string temporarily
        if(strlen(string) != 6){
            printf("\nPin length is not equal to 6\n");
        }
    }while(strlen(string) != 6);
   
        do{
            printf("Enter Deposit: ");
            scanf("%lf", &user.deposit);
                if(user.deposit <= 0){
                printf("\nInvalid deposit!\n");
        }
    }while(user.deposit <= 0);
    user.account_Balance = user.deposit;


    fwrite(&user, sizeof(struct account), 1, accountsFP);


    fclose(accountsFP);
}
void openAccount() {
    char accountNumber[10];
    bool accountFound = false;
    int tries = 3;
    FILE *accountsFP = fopen("ACCOUNTS.dat", "rb");


    checkFile(accountsFP);


    printf("Enter Account Number: ");
    scanf("%s", accountNumber);


    while (fread(&user, sizeof(struct account), 1, accountsFP) != 0) {
        if (strcmp(user.account_No, accountNumber) == 0) {
            accountFound = true;
            break;
        }
    }


    if (!accountFound) {
        printf("Account not found!\n");
        fclose(accountsFP);
        return;
    }


    while (tries > 0) {
        printf("Enter PIN: ");
        scanf("%d", &pin);
            if (user.PIN == pin) {
                printf("\nVALID PIN! The account belongs to %s\n", user.account_Name);
                fclose(accountsFP);
                transactionMenu(accountNumber);
                return;
            } else {
                printf("INVALID PIN! You have %d tries left\n", --tries);
            }
    }
    printf("\nCARD CAPTURED! Please get your card from your Bank Branch.\n");
    fclose(accountsFP);
}
void balanceInquiry(char accountNumber[]) {
    FILE *accountsFP = fopen("ACCOUNTS.dat", "rb");

    checkFile(accountsFP);
   
    printf("\nBALANCE INQUIRY\n------------------------------------\n");
    while (fread(&user, sizeof(struct account), 1, accountsFP) != 0) {
        if (strcmp(user.account_No, accountNumber) == 0) {
            printf("Name: %s\n", user.account_Name);
            printf("Account Number: %s\n", user.account_No);
            printf("Your current balance is: %.2lf\n", user.account_Balance);
        }
    }
    printf("------------------------------------\n");
    fclose(accountsFP);
    transactionMenu(accountNumber);
}
void deposit(char accountNumber[]) {
    bool accountFound = false;

    FILE *accountsFP = fopen("ACCOUNTS.dat", "rb");
   
    checkFile(accountsFP);

    FILE *tempFP = fopen("TEMP.dat", "wb");

    if (tempFP == NULL) {
        printf("Temporary file cannot be opened for writing!\n");
        fclose(accountsFP);
        return;
    }


    while (fread(&user, sizeof(struct account), 1, accountsFP) != 0) {
        if (strcmp(user.account_No, accountNumber) == 0) {
            accountFound = true;
            printf("Enter amount deposit: ");
            scanf("%lf", &user.amount);
            user.account_Balance += user.amount;
            printf("\nDEPOSIT SUCCESSFUL\n--------------------------------------------------------\n");
            printf("Your new balance is: %.2lf\n", user.account_Balance);
            printf("--------------------------------------------------------\n");
        }
        fwrite(&user, sizeof(struct account), 1, tempFP);
    }


    fclose(accountsFP);
    fclose(tempFP);


    if (!accountFound) {
        printf("Account not found!\n");
        remove("TEMP.dat"); // remove temporary file
    } else {
        remove("ACCOUNTS.dat"); // remove original file
        rename("TEMP.dat", "ACCOUNTS.dat"); // rename temporary file to original file
    }
    transactionMenu(accountNumber);
}
void withdrawal(char accountNumber[]) {
    bool accountFound = false;


    FILE *accountsFP = fopen("ACCOUNTS.dat", "rb");
   
    checkFile(accountsFP);


    FILE *tempFP = fopen("TEMP.dat", "wb");


    if (tempFP == NULL) {
        printf("Temporary file cannot be opened for writing!\n");
        fclose(accountsFP);
        return;
    }


    while (fread(&user, sizeof(struct account), 1, accountsFP) != 0) {
        if (strcmp(user.account_No, accountNumber) == 0) {
            accountFound = true;
            printf("Enter amount withdrawal: ");
            scanf("%lf", &user.amount);
                if (user.account_Balance >= user.amount) {
                    user.account_Balance -= user.amount;
                    printf("\nWITHDRAW SUCCESSFUL\n--------------------------------------------------------\n");
                    printf("Your new balance is: %.2lf\n", user.account_Balance);
                    printf("--------------------------------------------------------\n");
                } else {
                    printf("\nNot enough funds\n");
                }
        }
        fwrite(&user, sizeof(struct account), 1, tempFP); // write to temporary file
    }


    fclose(accountsFP);
    fclose(tempFP);


    if (!accountFound) {
        printf("Account not found!\n");
        remove("TEMP.dat"); // remove temporary file
    } else {
        remove("ACCOUNTS.dat"); // remove original file
        rename("TEMP.dat", "ACCOUNTS.dat"); // rename temporary file to original file
    }
    transactionMenu(accountNumber);
}
void transactionMenu(char accountNumber[]) {

    printf("\nEnter transaction Code: <A>, <B>, <C>, <D>\n\n");
    printf("\t\tTRANSACTION MENU\n\n");
    printf("A. BALANCE INQUIRY\nB. DEPOSIT\nC. WITHDRAWAL\nD. QUIT\n");
    printf("Enter your choice: ");
    scanf(" %c", &user.transaction_code);

    switch(toupper(user.transaction_code)) {
        case 'A': balanceInquiry(accountNumber); break;
        case 'B': deposit(accountNumber); break;
        case 'C': withdrawal(accountNumber); break;
        case 'D': return;
        default: printf("\nInvalid option! Please enter a valid option.\n"); break;
    }
}
char mainMenu() {
    printf("\n\t\tMain Menu\n\n");
    printf("A. Create an account\n");
    printf("B. Open an account\n");
    printf("C. Remove an account\n");
    printf("D. Print records\n");
    printf("E. Exit\n");
    printf("\nEnter your choice: ");
    scanf(" %c", &user.transaction_code);
   
    switch(toupper(user.transaction_code)) {
        case 'A': createAccount(); break;
        case 'B': openAccount(); break;
        case 'C': removeAccount(); break;
        case 'D': printRecord(); break;
        case 'E': printf("\nThank you, have a nice day!\n\n"); return user.transaction_code;
        default: printf("\nInvalid option! Please enter a valid option.\n"); return 0;
    }
    return user.transaction_code;
}
void printRecord() {
    FILE *accountsFP = fopen("ACCOUNTS.dat", "rb");


    checkFile(accountsFP);


    printf("--------------------------------------------------------------------------------\n");
    printf("Account Number\t\t\tAccount Name\t\t\tAccount Balance\n\n");
    while (fread(&user, sizeof(struct account), 1, accountsFP) != 0) {
        printf("%-16s\t\t%-16s\t\t%-9.2lf\n", user.account_No, user.account_Name, user.account_Balance);
    }
    printf("--------------------------------------------------------------------------------\n");
    fclose(accountsFP);
}
bool checkAvailability(char accountNo[]) {
    FILE *accountsFP = fopen("ACCOUNTS.dat", "rb");

    checkFile(accountsFP);

    while (fread(&user, sizeof(struct account), 1, accountsFP) != 0) {
        if (strcmp(user.account_No, accountNo) == 0) {
            fclose(accountsFP);
            return true;
        }
    }
    fclose(accountsFP);
    return false;
}
void removeAccount() {
    char accountNumber[25];
    bool accountFound = false;

    FILE *accountsFP = fopen("ACCOUNTS.dat", "rb");

    if (accountsFP == NULL) {
        printf("File cannot be read!");
        return;
    }

    FILE *tempFP = fopen("TEMP.dat", "wb");

    if (tempFP == NULL) {
        printf("File cannot be opened for writing!");
        fclose(accountsFP);
        return;
    }


    printf("\nWhich account number do you wish to remove?: ");
    scanf("%s", accountNumber);


    while (fread(&user, sizeof(struct account), 1, accountsFP) != 0) {
        if (strcmp(user.account_No, accountNumber) == 0) {
            int tries = 3;
            while (tries > 0) {
                printf("Enter PIN: ");
                scanf("%d", &pin);
                if (user.PIN == pin) {
                    accountFound = true;
                    break;
                } else {
                    printf("\nWrong PIN! You have %d tries left\n", --tries);
                }
            }
            break;
        }
    }


    rewind(accountsFP);
    while (fread(&user, sizeof(struct account), 1, accountsFP) != 0) {
        if (strcmp(user.account_No, accountNumber) != 0) {
            fwrite(&user, sizeof(struct account), 1, tempFP);
        }
    }


    fclose(accountsFP);
    fclose(tempFP);


    if (accountFound) {
        remove("ACCOUNTS.dat");
        rename("TEMP.dat", "ACCOUNTS.dat");
    }
    else {
        printf("\nThere is no registered account with a number of %s\n", accountNumber);
        remove("TEMP.dat");
    }
    return;
}
void checkFile(FILE *accountsFP){
    if (accountsFP == NULL) {
        printf("File cannot be created and/or written, read!");
        return;
    }
}
