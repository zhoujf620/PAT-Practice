// 1011. World Cup Betting (20)

// With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa.  Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.

// Chinese Football Lottery provided a "Triple Winning" game.  The rule of winning was simple: first select any three of the games.  Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose.  There was an odd assigned to each result.  The winner's odd would be the product of the three odds times 65%.

// For example, 3 games' odds are given as the following:
//  W    T    L
// 1.1  2.5  1.7
// 1.2  3.0  1.6
// 4.1  1.2  1.1

// To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game.  If each bet takes 2 yuans, then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 = 37.98 yuans (accurate up to 2 decimal places).

// Input

// Each input file contains one test case.  Each case contains the betting information of 3 games.  Each game occupies a line with three distinct odds corresponding to W, T and L.

// Output

// For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places.  The characters and the number must be separated by one space.

// Sample Input
// 1.1 2.5 1.7
// 1.2 3.0 1.6
// 4.1 1.2 1.1

// Sample Output
// T T W 37.98


#include <iostream>
using namespace std;

int main() {
	char ch[4] = {"WTL"};
	float profit = 1.0;

	for(int i = 0; i < 3; i++) {

		float value = 0.0;
		int index = 0;
		for(int j = 0; j < 3; j++) {
			float temp;
			scanf("%f", &temp);
			if(value <= temp) {
				value = temp;
				index = j;
			}
		}

		profit *= value;
		printf("%c ", ch[index]);
	}
	printf("%.2f", (profit * 0.65 - 1) * 2);
	return 0;
}