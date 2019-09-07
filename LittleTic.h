//this is the header file for the tic tac toe game
#ifndef LittleTic_H
#define LittleTic_H
//this is a header file that for ultimate tic tac toe.
class LittleTic{

     private:

          char *symbol;  //puts symbol on a players solved grid
          int *countSmall;    //keeps count of the small tic for optimisation
          char *tic_tac; //the small 3 X 3 grid
     public:
          LittleTic();
          ~LittleTic();
          int GetCountSmall ( ) const;
          char GetSymbolBig ( ) const;
          char GetSymbolSmall ( int lr, int lc) const;

          void SetSymbolBig ( char*t );
          void SetSymbolSmall ( int*br, int*bc, char*t );

          void RaiseCountSmall ( );

          bool CheckForWin (LittleTic bt[ 9 ], char * o, int * t, bool go);
          void CheckForSolve (LittleTic *bt, char * t, int * cb );
          void SwitchTurn ( char * t, int * lr, int * lc, int * br, int * bc);
          void WildCard ( int * br, int * bc);
          void PlayerTurn ( char * t, int * lr, int * lc, LittleTic *bt);
          void StartGame ( int * br, int * bc);
};

#endif
