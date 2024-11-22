#pragma once
#include <vector>

using namespace std;

enum MapObj {
	ROAD,//通路
	WALL,//壁
	TREASURE//宝物
};

class MapData {
public:
	MapData();						//コンストラクタ

	int getMapValue(int x, int y);	//指定座標のデータを返す
	int getMapSize(int i);			//列数を取得
	int getMapSize();				//行数を取得
	void addMap(int j, int value);				//指定行にvalueを追加
	void resizeMap();							//二次元配列に新しい行を追加
	void setMapValue(int x, int y, int value);	//指定座標にvalueを格納

private:
	vector<vector<int>> mapData{};	//マップ格納用二次元配列
};