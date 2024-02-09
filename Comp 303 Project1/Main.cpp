#include "function.h"

using namespace std;

int main() {
	// opens file
	ifstream inFile;
	inFile.open("Input.txt");

	//iterates through each line of the file, fills the Array
	int inInt;
	int array[100];
	int size = 100;
	int count = 0;
	while (inFile >> inInt) {
		array[count] = inInt;
		count += 1;
	}
	
	//Menu function, allows accesss to sub-functions
	char choice;
	int num = 0;
	int num2 = 0;
	int turned = 0;
	while (true) {
		try {
			cout << "Choose your command: "
				<< endl
				<< "(C)heck, (M)odify, (A)ppend, (N)ull"
				<< endl
				<< "---> ";
			cin >> choice;
			choice = toupper(choice);
			if (choice != 'C' && choice != 'M' && choice != 'A' && choice != 'N') {
				throw 0;
			}

			switch (choice) {
			case 'C'://COMPLETE
				cout << "What num would you like to check?"
					<< endl
					<< "---> ";
				cin >> num;
				if (num < 0 || num >= size) {
					throw 0;
				}
				turned = check_num(size, array, num);
				if (turned != -999) {
					cout << endl
						<< "The number has been found at position " << turned << "."
						<< endl
						<< endl;
				}
				else {
					cout << endl
						<< "Number not found."
						<< endl
						<< endl;
				}
				turned = 0;
				break;

			case 'M': //COMPLETE
				cout << "What space would you like to modify?"
					<< endl
					<< "---> ";
				cin >> num;
				if (num < 0 || num >= size) {
					throw 0;
				}

				cout << "What num would you like to put in it?"
					<< endl
					<< "---> ";
				cin >> num2;

				turned = modify(size, array, num, num2);

				if (turned == 1) {
					cout << endl
						<< "Modification successful"
						<< endl
						<< endl;
				}
				else {
					cout << endl
						<< "Modification failed"
						<< endl
						<< endl;
				}

				turned = 0;
				break;

			case 'A':
				cout << "What num would you like to Append?"
					<< endl
					<< "---> ";
				cin >> num;
				if (num < 0 || num >= size) {
					throw 0;
				}
				append(size, array, num);
				turned = 0;
				break;

			case 'N': //COMPLETE
				cout << "What space would you like to Nullify?"
					<< endl
					<< "---> ";
				cin >> num;
				if (num < 0 || num >= size) {
					throw 0;
				}
				turned = zero_out(size, array, num);
				if (turned == 1) {
					cout << endl
						<< "Null successful."
						<< endl
						<< endl;
				}
				else {
					cout << endl
						<< "Null failed."
						<< endl
						<< endl;
				}
				turned = 0;
				break;
			}
		}
		catch (...) {
			cout << endl
				<< "Num out of range."
				<< endl
				<< endl;
		}
	}
}
