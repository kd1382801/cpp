#include "map.h"
#include "maze.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

using namespace std;

Map::Map() = default;

void Map::Load(string filename){
	ifstream ifs(filename);	//���̓t�@�C���X�g���[���̐���

	if (ifs.fail()) {	//�G���[�`�F�b�N
		cout << "FileOpen Error" << endl;
		exit(-1);//�R�[�h-1�ŋ����I��
	}

	string text;
	int j = 0;	//�񎟌��z��̍s���Ǘ�����ϐ�
	while (getline(ifs, text)) {	//�t�@�C�������s�ǂݍ���
		mapdata.resizeMap();		//�񎟌��z��̍s��ǉ�
		istringstream iss(text);	//������X�g���[���𐶐�
		while (getline(iss, text, ',')) {	//�R���}�ŕ���
			mapdata.addMap(j, stoi(text));	//�}�b�v�f�[�^�Ɋi�[
		}
		j++;	//�s�����J�E���g�A�b�v
	}
	ifs.close();
}

void Map::DrawMap(int px, int py) {
	for (int y = py - 2; y <= py + 2; y++) {	//py-2 ~ py+2
		for (int x = px - 2; x <= px + 2; x++) {//px-2 ~ px+
			if (x == px && y == py) {//���S���W�ɂȂ�����
				cout << "@";//���L������\��
			}
			else {	//���S���W�ȊO�̕\������
				if (mapdata.getMapValue(x, y) == WALL) {
					cout << "\033[31m#\033[m";	//�ǂƂ���#��ԐF�ŏo��(�G�X�P�[�v�V�[�P���X���g�p)
				}
				else if (mapdata.getMapValue(x, y) == ROAD) {
					cout << "\033[30m.\033[m";	//�ʘH�Ƃ���.�����F�ŏo��
				}
				else if (mapdata.getMapValue(x, y) == TREASURE) {
					cout << "\033[33m$\033[m";	//�󕨂Ƃ���$�����F�ŏo��
				}
			}
		}
		cout << endl;
	}
}

void Map::SetTreasure() {
	//����������ƃ����Z���k�c�C�X�^�[�A���S���Y����ݒ�
	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	//���z�������x,y���W�̒l�𐧌�����
	uniform_int_distribution<int> rnd_x(2, mapdata.getMapSize(0) - 3);//2~�ő��-3
	uniform_int_distribution<int> rnd_y(2, mapdata.getMapSize() - 3);//2~�ő�s��-3
	
	while (true) {
		int x = rnd_x(rand_engine);
		int y = rnd_y(rand_engine);
		//�z���y�sx��ڂ̒l��ROAD(0)���ǂ������`�F�b�N
		if (mapdata.getMapValue(x, y) == ROAD) {
			//ROAD(0)�������Ƃ��́A���̒n�_�̓��e��TREASURE(2)�ɏ�������
			mapdata.setMapValue(x, y, TREASURE);
			break;//�������[�v�𔲂���
		}
	}
}