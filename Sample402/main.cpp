#include <iostream>
#include "car.h"

using namespace std;

int main() {
	Car* pCar = nullptr;

	//�C���X�^���X�̐���
	pCar = new Car();
	//�X�s�[�h�̐ݒ�(car�̃����o�ϐ��ɒl����)
	pCar->setSpeed(40);
	//���s����(car�̃����o�֐������s)
	pCar->drive(1.5);
	//���s����
	pCar->drive(2.0);
	//���ړ������̕\��
	cout << "���ړ�����:" << pCar->getMigration() << "km" << endl;
	//�C���X�^���X�̏���
	delete pCar;
	cout << "�C���X�^���X�����I��" << endl;
	return 0;
}