#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class bingoboard {
	private:
		char base[90];	// int works but char gives us a nice pictogram
		int validdraws;
	public:
		bingoboard();
		~bingoboard();
		int disp_card();
		int draw_number();
};


bingoboard::bingoboard()
{
	validdraws = 0;
	for (int i = 0; i < 86; i++){
		base[i]=0;  // zero all board numbers
	}
}


bingoboard::~bingoboard()
{
//	nothing done here
}


int bingoboard::disp_card()
{

	for (int i = 1; i < 86; i+=5){
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


int bingoboard::draw_number()
{
	int i;

	srand (time(NULL));

	do {
		i = random() % 85 + 1; // pick a random number from 1 to 85
	}
	while ((base[i] == 1) && (validdraws < 85));	// ensure not already drawn and still need a number drawn

	validdraws++;
	base[i] = 1; // number has been drawn
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


	for (int k=0; k<85; k++) {  // draw 85 numbers

		game.draw_number();
		game.disp_card();
		sleep(speed);
	}

	return 0;
}
