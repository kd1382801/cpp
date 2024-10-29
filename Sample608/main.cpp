#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, int> score{};

	score["Tom"] = 100;
	score["Bob"] = 80;
	score["Mike"] = 76;

	score["Tom"] = 90;//"Tom"��90���㏑�������

	//�v�f��ǉ�
	score.insert(make_pair("John", 88));
	score.emplace("David", 70);

	auto itr = score.find("John");
	//first�����o���L�[,second�����o�[���l��\��
	cout << itr->first << "�̓_����" << itr->second << endl;

	//�v�f���폜
	score.erase("Mike");

	cout << "Tom�̓_��:" << score["Tom"] << endl;
	cout << "Bob�̓_��:" << score["Bob"] << endl;
	
	//count() : Mike�������1,�Ȃ����0���Ԃ�
	if (score.count("Mike")) {
		cout << "Mike�̓_��:" << score["Mike"] << endl;
	}

	/*for (auto itr = score.begin(); itr != score.end(); itr++) {
		cout << "Key: " << itr->first << " Value: " << itr->second << endl;
	}*/

	/*for (auto p : score) {
		cout << "Key: " << p.first << " Value: " << p.second << endl;
	}*/
	
	for (auto& [key,value] : score) {
		cout << "Key: " << key << " Value: " << value << endl;
	}

	return 0;
}