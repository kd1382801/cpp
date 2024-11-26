#include "map.h"
#include "maze.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

using namespace std;

Map::Map() = default;

void Map::Load(string filename){
	ifstream ifs(filename);	//入力ファイルストリームの生成

	if (ifs.fail()) {	//エラーチェック
		cout << "FileOpen Error" << endl;
		exit(-1);//コード-1で強制終了
	}

	string text;
	int j = 0;	//二次元配列の行を管理する変数
	while (getline(ifs, text)) {	//ファイルから一行読み込み
		mapdata.resizeMap();		//二次元配列の行を追加
		istringstream iss(text);	//文字列ストリームを生成
		while (getline(iss, text, ',')) {	//コンマで分割
			mapdata.addMap(j, stoi(text));	//マップデータに格納
		}
		j++;	//行数をカウントアップ
	}
	ifs.close();
}

void Map::DrawMap() {
	for (int y = 0; y < mapdata.getMapSize(); y++) {
		for (int x = 0; x < mapdata.getMapSize(y); x++) {
			if (mapdata.getMapValue(x, y) == WALL) {
				cout << "#";	//壁として#を出力
			}
			else if (mapdata.getMapValue(x, y) == ROAD) {
				cout << ".";	//通路として.を出力
			}
		}
		cout << endl;
	}
}