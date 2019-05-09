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
   int dice,position,temp,number,k,thesi,done;/* οι μεταβλητές έχουν ως εξής: 
                                    number: ο αύξων αριθμός ρίψης του ζαριού
                                    position: η θέση του πίνακα στην οποία κάθε δεδομένη στιγμή βρίσκεται το πιόνι (το *)
                                    dice: ο αριθμός που τυχαίνει το ζάρι*/                    
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
   show_board(board);/* εμφανίζεται το ταμπλό στην αρχική του κατάσταση*/
   printf("\n");
   while (done==0)
   {
         number+=1;/* αυξάνεται σε κάθε επανάληξη δηλαδή σε κάθε ρίψη του ζαριού*/
         printf("Dice rolled %d time(s)\n",number);
         temp=position;/* στη μεταβλητή temp αποθηκεύεται η θέση του πίνακα στην οποία βρισκόταν το πιόνι πριν τη ρίψη του ζαριού*/
         dice=1+rand()%6;/*ρίψη του ζαριού*/
         printf("Number rolled:%d \n",dice); 
         if((position/20==0,2,4,6,8) && (position%20<10))/*αρτιες σειρές ταμπλού*/
         {
                                     if((9-position%20)<dice)
                                     {
                                     thesi=position+dice+1;
                                     position=20*(thesi/10)+10-thesi;
                                     }
                                     else
                                     position+=dice;
         }  
         else if ((position/10==1,3,5,7,9)) /*περιττές σειρές ταμπλού*/
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
         if (board[position]=='l'){/*στη περίπτωση που το πιόνι πέσει σε μικρή σκάλα πηγαίνει στη ακριβώς επόμενη γραμμή του ταμπλού
                                     ενέργεια η οποία αντιστοιχεί στην αύξηση της θέσης του πίνακα στην οποία βρίσκεται το πιόνι κατα 10*/
           position += 10;
           board[position]='*';
           board[temp]='_';
           printf("Small ladder at position:%d",position-9);
           }
         else if(board[position]=='L'){/*στη περίπτωση που το πιόνι πέσει σε μεγάλη σκάλα πηγαίνει στη  μεθεπόμενη γραμμή του ταμπλού
                                     ενέργεια η οποία αντιστοιχεί στην αύξηση της θέσης του πίνακα στην οποία βρίσκεται το πιόνι κατα 20*/
              position+= 20;
              board[position]='*';
              board[temp]='_';
              printf("Big ladder at position:%d",position-19);
              }
         else if(board[position]=='s'){/*στη περίπτωση που το πιόνι πέσει σε μικρό φίδι πηγαίνει στη ακριβώς προηγούμενη γραμμή του ταμπλού
                                     ενέργεια η οποία αντιστοιχεί στην μείωση της θέσης του πίνακα στην οποία βρίσκεται το πιόνι κατα 10*/
              position-= 10;
              board[position]='*';
              board[temp]='_';
              printf("Small snake at position:%d",position+11);
              }
         else if(board[position]=='S'){/*στη περίπτωση που το πιόνι πέσει σε μεγάλο φίδι πηγαίνει στην προπροηγούμενη γραμμή του ταμπλού
                                     ενέργεια η οποία αντιστοιχεί στην μείωση της θέσης του πίνακα στην οποία βρίσκεται το πιόνι κατα 20*/
              position-= 20;
              board[position]='*';
              board[temp]='_';
              printf("Big snake at position:%d",position+21);
              }
         else{/* στην περίπτωση που το πιόνι δεν πέσει σε κάποιο τετράγωνο δράσης το παιχνίδι συνεχίζεται κανονικά*/
              board[position]='*';
              board[temp]='_'; 
              }              
   show_board(board);/* ξαναεμφανίζουμε το ταπλό με τις αλλαγές που έγιναν μετά τη ρίψη του ζαριού*/
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
void show_board(char board[])/* συνάρτηση εμφάνισης του πίνακα στην τρέχουσα κατάσταση του*/
{
     int i;
     for (i=0;i<100;i++)
     {
         if (i%10==0)
            printf("\n");
         printf("%c",board[i]);
     }
}
         
         
       
       

