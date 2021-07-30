//A number guessing game in C
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x long long int

void guessing(x num, x choice2) {
    x entry,chance=4;
    if(choice2==1) {
    do {
    printf("\nEnter your guess: ");
    scanf("%lld",&entry);
    if(entry==num) {
       printf("\nYou have guessed it right! The number is %lld",num);
       break;  
     } 
    else {
       printf("\nWrong guess! Try that again!");
       chance--;
     }
    
    if(chance==0) {
       printf("\nThe number was %lld",num);
     }
    } while(chance!=0);
  }
  
else {
    do {
    printf("\nEnter your guess: ");
    scanf("%lld",&entry);
    if(entry==num) {
       printf("\nYou have guessed it right! The number is %lld",num);
       break;
     } 
    else {
       printf("\nWrong guess! Try that again!");
     }
  } while(chance!=0);  
 }
}

void game_play(x choice1, x choice2) {
   srand(time(0));
   x num;     
   switch(choice1) {
      case 1: num=rand()%10;
              guessing(num,choice2);
              break;
      case 2: num=rand()%100;
              guessing(num,choice2);
              break;
      case 3: num=rand()%1000;
              guessing(num,choice2);
              break;
      case 4: num=rand()%10000;  
              guessing(num,choice2);
              break;
      default: printf("Error! Try Again!");
    }   
 }

int main(void) {
   x choice1,choice2,exit=1;
   do {
   printf("Enter the level!\n1.Easy \n2.Medium \n3.Hard \n4.Pro");
   scanf("%lld",&choice1);
   printf("Enter the number of chances:\n1.Limited \n2.Unlimited");
   scanf("%lld",&choice2);
   game_play(choice1,choice2);
   system("clear");
   printf("\nDo you want to  play again? 1 to yes, else no");
   scanf("%lld",&exit);
   } while(exit!=0); 
   return 0;
}

