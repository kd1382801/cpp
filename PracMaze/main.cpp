#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
#include "player.h"
#include <random>
#include <algorithm>
#include "battle.h"

using namespace std;

int main() {
	Map map;				//Mapクラスの生成

	map.Load("2d_maze.csv");//マップファイルの読み込みと格納
	map.SetTreasure();		//迷路上に宝物を設置
	Player player;			//Playerクラスのインスタンスを生成

	//乱数生成器とメルセンヌツイスターアルゴリズムを設定
	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	//分布生成器でx,y座標の値を制限する
	uniform_int_distribution<int> rnd_x(2, map.mapdata.getMapSize(0) - 3);//2~最大列数-3
	uniform_int_distribution<int> rnd_y(2, map.mapdata.getMapSize() - 3);//2~最大行数-3

	while (true) {
		int x = rnd_x(rand_engine);
		int y = rnd_y(rand_engine);
		//配列のy行x列目の値がROAD(0)かどうかをチェック
		if (map.mapdata.getMapValue(x, y) == ROAD) {
			//ROAD(0)だったときは、自キャラの初期位置をセットする
			player.setX(x);
			player.setY(y);
			break;//無限ループを抜ける
		}
	}

	Battle battle;		//Battleクラスのインスタンスを生成
	system("cls");		//コマンドプロンプトの画面消去
	while (true) {		//ゲームループ
		//コマンドプロンプトの表示位置を(0,0)へ設定
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
		map.DrawMap(player.getX(), player.getY());//マップの描画
		char input = _getch();
		//宝を発見したらバトル開始
		if (player.move(input, map.mapdata) == 99) {
			if (battle.Initialize() == 0) {			
				//バトルに勝利したとき
				cout << "\033[33mお宝ゲット！ゲームクリア\033[m" << endl;
				return 0;
			}
			else {
				//バトルに敗北したとき
				cout << "\033[31mゲームオーバー…\033[m" << endl;
				return 0;
			}
		}
	}
	return 0;
}