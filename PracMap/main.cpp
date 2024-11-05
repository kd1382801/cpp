#include<map>
#include<vector>
#include<iostream>

using namespace std;

typedef struct {
	string name;
	int hp, atk, def;
} Enemy;

int main() {
	vector<Enemy> vEne{ {"Slime",10,5,8},
						{"Wolf",20,30,1},
						{"Spider",30,15,5} };
	map<string, Enemy> mapEne;

	//�\���̂��Q�Ƃ���d�Ɋi�[(�Q�Ɠn��)
	for (const auto& d : vEne) {
		mapEne.emplace(d.name, d);
	}

	/*for (int i = 0; i < vEne.size(); i++) {
		mapEne[vEne[i].name] = vEne[i];
	}*/

	string str;
	cout << "Enemy�������>";
	cin >> str;//Enemy�����L�[�{�[�h������͂���str��

	//Enemy�����L�[�Ƃ��Ă��邩�ǂ���
	if (mapEne.count(str)) {
		cout << "Name:" << mapEne[str].name << endl
			 << "HP:" << mapEne[str].hp << endl
			 << "Atk:" << mapEne[str].atk << endl
			 << "Def:" << mapEne[str].def << endl;
	}
	
	return 0;
}