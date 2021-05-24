#include <iostream>
using namespace std;

// C.재귀 버전이 더 효율적으로 성능을 향상시킨다고 생각하는가?
// 답: 향상되지 않는다고 생각한다. 
//	   재귀 버전일 때 똑같은 계산을 여러 번 반복하기 때문에 계산량이 늘어나 비효율적이다.

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);

int main()
{
	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_recursive(10) << endl;

	return 0;
}

int Fibonacci_recursive(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci_recursive(n - 2) + Fibonacci_recursive(n - 1);
}

int Fibonacci_non_recursive(int n) {
	if (n == 1)
		return 1;
	int num = 0;
	int sum = 0;
	int n0 = 0, n1 = 1;
	while (num < n-1) {
		sum = n0 + n1;
		n0 = n1; 
		n1 = sum;
		num++;
	}
	return sum;
}