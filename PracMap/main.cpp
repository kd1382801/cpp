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

	//構造体を参照してdに格納(参照渡し)
	for (const auto& d : vEne) {
		mapEne.emplace(d.name, d);
	}

	/*for (int i = 0; i < vEne.size(); i++) {
		mapEne[vEne[i].name] = vEne[i];
	}*/

	string str;
	cout << "Enemy名を入力>";
	cin >> str;//Enemy名をキーボードから入力してstrへ

	//Enemy名がキーとしてあるかどうか
	if (mapEne.count(str)) {
		cout << "Name:" << mapEne[str].name << endl
			 << "HP:" << mapEne[str].hp << endl
			 << "Atk:" << mapEne[str].atk << endl
			 << "Def:" << mapEne[str].def << endl;
	}
	
	return 0;
}