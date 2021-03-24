#include <iostream>
#include <string>
#include "GameField.h"
#include "Player.h"
#include "AI.h"

using namespace std;
// 1 - tic X
// 0 - tac O

int main() {
    cout << "\033[0;31m Red text \e[0m" << endl;

	cout << "Welcome to TicTacToe\n\n";
	while (true) {
		system("clear");
		cout << "Welcome to TicTacToe\n\n";
		cout << "Choose mode: 1 - 'vs AI', 2 - 'vs Friend'\n";
		string mode;
		getline(cin, mode);

		GameField game_field;
		if (mode[0] == '1') {
			cout << "Choose 1 - \e[0;32m'X'\e[0m, 2 - \e[0;33m'O'\e[0m\n";

			string tic_or_toe;
			getline(cin, tic_or_toe);

			bool is_tic_turn = true;
			bool is_players_turn = false;

			if (tic_or_toe[0] == '1')
				is_players_turn = true;

			Player player1(is_players_turn);
			AI player2(!is_players_turn);

			bool done = true;
			while (done) {
				game_field.show();
				if (is_players_turn)
					player1.do_move(game_field);
				else
					player2.do_move(game_field);

				is_tic_turn = !is_tic_turn;
				is_players_turn = !is_players_turn;

				system("clear");
				if (game_field.check() != -1)
					done = false;
			}
		}
		else {
			bool is_tic_turn = true;
			bool is_players_turn = true;

			Player player1(is_players_turn);
			Player player2(!is_players_turn);

			bool done = true;
			while (done) {
				game_field.show();
				if (is_players_turn)
					player1.do_move(game_field);
				else
					player2.do_move(game_field);

				is_tic_turn = !is_tic_turn;
				is_players_turn = !is_players_turn;

				system("clear");
				if (game_field.check() != -1)
					done = false;
			}
		}

		game_field.show();
		cout << "Do you want to restart the game? 1 - Yes or 2 - No?\n";
		string agreement;
		getline(cin, agreement);
		if (agreement[0] == '2') {
			cout << "Bye, come back later!\n";
			break;
		}
	}

	return 0;
}