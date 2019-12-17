#ifndef DATA_SOURCE_DECORATOR_HPP
#define DATA_SOURCE_DECORATOR_HPP

#include "data_source.hpp"
#include <iostream>

class DataSourceDecorator : public DataSource {

    protected:
        DataSource* wrapper;
    public:
        DataSourceDecorator(DataSource* source) : wrapper(source) {
            std::cout << "DataSourceDecorator" << std::endl;
            //wrapper = source;
        }

        void writeData(const char * data, int length) {
            wrapper->writeData(data, length);
        }

        void readData(char *data, int length) {
            return wrapper->readData(data, length);
        }

        ~DataSourceDecorator() {
            std::cout << "~DataSourceDecorator" << std::endl;
        }
};

#endif