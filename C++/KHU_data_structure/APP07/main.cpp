#include <iostream>
#include <string>
#define MAX_LEN 50
using namespace std;

string decrypt(string &n) {
	int i = 0;

	while (i < n.length()) {
		if (n[i] != ')' && n[i] != '(') {
			i++;
			if (i == n.length() - 1)
				return n;
		}
		else
			break;
	}
	
	int j = 0;
	string sum1, sum2, sum3;
	while (j < MAX_LEN) {
		if (n[j] != ')')
			sum1 += n[j];
		j++;
	}

	int k = sum1.length();
	while (sum1.length() != 0) {
		if (n[k] != '(') {
			char c = sum1.back();
			sum1.pop_back();
			sum2 += c;
		}
		k--;
	}

	int m = 0;
	while (sum1.length() != 0) {
		if(sum1[m] != '(')
			sum1.pop_back();
	}
	
	int num = sum1.back();
	
	for (int i = 0; i < num; i++) {
		sum2 += sum2;
	}

	sum3 = sum1 + '(' + sum2 +')';

	return decrypt(sum3);
}

int main() {
	string n;
	std::getline(cin, n);

	cout << decrypt(n) << endl;
	cout << decrypt(n).length() << endl;

	return 0;
}