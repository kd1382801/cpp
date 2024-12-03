#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
#include "player.h"
#include <random>
#include <algorithm>
#include "battle.h"

using namespace std;

int main() {
	Map map;				//Map�N���X�̐���

	map.Load("2d_maze.csv");//�}�b�v�t�@�C���̓ǂݍ��݂Ɗi�[
	map.SetTreasure();		//���H��ɕ󕨂�ݒu
	Player player;			//Player�N���X�̃C���X�^���X�𐶐�

	//����������ƃ����Z���k�c�C�X�^�[�A���S���Y����ݒ�
	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	//���z�������x,y���W�̒l�𐧌�����
	uniform_int_distribution<int> rnd_x(2, map.mapdata.getMapSize(0) - 3);//2~�ő��-3
	uniform_int_distribution<int> rnd_y(2, map.mapdata.getMapSize() - 3);//2~�ő�s��-3

	while (true) {
		int x = rnd_x(rand_engine);
		int y = rnd_y(rand_engine);
		//�z���y�sx��ڂ̒l��ROAD(0)���ǂ������`�F�b�N
		if (map.mapdata.getMapValue(x, y) == ROAD) {
			//ROAD(0)�������Ƃ��́A���L�����̏����ʒu���Z�b�g����
			player.setX(x);
			player.setY(y);
			break;//�������[�v�𔲂���
		}
	}

	Battle battle;		//Battle�N���X�̃C���X�^���X�𐶐�
	system("cls");		//�R�}���h�v�����v�g�̉�ʏ���
	while (true) {		//�Q�[�����[�v
		//�R�}���h�v�����v�g�̕\���ʒu��(0,0)�֐ݒ�
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
		map.DrawMap(player.getX(), player.getY());//�}�b�v�̕`��
		char input = _getch();
		//��𔭌�������o�g���J�n
		if (player.move(input, map.mapdata) == 99) {
			if (battle.Initialize() == 0) {			
				//�o�g���ɏ��������Ƃ�
				cout << "\033[33m����Q�b�g�I�Q�[���N���A\033[m" << endl;
				return 0;
			}
			else {
				//�o�g���ɔs�k�����Ƃ�
				cout << "\033[31m�Q�[���I�[�o�[�c\033[m" << endl;
				return 0;
			}
		}
	}
	return 0;
}