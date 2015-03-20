// std_map_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iterator>
#include "../std_map/MapProcessor.h"

using namespace std;

bool isMapsEqual(map<string, int> first, map<string, int> second)
{
	return first == second;
}

BOOST_AUTO_TEST_CASE(EmptyMapProducesEmptyMap)
{
	map<string, int> emptyMap;
	vector<string> Strings;
	auto copy = emptyMap;
	for (vector<string>::iterator position = Strings.begin(); position != Strings.end(); ++position)
	{
		ProcessingMap(emptyMap, *position);
	}
	BOOST_CHECK(isMapsEqual(emptyMap, copy));
}

BOOST_AUTO_TEST_CASE(MapWithOneElementStringProducesMapWithOneElementString)
{
	map<string, int> Map;
	vector<string> Strings = {"size"};
	for (vector<string>::iterator position = Strings.begin(); position != Strings.end(); ++position)
	{
		ProcessingMap(Map, *position);
	}
	map<string, int> copy;
	copy["size"] = 1;
	BOOST_CHECK(isMapsEqual(Map, copy));
}

BOOST_AUTO_TEST_CASE(MapWithEqualElementsStringsProducesMapWithOneElementString)
{
	map<string, int> Map;
	vector<string> Strings = { "size", "size", "size", "size" };
	for (vector<string>::iterator position = Strings.begin(); position != Strings.end(); ++position)
	{
		ProcessingMap(Map, *position);
	}
	map<string, int> copy;
	copy["size"] = 4;
	BOOST_CHECK(isMapsEqual(Map, copy));
}

BOOST_AUTO_TEST_CASE(MapWithDifferentElementsStringsProducesMapWithDifferentElementsStrings)
{
	map<string, int> Map;
	vector<string> Strings = { "size", "string", "hello", "object", "hello" };
	for (vector<string>::iterator position = Strings.begin(); position != Strings.end(); ++position)
	{
		ProcessingMap(Map, *position);
	}
	map<string, int> copy;
	copy["size"] = 1; copy["string"] = 1; copy["hello"] = 2; copy["object"] = 1;
	BOOST_CHECK(isMapsEqual(Map, copy));
}

BOOST_AUTO_TEST_CASE(MapWithDifferentElementsProducesMapWithDifferentElements)
{
	map<string, int> Map;
	vector<string> Strings = { "size", "123" , "hello", "123", "object", "size" };
	for (vector<string>::iterator position = Strings.begin(); position != Strings.end(); ++position)
	{
		ProcessingMap(Map, *position);
	}
	map<string, int> copy;
	copy["size"] = 2; copy["123"] = 2; copy["hello"] = 1; copy["object"] = 1;
	BOOST_CHECK(isMapsEqual(Map, copy));
}
