#include <iostream>

void calculator();
void guessingGame();
void cppBank();
void checkBalance(double balance);
double withdraw(double balance);
double deposit(double balance);
void rockPaperScissorsGame();
char userChoice();
char computerChoice();
void showChoice(char choice);
int checkWinner(char user, char computer, int &userPoints, int &computerPoints);
void votingProgram();
void winner(int &BBM, int &Leni, int &Manny, int &Isko);
void harryPotterGame();

int main(){

    int choice;

std:: cout << "----------------------------\n";
std:: cout << "What do you want to do today?\n";
std:: cout << "----------------------------\n\n";
std:: cout << "0. Exit\n";
std:: cout << "1. Calculator\n";
std:: cout << "2. Guessing Game\n";
std:: cout << "3. C++ Bank\n";
std:: cout << "4. Rock Paper Scissor Game\n";
std:: cout << "5. Vote for your president\n";
std:: cout << "6. Harry Potter Game\n";

std:: cout << '\n';
std:: cin >> choice;

switch (choice) {
    case 0: std:: cout << "Thank you for using, have a nice day";
        break;
    case 1: calculator();
        break;
    case 2: guessingGame();
        break;
    case 3: cppBank();
        break;
    case 4: rockPaperScissorsGame();
        break;
    case 5: votingProgram();
        break;
    case 6: harryPotterGame();
        break;

        
    default: std:: cout << "Wrong input!";

}




    return 0;
}

