#include "player.h"

Player::Player() :m_Sp(0) {};

Player::Player(int a_hp, int a_atk, int a_def, int a_sp) : Chara(a_hp,a_atk,a_def), m_Sp(a_sp) {}

int Player::getSp() {
	return m_Sp;
}