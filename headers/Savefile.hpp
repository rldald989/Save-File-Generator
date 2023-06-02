#pragma once

#include <string>
#include <vector>
#include <fstream>

namespace files
{
    struct FILE_DATA
    {
        std::string name;
        std::string data;
    };

    FILE_DATA CreateData(std::string name, std::string data)
    {
        FILE_DATA fd = {name, data};
        return fd;
    }

    struct FILE
    {
        std::string name;
        std::vector<FILE_DATA> fileData;

        void AddData(std::string name, std::string data)
        {
            fileData.push_back(CreateData(name, data));
        }
    };

    

    class Savefile
    {

    public:
        

        Savefile(std::vector<FILE*> saveFiles)
        {
            m_saveFiles = saveFiles;
        }
        ~Savefile()
        {

        }

        void WriteToFile()
        {
            for(size_t i = 0; i < m_saveFiles.size(); i++)
            {
                std::ofstream outfile;
                outfile.open(m_saveFiles[i]->name);
                for(size_t j = 0; j < m_saveFiles[i]->fileData.size(); j++)
                {
                    outfile << m_saveFiles[i]->fileData[j].name <<
                    ": " << m_saveFiles[i]->fileData[j].data << std::endl; 
                }
                outfile.close();
            }
        }

    private:
        std::vector<FILE*> m_saveFiles;
    };
    
}