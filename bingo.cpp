#include <iostream>
#include <cstdlib>
#include <cstring>

#define BINGO_BOARD_SIZE 85

using namespace std;

class bingoboard {
	private:
		char base[BINGO_BOARD_SIZE];	// int works but char gives us a nice pictogram
		int called[BINGO_BOARD_SIZE];
		int validdraws;
	public:
		bingoboard();
		~bingoboard();
		int disp_card();
		int draw_number();
		int disp_called();
};


bingoboard::bingoboard()
{
	validdraws = 0;
	for (int i = 0; i < BINGO_BOARD_SIZE+1; i++){
		base[i]=0;  // zero all board numbers, always good practice but required here as we will be checking to see if numbers have been called
	}
}


bingoboard::~bingoboard()
{
//	nothing done here
}


int bingoboard::disp_card()
{

	for (int i = 1; i < BINGO_BOARD_SIZE+1; i+=5){
		for (int j=0; j<5; j++){

			if ((i+j) < 10) // pad with leading space for single digit numbers
					cout << " ";

			cout << i+j << ":" << base[i+j];

			if (base[i+j] == 0)
				cout << " ";
			cout << "     ";
		}
		cout << endl; // << end of row
	}
	return 0;
}


int bingoboard::disp_called()
{
	for (int k=1; k<BINGO_BOARD_SIZE+1; k+=5) {  // loop

		for (int l = 0; l < 5; l++){
			cout << called[k+l];
			if ( called[k+l] < 10 )
				cout << " ";
			cout << "   ";
		}
		cout << endl;
	}
	return 0;
}


int bingoboard::draw_number()
{
	int i;

	srand (time(NULL));

	do {
		i = random() % BINGO_BOARD_SIZE + 1; // pick a random number from 1 to 85
	}
	while ((base[i] == 1) && (validdraws < 85));	// ensure not already drawn and still need a number drawn

	validdraws++;
	base[i] = 1; // number has been drawn
	called[validdraws] = i;	// save called number in sequence
	cout << "Number drawn: " << i  << "  (" << validdraws << ")" << endl;

	return i;
}


int main()
{
	bingoboard game;

	int speed;

	cout << "Welcome to Bingo number caller." << endl << "enter speed 1-10 where 1 is fastest (1 second pause between draws)" << endl;

	do {
		cin >> speed;
	}
	while ( (speed > 10) || (speed < 1));


	for (int k=0; k<BINGO_BOARD_SIZE; k++) {  // draw 85 numbers

		game.draw_number();
		game.disp_card();
		sleep(speed);
	}

	cout << "Numbers were called in this order:" << endl;
	game.disp_called();

	return 0;
}
