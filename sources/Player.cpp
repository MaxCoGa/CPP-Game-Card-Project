//Compile Switch for testing. Comment line to turn off testing
#define TEST_PLAYER

#include "Player.h"


//Overloading the output stream insertion operator to print the class information
std::ostream &operator<<(std::ostream &os, const Player &thePlayer) {
	switch (thePlayer.displayMode)
	{
	case true:
		return os << thePlayer.name << ": " << thePlayer.nRubies << " rubies";
	case false:
		switch (thePlayer.activeStatus)
		{
		case true:
			return os << thePlayer.name << ": " << thePlayer.side << " (active)";
		case false:
			return os << thePlayer.name << ": " << thePlayer.side << " (inactive)";
		}
	}
}


#ifdef TEST_PLAYER
int main() {

	using namespace std;

	bool testPassed = true;

	//Test 1: testing contructors and getters
	cout << "Test 1: Testing constructors..." << endl;

	Player player1 = Player("Bill", "bottom");
	Player player2 = Player("Janet", "right");
	Player player3 = Player("Dave", "top");
	Player player4 = Player("Annie", "left");

	if (player1.getName() != "Bill")
		testPassed = false;
	if (player2.getNRubies() != 0)
		testPassed = false;
	if (player3.isActive() != false)
		testPassed = false;
	if (player4.getName() != "Annie")
		testPassed = false;

	if (testPassed)
		cout << "Test 1 passed" << endl;
	else
		cout << "Test 1 failed" << endl;

	//Test2: testing setActive
	testPassed = true;

	cout << "Test 2: Testing setActive method " << endl;
	player1.setActive(true);
	player3.setActive(true);
	if (player1.isActive() != true)
		testPassed = false;
	if (player3.isActive() != true)
		testPassed = false;
	player1.setActive(false);
	if (player1.isActive() != false)
		testPassed = false;

	if (testPassed)
		cout << "Test 2 passed" << endl;
	else
		cout << "Test 2 failed" << endl;

	//TO DO IMPLEMENT TESTING OF addReward CLASS ONCE REWARD IMPLEMENTED
	//Test 3: Testing addRewards method
	cout << "Test 3: Testing addRewards method" << endl;
	cout << "Test 3 not implemented" << endl;

	//Test4: testing output stream
	cout << "Test 4: Testing output stream" << endl;
	cout << "Actual output:\t\t" << player1 << endl;
	cout << "Expected output:\t" << "Bill: bottom (inactive)" << endl;

	cout << "\nActual output:\t\t" << player3 << endl;
	cout << "Expected output:\t" << "Dave: top (active)" << endl;

	player1.setDisplayMode(true);
	cout << "\nActual output:\t\t" << player1 << endl;
	cout << "Expected output:\t" << "Bill: 0 rubies" << endl;

	//Uncomment once Reward class has been implemented
	/*player2.setDisplayMode(true);
	cout << "\nActual output:\t\t" << player1 << endl;
	cout << "Expected output:\t" << "Janet: 5 rubies" << endl;*/

	cout << "\nTest 4 complete" << endl;
	cout << "Player test complete" << endl;

	return 0;
}

#endif // TEST_PLAYER