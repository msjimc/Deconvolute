// Deconvolute.cpp : Defines the entry point for the console application.
//
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <fstream>
#include <vector>
#include "dirent.h"
#include <string>

#include "Engine.h"

int main(int argc, char *argv[])
{
	vector<string> arguments;

	if (argc != 8)
	{
		cout << "Wrong number of arguments, usage:\nRead one filename with path,\nRead two filename with path,\nPrimer file with path,\nIndex file with path\nPath to folder to save data in\nMinimum PCR length\nMaximum PCR length\n";

		for (int index = 0; index < argc; index++)
		{
			cout << argv[index] << "\n";
		}

		return -1;
	}

	for (int index = 1; index < argc; index++)
	{
		arguments.push_back(argv[index]);
	}

	Engine eng(arguments);
	eng.AnalyseData();

	return 0;
}

