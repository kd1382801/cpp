#include <iostream>
#include "car.h"

using namespace std;

int main() {
	Car* pCar = nullptr;

	//インスタンスの生成
	pCar = new Car();
	//スピードの設定(carのメンバ変数に値を代入)
	pCar->setSpeed(40);
	//走行する(carのメンバ関数を実行)
	pCar->drive(1.5);
	//走行する
	pCar->drive(2.0);
	//総移動距離の表示
	cout << "総移動距離:" << pCar->getMigration() << "km" << endl;
	//インスタンスの消去
	delete pCar;
	cout << "インスタンス消去終了" << endl;
	return 0;
}