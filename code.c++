#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using Board = vector<vector<char>>;

/*************************************************/

/*
  Prints the board b to the terminal.
  PARAMETERS: Board b.
*/
void print_board(Board b){
  for(int j = 0; j < 6; j++){
    cout << "| ";
    for(int i = 0; i < 7; i++){
      cout << b[j][i] << "| ";
    }
    cout << "\n";
  }
}

/*
  Prints a welcoming message and 
  shows the rules of the game.
*/
void welcome_message(){
  cout << "\n \n \n \n \n" << "Hello, players! \n";
  cout << "You are about to start playing Connect 4. \n \n";
  cout << "||--------------------------------------|| \n \n \n";
  cout << "        *****|| GAME RULES ||***** \n \n";
  cout << "Each player takes a symbol - either X or O. \n";
  cout << "The player chooses a horizontal position to fill with \n";
  cout << "their respective symbol. \n";
  cout << "If there are no symbols below prior to the choice of the player \n";
  cout << "then the symbol is put in the lowest level for that column. \n";
  cout << "If there are symbols below, ";
  cout << "then the symbol is put above the existing ones. \n";
  cout << "The first player to have 4 of their symbols ";
  cout << "consequetively positioned in a \n";
  cout << "horizontal, vertical or a diagonal way wins the game.\n \n";
  cout << "Player 1: you take X. Player 2: you take O. \n";
  cout << "Now, here is the empty board.  \n \n";
}

/*
  Prompts Player 1 to choose a column to put X.
  ASSUMES: integer input.
  RETURNS: column to put X.
*/
int p1_in(){
  cout << "Player 1, enter number of column to put X: ";
  int column;
  cin >> column;
  return column;
}

/*
  Prompts Player 2 to choose a column to put O.
  ASSUMES: integer input.
  RETURNS: column to put O.
*/
int p2_in(){
  cout << "Player 2, enter number of column to put O: ";
  int column;
  cin >> column;
  return column;
}

/*
Checks if Player 1 wins the game.
PARAMETERS: Board b.
RETURNS: true if Player 1 wins, false otherwise.
*/
bool X_wins(Board b){
  //rows
  for(int j = 0; j < 6; j++){
    for(int i = 0; i < 4; i++){
      if(b[j][i] == b[j][i+1] && b[j][i] == b[j][i+2] &&
         b[j][i] == b[j][i+3] && b[j][i] == 'X'){
        return true;
      }
    }
  }
  //columns
  for(int j = 0; j < 3; j++){
    for(int i = 0; i < 7; i++){
      if(b[j][i] == b[j+1][i] && b[j][i] == b[j+2][i] &&
         b[j][i] == b[j+3][i] && b[j][i] == 'X'){
        return true;
      }
    }
  }
  //diagonals (down right/ up left)
  for(int j = 0; j < 3; j++){
    for(int i = 0; i < 4; i++){
      if(b[j][i] == b[j+1][i+1] && b[j][i] == b[j+2][i+2] &&
         b[j][i] == b[j+3][i+3] && b[j][i] == 'X'){
        return true;
      }
    }
  }
  //diagonals (down left / up right)
  for(int j = 5; j >= 3; j--){
    for(int i = 0; i < 4; i++){
      if(b[j][i] == b[j-1][i+1] && b[j][i] == b[j-2][i+2] &&
         b[j][i] == b[j-3][i+3] && b[j][i] == 'X'){
        return true;
      }
    }
  }
}


/*
Checks if Player 2 wins the game.
PARAMETERS: Board b.
RETURNS: true if Player 2 wins, false otherwise.
*/
bool O_wins(Board b){
  //rows
  for(int j = 0; j < 6; j++){
    for(int i = 0; i < 4; i++){
      if(b[j][i] == b[j][i+1] && b[j][i] == b[j][i+2] &&
         b[j][i] == b[j][i+3] && b[j][i] == 'O'){
        return true;
      }
    }
  }
  //columns
  for(int j = 0; j < 3; j++){
    for(int i = 0; i < 7; i++){
      if(b[j][i] == b[j+1][i] && b[j][i] == b[j+2][i] &&
         b[j][i] == b[j+3][i] && b[j][i] == 'O'){
        return true;
      }
    }
  }
  //diagonals (down right/ up left)
  for(int j = 0; j < 3; j++){
    for(int i = 0; i < 4; i++){
      if(b[j][i] == b[j+1][i+1] && b[j][i] == b[j+2][i+2] &&
         b[j][i] == b[j+3][i+3] && b[j][i] == 'O'){
        cout << "X down right";
        return true;
      }
    }
  }
  //diagonals (down left / up right)
  for(int j = 5; j >= 3; j--){
    for(int i = 0; i < 4; i++){
      if(b[j][i] == b[j-1][i+1] && b[j][i] == b[j-2][i+2] &&
         b[j][i] == b[j-3][i+3] && b[j][i] == 'O'){
        cout << "X down left";
        return true;
      }
    }
  }
}

/*
  Checks whether the game board is full.
  PARAMETERS: Board b.
  RETURNS: true if board is full, false otherwise.
*/
bool is_board_filled(Board b){
  for(int j = 0; j < 6; j++){
    for(int i = 0; i < 7; i++){
      if(b[j][i] == ' '){
        return false;
      }
    }
  }
  return true;
}

/*
  Prompts Player 1 to choose a column to put X.
  PARAMETERS: Board b, Z (Value for column), rows(helper value = 6).
  RETURNS: The best row to put a symbol in.
*/
int good_place(Board b, int z, int rows){
  // base case
  if(rows == 0){return rows;}
  if(b[rows][z] == ' '){
    return rows;
  }
  // recursive steps
  rows -= 1;
  return good_place(b, z, rows);
}


int main(){
  Board b = {{' ',' ',' ',' ',' ',' ',' '},
             {' ',' ',' ',' ',' ',' ',' '},
             {' ',' ',' ',' ',' ',' ',' '},
             {' ',' ',' ',' ',' ',' ',' '},
             {' ',' ',' ',' ',' ',' ',' '},
             {' ',' ',' ',' ',' ',' ',' '}};
  welcome_message();
  print_board(b);
  cout << "\n";

  while(not X_wins(b) && not O_wins(b) && not is_board_filled(b)){
    // Player 1 turn
    int X = p1_in() - 1;
    int row = good_place(b, X, 5);
    b[row][X] = 'X';
    print_board(b);
    if(X_wins(b)){
      break;
    }
    if(is_board_filled(b)){
      break;
    }

    // Player 2 turn
    int O = p2_in() - 1;
    row = good_place(b, O, 5);
    b[row][O] = 'O';
    print_board(b);
    if(O_wins(b)){
      break;
    }
    if(is_board_filled(b)){
      break;
    }
  }

  // Check how game ends
  if(X_wins(b)){cout << "\n Player 1 wins! \n";}
  if(O_wins(b)){cout << "\n Player 2 wins! \n";}
  if(is_board_filled(b)){cout << "\n Sorry! The board is full. There is no winner. \n";}

}
