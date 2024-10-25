#include <list>
#include <iostream>

using namespace std;

int main() {
	//ブロック(ブロック内の変数はブロック内でしか使えない)
	//li1の末尾にli2のデータを順に追加する方法
	{
		list<int> li1{ 2,3,11,17 };
		list<int> li2{ 5,7,13,19 };

		for (auto d : li2) {
			li1.push_back(d);
		}
		li1.sort();
		cout << "連結結果：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	//li2の先頭にli1の末尾データから順に追加する方法
	{
		list<int> li1{ 2,3,11,17 };
		list<int> li2{ 5,7,13,19 };

		/*//逆順にする
		li1.reverse();//li1を逆順にする
		for (auto d:li1) {
			li2.push_front(d);
		}*/

		//逆イテレーターを使う(末尾rbegin()から先頭rend()までのループ)
		for (auto itr = li1.rbegin(); itr != li1.rend(); itr++) {
			li2.push_front(*itr);
		}

		li2.sort();
		cout << "連結結果：";
		for (auto d : li2) {
			cout << d << " ";
		}
		cout << endl;
	}
	//merge関数を使った方法
	{
		list<int> li1{ 2,3,11,17 };
		list<int> li2{ 5,7,13,19 };

		//li1にli2を統合する(li2の内容は消える)
		li1.merge(li2);//merge()を使うと自動的に昇順ソートされる
		cout << "連結結果：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2の要素数:" << li2.size() << endl;
	}
	//insert関数を使った方法
	{
		list<int> li1{ 2,3,11,17 };
		list<int> li2{ 5,7,13,19 };

		//li1の末尾にli2の先頭から末尾までを挿入する(li2の内容はそのまま残る)
		li1.insert(li1.end(), li2.begin(), li2.end());//昇順ソートはされない
		li1.sort();
		cout << "連結結果：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2の要素数:" << li2.size() << endl;
	}
	//splice関数を使った方法
	{
		list<int> li1{ 2,3,11,17 };
		list<int> li2{ 5,7,13,19 };

		//li1の末尾にli2を挿入する(li2の内容は消える)
		li1.splice(li1.end(), li2);//昇順ソートはされない
		li1.sort();
		cout << "連結結果：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2の要素数:" << li2.size() << endl;
	}
}