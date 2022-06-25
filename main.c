//SBG my first game.

/*This version is for Windows only, for Unix I need to change the clear screen and sleep commands*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

#define point_pool 100
#define NAME_LEN 10

int getbet();/*Declaring Functions*/
int bethigh();
int betlow();
int checkbet();
int disphigh();
int highwrite();

long points;/*Global Variables*/
int dice1;
int dice2;
long bet;
int hilo;
char player[NAME_LEN+1];
struct highscore {
    long score;
    char name[NAME_LEN+1];
    }highscore1;

int main()
{

int i;
char c;
points = point_pool; //Set starting points to 100

printf("                          //   ) )  //   ) )  //   ) ) \n");
printf("                         ((        //___/ /  //        \n");
printf("                           \\     / __  (   //  ____   \n");
printf("                             ) ) //    ) ) //    / /   \n");
printf("                      ((___ / / //____/ / ((____/ /    \n\n");
printf("Welcome to Simple Betting Game. Each turn I will roll a 10 sided dice, you will\nthen place a bet on whether the next roll will be higher or lower than the\nprevious roll. The less likely your bet is the higher the payout will be. If \nthe number is the same as the first roll then I keep the bet.\n\nYou have 100 points and 15 rounds to get the high score.\n");
printf("\n\n\n\n\n\n\n\nCurrent High Score:");
disphigh();
printf("\nEnter your name start the game: ");
scanf("%s", player);
system ("cls");

for(i = 1;i <=15;i++)
    {
  if(points < 1) break;
    else{
        srand(time(NULL));
        dice1 = rand() % 10 + 1;

        printf("    //   ) )  //   ) )  //   ) )                          Player: %s\n", player);
        printf("   ((        //___/ /  //                                 Current Points: %ld\n", points);
        printf("     \\     / __  (   //  ____                             Rounds left: %d\n", 16 - i);
        printf("       ) ) //    ) ) //    / /   \n");
        printf("((___ / / //____/ / ((____/ /    \n\n");

        printf("\n\n\n\nRoll 1: %d \n\nEnter 'H' to bet high, enter 'L' to bet low, any other entry cashes out: ", dice1);
        getbet();

        dice2 = rand() % 10 + 1;

        if(hilo == 1){bethigh();} //reading input then reacting to a low or high bet.
            else if (hilo == 0){betlow();}
            else break;
        Sleep(3000);
        system ("cls");
        }
    }
highwrite();
  return 0;
}

/*Determines if player wants to bet high or low*/
int getbet()
{
char c;

scanf(" %c", &c);
c = tolower(c);
if(c == 104){hilo = 1;} //reading input then reacting to a low or high bet.
  else if (c == 108){hilo = 0;}
  else {hilo = 3;}
return 0;
}
/*Get the players bet, verify the bet is valid, then apply the results*/
int bethigh()
{
printf("\n\nYou have bet high. How many points would you like to bet?\nYour Bet: ");
scanf("%ld", &bet);//place bet
checkbet();//verify the bet is valid
if(dice1 < dice2){
  switch(dice1){//apply results
    case 1: points = points + (bet / 8); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet / 8); break;
    case 2: points = points + (bet / 6); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet / 6); break;
    case 3: points = points + (bet / 4); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet / 4); break;
    case 4: points = points + (bet / 2); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet / 2); break;
    case 5: points = points + (bet); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet); break;
    case 6: points = points + (bet); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet); break;
    case 7: points = points + (bet * 2); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet * 2); break;
    case 8: points = points + (bet * 3); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet * 3); break;
    case 9: points = points + (bet * 5); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet * 5); break;
    }
  }
  else{
    printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have lost %ld Points.", dice1, dice2, bet);
    points = points - bet;
  }
return 0;
}

/*Get the players bet, verify the bet is valid, then apply the results*/
int betlow()
{
printf("\n\nYou have bet low. How many points would you like to bet?\nYour Bet: ");
scanf("%ld", &bet);//place bet
checkbet();//verify the bet is valid
if(dice1 > dice2){//apply results
  switch(dice1){
    case 2: points = points + (bet * 5); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet * 5); break;
    case 3: points = points + (bet * 3); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet * 3); break;
    case 4: points = points + (bet * 2); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet * 2); break;
    case 5: points = points + (bet); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet); break;
    case 6: points = points + (bet); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet); break;
    case 7: points = points + (bet / 2); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet / 2); break;
    case 8: points = points + (bet / 4); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet / 4); break;
    case 9: points = points + (bet / 6); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet / 6); break;
    case 10: points = points + (bet / 8); printf("\n\n\n\nRoll 1: %d\nRoll 2: %d\n\nYou have won %ld Points.", dice1, dice2, bet / 8); break;
    }
  }
  else{
    printf("\nRoll 1: %d\nRoll 2: %d\n\n\n\n\nYou have lost %ld Points.", dice1, dice2, bet);
    points = points - bet;
  }
return 0;
}

/*checks to ensure bet is valid*/
int checkbet()
{
if(bet < 1){
    printf("\nYour bet must be at least 1 point.\nYour Bet: ");
    scanf("%ld", &bet);
    checkbet();
    }
    else if (bet > points){
        printf("\nYou only have %ld points.\nYour Bet: ", points);
        scanf("%ld", &bet);
        checkbet();
        }
    else return 0;
}

/*Reads high score file and prints high scores*/
int disphigh()
{
    FILE *fp;
    if ((fp = fopen("highscore.txt", "rb")) == NULL){
        printf("ERROR: HIGHSCORES COULD NOT BE LOADED OR SAVED!\n");
        return;
        }
    fread(&highscore1, sizeof(highscore1), 1, fp);
    fclose(fp);
    printf(" %s    %-15ld\n", highscore1.name, highscore1.score);
    return;
}



/*Checks if user has a high score then asks for name and updates high score list.*/
int highwrite()
{
    FILE *fp;
    fp = fopen("highscore.txt", "wb");

    if(points > highscore1.score){
            highscore1.score = points;
            strcpy(highscore1.name, player);

            }

    fwrite(&highscore1, sizeof(highscore1), 1, fp);
    fclose(fp);
return;
}
