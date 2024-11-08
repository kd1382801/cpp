#include<iostream>
#include<map>
#include<random>

using namespace std;

int main() {
	//英単語の和訳と英訳のペアをdicに格納
	map<string, string>dic{ {"活動","activity"},
							{"雰囲気","atmosphere"},
							{"血液","blood"},
							{"環境","environment"},
							{"温度","temperature"}};

	auto itr = dic.begin();//先頭要素のイテレータを取得
	cout << itr->first << endl;

	//範囲for
	for (const auto d : dic) {
		cout << d.first << endl;
	}

	//乱数生成器を作成
	random_device rand_dev{};
	//乱数アルゴリズムにメルセンヌツイスターを指定
	mt19937 rand_engine(rand_dev());
	//0～(mapの要素数)-1を均等な確率で得る分布生成器を作成
	uniform_int_distribution<int> dist(0, dic.size() - 1);

	//cout << dist(rand_engine) << endl;

	itr = dic.begin();
	itr = next(itr, dist(rand_engine));//std::next(イテレータ,進める量)
	cout << itr->first << "の英単語は?>" << endl;
	string str;
	cin >> str;
	if (str == itr->second) {
		cout << "正解!" << endl;
	}
	else {
		cout << "不正解…" << endl;
	}


	return 0;
}