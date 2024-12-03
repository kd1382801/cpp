#pragma once
#include "maze.h"

using namespace std;

struct Vector2 {
	int x, y;
	Vector2(int x, int y) :x(x), y(y) {};//�R���X�g���N�^
};

class Player {
public:

	Player();			//�R���X�g���N�^(�����Ȃ�)
	Player(int x,int y);//�R���X�g���N�^(��������)
	void setX(int x);	//�Z�b�^�[
	void setY(int y);
	int getX();			//�Q�b�^�[
	int getY();
	int move(char key, MapData& mapdata);

private:

	Vector2 Pos;	//�\����Vector2��Pos�Ƃ��Ē�`
};