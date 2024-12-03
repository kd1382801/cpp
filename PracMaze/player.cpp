#include "maze.h"
#include "player.h"
#include <iostream>

Player::Player() :Pos(0, 0) {};

Player::Player(int x, int y) :Pos(x, y) {};

void Player::setX(int x) {
	Pos.x = x;
}

void Player::setY(int y) {
	Pos.y = y;
}

int Player::getX() {
	return Pos.x;
}

int Player::getY() {
	return Pos.y;
}

int Player::move(char key, MapData& mapdata) {
	int newPosX = Pos.x;
	int newPosY = Pos.y;

	switch (key){
	case 'w':		//��
		newPosY--;
		break;
	case 'a':		//��
		newPosX--;
		break;
	case 's':		//��
		newPosY++;
		break;
	case 'd':		//�E
		newPosX++;
		break;
	case '@':		//�����I���p
		exit(0);
	}

	//�ړ��͈̓`�F�b�N�FX,Y���W�Ƃ���0�ȏォ�񐔂�s���菬����
	if (newPosX >= 0 && newPosX < mapdata.getMapSize(0)
		&& newPosY >= 0 && newPosY < mapdata.getMapSize()) {
		//�ړ��\���ʒu���ǂłȂ����ǂ����̃`�F�b�N
		if (mapdata.getMapValue(newPosX, newPosY) != WALL) {
			//�ړ��\�Ȃ�v���C���[�ʒu���X�V
			Pos.x = newPosX;
			Pos.y = newPosY;
			//�v���C���[�̈ʒu���󔠂Əd�Ȃ�Ƃ�
			if (mapdata.getMapValue(newPosX, newPosY) == TREASURE) {
				return 99;
				cout << "\033[33m���󔭌��I�I�Q�[���N���A\033[m" << endl;
				exit(0);
			}
		}
	}
	return 0;
}