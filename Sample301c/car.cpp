#include "car.h"
#include <iostream>

using namespace std;

void Car::setSpeed(double speed) {
	m_speed = speed;
}

//‘–s‚·‚é
void Car::drive(double hour) {
	cout << "‘¬" << m_speed << "km‚Å" << hour << "ŠÔ‘–s" << endl;
	cout << m_speed * hour << "kmˆÚ“®‚µ‚Ü‚µ‚½" << endl;
}