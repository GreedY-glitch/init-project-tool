#include "files_init.hpp"
#include <cstring>



int MakeFileInheriance::MakeCMakeLists_txt(PATH_DIRECTORY path_to_dir)
/*
    This function implements a fill cmakelists for default project
*/
{
    using INPUT = std::ios;

    // Take a path to create a file named as CMakeLists.txt
    PATH_PROJECT project_directory = "${path_to_dir}/src/CMakeLists.txt";
    
    system(strcat("touch ", project_directory.c_str()));
    FILE_in write_cmake_lists_txt(project_directory,
                                  INPUT::in);


    if (write_cmake_lists_txt.is_open()) 
    {
        unsigned int i = 0;
        while (i < cmake_file_properties->size())
        {
            write_cmake_lists_txt << cmake_file_properties[i];
            ++i;
        } 

        write_cmake_lists_txt.close();
    } else {
        throw CantOpenFileException();
    }
    return 0;
}

int MakeFileInheriance::MakeBuildFolder(PATH_DIRECTORY path_to_dir)
{
    system("mkdir ${path_to_dir}/build");
    return 0;
}

int MakeFileInheriance::MakeSrcFolder(PATH_DIRECTORY path_to_dir)
{
    system("mkdir ${path_to_dir}/src");
    return 0;
}

int MakeFileInheriance::MakeMain_cpp(PATH_DIRECTORY dir)
{
    return 0;
}


