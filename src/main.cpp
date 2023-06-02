#include "../headers/Savefile.hpp"
#include <iostream>

int main()
{
    files::FILE* fileOne = new files::FILE;
    fileOne->name = "CharacterData";
    fileOne->AddData("Position", "1, 2");
    fileOne->AddData("Character", "yellow");

    std::vector<files::FILE*> s_files;
    s_files.push_back(fileOne);

    files::Savefile saveFile(s_files);

    saveFile.WriteToFile();
}