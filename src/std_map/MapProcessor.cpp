#include "stdafx.h"
#include "MapProcessor.h"
#include <iostream>

using namespace std;

void ProcessingMap(map<string,int> &Map, string key)
{
	map<string, int>::iterator position = Map.find(key);
	if (position != Map.end())
	{
		position->second += 1;
	}
	else
	{
		Map[key];
		position = Map.find(key);
		position->second += 1;
	}
}

