#pragma once
#include "car.h"

class Ambulance : public Car {
public:
	//コンストラクタ
	Ambulance();
	//デストラクタ
	virtual ~Ambulance();
	//救急救命活動
	void sevePeople();
private:
	int m_number;
};
