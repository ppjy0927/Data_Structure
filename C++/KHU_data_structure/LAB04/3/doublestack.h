#ifndef __DOUBLESTACK_H__
#define __DOUBLESTACK_H__

const int MAX_ITEMS = 200;

class doublestack {
private:
	int top_small; // 1000���� �۰ų� ���� ������ top
	int top_big; // 1000���� ū ������ top
	int items[MAX_ITEMS];
public:
	doublestack();
	// Class constructor.
	void Push(int item); // �����ؾ��ϴ� push ����
	void Print(); // stack�� �������� ����ϴ� �Լ�
	bool IsFull() const;
};

#endif