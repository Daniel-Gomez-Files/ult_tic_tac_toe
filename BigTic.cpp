#include "LittleTic.h" //gg this ga,e should be cool
#include <iostream>
using namespace std;

const int SIZE = 9;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int main( ){

     LittleTic bigTic [ SIZE ];    //makes a 3X3 Little tic_tac_toe grid
     LittleTic *bigObj = NULL;     //gets the desired object made from the bigTic grid
     bool gameOver = false;

     int countBig = 0;   //used for when trying to find the winner
     int *countBigPtr = &countBig;      //used to help find winner

     char turn = '\0';
     char *turnPtr = &turn;   //changes the players turn

     int bigRow = 0, bigColumn = 0,
          littleRow = 0, littleColumn = 0;
     int *bigRowPtr = &bigRow, *bigColumnPtr = &bigColumn,  //used to move around the big grid
          *littleRowPtr = &littleRow, *littleColumnPtr = &littleColumn;    //used for the small grid



     bigObj->StartGame ( bigRowPtr, bigColumnPtr );   // lets user choose where to start on the big grid
     while ( !gameOver ){     //loops until the game is over

          bigObj->SwitchTurn( turnPtr, littleRowPtr, littleColumnPtr, bigRowPtr, bigColumnPtr );       //changes players and object that will be manipulated
          bigObj = &bigTic [ ((*bigRowPtr) * 3 ) + (*bigColumnPtr) ];     //gets the address of the object that will be used
          if ( bigObj -> GetSymbolBig() == ( 'X' || 'O' || 'D' ) ){

               bigObj->WildCard ( bigRowPtr, bigColumnPtr );
               bigObj = &bigTic [ (*bigRowPtr *3 ) + *bigColumnPtr ];     //if the object was won (in the game) this will let you go to another object
          }

          bigObj->PlayerTurn ( turnPtr, littleRowPtr, littleColumnPtr, bigObj );   //places symbol inside the array of the object

          if ( bigObj -> GetCountSmall() >= 3){ //only checks if there are at least 3 symbols in the small tic

               bigObj->CheckForSolve ( bigObj, turnPtr,  countBigPtr );      //passing just one object to see if its solved
          }

          if ( ( *countBigPtr ) >= 3 ){    //only checks if there is at least 3 symbols present in the big tic

               bigObj ->CheckForWin ( bigTic, turnPtr, countBigPtr, gameOver);      //passing all objects to see if someone won
          }

     }

     cout << "Thanks for playing \n \n ";
}//this is cool