void calculator () {

double num1, num2, result;
char choice;



std:: cout << "------------------------------\n";
std:: cout << "          CALCULATOR\n";
std:: cout << "------------------------------\n";

do {

std:: cout << "Select your preferred operation to use\n";
std:: cout << "0 for exit\n";
std:: cout << "+ for addition\n";
std:: cout << "- for subtraction\n";
std:: cout << "* for multiplication\n";
std:: cout << "/ for division\n";


std:: cin >> choice;

    if (choice == '0') {
        std:: cout << "Thank you for using!\n";
        break;
    }

    else if (choice != '+' && choice != '-' && choice != '*' && choice != '/') {
        std:: cout << "Invalid input!\n";
        
    }

    else {
    std:: cout << "Enter first number: ";
    std:: cin >> num1;

    std:: cout << "Enter second number: ";
    std:: cin >> num2;
    }

switch (choice) {

    

    case '+': 

    result = num1 + num2;
    std:: cout << "The sum of the two number is: " << result << '\n' << '\n';
        break;
    case '-':

    result = num1 - num2;
    std:: cout << "The difference of the two number is: " << result << '\n' << '\n';
        break;

    case '*':

    result = num1 * num2;
    std:: cout << "The product of the two number is: " << result << '\n' << '\n';
        break;

    case '/':

    result = num1 / num2;
    std:: cout << "The quotient of the two number is: " << result << '\n' << '\n';
        break;

    


}


} while (choice != '0');

    
}
void guessingGame () {
    int num, guess, tries, choice;

std:: cout << "------------------------------\n";
std:: cout << "        Guessing Game\n";
std:: cout << "------------------------------\n";

do {

    srand(time(NULL));
    guess = (rand() % 100) + 1;

    do {


    std:: cout << "Enter a number: ";
    std:: cin >> num;
    tries++;

    if (num > guess) {
        std:: cout << "Your guess is way higher!\n";
    }

    else if (num < guess) {
        std:: cout << "Your guess is way lower\n";
    }

    else {
        std:: cout << "YOU GUESSED IT RIGHT!\n";
        std:: cout << "Your tries before guessing it right: " << tries << '\n';
        std:: cout << "Do you want to play again? 1 for yes, 0 for no\n";
        std:: cin >> choice;
    }



    } while (num != guess);

tries = 0;

} while (choice != 0);
}
void cppBank () {

int choice;
double balance = 0;

std:: cout << "------------------------------\n";
std:: cout << "           C++ Bank\n";
std:: cout << "------------------------------\n";

std:: cout << "What do you want to do today?\n\n";
std:: cout << "Enter the respective number of your choice\n";

do {

std:: cout << "1. Check Balance\n";
std:: cout << "2. Withdraw\n";
std:: cout << "3. Deposit\n";
std:: cout << "4. Exit\n";

std:: cin >> choice;

switch (choice) {
    
    case 1: checkBalance(balance);
        break;
    case 2: balance -= withdraw(balance);
            checkBalance(balance);
        break;
    case 3: balance += deposit(balance);
            checkBalance(balance);
        break;
    case 4: std:: cout << "Transaction Done, have a nice day!";
        break;
    default: std:: cout << "Wrong input!\n\n";
}

} while (choice != 4);

}
void checkBalance(double balance){
    std:: cout << "Your current balance is: ₱" << balance << '\n' << '\n';
    
}
double withdraw(double balance){

    double amount = 0;

    std:: cout << "Enter amount to be withdrawn: ₱";
    std:: cin >> amount;

    if (amount > balance) {
        std:: cout << "Insufficient funds!\n\n";
        return 0;
    }

    else if (amount < 0) {
        std:: cout << "Invalid amount!\n\n";
        return 0;
    }

    else {
        std:: cout << "You've successfully withdrawn ₱" << amount << " in your bank account\n\n";
        return amount;
    }

}
double deposit(double balance){
    
    double amount = 0;

    std:: cout << "Enter amount you want to deposit: ₱";
    std:: cin >> amount;

    if (amount < 0) {
        std:: cout << "That's a invalid amount!\n\n";
        return 0;
    }

    else {
        std:: cout << "You've successfully deposited an amount of ₱" << amount << " into your bank account\n\n";
        return amount;
    }

}
void rockPaperScissorsGame(){

char user, computer, answer;

int userPoints = 0;
int computerPoints = 0;

std:: cout << "------------------------------\n";
std:: cout << "    Rock Paper Scissor Game\n";
std:: cout << "------------------------------\n";

do {



user = userChoice();
std:: cout << "\nYour choice: ";
showChoice(user);

computer = computerChoice();
std:: cout << "Computer's choice: ";
showChoice(computer);

checkWinner(user, computer, userPoints, computerPoints);

    do {

std:: cout << "\nDo you want to play again? y for yes n for no: ";
std:: cin >> answer;

    } while (answer != 'y' && answer != 'n');

} while (answer != 'n');


if (userPoints > computerPoints){
    std:: cout << "-----------";
    std:: cout << "\n You won!\n";
    std:: cout << "-----------";
    std:: cout << "\nYour total points: " << userPoints << '\n';
    std:: cout << "Computer's total points: " << computerPoints << '\n';

}

else if (userPoints < computerPoints){
    std:: cout << "----------";
    std:: cout << "\n You lose\n";
    std:: cout << "----------";
    std:: cout << "\nYour total points: " << userPoints << '\n';
    std:: cout << "\nComputer's total points: " << computerPoints << '\n';
}

else {
    std:: cout << "-------------";
    std:: cout << "\n It's a tie!\n";
    std:: cout << "-------------";
    std:: cout << "\nYour total points: " << userPoints << '\n';
    std:: cout << "\nComputer's total points: " << computerPoints << '\n';

}

   
}
char userChoice(){
    char user;

    do {

    std:: cout << "Please select your choice: \n";
    std:: cout << "r for Rock\n";
    std:: cout << "p for Paper\n";
    std:: cout << "s for Scissor\n";
    std:: cin >> user;

    } while (user != 'r' && user != 'p' && user != 's');
    
    return user;

}
char computerChoice(){
    
    char computer;

    srand(time(NULL));

    computer = (rand () % 3 ) + 1;

    switch (computer){
        case 1: return 'r';
            break;
        case 2: return 'p';
            break;
        case 3: return 's';
            break;
    }

    return 0;
}
void showChoice(char choice){

    
    switch (choice){
        case 'r': std:: cout << "Rock\n";
            break;
        case 'p': std:: cout << "Paper\n";
            break;
        case 's': std:: cout << "Scissor\n";
            break;
    }

}
int checkWinner(char user, char computer, int &userPoints, int &computerPoints){
    
    

    switch (user) {
        case 'r': if (computer == 'r') {
            std:: cout << "\nIt's a tie!\n\n";
            std:: cout << "Your Points: " << userPoints << '\n';
            std:: cout << "Computer's Points: " << computerPoints << '\n';
            
            return 0;

        }

        else if (computer == 'p') {
            std:: cout << "\nYou lose\n\n";
            computerPoints++;
            std:: cout << "Your Points: " << userPoints << '\n';
            std:: cout << "Computer's Points: " << computerPoints << '\n';
            
            return computerPoints;

        }

        else {
            std:: cout << "\nYou won!\n\n";
            userPoints++;
            std:: cout << "Your Points: " << userPoints << '\n';
            std:: cout << "Computer's Points: " << computerPoints << '\n';
            
            return userPoints;

        }

        case 'p': if (computer == 'r') {
            std:: cout << "\nYou won!\n\n";
            userPoints++;
            std:: cout << "Your Points: " << userPoints << '\n';
            std:: cout << "Computer's Points: " << computerPoints << '\n';

            return userPoints;

        }

        else if (computer == 'p') {
            std:: cout << "\nIt's a tie!\n\n";
            std:: cout << "Your Points: " << userPoints << '\n';
            std:: cout << "Computer's Points: " << computerPoints << '\n';

            return 0;

        }

        else {
            std:: cout << "\nYou lose\n\n";
            computerPoints++;
            std:: cout << "Your Points: " << userPoints << '\n';
            std:: cout << "Computer's Points: " << computerPoints << '\n';

            return computerPoints;

        }

        case 's': if (computer == 'r') {
            std:: cout << "\nYou lose\n\n";
            computerPoints++;
            std:: cout << "Your Points: " << userPoints << '\n';
            std:: cout << "Computer's Points: " << computerPoints << '\n';

            return computerPoints;

        }

        else if (computer == 'p') {
            std:: cout << "\nYou won!\n\n";
            userPoints++;
            std:: cout << "Your Points: " << userPoints << '\n';
            std:: cout << "Computer's Points: " << computerPoints << '\n';

            return userPoints;

        }

        else {
            std:: cout << "\nIt's a tie!\n\n";
            std:: cout << "Your Points: " << userPoints << '\n';
            std:: cout << "Computer's Points: " << computerPoints << '\n';

            return 0;

        }
        
        

    }

    return 0;
}
void votingProgram(){

    std::string *pVoters = NULL;
    int *pCandidates = NULL;
    int BBM = 0, Leni = 0, Manny = 0, Isko = 0;
    int candidate = 0, answer, size;

    std::cout << "How many people will vote today?";
    std::cin >> size;

    pVoters = new std::string[size];
    pCandidates = new int [size];

    std:: cout << "------------------------------\n";
    std:: cout << "         C++ Election\n";
    std:: cout << "------------------------------\n";   

    for (int i = 0; i < size; i++){
    std::cout << "Enter your last name: ";
    std::cin >> pVoters[i];
   
    std::cout << "------------------" << '\n';
    std::cout << "1. Bongbong Marcos" << '\n';
    std::cout << "2. Leni Robredo" << '\n';
    std::cout << "3. Manny Paquiao" << '\n';
    std::cout << "4. Isko Moreno" << '\n';
    std::cout << "------------------" << '\n';

    std::cout << "Enter candidate to vote: ";
    std::cin >> pCandidates[i];

    std::cin.clear();
    fflush(stdin);

        switch(pCandidates[i]){
            case 1: BBM++;
                    break;
            case 2: Leni++;
                    break;
            case 3: Manny++;
                    break;
            case 4: Isko++;
                    break;
            default: std::cout << "Wrong input\n";
        }

    }

    std::cout << "------Total votes-----\n";
    std::cout << "Bongbong Marco's votes: " << BBM << '\n';
    std::cout << "Leni Robredo's votes: " << Leni << '\n';
    std::cout << "Manny Paquiao's votes: " << Manny << '\n';
    std::cout << "Isko Moreno's votes: " << Isko << '\n';
    std::cout << "\nNAMES     : PRESIDENT:\n";

    for(int k = 0; k < size; k++){
        
        if (pCandidates[k] == 1){
        std::cout << "------------------------------\n";
        std::cout << pVoters[k] << " voted for Bongbong Marcos\n";
        }

        else if (pCandidates[k] == 2){
        std::cout << "------------------------------\n";
        std::cout << pVoters[k] << " voted for Leni Robredo\n";
        }

        else if (pCandidates[k] == 3){
        std::cout << "------------------------------\n";
        std::cout << pVoters[k] << " voted for Manny Paquiao\n";
        }

        else if (pCandidates[k] == 4){
        std::cout << "------------------------------\n";
        std::cout << pVoters[k] << " voted for Isko Moreno\n";
        }

    }

    delete[] pVoters;
    delete[] pCandidates;

    winner(BBM, Leni, Manny, Isko);

}
void winner(int &BBM, int &Leni, int &Manny, int &Isko){

    if (BBM > Leni && BBM > Manny && BBM > Isko){
        std::cout << "------------------------------\n";
        std::cout << "BONGBONG MARCOS WON!\n";
        
    }

    else if (Leni > BBM && Leni > Manny && Leni > Isko){
        std::cout << "------------------------------\n";
        std::cout << "LENI ROBREDO WON!\n";
        
    }

    else if (Manny > BBM && Manny > Leni && Manny > Isko){
        std::cout << "------------------------------\n";
        std::cout << "MANNY PAQUIAO WON!\n";
        
    }

    else if (Isko > BBM && Isko > Leni && Isko > Manny){
        std::cout << "------------------------------\n";
        std::cout << "ISKO MORENO WON!\n";
        
    }

}
void harryPotterGame(){

    char spot[] = {'w', 's', 's', 'd', 'b', 'd', 'w', 'b', 'b', 'd', 'w', 's', 'w', 'd', 'b', 'd', 's', 'w', 'b', 's' };
    int position;
    int points = 0;  
    
    std:: cout << "------------------------------\n";
    std:: cout << "       Harry Potter Game\n";
    std:: cout << "------------------------------\n";        

    while (points >= 0){

        std::cout << "Select a location in Hogarth Tower between 0 - 19: ";
        std::cin >> position;

        if (position < 0 || position > 19){
            std::cout << "The game is over, your inputted a invalid amount\n";
            break;
        }

        spot[position];

            switch(spot[position]){
                case 'b': std::cout << "Safe place, 2 points is awarded\n";
                points += 2;
                std::cout << "Points: " << points << '\n';
                break;
                case 'w': std::cout << "You picked up a Wizard, 3 points is awarded\n";
                points += 3;
                std::cout << "Points: " << points << '\n';
                break;
                case 's': std::cout << "You picked up a Sword, 4 points is awarded\n";
                points += 4;
                std::cout << "Points: " << points << '\n';
                break;
                case 'd': std::cout << "A demon has attacked, -5 points\n";
                points -= 5;
                std::cout << "Points: " << points << '\n';
                break;
            }

        if (points < 0){
            std::cout << "You are killed\n";
            break;
        }

    }
}



