#include "chara.h"
#include "player.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {   					      // Hp atk def  sp
	vector<Player*> pPlayer{ new Player(100, 50, 20, 30) };
	//Player�N���X�̃A�h���X��pPlayer[0]�ɓ���
	
	//�C���X�^���X��ǉ�
	pPlayer.push_back(new Player(300, 70, 40, 50));

	for (int i = 0; i < pPlayer.size(); i++) {
		cout << "Player�̏��" << endl
			<< " HP :" << pPlayer[i]->getHp() << endl
			<< " Sp :" << pPlayer[i]->getSp() << endl
			<< " Atk:" << pPlayer[i]->getAtk() << endl
			<< " Def:" << pPlayer[i]->getDef() << endl;
	}

	//vector�̗v�f�Ɋi�[�����A�h���X���폜
	//�擪�v�f���w���C�e���[�^���`
	auto itr = pPlayer.begin();
	//�Ō�̗v�f�܂Ń��[�v
	while (itr != pPlayer.end()){
		//�C�e���[�^�̎����A�h���X(�C���X�^���X)�����
		delete* itr;
		//vector�̗v�f���̂��폜(�v�f�̌����ς�邽�߃C�e���[�^���X�V����)
		itr = pPlayer.erase(itr);
	}

	cout << "pPlayer�̗v�f��:" << pPlayer.size() << endl;

	return 0;
}