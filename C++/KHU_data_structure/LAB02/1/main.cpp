#include <fstream>
using namespace std;
// mac_file���Ͽ��� ù ���� �о windows_file���
int main() {
	ifstream input_file("mac_file.txt");
	ofstream output_file("windows_file.txt");

	char ch;
	while (input_file.get(ch)) {
		if (!input_file.is_open()) break;
		if (ch == '\r')
			output_file << '\n';
		else
			output_file << ch;
	}
	input_file.close();
	output_file.close();
}