///////////////////////////////////////////////////////////////////////////////////////////////////////
// Program Name: Tic_Tac_Toe
// Program Version: 2.0
// Author: Brandon Castro
// Date: 12/14/2015
// Inputs to Program: Boolean choice between AI or Humans and Two integers: 1st is row and 2nd is column
// Outputs from Program: Contents of Tic Tac Toe grid and if anyone has won
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// Prototype functions
void print(char (&a)[3][3]);
bool check(char (&a)[3][3], int r, int c);
bool win(char (&a)[3][3], int r, int c);
int vsHuman(char (&board)[3][3]);
int vsAI(char (&board)[3][3]);
int minimax(int board[9], int player);
int winTemp(const int board[9]);

// Global variable, 0 is X_Player, 1 is O_Player (or AI)
bool player = 0;
bool digit = 0;

int main() {
	cout << "Tic Tac Toe v2.0\nHOW TO PLAY: Input row and column (ex: 1 2)" << endl;
	char board[3][3];
	
	// Populate grid with asterisks
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			board[i][j] = '*';
		
	bool choice = 0;
	print(board);
	cout << "Enter 0 for vs AI, 1 for vs Human: ";
	cin >> choice;
	
	if(!choice)
		vsAI(board);
	else
		vsHuman(board);
	
	return 0;
}

// Prints out the contents of the grid
void print(char (&a)[3][3]) {
	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}

// Checks for out of bounds or if position is already populated
// Returns true if errors found
bool check(char (&a)[3][3], int r, int c) {
	// Rows and columns must be between 1 and 3
	// Checks if position has been populated already
	if(r < 1 || c < 1 || r > 3 || c > 3) {
		cout << "ERROR: Out of bounds row/column." << endl;
		return true;
	}
	
	if(a[r-1][c-1] != '*') {
		cout << "ERROR: Invalid position (already populated)." << endl;
		return true;
	}
	
	return false;
}

// Checks char array for winners
// Finds 3 in a row, returns 0 if no winners, returns 1 if there's a winner
bool win(char (&a)[3][3]) {
	// Check horizontally for 3 non-asterisk matching symbols
	for(int i = 0; i<3; i++) 
		if(a[i][0] != '*' && a[i][0] == a[i][1] && a[i][0] == a[i][1] && a[i][0] == a[i][2])
			return 1;
	
	// Check vertically for 3 non-asterisk matching symbols
	for(int j = 0; j < 3; j++) 
		if(a[0][j] != '*' && a[0][j] == a[1][j] && a[0][j] == a[1][j] && a[0][j] == a[2][j] ) 
			return 1;
	
	// Check both diagonals for 3 in a row 
	if(a[0][0] != '*' && a[0][2] != '*') {
		if(a[0][0] == a[1][1] && a[0][0] == a[2][2])
			return 1;
		if(a[0][2] == a[1][1] && a[0][2] == a[2][0])
			return 1;
	}
	
	return 0;
}

int vsHuman(char (&board)[3][3]) {
	cout << "You chose vs Human" << endl;
	
	int turn = 1;
	// Does 10 turns until calls cat's game
	while(turn<10) { 
		int r, c;
		
		// Player 1 is odd number of turns
		if(turn%2!=0) {
			cout << "Player X, row and column: ";
			cin >> r >> c;
			// Check inputs for validity, asks for input again if errors found
			while(check(board, r, c)) {
				cout << "Player X, row and column: ";
				cin >> r >> c;
			}
			board[r-1][c-1] = 'X';
			player = 0;
		}
		
		// Player 2 is even number of turns
		else {
			cout << "Player O, row and column: ";
			cin >> r >> c;
			// Check inputs for validity, asks for input again if errors found
			while(check(board, r, c)) {
				cout << "Player O, row and column: ";
				cin >> r >> c;
			}
			board[r-1][c-1] = 'O';
			player = 1;
		}
		print(board);
		
		// Check if anyone has won
		// If there's a winner, last play is winning player
		if( win(board) ) {
			cout << "Player ";
			(player) ? cout<<"O":cout<<"X";
			cout << " wins!"<< endl;
			return 0;
		}
		turn++;
	}
	// If turns are over, cat's game is announced
	cout << "The cat wins."<<endl;
	return 0;
}

// AI verifies efficiency of next move using minimax algorithm
int vsAI(char (&temp)[3][3]) {
	cout << "You chose vs UNBEATABLE AI. You are 'X', AI is 'O'." << endl;
	
	int turn = 1;
	while(turn<10) {
		int r, c;
		cout<<endl;//Turn "<< turn <<endl<<"--------------"<<endl;
		// AI is odd number of turns
		if(turn%2!=0) {
			cout<<"AI moving..."<<endl;
			// put 2D array in temp 1D array from 0 - 8 for algorithm purposes
			// 1 = AI ('O'), -1 = Human ('X'), 0 = '*'
			int board[9];
			int index = 0;
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 3; j++) {
					board[index] = (temp[i][j] == '*')? 0 : (temp[i][j] == 'X')? -1 : 1;
					index++;
				}
			}
			
			// Calculate move algorithm with temp board array
			int move = -1, score = -2;
			for(int i = 0; i < 9; ++i) {
				if(board[i] == 0) {
					board[i] = 1;
					int tempScore = -minimax(board, -1);
					board[i] = 0;
					
					// Compare scores of potential moves
					// Best score is put into 'move'
					if(tempScore > score) {
						score = tempScore;
						move = i;
					}
				}
			}
			
			// move now equals place to put 'O'
			// translate 1D 'move' index to a 2D index w/ row and col
			if(move < 3)
				r = 0;
			else if(move < 6)
				r = 1;
			else
				r = 2;
			
			if(move == 0 || move == 3 || move == 6)
				c = 0;
			else if(move == 1 || move == 4 ||  move == 7)
				c = 1;
			else
				c = 2;
			
			temp[r][c] = 'O';
			player = 0;
		}
		
		// Human is even number of turns
		else {
			// premature check for AI win
			if( win(temp) ) {
				(player) ? cout<<"Human":cout<<"AI";
				cout << " wins!"<< endl;
				return 0;
			}
			
			cout << "Player X, row and column: ";
			cin >> r >> c;
			// Check inputs for validity, asks for input again if errors found
			while(check(temp, r, c)) {
				cout << "Player X, row and column: ";
				cin >> r >> c;
			}
			temp[r-1][c-1] = 'X';
			player = 1;
		}
		print(temp);
		
		// Check if anyone has won
		// If there's a winner, last play is winning player
		if( win(temp) ) {
			(player) ? cout<<"Human":cout<<"AI";
			cout << " wins!"<< endl;
			return 0;
		}
		turn++;
	}
	
	// If turns are over, cat's game is announced
	cout << "Draw game."<<endl;
	return 0;
}

// Checks the temp int array for possible winners
// Finds 3 in a row, returns 0 if no winners or returns winner's number
// 1 = AI ('O'), -1 = Human ('X'), 0 = '*'
int winTemp(const int board[9]) {
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(int i = 0; i < 8; ++i) {
        if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}

int minimax(int board[9], int player) {
	int winner = winTemp(board);
    if(winner != 0) return winner*player;

	int move = -1;
    int score = -2;
    for(int i = 0; i < 9; ++i) {
		// Check if empty space
        if(board[i] == 0) {
			// Check score of move
            board[i] = player;
            int thisScore = -minimax(board, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }
			// Reset the board
            board[i] = 0;
        }
    }
    if(move == -1) return 0;
    return score;
}
