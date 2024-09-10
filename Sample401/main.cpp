#include <iostream>
#include "car.h"

using namespace std;

int main() {
	//インスタンスの生成
	Car car;
	//スピードの設定(carのメンバ変数に値を代入)
	car.setSpeed(40);
	//走行する(carのメンバ関数を実行)
	car.drive(1.5);
	//走行する
	car.drive(2.0);
	//総移動距離の表示
	cout << "総移動距離:" << car.getMigration() << "km" << endl;
	
	return 0;
}