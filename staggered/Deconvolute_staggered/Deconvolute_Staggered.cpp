// Deconvolute_Staggered.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "Engine.h"

int main(int argc, char* argv[])
{
	std::vector<std::string> arguments;

	if (argc != 8)
	{
		std::cout << "Wrong parameter number\n";

		for (int index = 0; index < argc; index++)
		{
			std::cout << argv[index] << "\n";
		}

		std::cout << "Wrong number of arguments, usage:\n 'read one filename with path',\n 'read two filename with path',\n 'path to primer file',\n 'path to index file'\n 'path to folder to save data in' 'Minimum amplicon length', 'Maximum amplicon length'\n";

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

