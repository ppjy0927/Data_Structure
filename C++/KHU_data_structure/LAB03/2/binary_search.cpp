#include <iostream>
using namespace std;

int BinarySearch(int array[], int sizeOfArray, int value);

int main() {
	int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int result = BinarySearch(list, 10, 11);
	cout << result << endl; // -1 ����
	result = BinarySearch(list, 10, 7);
	cout << result << endl; // 6 ����
	
	return 0;
}

// A. ���� Ž��(binary search)�� ���� �Լ�
int BinarySearch(int array[], int sizeOfArray, int value) {
	int midPoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);
	bool found = false;
	while (moreToSearch && !found) {
		midPoint = (first + last) / 2;
		if (array[midPoint] < value) {
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else if (array[midPoint] > value) {
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else {
			found = true;
			return midPoint;
		}
	}
	return -1;
}


// B. ã���� �ϴ� ������ �۰ų� ���� ���� �߿��� ���� ū ���� �����ϴ� �Լ�
/*
int BinarySearch(int array[], int sizeOfArray, int value) {
	int midPoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);
	bool found = false;
	while (moreToSearch && !found) {
		midPoint = (first + last) / 2;
		if (array[midPoint] < value) {
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else if (array[midPoint] > value) {
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else {
			found = true;
			return midPoint;
		}
	}
	return array[last];
}
*/


// C. ã���� �ϴ� ������ ũ�ų� ���� ���� �߿��� ���� ���� ���� �����ϴ� �Լ�
/*
int BinarySearch(int array[], int sizeOfArray, int value) {
	int midPoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);
	bool found = false;
	while (moreToSearch && !found) {
		midPoint = (first + last) / 2;
		if (array[midPoint] < value) {
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else if (array[midPoint] > value) {
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else {
			found = true;
			return midPoint;
		}
	}
	return array[first];
}
*/