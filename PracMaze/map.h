#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:

	MapData mapdata;

	Map();
	void Load(string filename);	//CSV�t�@�C���̓ǂݍ��݂Ɗi�[
	void DrawMap(int px,int py);//�}�b�v�`��
	void SetTreasure();			//�󕨂𗐐��Őݒu����
};