/*
Takes input from classification-input.txt
Classifies each line by its type
Return totals for each type, then percentage of whole for each type
*/

#include "Header.h"

int function2_1(){
	ifstream inputFile;
	string line;
	int total = 0, transitAccess = 0, enterprise = 0, content = 0;

	inputFile.open("classification-input.txt", ios::out);

	if (!inputFile) {
		cout << "ERROR: file not properly open" << endl;
		return 0;
	}

	//for getline to work, be sure that the last line in input.txt ends with a \n
	getline(inputFile, line);
	while (!inputFile.eof()) {
		//cout << line << endl;//TESTING

		//this takes in one line of input, then checks the last character of the string to assign type
		//'s' = transit/access
		//'e' = enterprise
		//'t' = content
		switch (line.back()) {
		case 's':
			++transitAccess;
			//cout << "case s!!" << endl;//TESTING
			break;

		case 'e':
			++enterprise;
			//cout << "case e!!" << endl;//TESTING
			break;

		case 't':
			++content;
			//cout << "case t!!" << endl;//TESTING
			break;
		}
		//++total;//TESTING
		getline(inputFile, line);
	}
	total = transitAccess + content + enterprise;
	//cout << "total counter is at:" << total << endl;//TESTING
	//cout << "'s' + 'e' + 't' categories: " << transitAccess + content + enterprise << endl;//TESTING

	cout << "Type Totals:" << endl;
	cout << "Transit/Access\t" << transitAccess << endl;
	cout << "Enterprise\t" << enterprise << endl;
	cout << "Content\t\t" << content << endl;
	cout << "Total by Sum\t" << transitAccess + content + enterprise << endl;
	cout << "Total Int Variable\t" << total << endl << endl;

	cout << "Type Percentages:" << endl;
	cout << "Transit/Access\t" << (double)transitAccess / (double)total << endl;
	cout << "Enterprise\t" << (double)enterprise / (double)total << endl;
	cout << "Content\t\t" << (double)content / (double)total << endl;
	cout << "Total by Sum\t" << ((double)transitAccess / (double)total) + ((double)enterprise / (double)total) + ((double)content / (double)total) << endl;


	return 1;
}