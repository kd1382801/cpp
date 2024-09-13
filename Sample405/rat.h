#pragma once

class Rat {
public:
	Rat();
	~Rat();
	static void showNum();
	void squeak();

private:
	int m_id;
	static int s_count;
};