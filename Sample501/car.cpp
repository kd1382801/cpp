#include "car.h"
#include <iostream>

using namespace std;

Car::Car() : m_speed(20.0), m_migration(0.0) {
	cout << "Car�N���X�̃C���X�^���X����" << endl;
}

Car::~Car() {
	cout << "Car�N���X�̃C���X�^���X����" << endl;
}

void Car::setSpeed(double speed) {
	m_speed = speed;
}

double Car::getSpeed() {
	return m_speed;
}

double Car::getMigration() {
	return m_migration;
}

//���s����
void Car::drive(double hour) {
	cout << "����" << m_speed << "km��" << hour << "���ԑ��s" << endl;
	cout << m_speed * hour << "km�ړ����܂���" << endl;
	m_migration += m_speed * hour;
}