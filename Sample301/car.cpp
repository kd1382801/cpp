#include "car.h"
#include <iostream>

using namespace std;

//���s����
void Car::drive(double hour) {
	cout << "����" << speed << "km��" << hour << "���ԑ��s" << endl;
	cout << speed * hour << "km�ړ����܂���" << endl;
}