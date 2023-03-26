#pragma once
class stoss
{
public:
	const int ERROR = 1000000000;
	stoss();
	~stoss();

	void push(int x);
	int pop();
	int value();
	bool empty();
	unsigned int size();
private:
	bool f;
	unsigned int i;
	struct wezel {
		int element;
		wezel* poprzedni;
	};
	wezel* el;
	wezel* pom;
};

