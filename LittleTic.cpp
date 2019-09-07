#include "LittleTic.h"
#include<iostream>
using namespace std;


LittleTic :: LittleTic ( ){         //constructs the little tac

     symbol = new char;
     countSmall = new int;
     tic_tac = new char[ 9 ] {  '\0', '\0', '\0',
                                             '\0', '\0', '\0',
                                             '\0', '\0', '\0'   };
     *symbol = '\0';
     *countSmall = 0;
                    //this is a 3 x 3 grid that will hold the symbol of the player

}

LittleTic :: ~LittleTic ( ){

     delete symbol;
     delete countSmall;
     delete [ ] tic_tac;

     symbol = NULL;
     countSmall = NULL;
     tic_tac = NULL;
}

int LittleTic :: GetCountSmall ( ) const{    //gets the flag that will be used latter

     return *countSmall;
}

char LittleTic :: GetSymbolBig ( ) const{    //gets the symbol that was won in the whole grid

     return *symbol;
}

char LittleTic :: GetSymbolSmall ( int r, int c) const {    //gets the symbol in the small grid
     // int r = *littleRow;
     // int c = *littleColumn;
     return tic_tac[ ( 3 * r ) + c ];
}


void LittleTic :: SetSymbolBig ( char *turn){     //gives the grid to a player

     *symbol = *turn;
}

void LittleTic :: SetSymbolSmall ( int *littleRow, int *littleColumn, char *turn){  //places a symbol insede of the small grid

     int r = *littleRow;
     int c = *littleColumn;
     tic_tac[ (r * 3) + c ] = *turn;
}


void LittleTic :: RaiseCountSmall ( ){  //raises the count in the class

     *countSmall += 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
bool LittleTic :: CheckForWin ( LittleTic bigTic[], char *turn, int *countBig, bool gameOver ){   //finds a winner r

     if (bigTic[ 0 ].GetSymbolBig ( ) != '\0'){
          if( bigTic[ 2 ].GetSymbolBig ( ) != '\0' ){
               if( bigTic[ 1 ].GetSymbolBig ( ) != '\0' ){
                    return true;
               }
          }
          if( bigTic[ 6 ].GetSymbolBig ( ) != '\0'){
               if( bigTic[ 3 ].GetSymbolBig ( ) != '\0'){
                    return true;
               }
          }
          if( bigTic[ 8 ].GetSymbolBig ( ) != '\0'){
               if( bigTic[ 4 ].GetSymbolBig ( ) != '\0'){
                    return true;
               }
          }
     }else if( bigTic[ 8 ].GetSymbolBig ( ) != '\0'){
                    if( bigTic[ 2 ].GetSymbolBig ( ) != '\0' ){
                         if( bigTic[ 5 ].GetSymbolBig ( ) != '\0' ){
                              return true;
                         }
                    }
                    if( bigTic[ 6 ].GetSymbolBig ( ) != '\0' ){
                         if( bigTic[ 7 ].GetSymbolBig ( ) != '\0' ){
                              return true;
                         }
                    }

     }else if (bigTic[ 4 ].GetSymbolBig ( ) != '\0'){
                    if( bigTic[ 5 ].GetSymbolBig ( ) != '\0' ){
                         if( bigTic[ 3 ].GetSymbolBig ( ) != '\0' ){
                              return true;
                         }
                    }
                    if( bigTic[ 7 ].GetSymbolBig ( ) != '\0' ){
                         if( bigTic[ 1 ].GetSymbolBig ( ) != '\0' ){
                              return true;
                         }
                    }
     }
          return false;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LittleTic :: CheckForSolve ( LittleTic *bigTic, char *turn, int *countBig){   //finds a solved grid r-i

     if  (bigTic ->GetSymbolSmall(0, 0) != '\0'){
          if( bigTic ->GetSymbolSmall(0, 2) != '\0'){
               if(bigTic ->GetSymbolSmall(0, 1) != '\0'){
                    bigTic -> SetSymbolBig ( turn);
                    *countBig += 1;
               }
          }
          if( bigTic ->GetSymbolSmall(2, 0) != '\0'){
               if( bigTic ->GetSymbolSmall(1, 0) != '\0'){
                    bigTic -> SetSymbolBig ( turn);
                    *countBig += 1;
               }
          }
          if( bigTic ->GetSymbolSmall(2, 2) != '\0'){
               if( bigTic ->GetSymbolSmall(1, 1) != '\0'){
                    bigTic -> SetSymbolBig ( turn);
                    *countBig += 1;
               }
          }
     }else if( bigTic ->GetSymbolSmall(2, 2) != '\0'){
                    if( bigTic ->GetSymbolSmall(0, 2) != '\0'){
                         if( bigTic ->GetSymbolSmall(1, 2) != '\0' ){
                              bigTic -> SetSymbolBig ( turn);
                              *countBig += 1;
                         }
                    }
                    if( bigTic -> GetSymbolSmall(2, 0) != '\0' ){
                         if( bigTic -> GetSymbolSmall(2, 1) != '\0' ){
                              bigTic -> SetSymbolBig ( turn);
                              *countBig += 1;
                         }
                    }

     }else if (bigTic -> GetSymbolSmall(1, 1) != '\0'){
                    if( bigTic -> GetSymbolSmall(1, 2) != '\0' ){
                         if( bigTic -> GetSymbolSmall(1, 0) != '\0' ){
                              bigTic -> SetSymbolBig ( turn);
                              *countBig += 1;
                         }
                    }
                    if( bigTic -> GetSymbolSmall(2, 1) != '\0' ){
                         if(bigTic -> GetSymbolSmall(0, 1) != '\0' ){
                              bigTic -> SetSymbolBig ( turn);
                              *countBig += 1;
                         }
                    }
     }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void LittleTic :: SwitchTurn ( char *turn, int *littleRow, int *littleColumn, int *bigRow, int *bigColumn){  //changes player's turn r

     if ( *turn == 'X' ){
          *turn = 'O';
     }else {
          *turn = 'X';
     }

     *bigRow = *littleRow;
     *bigColumn = *littleColumn;
}

void LittleTic :: WildCard ( int *bigRow, int *bigColumn){     //lets the player choose a different grid to play on

     cout << "you can choose any position in the big grid\n ROW:";
     cin >>  *bigRow;
     cout << "\nCOLUMN:";
     cin >> *bigColumn;
     cout << "\n \n";
}

void LittleTic :: PlayerTurn ( char *turn, int *littleRow, int *littleColumn, LittleTic *bigTic ){    //this lets the player place his symbol in the small grid

     do{
          cout << "where would you like to place your symbol?\n ROW: ";
          cin >> *littleRow;
          cout << "\nCOLUMN: ";
          cin >> *littleColumn;
          cout << "\n \n";
     }while ( bigTic -> GetSymbolSmall ( *littleRow, *littleColumn) != '\0');
     bigTic -> SetSymbolSmall ( littleRow, littleColumn, turn);

}

void LittleTic :: StartGame ( int *bigRow, int *bigColumn){

     cout << "where would you like to go on the big grid?\n ROW:";
     cin >> *bigRow;
     cout << "\n COLUMN: ";
     cin >> *bigColumn;
     cout << "\n \n";
}
