#pragma once

class Car {
public:
	//�R���X�g���N�^
	Car();
	//�f�X�g���N�^
	virtual ~Car();
	//�X�s�[�h�̐ݒ�
	void setSpeed(double speed);
	//�X�s�[�h�̎擾
	double getSpeed();
	//�ړ������̎擾
	double getMigration();

	//���s����
	void drive(double hour);

private:
	//�X�s�[�h
	double m_speed;
	//�ړ�����
	double m_migration;
};
