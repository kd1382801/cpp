#include "chara.h"
#include "player.h"
#include <iostream>

using namespace std;

int main() {				   // Hp atk def  sp
	Player* pPlayer = new Player(100, 50, 20, 30);

	cout << "Player‚Ìó‘Ô" << endl
	   	 << " HP :" << pPlayer->getHp() << endl
	 	 << " Sp :" << pPlayer->getSp() << endl
		 << " Atk:" << pPlayer->getAtk() << endl
		 << " Def:" << pPlayer->getDef() << endl;

	delete pPlayer;
	return 0;
}