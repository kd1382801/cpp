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

void Map::DrawMap(int px, int py) {
	for (int y = py - 2; y <= py + 2; y++) {	//py-2 ~ py+2
		for (int x = px - 2; x <= px + 2; x++) {//px-2 ~ px+
			if (x == px && y == py) {//中心座標になったら
				cout << "@";//自キャラを表示
			}
			else {	//中心座標以外の表示処理
				if (mapdata.getMapValue(x, y) == WALL) {
					cout << "\033[31m#\033[m";	//壁として#を赤色で出力(エスケープシーケンスを使用)
				}
				else if (mapdata.getMapValue(x, y) == ROAD) {
					cout << "\033[30m.\033[m";	//通路として.を黒色で出力
				}
				else if (mapdata.getMapValue(x, y) == TREASURE) {
					cout << "\033[33m$\033[m";	//宝物として$を黄色で出力
				}
			}
		}
		cout << endl;
	}
}

void Map::SetTreasure() {
	//乱数生成器とメルセンヌツイスターアルゴリズムを設定
	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	//分布生成器でx,y座標の値を制限する
	uniform_int_distribution<int> rnd_x(2, mapdata.getMapSize(0) - 3);//2~最大列数-3
	uniform_int_distribution<int> rnd_y(2, mapdata.getMapSize() - 3);//2~最大行数-3
	
	while (true) {
		int x = rnd_x(rand_engine);
		int y = rnd_y(rand_engine);
		//配列のy行x列目の値がROAD(0)かどうかをチェック
		if (mapdata.getMapValue(x, y) == ROAD) {
			//ROAD(0)だったときは、その地点の内容をTREASURE(2)に書き換え
			mapdata.setMapValue(x, y, TREASURE);
			break;//無限ループを抜ける
		}
	}
}