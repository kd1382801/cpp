#include <iostream>
#include "car.h"

using namespace std;

int main() {
	//�C���X�^���X�̐���
	Car car;
	//�X�s�[�h�̐ݒ�(car�̃����o�ϐ��ɒl����)
	car.setSpeed(40);
	//���s����(car�̃����o�֐������s)
	car.drive(1.5);
	return 0;
}