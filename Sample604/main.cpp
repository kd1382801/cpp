#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> v1{ 10,9,8 };
	vector<string> v2;

	if (v1.empty()) {
		cout << "配列は空です" << endl;
	}

	cout << "v1の要素数：" << v1.size() << endl;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back("ABC");
	v2.push_back("DEF");
	
	cout << "v1の要素数：" << v1.size() << endl;

	for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]=" << v1[i] << endl;
	}

	//vector<int>::iterator itrV1 = v1.begin();//v1の先頭要素の場所
	auto itrV1 = v1.begin();//autoで省略 初期値が必要
	cout << "itrV1の値は" << *itrV1 << endl;
	v1.erase(itrV1);//v1のitrV1の要素を削除
	v1.insert(itrV1 + 1, 7);//itrV1+1の場所に7を挿入

	v1.pop_back();
	v1.emplace_back(4);
	
	/*for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]=" << v1[i] << endl;
	}*/

	/*//イテレーターを使った表示			最終要素+1になるまで
	//for (auto itr = v1.begin(); itr != v1.end(); ++itr) {
	//	cout << *itr << endl;
	}*/

	//範囲for : v1の先頭要素から最終要素まで全ての要素分ループ（指定はできない）
	for (auto itr : v1) {
		cout << itr << endl;//itrに*は不要
	}

	cout << "v1の要素数：" << v1.size() << endl;
	cout << "v2の要素数：" << v2.size() << endl;

	v2.pop_back();
	v2.emplace_back("G");

	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]=" << v2[i] << endl;
	}
	cout << "v2の要素数：" << v2.size() << endl;
	return 0;
}