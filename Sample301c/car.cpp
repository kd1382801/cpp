#include "car.h"
#include <iostream>

using namespace std;

void Car::setSpeed(double speed) {
	m_speed = speed;
}

//走行する
void Car::drive(double hour) {
	cout << "時速" << m_speed << "kmで" << hour << "時間走行" << endl;
	cout << m_speed * hour << "km移動しました" << endl;
}