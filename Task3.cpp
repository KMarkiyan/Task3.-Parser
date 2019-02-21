// Task3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <experimental/filesystem>
#include <string>
#include <cstring>
#include <iostream>
#include <chrono>w
#include <thread>

std::string get_extension(std::string path);

void FindFiles(const std::experimental::filesystem::path &path)
{
	if (!exists(path)) std::cout << "Bad!";
	std::experimental::filesystem::directory_iterator end_iter;
	
	for (std::experimental::filesystem::directory_iterator iter(path); iter != end_iter; ++iter)
	{
		//std::cout << iter->path() << std::endl;
		
		if (is_directory(iter->status()))
		{
			FindFiles(iter->path());
		}
		else
		{
			std::string extension = get_extension(iter->path().generic_string());
			if (extension == "h" || extension == "hpp" || extension == "c" || extension == "cpp")
				std::cout << extension << std::endl;
		}
	}
}

std::string get_extension(std::string path)
{
	size_t pos = path.rfind('.');
	return path.substr(pos+1);
}

int main()
{
	FindFiles("C:/Users/Lord/Documents/untitled");
	system("pause");
    return 0;
}

