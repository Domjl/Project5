#include <iostream>
#include <fstream>
using std::string;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
using std::cerr;

int readData(string fileName);
int writeData(string fileName);

int main() {

	string fileName = "/Users/Natas/Dropbox/School/CSE 220/ShoppingSystem/PolymorphismBooklist.txt";

	if(readData(fileName) == 0) {
		cout << "Success Reading File" << endl;
	}
	if(writeData(fileName) == 0) {
		cout << "Success Writing File" << endl;
	}
	
	return 0;
}

int readData(string fileName) {
	// Path to file to be opened
	string file = fileName;
	
	// Open a stream with the file provided above
	ifstream fin(file);
	// check to make sure file is found, otherwise create an error message and exit
	if (!fin) {
		cerr << "File " << file << " not found." << endl;
		return -1;
	}

	char str[100];

	// read in entire text file and output to console
	while (fin) {
		fin.getline(str, 100);
		if (fin) cout << str << endl;
	}

	// close both streams before exiting
	fin.close();

	return 0;
}

int writeData(string fileName) {
	// Path to file
	string file = fileName;

	// open the outstream for where the output should be written, in append mode to add to end
	ofstream fout(fileName, ios::app);

	// test write out into file
	fout << "\n\nTest Book Title\n" << "10\n" << "$72.99\n" << "2000\n\n";

	fout.close();

	return 0;
}