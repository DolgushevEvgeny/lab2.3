// std_map.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include "MapProcessor.h"
#include "iostream"

using namespace std;

int main(int argc, char* argv[])
{
	map<string, int> Map;
	vector<string> Strings;
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(Strings));
	for (vector<string>::iterator position = Strings.begin(); position != Strings.end(); ++position)
	{
		ProcessingMap(Map, *position);
	}
	map<string, int>::iterator position;
	for (position = Map.begin(); position != Map.end(); ++position)
	{
		cout << position->first << "->";
		cout << position->second << "\n";
	}
	system("pause");
	return 0;
}

