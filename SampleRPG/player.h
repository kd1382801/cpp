#pragma once
#include "chara.h"

class Player : public Chara{
public:
	Player();
	Player(int a_hp, int a_atk, int a_def, int a_sp);

	int getSp();

private:
	int m_Sp;
};