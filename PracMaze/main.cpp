#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"

using namespace std;

int main() {
	Map map;				//Mapクラスの生成

	map.Load("2d_maze.csv");//マップファイルの読み込みと格納
	system("cls");			//コマンドプロンプトの画面消去
	//コマンドプロンプトの表示位置を(0,0)へ設定
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
	map.DrawMap();			//マップの描画
	return 0;
}