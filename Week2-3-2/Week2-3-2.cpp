#include <map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

void Change_Capital(map<string,string>& map, string country, string capital) {
	if (map.count(country) == 0) {
		map.insert({ country,capital });
		cout << "Introduce new country " << country << " with capital " << capital << endl;
	}
	else if (map.find(country)->second == capital) {
		cout << "Country " << country << " hasn't change it's capital" << endl;
	}
	else {
		cout << "Country " << country << " has change capital from " << map.find(country)->second << " to " << capital << endl;
		map.find(country)->second = capital;
	}
}

void Rename(map<string, string>& map, string oldCoutry, string newCountry) {
	if ((map.count(oldCoutry) == 0) || (map.count(newCountry) != 0) || (oldCoutry == newCountry))
		cout << "Incorrect rename, skipping" << endl;
	else {
		cout << "Country " << oldCoutry << " with capital " << map.find(oldCoutry)->second << " has been renamed to " << newCountry << endl;
		map.insert({ newCountry, map.find(oldCoutry)->second });
		map.erase(map.find(oldCoutry));
	}
}

void About(map<string, string>& map, string country) {
	if (map.count(country) != 0)
		cout << "Country " << country << " has capital " << map.find(country)->second << endl;
	else
		cout << "Country " << country << " don't exist" << endl;
}

void Dump(map<string, string>& map) {
	if (map.empty())
		cout << "There are no countries in the world" << endl;
	else
		for (auto& i : map)
			cout << i.first << '/' << i.second << ' ';
	cout << endl;
}

int main()
{
	int N;
	map<string,string> countries;
	string line, str1, str2, command;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		getline(cin, line);
		stringstream ss(line);
		ss >> command;
		if(ss.good())
			ss >> str1;
		if(ss.good())
			ss >> str2;
		if (command == "ABOUT") { 
			About(countries, str1);
		}
		if (command == "RENAME") { 
			Rename(countries, str1, str2);
		}
		if (command == "DUMP") {
			Dump(countries);
		}
		if (command == "CHANGE_CAPITAL") {
			Change_Capital(countries, str1, str2);
		}
	}

}
