#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
char *str;
int game_code=10, rem_wickets=0;
int main_score=0, computer_score=0;

void view_scoreboard(int score, int wicket) {
  printf("The Score is: %d - %d\n",score,wicket);
}

void view_scoreboard_chase(int x,int score, int wicket) {
  printf("The Score is: %d - %d\n",score,wicket);
  printf("%d runs required to win!",(x-score));
}

void case_one_function() {
   int score=0, first_wickets=10, first_wicket=0;
   int comp_score=0, second_wickets=10, second_wicket=0;
   srand(time(0));
   printf("Team %s is batting first! Team Computer is bowling!\n",str);
   printf("%s, be warned! Invalid shots will cost you wickets!",str);
   do {
      int shot=0, bowl;
      printf("\nThe bowler is ready! Are you ready?\n Play a shot: ");
      scanf("%d",&shot);
      bowl=rand()%8;
      if(shot>6) {
        printf("The ball's high in the air, and it's caught!\n");
        printf("OUT!");
        first_wickets--;
        first_wicket+=1;
        continue;
        view_scoreboard(score,first_wicket);
      }
       if(bowl>6) {
        printf("No ball!\n");
        printf("It's high in the air!\n");
        score+=7;
        view_scoreboard(score,first_wicket);
        continue;
      }
      if(shot==bowl) {
        printf("OUT!\n");
        first_wickets--;
        first_wicket+=1;
        view_scoreboard(score,first_wicket);
        continue;
      }
      else {
        score+=shot;
        view_scoreboard(score,first_wicket);
      }

   } while(first_wickets!=0);
   main_score=score;
   main_score+=1;
   printf("\n %s's Team has scored %d runs! The Computer needs to score %d runs",str,score,main_score);
   printf("Be warned! Invalid bowls will cost you runs!\n");
   do {
     int shot=0, bowl;
     printf("The Computer is ready! Are you ready to bowl?");
     printf("Bowl now: ");
     scanf("%d",&bowl);
     shot=rand()%8;
     if(bowl>6) {
       printf("Invalid bowl! It's a big hit!\n");
       shot=6;
       comp_score+=6;
       view_scoreboard_chase(main_score,comp_score,second_wicket);
       continue;
     }
     else if(shot>6) {
       printf("Invalid shot!\n");
       printf("It's caught by %s!\n",str);
       second_wicket+=1;
       second_wickets--;
       view_scoreboard_chase(main_score,comp_score,second_wicket);
       continue;
     }
     if(bowl==shot) {
       printf("OUT!\n");
       second_wicket+=1;
       second_wickets--;
       view_scoreboard_chase(main_score,comp_score,second_wicket);
     }
     else {
       comp_score+=shot;
       view_scoreboard_chase(main_score,comp_score,second_wicket);
     }
     if(comp_score>=main_score) {
       printf("Match over!\n");
       computer_score=comp_score;
       printf("Team %s has scored %d runs.",str,main_score);
       printf("\n The Computer has scored %d runs in %d wickets",computer_score,second_wicket);
       printf("\n The Computer has won the match by %d wickets",second_wickets);
       printf("\n You've lost to a computer, fufufu!");
       break;
     }

     else if(second_wicket==10 || second_wickets==0) {
       printf("Match Over!\n");
       computer_score=comp_score;
       printf("Team %s has scored %d runs.",str,main_score);
       printf("\n The Computer has scored %d runs in %d wickets",computer_score,second_wicket);
       printf("\nTeam %s has won the match by %d runs!",str,(main_score-computer_score));
       printf("\nYou've beaten a computer! Good job!\n");
       break;
     }
   } while(second_wickets!=0);
}

