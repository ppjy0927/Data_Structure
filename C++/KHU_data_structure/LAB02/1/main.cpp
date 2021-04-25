#include <fstream>
using namespace std;
// mac_file파일에서 첫 문자 읽어서 windows_file기록
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