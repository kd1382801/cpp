#include "chara.h"

Chara::Chara() : m_Hp(0), m_Atk(0), m_Def(0) {}

Chara::Chara(int a_hp, int a_atk, int a_def) : m_Hp(a_hp), m_Atk(a_atk), m_Def(a_def) {}

int Chara::getHp() {
	return m_Hp;
}

int Chara::getAtk() {
	return m_Atk;
}

int Chara::getDef() {
	return m_Def;
}