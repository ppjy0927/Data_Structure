#include <iostream>
using namespace std;

int BinarySearch(int array[], int sizeOfArray, int value);

int main() {
	int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int result = BinarySearch(list, 10, 11);
	cout << result << endl; // -1 리턴
	result = BinarySearch(list, 10, 7);
	cout << result << endl; // 6 리턴
	
	return 0;
}

// A. 이진 탐색(binary search)를 위한 함수
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


// B. 찾고자 하는 값보다 작거나 같은 값들 중에서 가장 큰 값을 리턴하는 함수
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


// C. 찾고자 하는 값보다 크거나 같은 값들 중에서 가장 작은 값을 리턴하는 함수
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