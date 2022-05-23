#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int score = 0;
	char parede = (char)219;
	char player = (char)1;
	char fantasma = (char)64;
	float time = 120;
	int playerY = 15, playerX = 9;
	int fantasma1Y = 11, fantasma1X = 9;
	int tabuleiro[23][19] = {'S','C','O','R','E','-','0','0','0',' ',' ','T','I','M','E','-',' ',' ',' ',
						     '=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=',
							 'O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O',
							 'O','*',' ','*',' ','*',' ','*',' ','O',' ','*',' ','*',' ','*',' ','*','O',
							 'O',' ','O','O','*','O','O','O','*','O','*','O','O','O','*','O','O',' ','O',
							 'O','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ','*',' ','*',' ','*','O',
							 'O',' ','O','O','*','O','*','O','O','O','O','O','*','O','*','O','O',' ','O',
							 'O','*',' ','*',' ','O',' ','*',' ','O',' ','*',' ','O',' ','*',' ','*','O',
							 'O','O','O','O','*','O','O','O','*','O','*','O','O','O','*','O','O','O','O',
							 ' ',' ',' ','O',' ','O',' ','*',' ','*',' ','*',' ','O',' ','O',' ',' ',' ',
							 'O','O','O','O','*','O','*','O','O',' ','O','O',' ','O','*','O','O','O','O',
							 ' ',' ',' ',' ',' ','*',' ','O',' ',' ',' ','O',' ',' ',' ',' ',' ',' ',' ',
							 'O','O','O','O','*','O','*','O','O','O','O','O',' ','O','*','O','O','O','O',
							 ' ',' ',' ','O',' ','O',' ','*',' ','*',' ','*',' ','O',' ','O',' ',' ',' ',
							 'O','O','O','O','*','O',' ','O','O','O','O','O','*','O','*','O','O','O','O',
							 'O','*',' ','*',' ',' ',' ',' ',' ','O',' ','*',' ',' ',' ',' ',' ',' ','O',
							 'O',' ','O','O','*','O','O','O',' ','O','*','O','O','O','*','O','O',' ','O',
							 'O','*',' ','O',' ','*',' ','*',' ','*',' ','*',' ','O',' ','O',' ',' ','O',
							 'O','O','*','O','*','O','*','O','O','O','O','O','*','O','*','O',' ','O','O',
							 'O','*',' ',' ',' ','O',' ','*',' ','O',' ','*',' ','O',' ','*',' ','*','O',
							 'O',' ','O','O','O','O','O','O','*','O','*','O','O','O','O','O','O',' ','O',
							 'O','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*','O',
							 'O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O',};
	
	tabuleiro[playerY][playerX] = player;
	tabuleiro[fantasma1Y][fantasma1X] = 'H';
	for(int y = 0;y < 23;y++)
	{
		for(int x = 0;x < 19;x++)
		{
			if(tabuleiro[y][x] == 'O'){tabuleiro[y][x] = parede;}
		}
	}
	
	//Execução
	bool rodando = true;
	bool morreu = false;;
	while(rodando)
	{
		Sleep(15);
		
		system("cls");
		//Tabuleiro
 		int x = 0;
		for(int y = 0; y < 23;)
		{			
			if(x == 19)
			{
	   	   	    x = 0;
	   	  	    printf("\n");
				y++; 		 
			}
			else
			{
				printf("%c ", tabuleiro[y][x]);
				x++;
			}
		}

			//Player
			while(kbhit())
			{
				int key = _getch();
				if(key == 97 & tabuleiro[playerY][playerX-1] != parede)
				{
					if(tabuleiro[playerY][playerX-1] == '*'){ score++;}
					if(tabuleiro[playerY][playerX-1] == fantasma){ morreu = true;}
					tabuleiro[playerY][playerX] = ' ';
					playerX--;
					if(playerX == 0){ playerX = 18;}
					
				}
				if(key == 100 & tabuleiro[playerY][playerX+1] != parede)
				{
					if(tabuleiro[playerY][playerX+1] == '*'){ score++;}
					if(tabuleiro[playerY][playerX+1] == fantasma){ morreu = true;}
					tabuleiro[playerY][playerX] = ' ';
					playerX++;
					if(playerX == 18){ playerX = 1;}
				}
				if(key == 119 & tabuleiro[playerY-1][playerX] != parede)
				{
					if(tabuleiro[playerY-1][playerX] == '*'){ score++;}
					if(tabuleiro[playerY-1][playerX] == fantasma){ morreu = true;}
					tabuleiro[playerY][playerX] = ' ';
					playerY--;
				}
				if(key == 115 & tabuleiro[playerY+1][playerX] != parede)
				{
					if(tabuleiro[playerY+1][playerX] == '*'){ score++;}
					if(tabuleiro[playerY+1][playerX] == fantasma){ morreu = true;}
					tabuleiro[playerY][playerX] = ' ';
					playerY++;
				}
				
				
				tabuleiro[playerY][playerX] = player;
			}
			//Inimigos
			bool emCima;
			
			int mov = rand() % 5;

			if(mov == 1 & tabuleiro[fantasma1Y][fantasma1X-1] != parede)
			{
				if(emCima){ tabuleiro[fantasma1Y][fantasma1X] = '*'; emCima = false;}
				else{ tabuleiro[fantasma1Y][fantasma1X] = ' ';}
				if(tabuleiro[fantasma1Y][fantasma1X-1] == '*'){ emCima = true;}
				if(tabuleiro[fantasma1Y][fantasma1X-1] == player){ morreu = true;}
				fantasma1X--;
			}
			if(mov == 2 & tabuleiro[fantasma1Y][fantasma1X+1] != parede)
			{
				if(emCima){ tabuleiro[fantasma1Y][fantasma1X] = '*'; emCima = false;}
				else{ tabuleiro[fantasma1Y][fantasma1X] = ' ';}
				if(tabuleiro[fantasma1Y][fantasma1X+1] == '*'){ emCima = true;}	
				if(tabuleiro[fantasma1Y][fantasma1X+1] == player){ morreu = true;}				
				fantasma1X++;
			}
			if(mov == 3 & tabuleiro[fantasma1Y-1][fantasma1X] != parede)
			{				
				if(emCima){ tabuleiro[fantasma1Y][fantasma1X] = '*'; emCima = false;}
				else{ tabuleiro[fantasma1Y][fantasma1X] = ' ';}
				if(tabuleiro[fantasma1Y-1][fantasma1X] == '*'){ emCima = true;}
				if(tabuleiro[fantasma1Y-1][fantasma1X] == player){ morreu = true;}
				fantasma1Y--;
			}
			if(mov == 4 & tabuleiro[fantasma1Y+1][fantasma1X] != parede)
			{				
				if(emCima){ tabuleiro[fantasma1Y][fantasma1X] = '*'; emCima = false;}
				else{ tabuleiro[fantasma1Y][fantasma1X] = ' ';}
				if(tabuleiro[fantasma1Y+1][fantasma1X] == '*'){ emCima = true;}
				if(tabuleiro[fantasma1Y+1][fantasma1X] == player){ morreu = true;}
				fantasma1Y++;
		    }
			tabuleiro[fantasma1Y][fantasma1X] = fantasma;
			
			//HUD
			//TIME
			char digitsTime[3] {'0','0','0'};
			int count = 0;		
			time = time - 0.1;
			int value = (int)time;

			while (value > 0)
			{
				 int digit = value % 10;
				 if(digit == 0){digitsTime[count] = '0'; }
			 	 else{ digitsTime[count] = digit + '0'; }
			 	 value /= 10;
			 	 count++;
			 	 
		    }

			tabuleiro[0][16] = digitsTime[2];
			tabuleiro[0][17] = digitsTime[1];
			tabuleiro[0][18] = digitsTime[0];
			//SCORE
			char digitsScore[3] = {' ',' ',' '};	
			int value2 = score;
			
			sprintf(digitsScore, "%d", value2);
			
			tabuleiro[0][6] = digitsScore[0];
			tabuleiro[0][7] = digitsScore[1];
			tabuleiro[0][8] = digitsScore[2];
			//WIN AND LOSE
			if(score == 83)
			{
				system("cls");
				rodando = false;
				printf("Voce Ganhou!!!!");
				Sleep(1000);
			}
			if(time <= 0)
			{
				system("cls");
				rodando = false;
				printf("O tempo acabou, Voce Perdeu!!!!");
				Sleep(1000);
			}
			if(morreu)
			{
				system("cls");
				rodando = false;
				printf("Pego pelo fantasma, Voce Perdeu!!!!");
				Sleep(1000);
			}
	}
	

	

}

