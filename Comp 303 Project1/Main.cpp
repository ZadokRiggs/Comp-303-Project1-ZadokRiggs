#include "function.h"

using namespace std;

int main() {
	// opens file
	ifstream inFile;
	inFile.open("input.txt");

	//iterates through each line of the file, fills the Array
	int inInt;
	int array[100];
	int count = 0;
	while (inFile >> inInt) {
		array[count] = inInt;
		count += 1;
	}
	
	//Menu function, allows accesss to sub-functions
	char choice;
	int num = 0;
	while (true) {
		cout << "Choose your command: " << endl
			<< "(C)heck, (I)nsert, (A)ppend, (N)ull" << endl
			<< "---> ";
		cin >> choice;
		toupper(choice);

		switch (choice) {
		case 'C' :
			cout << "What num would you like to check?" << endl
				<< "---> ";
			cin >> num;
			check_num(num);
		case 'I':
			cout << "What num would you like to check?" << endl
				<< "---> ";
			cin >> num;
			check_num(num);
		}


	}
}