#include "Header.h"
#define KEY_MAX 396450

int parseInData(map<int, int>& degreeMap, map<int, vector<int>>& providerMap);

int updateMaps(int as1, int as2, bool p2p, map<int, int>& degreeMap, map<int, vector<int>>& providerMap);

int displayGraph2Data(map<int, int>& degreeMap);

int function2_2() {

	map<int, int> degreeMap;
	map<int, vector<int>> providerMap;
	int i = 0;
	

	//set degree for each key to 0
	for (i = 0; i <= KEY_MAX; ++i) {
		degreeMap[i] = 0;
	}
	i = 0;
	cout << "degreeMap initialized!" << endl;//TESTING
	

	parseInData(degreeMap, providerMap);
	
	displayGraph2Data(degreeMap);
	
	//TESTING
	//cout << "key:2 degree:" << degreeMap[2] << endl;//
	//cout << "key:45714 degree:" << degreeMap[45714] << endl;
	//cout << "key:6347 degree:" << degreeMap[6347] << endl;
	//cout << "key:2 degree:" << degreeMap[9365] << endl;
	//cout << "key:396450 degree:" << degreeMap[396450] << endl;
	//cout << "key:366350 degree:" << degreeMap[366350] << endl;


	return 1;
}

int updateMaps(int as1, int as2, bool p2p, map<int, int>& degreeMap, map<int, vector<int>>& providerMap) {
	
	if (p2p) {//p2p
		degreeMap[as1]++;
		degreeMap[as2]++;
	}
	else {//p2c
		degreeMap[as1]++;

		//checks if as2 is already present in array, if not it adds
		if(find(providerMap[as1].begin(), providerMap[as1].end(), as2) != providerMap[as1].end())
			providerMap[as1].push_back(as2);
	}

	return 1;
}

int parseInData(map<int, int>& degreeMap, map<int, vector<int>>& providerMap) {
	ifstream inputFile;
	string line;
	int i = 0;
	string as1, as2;
	bool p2p;

	inputFile.open("relationship-input.txt", ios::out);

	if (!inputFile) {
		cout << "ERROR: file not properly open" << endl;
		return 0;
	}

	//for getline to work, be sure that the last line in input.txt ends with a \n
	getline(inputFile, line);
	while (!inputFile.eof()) {

		//parse in as1, one char at a time until it reaches '|'
		while (line.at(i) != '|') {
			as1.append(line, i, 1);
			++i;
		}
		++i;
		//parse in as2
		while (line.at(i) != '|') {
			as2.append(line, i, 1);
			++i;
		}
		++i;

		//set p2p or p2c type
		p2p = (line.at(i) == '0') ? true : false;

		updateMaps(atoi(as1.c_str()), atoi(as2.c_str()), p2p, degreeMap, providerMap);

		as1 = as2 = ""; 
		i = 0;
		getline(inputFile, line);

	}

	return 1;
}

int displayGraph2Data(map<int, int>& degreeMap) {
	int total = 0, one = 0, two_five = 0, five_hundred = 0, 
		hundred_2hundred = 0, twohundred_thousand = 0, thousand_plus = 0;

	/*for (int i = 0; i <= KEY_MAX; ++i) {

	}*/

	return 1;
}