#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X long long int
char *str;
X playing_code=0, terminater;
X main_score, chase_score, comp_score, comp_chase;
/* playing code: 11 -> Player bats, Computer bowls first
   playing code: 12 -> player bowls, Computer bats first
   playing code: 15 -> Computer bats, Player bowls first
   playing code: 16 -> Computer bowls, Player bats first */
   

void scoreboard(X score, X wicket) {
    if(playing_code==11 || playing_code==16) {
    printf("The Score is: %lld - %lld\n",score,wicket);
    }
}

X chase_board(X score) {
    chase_score=comp_score-score;
    printf("You need %lld runs to win!",chase_score);
    if(chase_score==0||chase_score<0) {
        terminater=1;
    }
    terminater=0;
    return terminater;
}

void bat() {
    if((playing_code==11||playing_code==16)) {
     printf("%s Team is batting first! The Computer is bowling!",str);
    } 
    else {
        printf("%s Team has to beat the score %lld of the Computer!",str,comp_score);
    }
     X score=0, wickets=10, wicket=0;
     printf("Invalid shots will cost you wickets!\n");
     do {
        X shot, bowl;
        srand(time(0));
        printf("The bowler is ready!\nYou score is %lld - %lld\nPlay the shot: ",score,wicket);
        scanf("%lld",&shot);
        if(shot>6) {
            printf("Invalid shot!\nIt's high in the air and caught!\nOUT!\n");
            wickets--;
            wicket+=1;
            continue;
            scoreboard(score,wicket);
        }
        bowl=rand()%7;
        if(shot==bowl) {
            printf("OUT!\n");
            wickets--;
            wicket+=1;
            scoreboard(score,wicket);
        }
        else {
            score+=shot;
            scoreboard(score,wicket);
        }
        
        if(playing_code==12||playing_code==15) {
            scoreboard(score,wicket);
            terminater=chase_board(score);
            if(terminater==1) {
                break;
            }
        }
        if(wickets==0 || wicket==10) {
            main_score=score;
            scoreboard(main_score,wicket);
        }
     } while(wickets!=0);
 }

X defend_board(X score) {
    comp_chase=main_score-score;
    printf("The Computer needs %lld runs to win!\n",comp_chase);
    if(comp_chase<=0) {
        terminater=1;
    }
    terminater=0;
    return terminater;
}

void bowl() {
   if(playing_code==11||playing_code==16) {
       printf("%s Team has to defend the score of %lld to win against the Computer!",str,main_score);
   }
   else {
       printf("%s Team has to score higher than the Computer's score!\n",str);
   }
   X score=0, wickets=10, wicket=0;
   printf("Invalid balls will cost you runs!\n");
   do {
       X shot=0, bowl;
       printf("The batsmen are ready! Their score is %lld - %lld\nAre you?\n Bowl: ",score,wicket);
       shot=rand()%7;
       scanf("%lld",&bowl);
       if(bowl>6) {
           printf("No ball!");
           shot=7;
           score+=shot;
           scoreboard(score,wicket);
           continue;
       }
       if(shot==bowl) {
           printf("OUT!\n");
           wickets--;
           wicket+=1;
           scoreboard(score,wicket);
       }
       else {
           score+=shot;
           scoreboard(score,wicket);
       }
       scoreboard(score,wicket);
       if(playing_code==11||playing_code==16) {
           scoreboard(score,wicket);
           terminater=defend_board(score);
           if(chase_score<=0) {
               printf("That's it!\n");
               break;
           }
           if(terminater==1) {
               break;
           }
       }
       if(wickets==0||wicket==10) {
           comp_score=score;
       }
   } while(wickets!=0);
}

void victory_result() {
        printf("%s has scored: %lld - 10",str,main_score);
        printf("\n The Computer has scored: %lld",comp_score);
        if(comp_score>=main_score) {
        printf("\n The Computer has beaten %s!\n",str);
        printf("%s, you've lost to a computer! Fu fu fu!",str);
        }
        else {
            printf("%s, You've beaten the Computer! by %lld runs",str,(main_score-comp_score));
            printf("\n Yeah, Congratulations! But you've beaten a souless device, should you celebrate? Ha!");
        }
}

void start_game(X playing_code) {
    switch(playing_code) {
        case 11: printf("The Player %s is batting first! The Computer will bowl!\n",str);
                 bat();
                 bowl();
                 victory_result();
                 break;
        case 12: printf("The Player %s is bowling first! The Computer will bat!\n",str);
                 bowl();
                 bat();
                 victory_result();
                 break;
        case 15: printf("The Computer is batting first! The Player %s will bowl!\n",str);
                 bowl();
                 bat();
                 victory_result();
                 break;
        case 16: printf("The Computer is bowling first! The Player %s will bat!\n",str);
                 bat();
                 bowl();
                 victory_result();
                 break;
        default: printf("Error!\n");
    }
}

void start_toss_option() {
    srand(time(0));
    X toss, option, decision;
    printf("It's time for the toss!\n");
    printf("Heads (1) or Tails (0): ");
    scanf("%lld",&option);
    toss=rand()%2;
    if(toss==1) {
        if(option==toss) {
            printf("The call was Heads and the coin showed Heads!\n");
            printf("You've won the toss!");
            printf("What do you want to do? Bat (1) or Bowl (2)?\n");
            scanf("%lld",&decision);
            if(decision>2 || decision<1) {
                printf("Invalid option! You are batting first :| \n");
                playing_code=11;
            }
            playing_code=10+decision;
            start_game(playing_code);
        }
        else {
            printf("The call was Tails and the coin showed Heads!\n");
            printf("You've lost the toss!\n");
            decision=rand()%2;
            if(decision==1) {
                printf("The Computer has decided to bat first!\n");
                playing_code=15;
                start_game(playing_code);
            }
            else {
                printf("The Computer has decided to bowl!\n");
                playing_code=16;
                start_game(playing_code);
            }
        }
    }
    else {
        if(option==toss) {
            printf("The call was Tails and the coin lands on Tails!\n");
            printf("You've won the toss!");
            printf("What do you want to do? Bat(1) or Bowl(2)? \n");
            scanf("%lld",&decision);
            if(decision==1) {
                playing_code=11;
                start_game(playing_code);
            }
            else {
                playing_code=12;
                start_game(playing_code);
            }
        }
        else {
            printf("The call was Heads and the coin lands on Tails!\n");
            printf("You've lost the toss!\n");
            decision=rand()%2;
            if(decision==1) {
                printf("The Computer has decided to bat first!\n");
                playing_code=15;
                start_game(playing_code);
            }
            else {
                printf("The Computer has decided to bowl first!\n");
                playing_code=16;
                start_game(playing_code);
            }
        }
    }
    
}

void entry() {
    str=(char *)malloc(20*sizeof(char));
    printf("Enter the name: ");
    scanf("%s",str);
    printf("%s will be against the Computer!\n",str);
}

int main(void) {
    X choice=1;
    do {
        entry();
        start_toss_option();
        printf("\nDo you want to play again? Yes(1) or No(0): ");
        scanf("%lld",&choice);
    }while(choice!=0);
    return 0;
}
