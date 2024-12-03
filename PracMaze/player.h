#pragma once
#include "maze.h"

using namespace std;

struct Vector2 {
	int x, y;
	Vector2(int x, int y) :x(x), y(y) {};//コンストラクタ
};

class Player {
public:

	Player();			//コンストラクタ(引数なし)
	Player(int x,int y);//コンストラクタ(引数あり)
	void setX(int x);	//セッター
	void setY(int y);
	int getX();			//ゲッター
	int getY();
	int move(char key, MapData& mapdata);

private:

	Vector2 Pos;	//構造体Vector2をPosとして定義
};