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

void Map::DrawMap() {
	for (int y = 0; y < mapdata.getMapSize(); y++) {
		for (int x = 0; x < mapdata.getMapSize(y); x++) {
			if (mapdata.getMapValue(x, y) == WALL) {
				cout << "#";	//�ǂƂ���#���o��
			}
			else if (mapdata.getMapValue(x, y) == ROAD) {
				cout << ".";	//�ʘH�Ƃ���.���o��
			}
		}
		cout << endl;
	}
}