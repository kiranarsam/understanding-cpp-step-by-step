
#ifndef FILE_DATA_SOURCE_HPP
#define FILE_DATA_SOURCE_HPP

#include "data_source.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <ios>

class FileDataSource : public DataSource {
    private:
        std::string fileName;
        std::fstream *fileio;
    public:
        FileDataSource(std::string filename = "") : fileName(filename) {
            std::cout << "FileDataSource" << std::endl;

            if(filename.empty()) {
                std::cout << "Empty file name" << std::endl;
            }
            else
            {
                fileio = new std::fstream(filename, std::ios::in | std::ios::out | std::ios::app);
                if(fileio->is_open()) {
                    std::cout << "FileDataSource: File is opened successfully" << std::endl;
                }
                else
                {
                    std::cout << "FileDataSource: File is not opened properly" << std::endl;
                }
            }
        }

        void writeData(const char* data, int length) {
            fileio->write(data, length);
            fileio->write("\n", 1);
        }

        void readData(char *data, int length) {
            //std::ifstream file(fileName, std::ios::in);
            //fileio->read(line, );
            fileio->seekg(std::ios::beg);
            fileio->read(data, length);
        }

        ~FileDataSource() {
            if(fileio && fileio->is_open()) {
                fileio->close();
                std::cout << "FileDataSource: File is closed successfully " << std::endl;
            }
            std::cout << "~FileDataSource" << std::endl;
        }
};

#endif