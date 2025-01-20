#include <iostream>
 #include <cstdlib>
  using namespace std;
   char Player_symbol = 'X'; 
   char Computer_symbol = 'O';
    void Gbox(char box[]);
	 void computer(char box[]);
	  void player(char box[]);
	   bool check(char box[]); 
	   void win_or_lose(char box[]);
	    int main() 
		{ char box[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
		 bool Game_check = check(box); while (Game_check) { system("cls"); 
		 // Clear screen
		  Gbox(box); player(box); if (!check(box)) break;
		   // Check after player move
		    win_or_lose(box);
			 // Check win condition after player move
			  computer(box); if (!check(box)) break; 
			  // Check after computer move
			   win_or_lose(box); 
			   // Check win condition after computer move
			    Game_check = check(box); } system("cls");
				 // Clear screen
				  Gbox(box); 
				  // Display final board 
				  win_or_lose(box); 
				  // Display final result
				   return 0; } 
				   void Gbox(char box[]) 
				   { cout << " || || "; cout << "\n " << box[0] << " || " << box[1] << " || " << box[2]; cout << "\n || || "; cout << "\n--------------------------"; 
				   cout << "\n || || "; cout << "\n " << box[3] << " || " << box[4] << " || " << box[5]; cout << "\n || || "; cout << "\n--------------------------"; cout << "\n || || "; cout << "\n " << box[6] << " || " << box[7] << " || " << box[8]; cout << "\n || || "; } void computer(char box[]) { int cbox; bool check = false; while (!check) { cbox = rand() % 9; if (box[cbox] == ' ') { box[cbox] = Computer_symbol; check = true; } } } void player(char box[]) { int pbox; bool check = true; while (check) { cout << "\nEnter the box number (1-9) where you wish to place your mark: "; cin >> pbox; if (pbox >= 1 && pbox <= 9 && box[pbox - 1] == ' ') { box[pbox - 1] = Player_symbol; check = false; } else { cout << "\nInvalid input or box already taken. Try again."; } } } bool check(char box[]) { for (int i = 0; i < 9; ++i) { if (box[i] == ' ') { return true; } } return false; } void win_or_lose(char box[]) { if ((box[0] == Player_symbol && box[1] == Player_symbol && box[2] == Player_symbol) || (box[3] == Player_symbol && box[4] == Player_symbol && box[5] == Player_symbol) || (box[6] == Player_symbol && box[7] == Player_symbol && box[8] == Player_symbol) || (box[0] == Player_symbol && box[3] == Player_symbol && box[6] == Player_symbol) || (box[1] == Player_symbol && box[4] == Player_symbol && box[7] == Player_symbol) || (box[2] == Player_symbol && box[5] == Player_symbol && box[8] == Player_symbol) || (box[0] == Player_symbol && box[4] == Player_symbol && box[8] == Player_symbol) || (box[2] == Player_symbol && box[4] == Player_symbol && box[6] == Player_symbol)) { cout << "\nCONGRATULATIONS! YOU WON" << endl; exit(0); } else if ((box[0] == Computer_symbol && box[1] == Computer_symbol && box[2] == Computer_symbol) || (box[3] == Computer_symbol && box[4] == Computer_symbol && box[5] == Computer_symbol) || (box[6] == Computer_symbol && box[7] == Computer_symbol && box[8] == Computer_symbol) || (box[0] == Computer_symbol && box[3] == Computer_symbol && box[6] == Computer_symbol) || (box[1] == Computer_symbol && box[4] == Computer_symbol && box[7] == Computer_symbol) || (box[2] == Computer_symbol && box[5] == Computer_symbol && box[8] == Computer_symbol) || (box[0] == Computer_symbol && box[4] == Computer_symbol && box[8] == Computer_symbol) || (box[2] == Computer_symbol && box[4] == Computer_symbol && box[6] == Computer_symbol)) { cout << "\nOH NO! YOU LOST" << endl; exit(0); } else if (!check(box)) { cout << "\nIT'S A DRAW" << endl; exit(0); } }