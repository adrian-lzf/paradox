#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int table[21];
char poker[52][11] = {{"Heart A"},{"Heart 2"},{"Heart 3"},{"Heart 4"},{"Heart 5"},{"Heart 6"},{"Heart 7"},
	   {"Heart 8"},{"Heart 9"},{"Heart 10"},{"Heart J"},{"Heart Q"},{"Heart K"},
	   {"Spade A"},{"Spade 2"},{"Spade 3"},{"Spade 4"},{"Spade 5"},{"Spade 6"},{"Spade 7"},
	   {"Spade 8"},{"Spade 9"},{"Spade 10"},{"Spade J"},{"Spade Q"},{"Spade K"},
	   {"Diamond A"},{"Diamond 2"},{"Diamond 3"},{"Diamond 4"},{"Diamond 5"},{"Diamond 6"},{"Diamond 7"},
	   {"Diamond 8"},{"Diamond 9"},{"Diamond 10"},{"Diamond J"},{"Diamond Q"},{"Diamond K"},
	   {"Club A"},{"Club 2"},{"Club  3"},{"Club 4"},{"Club 5"},{"Club 6"},{"Club 7"},
 	   {"Club 8"},{"Club 9"},{"Club 10"},{"Club J"},{"Club Q"},{"Club K"}};

void giveOut(int &c, double &score);
void gameStart(int &c, double &score);
int AIPlay(int &c, double &score);


int main()
{
	char judge = 'y';	 		  //This variable is created to judge whether to play the game again
	while(judge == 'y')  
	{
		int c = 0;		 		  //Represents the amount of the cards on the table 
		double score = 0;
		srand(time(NULL));
		gameStart(c, score);  	  //Deliver the addresses of the 2 variables
		if (score > 21) {cout << "\nYou lose\n\n";
		cout << "One more game? (y/n)£º";
		cin >> judge; continue;}  //When the score of the player is more than 21, the game should end immediately			
		AIPlay(c, score);  		  //The stage of the AI
		cout << "One more game? (y/n)£º";
		cin >> judge;
	}
	return 0;
}


void giveOut(int &c, double &score)
{
	int i, tmp;
	tmp = rand()%52;
	for (i=0; i<c; ++i)			  //Insure that every card on the table is unique
	{
		if (tmp == table[i]) {tmp = rand()%52; i=0;}
	} 
	table[c] = tmp;
	
	if (table[c]%13 <= 9) score += table[c]%13 + 1;
    else score += 0.5;			  //J, Q, K equals 0.5 points 
    if (c != 0) {for (i = 0; i <= c; ++i) cout << poker[table[i]] << "  ";};  //show the pokers on the table
    c++;
}


void gameStart(int &c, double &score)
{
	char judge = 'y';
	cout << "Player Stage\nYou get cards: ";
	giveOut(c, score); giveOut(c, score);
	while (judge == 'y')
	{
		cout << "\nOne more card? (y/n)";
		cin >> judge;
		if (judge == 'y')
		{
			cout << "Your cards: ";
			giveOut(c, score);
		}
		if (score > 21) break;
	}
}


int AIPlay(int &c, double &score)
{
	double tmp1 = score;
	int tmp2 = c;
	c = 0; score = 0;
	char judge = 'y';
	cout << "\nAI Stage\nAI gets cards: ";
	giveOut(c, score); giveOut(c, score);
	while (score < tmp1 || (score == tmp1 && c < tmp2))
	{
		cout << "\nAI's Cards: ";
		giveOut(c, score);
	}
	if (score > 21 || (score == tmp1 && tmp2 > c)) {cout << "\nYou win!!\n\n"; return 0;}
	if (score > tmp1 || (score == tmp1 && tmp2 < c)) cout << "\nYou lose...\n\n";
	else cout << "\nTie\n\n"; 	
}
