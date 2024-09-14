import java.util.Scanner;

public class Airline {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int answer;
		int choice;
		int column;
		int row;
		
		char[][] seats = new char[10][3];
		
		//Fill all of the char array with o's
		for(int i = 0; i < seats[0].length; i++) {
			for(int j = 0; j < seats.length; j++) {
				seats[j][i] = 'A';
			}
		}
		
		do {
			
			System.out.println("************************* AIRLINE RESERVATION SYSTEM *************************************\n");
			System.out.println("C O L U M N				      R O W					 \n");
			System.out.println("\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
			//Print value of each cell
			for(int i = 0; i < seats[0].length; i++) {
				System.out.print("    " + (i+1) + "	  ");
				for(int j = 0; j < seats.length; j++) {
					System.out.print("  	" + seats[j][i] + "  ");
				}System.out.println();
			}
			
			System.out.println("\nLegend: A = Available O = Occupied");
			System.out.println("******************************************************************************************\n");
			
			System.out.println("Select an option\n [1] Reserve seat\n [2] Exit\n");
			answer = scanner.nextInt();
			
			if(answer == 1) {
				
				//Ensure user to input number between 1 to 3
				do {
					System.out.println("Enter column: ");
					column = scanner.nextInt();
				}while(column > 3 || column <= 0);
				//Ensure user to input number between 1 to length of seats
				do {
					System.out.println("Enter row: ");
					row = scanner.nextInt();
				}while(row > seats.length || row <= 0);
				//Occupy/turn to true the chosen specific cell
				for(int i = column; i <= column; i++) {
					for(int j = row; j <= row; j++) {
						if(seats[j-1][i-1] == 'O') {
							System.out.println("It is already occupied");
						}
						else {
							seats[j-1][i-1] = 'O';
						}
					}
				}
				
			}
			
			if (answer != 2 && answer != 1){
				System.out.println("Wrong input\n");
			}
			
			//Check if all seats are occupied then if it is, it will terminate the whole program
			boolean checkOccupied = true;
			for(int i = 0; i < seats[0].length; i++) {
				for(int j = 0; j < seats.length; j++) {
					if(seats[j][i] != 'O') {
						checkOccupied = false;
						break;
					}
				}
			}
			
			if(checkOccupied) {
				System.out.println("\nAll seats are occupied!\n");
				answer = 2;
			}
			
		}while(answer != 2);
		if(answer == 2) {
			System.out.println("Thank you for using and have a safe flight!");
		}
	}
	
}
