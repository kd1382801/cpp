#pragma once

class Chara {
protected:
	int m_Hp;
	int m_Atk;
	int m_Def;

public:
	Chara();
	Chara(int a_hp,int a_atk,int a_def);

	int getHp();
	int getAtk();
	int getDef();

};