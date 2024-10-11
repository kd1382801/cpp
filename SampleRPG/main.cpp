#include "chara.h"
#include "player.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {   					      // Hp atk def  sp
	vector<Player*> pPlayer{ new Player(100, 50, 20, 30) };
	//PlayerクラスのアドレスがpPlayer[0]に入る
	
	//インスタンスを追加
	pPlayer.push_back(new Player(300, 70, 40, 50));

	for (int i = 0; i < pPlayer.size(); i++) {
		cout << "Playerの状態" << endl
			<< " HP :" << pPlayer[i]->getHp() << endl
			<< " Sp :" << pPlayer[i]->getSp() << endl
			<< " Atk:" << pPlayer[i]->getAtk() << endl
			<< " Def:" << pPlayer[i]->getDef() << endl;
	}

	//vectorの要素に格納したアドレスを削除
	//先頭要素を指すイテレータを定義
	auto itr = pPlayer.begin();
	//最後の要素までループ
	while (itr != pPlayer.end()){
		//イテレータの示すアドレス(インスタンス)を解放
		delete* itr;
		//vectorの要素自体を削除(要素の個数が変わるためイテレータを更新する)
		itr = pPlayer.erase(itr);
	}

	cout << "pPlayerの要素数:" << pPlayer.size() << endl;

	return 0;
}