#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:

	MapData mapdata;

	Map();
	void Load(string filename);	//CSV�t�@�C���̓ǂݍ��݂Ɗi�[
	void DrawMap();				//�}�b�v�`��
};