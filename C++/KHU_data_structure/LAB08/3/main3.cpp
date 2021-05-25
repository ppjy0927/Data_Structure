#include <iostream>
#include <cmath>
using namespace std;

// 재귀 버전
float SqrRoot_recursion(float number, float approx, float tol)
{
	if (fabs(approx * approx - number) <= tol)
		return approx;
	else
		return SqrRoot_recursion(number, (approx * approx + number) / (2 * approx), tol);
}

// 비재귀 버전
float SqrRoot_non_recursion(float number, float approx, float tol)
{
	while (fabs(approx * approx - number) > tol)
	{
		// (approx*approx + number)계산 수행
		approx = (approx * approx + number) / (2 * approx);

	}
	return approx;
}

int main() {
	cout << SqrRoot_recursion(2, 1, 0.1) << endl;
	cout << SqrRoot_non_recursion(2, 1, 0.1) << endl;

	return 0;
}