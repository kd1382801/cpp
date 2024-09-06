#pragma once

class Car {
public:
	void setSpeed(double speed);
	//走行する
	void drive(double hour);

private:
	//スピード
	double m_speed;
};
