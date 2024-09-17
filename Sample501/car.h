#pragma once

class Car {
public:
	//コンストラクタ
	Car();
	//デストラクタ
	virtual ~Car();
	//スピードの設定
	void setSpeed(double speed);
	//スピードの取得
	double getSpeed();
	//移動距離の取得
	double getMigration();

	//走行する
	void drive(double hour);

private:
	//スピード
	double m_speed;
	//移動距離
	double m_migration;
};
