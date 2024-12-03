#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:

	MapData mapdata;

	Map();
	void Load(string filename);	//CSVファイルの読み込みと格納
	void DrawMap(int px,int py);//マップ描画
	void SetTreasure();			//宝物を乱数で設置する
};