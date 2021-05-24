#include <iostream>
using namespace std;

// C.��� ������ �� ȿ�������� ������ ����Ų�ٰ� �����ϴ°�?
// ��: ������ �ʴ´ٰ� �����Ѵ�. 
//	   ��� ������ �� �Ȱ��� ����� ���� �� �ݺ��ϱ� ������ ��귮�� �þ ��ȿ�����̴�.

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