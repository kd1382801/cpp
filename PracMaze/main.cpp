#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"

using namespace std;

int main() {
	Map map;				//Map�N���X�̐���

	map.Load("2d_maze.csv");//�}�b�v�t�@�C���̓ǂݍ��݂Ɗi�[
	system("cls");			//�R�}���h�v�����v�g�̉�ʏ���
	//�R�}���h�v�����v�g�̕\���ʒu��(0,0)�֐ݒ�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
	map.DrawMap();			//�}�b�v�̕`��
	return 0;
}