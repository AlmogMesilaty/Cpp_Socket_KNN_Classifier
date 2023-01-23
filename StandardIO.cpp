#include "StandardIO.hpp"
//Read
string StandardIO::read() {
	string input;
	getline(cin, input);
	return input;
}
//Write
void StandardIO::write(string s) {
	cout << s;
}
//IOType
string StandardIO::IOType() {
	return StandardIO::type;
}