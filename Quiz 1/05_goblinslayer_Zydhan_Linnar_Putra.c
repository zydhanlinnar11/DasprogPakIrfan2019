#include <stdio.h>

int main() {
	// Declare HP
	int boy = 200; // boy HP
	int ghp1 = 165; // Goblin 1 HP
	int ghp2 = ghp1; // Goblin 2 HP
	int ghp3 = ghp1; // Goblin 3 HP
	
	int turn = 1;
	// We use while looping until boy or Goblin 3 HP reach 0
	do {
		printf( "turn %d\n", turn); // Print turn
		int boyattack=10;
		
		// The boy attack is 10 and every 3rd turn the boy can unleash his skill that deals 20 damage
		if( (turn%3) == 0 ) {
			boyattack+=10;
		}
		
		/*	Boy will attack goblin 1 first till it died and then attack goblin 2 and lastly attack goblin 3
			Goblins will die when their HP reach 0 */
		if( ghp1>0 ) {
			ghp1-=boyattack;
			printf( "boy attacked goblin1 for %d damage; goblin1 hp: %d\n",boyattack,(ghp1<0)?0:ghp1);
		} else if ( ghp2>0 ) {
			ghp2-=boyattack;
			printf( "boy attacked goblin2 for %d damage; goblin2 hp: %d\n",boyattack,(ghp2<0)?0:ghp2);
		} else if ( ghp3>0 ) {
			ghp3-=boyattack;
			printf( "boy attacked goblin3 for %d damage; goblin3 hp: %d\n",boyattack,(ghp3<0)?0:ghp3);
		}
		
		//  The goblins alive will attack the boy for each turn (the dead goblin won't attack)
		if(ghp1>0){
			boy-=3;
			printf("goblin 1 attacked boy for 3 damage; boy hp: %d\n",(boy<0)?0:boy);
		}
		if (ghp2>0) {
			boy-=4;
			printf("goblin 2 attacked boy for 4 damage; boy hp: %d\n",(boy<0)?0:boy);
		}
		if (ghp3>0) {
			boy-=1;
			printf("goblin 3 attacked boy for 1 damage; boy hp: %d\n",(boy<0)?0:boy);
		}
		turn++;
		printf( "\n" );
	} while( (boy>0) && (ghp3>0) );
	
	// Print total turns and cumulative HP of the winning party
	printf( "Total turns: %d\n",--turn );
	if (boy>0){
		printf( "Cumulative HP of the winning party: %d\n", boy);
	} else {
		printf( "Cumulative HP of the winning party: %d\n", ghp1+ghp2+ghp3);
	}
	
	return 0;
}