void case_two_function() {
  int score=0, first_wickets=10, first_wicket=0;
  int second_score=0, second_wickets=10, second_wicket=0;
  srand(time(0));
  printf("Team Computer is batting first! Team %s is bowling!\n",str);
  do {
  int shot=0, bowl;
  printf("The batsmen are ready! Are you?\n");
  printf("Okie, bowl: ");
  scanf("%d",&bowl);
  shot=rand()%8;
  if(shot>6) {
    printf("The perfect one has hit an imperfect shot!\n"); //The computer can go to hell! Ha!
    printf("It's high in the air and %s has caught it!\n",str);
    first_wicket+=1;
    first_wickets--;
    view_scoreboard(score,first_wicket);
    continue;
  }
   if(bowl>6) {
    printf("No ball!\n");
    score+=7;
    view_scoreboard(score,first_wicket);
    continue;
  }
  if(shot==bowl) {
    printf("OUT!\n");
    first_wicket+=1;
    first_wickets--;
    view_scoreboard(score,first_wicket);
  }
  else {
    score+=shot;
    view_scoreboard(score, first_wicket);
  }

/*  if(first_wicket==10 || first_wickets==0) {
     computer_score=score;
  } */
} while(first_wickets!=0);

computer_score=score;
computer_score+=1;

printf("The Computer has scored %d runs!\nTeam %s needs %d runs to win!",computer_score,str,computer_score);
printf("Invalid shots will cost you runs!\n");
do {
  int shot, bowl;
  printf("Play the shot: ");
  scanf("%d",&shot);
  bowl=rand()%8;
  if(shot>6) {
    printf("The ball is high in the air!\n");
    printf("OUT!\n");
    second_wickets--;
    second_wicket+=1;
    view_scoreboard_chase(computer_score,second_score,second_wicket);
    continue;
  }
  if(bowl>6) {
    printf("No Ball!\n");
    printf("It's gone high!\n");
    second_score+=7;
    view_scoreboard_chase(computer_score,second_score,second_wicket);
    continue;
  }
  if(shot==bowl) {
    printf("OUT!\n");
    second_wicket+=1;
    second_wickets--;
    view_scoreboard_chase(computer_score,second_score,second_wicket);
  }
  else {
    second_score+=shot;
    view_scoreboard_chase(computer_score,second_score,second_wicket);
  }
  //Result part
  if(second_score>=computer_score) {
    printf("Match Over!\n");
    main_score=second_score;
    printf("The Computer has scored %d runs.\n",computer_score);
    printf("Team %s has scored %d runs in %d wickets.",str,main_score,second_wicket);
    printf("\nTeam %s has won by %d wickets!",str,second_wickets);
    printf("\nYou've beaten the computer! Wooo!\n");
    break;
  }
  if(second_wicket==10 || second_wickets==0) {
    printf("Match Over!\n");
    main_score=second_score;
    printf("The Computer has scored %d runs.\n",computer_score);
    printf("Team %s has scored %d runs in %d wickets.",str,main_score,second_wicket);
    printf("The Computer has won by %d runs!\n",(computer_score-main_score));
    printf("You've lost to a computer! Fufufufu!\n");
    break;
  }
} while(second_wickets!=0);
}

void case_three_function() {
  printf("Team Computer is batting first! Team %s is bowling!\n",str);
  case_two_function();
}

void case_four_function() {
  printf("Team %s is batting first! Team Computer is bowling!\n",str);
  case_one_function();
}

void start_game_play(int game_play_op) {
   switch(game_play_op) {
      case 11: case_one_function();
               break;
      case 12: case_two_function();
               break;
      case 21: case_three_function();
               break;
      case 22: case_four_function();
               break;
      default: printf("Error!");
   }
}

void toss_decision() {
  int toss, choice, game_play_op;
  srand(time(0));
  printf("\nEnter the toss: Head(1) or Tails(0)? ");
  scanf("%d",&choice);
  toss=rand()%10;
  toss%=2;
  switch(toss) {
    case 1: if(choice==1) {
                printf("\n %s, You've won the toss!\nWhat do you want to do?",str);
                printf("\n1.Bat \n2.Bowl\n");
                scanf("%d",&game_play_op);
                start_game_play(game_code+game_play_op);
            }
            else {
              printf("\n %s, You've lost the toss!!\n",str);
              game_play_op=(rand()%2)+1;
              if(game_play_op==1) {
                printf("The Computer has won the toss and has decided to bat!\n");
                start_game_play(game_code+game_play_op+10);
              }
              else {
                printf("The Computer has won the toss and has decided to bowl!\n");
                start_game_play(game_code+game_play_op+10);
              }
            }
            break;

    case 0: if(choice==0) {
              printf("\n %s, You've won the toss!\nWhat do you want to do?",str);
              printf("\n1.Bat \n2.Bowl\n");
              scanf("%d",&game_play_op);
              start_game_play(game_code+game_play_op);
            }
            else {
              printf("\n %s, You've lost the toss!!\n",str);
              game_play_op=(rand()%2)+1;
              if(game_play_op==1) {
                printf("The Computer has won the toss and has decided to bat!\n");
                start_game_play(game_code+game_play_op+10);
              }
              else {
                printf("The Computer has won the toss and has decided to bowl!\n");
                start_game_play(game_code+game_play_op+10);
              }
            }
            break;

       default: printf("Error!");
  }
}

void entry() {
  str=(char *)malloc(20*sizeof(char));
  printf("Enter the name: ");
  scanf("%s",str);
  printf("It's Team %s V/S Team Computer!\n",str);
}

int main(void) {
  int choice=1;
  entry();
  do {
  toss_decision();
  printf("Do you want to play again? Yes(1)/No(0)?");
  scanf("%d",&choice);
} while(choice!=0);
  return 0;
}


