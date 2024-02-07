// Deconvolute.cpp : Defines the entry point for the console application.
//
//#include <boost/iostreams/filter/gzip.hpp>
//#include <boost/iostreams/filtering_stream.hpp>
//#include <boost/iostreams/filter/zlib.hpp>
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

std::ifstream input1(argv[1]);
	if (!input1)
	{
		std::perror(argv[1]);
		std::cerr << "Can not open the 'Read 1 file'\n";
		return EXIT_FAILURE;
	}
	input1.close();

	std::ifstream input2(argv[2]);
	if (!input2)
	{
		std::perror(argv[2]);
		std::cerr << "Can not open the 'Read 2 file'\n";
		return EXIT_FAILURE;
	}
	input2.close();

	std::ifstream input3(argv[3]);
	if (!input3)
	{
		std::perror(argv[3]);
		std::cerr << "Can not open the 'primer file'\n";
		return EXIT_FAILURE;
	}
	input3.close();

	std::ifstream input4(argv[4]);
	if (!input4)
	{
		std::perror(argv[4]);
		std::cerr << "Can not open the 'index file'\n";
		return EXIT_FAILURE;
	}
	input4.close();
  
	for (int index = 1; index < argc; index++)
	{
		arguments.push_back(argv[index]);
	}

	Engine eng(arguments);
	eng.AnalyseData();

	return 0;
}
