#pragma once


#ifndef INSERT
#define INSERT


#include <iostream>
#include <fstream>
#include <string>


class Test_exception : public std::exception 
{
public:
	char* what() {
		return "Test exception\n";
	}
};


class CantOpenFileException : public std::exception 
{
public:
	char* what() {
		return "Troubles to open a file.\n" \
				"Please check your project directory\n";
	}
};


class MakeFileInheriance 
{
	using FILE_in        = std::ofstream;
	using FILE_out       = std::ifstream;
	using PATH_PROJECT   = std::string;
	using PATH_DIRECTORY = std::string;


	FILE_out out_of_file;
	FILE_in input_file;
	PATH_PROJECT path;

	constexpr static int lines_count = 3; 
	std::string cmake_file_properties[lines_count] = {
		"cmake_minimum_required(VERSION 2.8)\n",
		"project(hello_world)\n",
		"add_executable(main main.cpp)" };
	
	
	std::string default_program_main_cxx = { 
	"#include <iostream" \
	"\n\n\n" \
	"int main()" \ 
	"{" \
	"	std::cout << \"Hello, world!\n\";"\
	"	return EXIT_SUCCESS;"\
	"}"}; 



public:
	MakeFileInheriance(PATH_PROJECT path) : path(path) {} 
	~MakeFileInheriance() = default;

	/* The key methods for make a project struct */
	int MakeCMakeLists_txt	(PATH_DIRECTORY);
	int MakeBuildFolder	 	(PATH_DIRECTORY);
	int MakeSrcFolder		(PATH_DIRECTORY);
	int MakeMain_cpp		(PATH_DIRECTORY); 
};


#endif // INSERT
