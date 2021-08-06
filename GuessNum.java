package numguesser;

import java.util.Scanner;

public class GuessNum {
   public static void main(String[] args) {
       //MINI PROJECT
       @SuppressWarnings("resource")
	Scanner sc = new Scanner(System.in);
       int myNumber = (int)(Math.random()*100);
       int userNumber = 0;
       System.out.println("Welcome to the Guess the Number Game!");
       System.out.println("You have unlimited chances to guess the correct number");

       do {
           System.out.println("Guess my number(1-100) : ");
           userNumber = sc.nextInt();

           if(userNumber == myNumber) {
               System.out.println("THATS RIGHT!... CORRECT NUMBER!!!");
               break;
           }
           else if(userNumber > myNumber) {
               System.out.println("your number is too large");
           }
           else {
               System.out.println("your number is too small");
           }
       } while(userNumber >= 0);

       System.out.print("My number was : ");
       System.out.println(myNumber);
   }
}

