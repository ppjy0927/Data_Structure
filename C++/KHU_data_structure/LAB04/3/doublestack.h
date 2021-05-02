#ifndef __DOUBLESTACK_H__
#define __DOUBLESTACK_H__

const int MAX_ITEMS = 200;

class doublestack {
private:
	int top_small; // 1000보다 작거나 같은 스택의 top
	int top_big; // 1000보다 큰 스택의 top
	int items[MAX_ITEMS];
public:
	doublestack();
	// Class constructor.
	void Push(int item); // 구현해야하는 push 연산
	void Print(); // stack의 아이템을 출력하는 함수
	bool IsFull() const;
};

#endif