#include <iostream>
#include <random>
#include <ctime>

using namespace std;

//This is where the progarm starts
int main()
{
	default_random_engine randomGenerator(time(0));
	uniform_real_distribution<float> attack(0.0f, 1.0f);
	
	
	//Basic Stats

	float humanHealth = 200.0f;
	float humanAttack = 0.6f;
	float humanDamage = 25.0f;
	float currentHumanHealth = humanHealth;

	float slimeHealth = 100.0f;
	float slimeAttack = 0.2f;
	float slimeDamage = 15.0f;
	float currentSlimeHealth = slimeHealth;

	//Random Number Maker

	float attackRoll;

	//start numbers 

	int startHumans;
	int startSlimes;

	//Army size
	int numHuman;
	int numSlime;

	//Turns
	char turn = 'H';

	//title
	
	cout << "*** Humans VS Slimes ***\n\n";

	//Amount of Human and Slimes
	
	cout << "Input the number of Humans: ";
	cin >> numHuman;

	startHumans = numHuman;

	cout << "Input the number of Slimes: ";
	cin >> numSlime;

	startSlimes = numSlime;

	//Battle

	cout << "\nBattle Begins!\n\n";

	while ((numHuman > 0) && (numSlime > 0)) {

		attackRoll = attack(randomGenerator);
		
		//Human Attack
		if (turn == 'H') {

			//Check if attack was a hit
			if (attackRoll <= humanAttack) {
				currentSlimeHealth -= humanDamage;

				if (currentSlimeHealth < 0) {
					numSlime--;
					currentSlimeHealth = slimeHealth;
				}
			}

			//Change turn
			turn = 'S';

		} else {
			if (attackRoll <= slimeAttack) {
				currentHumanHealth -= slimeDamage;

				if (currentHumanHealth < 0) {
					numHuman--;
					currentHumanHealth = humanHealth;
				}
			}

			turn = 'H';

		}

	}

	cout << "\nBattle Over!\n\n";

	if (numHuman > 0) {
		cout << "Humans Win!\n";
		cout << "There are " << numHuman << " Humans left!\n";
	} else {
		cout << "Slimes Win!\n";
		cout << "There are " << numSlime << " Slimes left!\n";
	}

	cout << startHumans - numHuman << " humans and " << startSlimes - numSlime << " slimes lost thier lives!\n";
	
	system("PAUSE");
	return 0;
}