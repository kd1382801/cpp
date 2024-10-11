#include <iostream>
#include <vector>

using namespace std;

void compare(int& max, int& min, int data) {
	if (data > max) {
		max = data;
	}
	if (data < min) {
		min = data;
	}
}

int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;

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