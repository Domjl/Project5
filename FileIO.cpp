#include <iostream>
#include <fstream>
using std::string;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
using std::cerr;

int main() {
	// Path to file to be opened (this is also the file we will write out to)
	string fileName = "/Users/Natas/Dropbox/School/CSE 220/ShoppingSystem/bookFile.txt";
	
	// Open a stream with the file provided above
	ifstream fin(fileName);
	// check to make sure file is found, otherwise create an error message and exit
	if (!fin) {
		cerr << "File " << fileName << " not found." << endl;
		return -1;
	}
	// open the outstream for where the output should be written, in append mode to add to end
	ofstream fout(fileName, ios::app);

	char str[50];

	// read in entire text file and output to console
	while (fin) {
		fin.getline(str, 50);
		if (fin) cout << str << endl;
	}

	fout << "\n\nTest Book Title\n" << "10\n" << "$72.99\n" << "2000\n\n";

	// close both streams before exiting
	fin.close();
	fout.close();
	return 0;
}