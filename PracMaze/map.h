#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:

	MapData mapdata;

	Map();
	void Load(string filename);	//CSVファイルの読み込みと格納
	void DrawMap();				//マップ描画
};