#include <iostream>
#include <vector>

using namespace std;

//参照渡し
void compare(int& max, int& min, const int& data) {
	/*if (data > max) {
		max = data;
	}
	if (data < min) {
		min = data;
	}*/

	//条件演算子を使った書き方
	max = data > max ? data : max;
	min = data < min ? data : min;
	
}

int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;

	//ループを使わない
	cout << "max_element,min_element" << endl;
	max = *max_element(vec.begin(), vec.end());//戻り値:最大値のイテレータ
	min = *min_element(vec.begin(), vec.end());
	cout << "最大値:" << max << " " << "最小値:" << min << endl;

	//添え字の番号を使ったループ
	max = vec[0];
	min = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		compare(max, min, vec[i]);
	}
	cout << "最大値:" << max << " " << "最小値:" << min << endl;

	vec.push_back(0);

	//イテレータを使ったループ
	max = min = vec.at(0);//vec[0]と同じ
	for (auto itr = vec.begin() + 1; itr != vec.end(); ++itr) {
		compare(max, min, *itr);
	}
	cout << "最大値:" << max << " " << "最小値:" << min << endl;

	vec.push_back(100);

	//範囲forを使ったループ
	max = min = vec.front();//vecの先頭要素を取得
	for (auto i : vec) {
		compare(max, min, i);
	}
	cout << "最大値:" << max << " " << "最小値:" << min << endl;

	return 0;
}