#pragma once
#include "car.h"

class Ambulance : public Car {
public:
	//�R���X�g���N�^
	Ambulance();
	//�f�X�g���N�^
	virtual ~Ambulance();
	//�~�}�~������
	void sevePeople();
private:
	int m_number;
};
