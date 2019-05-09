/* 
 * File:LAB10115248_set1_exer1.c
 * Author: Mprellas Iwannhs
 * A.M: 2012030007
 * Created on November 30, 2012, 4:16 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BOARD_SIZE 100
void show_board(char[]);
int main() {
   int dice,position,temp,number,k,thesi,done;/* �� ���������� ����� �� ����: 
                                    number: � ����� ������� ����� ��� ������
                                    position: � ���� ��� ������ ���� ����� ���� �������� ������ ��������� �� ����� (�� *)
                                    dice: � ������� ��� �������� �� ����*/                    
   char board[BOARD_SIZE] = { '*','_','_','l','_','_','_','L','_','_',\
                              '_','_','_','_','s','l','_','_','_','_',\
                              '_','_','S','_','_','_','_','_','_','S',\
                              'L','_','_','s','_','_','L','_','_','_',\
                              '_','_','_','_','l','_','_','S','_','_',\
                              '_','_','_','_','_','_','_','_','_','_',\
                              '_','_','S','_','_','l','_','s','_','L',\
                              '_','_','_','L','_','_','_','_','S','_',\
                              '_','l','_','_','_','_','_','_','_','_',\
                              '_','_','S','_','_','_','_','S','_','_',\
                            };
   srand( time(NULL) );
   k=0;
   number=0;
   position=0;
   done=0;
   show_board(board);/* ����������� �� ������ ���� ������ ��� ���������*/
   printf("\n");
   while (done==0)
   {
         number+=1;/* ��������� �� ���� ��������� ������ �� ���� ���� ��� ������*/
         printf("Dice rolled %d time(s)\n",number);
         temp=position;/* ��� ��������� temp ������������ � ���� ��� ������ ���� ����� ��������� �� ����� ���� �� ���� ��� ������*/
         dice=1+rand()%6;/*���� ��� ������*/
         printf("Number rolled:%d \n",dice); 
         if((position/20==0,2,4,6,8) && (position%20<10))/*������ ������ �������*/
         {
                                     if((9-position%20)<dice)
                                     {
                                     thesi=position+dice+1;
                                     position=20*(thesi/10)+10-thesi;
                                     }
                                     else
                                     position+=dice;
         }  
         else if ((position/10==1,3,5,7,9)) /*�������� ������ �������*/
         {
              if ( (position+dice>90) && ((position%10)<dice) )
                    position=(position-position%9)+(dice-position%9);
              else
              {
                  if (position%10>=dice)
                        position=position-dice;
                     else
                         
                         position=position+(9-position%10)+dice-position%10; 
              }
         }                                                           
         if (board[position]=='l'){/*��� ��������� ��� �� ����� ����� �� ����� ����� �������� ��� ������� ������� ������ ��� �������
                                     �������� � ����� ����������� ���� ������ ��� ����� ��� ������ ���� ����� ��������� �� ����� ���� 10*/
           position += 10;
           board[position]='*';
           board[temp]='_';
           printf("Small ladder at position:%d",position-9);
           }
         else if(board[position]=='L'){/*��� ��������� ��� �� ����� ����� �� ������ ����� �������� ���  ���������� ������ ��� �������
                                     �������� � ����� ����������� ���� ������ ��� ����� ��� ������ ���� ����� ��������� �� ����� ���� 20*/
              position+= 20;
              board[position]='*';
              board[temp]='_';
              printf("Big ladder at position:%d",position-19);
              }
         else if(board[position]=='s'){/*��� ��������� ��� �� ����� ����� �� ����� ���� �������� ��� ������� ����������� ������ ��� �������
                                     �������� � ����� ����������� ���� ������ ��� ����� ��� ������ ���� ����� ��������� �� ����� ���� 10*/
              position-= 10;
              board[position]='*';
              board[temp]='_';
              printf("Small snake at position:%d",position+11);
              }
         else if(board[position]=='S'){/*��� ��������� ��� �� ����� ����� �� ������ ���� �������� ���� �������������� ������ ��� �������
                                     �������� � ����� ����������� ���� ������ ��� ����� ��� ������ ���� ����� ��������� �� ����� ���� 20*/
              position-= 20;
              board[position]='*';
              board[temp]='_';
              printf("Big snake at position:%d",position+21);
              }
         else{/* ���� ��������� ��� �� ����� ��� ����� �� ������ ��������� ������ �� �������� ����������� ��������*/
              board[position]='*';
              board[temp]='_'; 
              }              
   show_board(board);/* ��������������� �� ����� �� ��� ������� ��� ������ ���� �� ���� ��� ������*/
   if (position==90)
   {
       done=1;
   }    
   printf("\n");
   sleep(4000);
   }
   printf("Congratulations!! You win this game!");
   system("pause");
}
void show_board(char board[])/* ��������� ��������� ��� ������ ���� �������� ��������� ���*/
{
     int i;
     for (i=0;i<100;i++)
     {
         if (i%10==0)
            printf("\n");
         printf("%c",board[i]);
     }
}
         
         
       
       

