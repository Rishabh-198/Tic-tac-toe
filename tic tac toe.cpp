#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
int pl,score[]={0,0};
int x;
int y;
char player1[30];
char player2[30];
char board[3][3];
const char player1_sym = 'X';
const char player2_sym = 'O';
void resetBoard();
void printBoard(int);
int checkFreeSpaces();
void playerMove(); 
void computerMove();
char checkWinner();
void printWinner(char);
int main()
{
   char winner = ' ';
   char response = ' ';
   printf("Enter name of first player:\n");
   gets(player1);
   printf("Enter name of second player:\n");
   gets(player2);
   do
   {  pl=2;
      winner = ' ';
      response = ' ';
      resetBoard();
      int gmode=DETECT, gdriver;
	  initgraph(&gmode, &gdriver, (char*)"");
	  line(170,170,470,170);
	  line(170,240,470,240);
	  line(270,100,270,310);
	  line(370,100,370,310);
	  settextstyle(1,0,1);
	outtextxy(200,130,"11");
	outtextxy(300,130,"12");
	outtextxy(400,130,"13");
	outtextxy(200,200,"21");
	outtextxy(300,200,"22");
	outtextxy(400,200,"23");
	outtextxy(200,270,"31");
	outtextxy(300,270,"32");
	outtextxy(400,270,"33");	
				  	  
	  
      while(winner == ' ' && checkFreeSpaces() != 0)
      { 
   	 if(pl%2==0)
      	 { 
      	 setcolor(0);
      	 settextstyle(3,0,5); 
      	 outtextxy(10,10,"                              ");
		 outtextxy(10,30,"                              ");      	 
		 settextstyle(3,0,2);  
		// setbkcolor(15);  
		 setcolor(3);
         outtextxy(10,10,"Your chance:");
         setcolor(3);
         outtextxy(10,30,player1);
		 printf("%s's move\n",player1);
		 playerMove();
         pl++;
		winner = checkWinner();
		}
		if(winner != ' ' || checkFreeSpaces() == 0)
         {
         	printBoard(1);
            break;
         }
		 printBoard(1);
		if(pl%2!=0)
		{
		setcolor(0);
      	settextstyle(3,0,2); 
      	outtextxy(10,10,"                              ");
		outtextxy(10,30,"                              ");      	
	//	setbkcolor(15);
		settextstyle(3,0,2);    
		setcolor(5);
        outtextxy(10,10,"Your chance:");
        setcolor(5);
		outtextxy(10,30,player2);
		printf("%s's move\n",player2);
        playerMove();
        pl++;
        winner = checkWinner();
 }
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
		 printBoard(2);
            break;
         }
        printBoard(2);
      }
      printWinner(winner);
      printf("\nWould you like to play again? (Y/N): ");
      scanf("%c");
      scanf("%c", &response);
      response = toupper(response);
   } while (response == 'Y');

   printf("Thanks for playing!");

   return 0;
}
void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
void printBoard(int i)
{
	settextstyle(1,0,5);
	if(i%2!=0){
	setcolor(i);
    if(x==0&&y==0)
	outtextxy(200,120,"X");
	if(x==0&&y==1)
	outtextxy(300,120,"X");
	if(x==0&&y==2)
	outtextxy(400,120,"X");
	if(x==1&&y==0)
	outtextxy(200,190,"X");
	if(x==1&&y==1)
	outtextxy(300,190,"X");
	if(x==1&&y==2)
	outtextxy(400,190,"X");
	if(x==2&&y==0)
	outtextxy(200,260,"X");
	if(x==2&&y==1)
	outtextxy(300,260,"X");
	if(x==2&&y==2)
	outtextxy(400,260,"X");
}
else{
	setcolor(i);
	if(x==0&&y==0)
	outtextxy(200,120,"O");
	if(x==0&&y==1)
	outtextxy(300,120,"O");
	if(x==0&&y==2)
	outtextxy(400,120,"O");
	if(x==1&&y==0)
	outtextxy(200,190,"O");
	if(x==1&&y==1)
	outtextxy(300,190,"O");
	if(x==1&&y==2)
	outtextxy(400,190,"O");
	if(x==2&&y==0)
	outtextxy(200,260,"O");
	if(x==2&&y==1)
	outtextxy(300,260,"O");
	if(x==2&&y==2)
	outtextxy(400,260,"O");
   }/*printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");*/
}	
int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void playerMove()
{
   do
   {
   	  int arr[1];
      scanf("%d", &arr[0]);
      x=arr[0]/10;
      x--;
      y=arr[0]%10;
      y--;
      if(x<0||x>2||y<0||y>2)
      {
      	printf("Invalid move\n");
		}
      else
    {  if(board[x][y] != ' ')
      {
         printf("That's invalid move!!\n");
      }
      else
      {
      	if(pl%2==0)
       {
    	board[x][y] = player1_sym;
      }  
	  else
      {
		board[x][y]= player2_sym;
		 } 
		 break;
      }
	  }	
      
   } while(board[x][y] != ' ');
}
char checkWinner()
{  
for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   } 
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }
   return ' ';
}
void printWinner(char winner)
{	
   if(winner == player1_sym)
   {score[0]++;
      printf("%s is winner ",player1);
      printf("\nScore %d:%d",score[0],score[1]);
      settextstyle(3,0,2);
      setcolor(10);
     outtextxy(10,60,"Winner is: ");
      outtextxy(100,60,player1);
      
   }
   else if(winner == player2_sym)
   { score[1]++;
      printf("%s is winner",player2);
      printf("\nScore %d:%d",score[0],score[1]);
       settextstyle(3,0,2);
      outtextxy(10,60,"Winner is: ");
      outtextxy(100,60,player2);
   }
   else{
      printf("IT'S A TIE!");
       printf("\nScore %d:%d",score[0],score[1]);
       outtextxy(10,60,"It's a tie");
   }
}
