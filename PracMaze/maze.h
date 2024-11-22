#pragma once
#include <vector>

using namespace std;

enum MapObj {
	ROAD,//�ʘH
	WALL,//��
	TREASURE//��
};

class MapData {
public:
	MapData();						//�R���X�g���N�^

	int getMapValue(int x, int y);	//�w����W�̃f�[�^��Ԃ�
	int getMapSize(int i);			//�񐔂��擾
	int getMapSize();				//�s�����擾
	void addMap(int j, int value);				//�w��s��value��ǉ�
	void resizeMap();							//�񎟌��z��ɐV�����s��ǉ�
	void setMapValue(int x, int y, int value);	//�w����W��value���i�[

private:
	vector<vector<int>> mapData{};	//�}�b�v�i�[�p�񎟌��z��
};