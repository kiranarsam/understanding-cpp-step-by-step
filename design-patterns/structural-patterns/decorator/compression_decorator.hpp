#ifndef COMPRESSION_DECORATOR_HPP
#define COMPRESSION_DECORATOR_HPP

#include "data_source_decorator.hpp"

class CompressionDecorator : public DataSourceDecorator {
    public:
        CompressionDecorator(DataSource* source) : DataSourceDecorator(source) {
            std::cout << "CompressionDecorator" << std::endl;
        }

        void writeData(const char* data, int length) {
            // 1. Compress passed data.
            // 2. Pass compressed data to the wrappee's writeData method.
            wrapper->writeData(data, length);
        }

        void readData(char* data, int length) {
            // 1. Get data from the wrappee's readData method.
            // 2. Try to decompress it if it's compressed.
            // 3. Return the result.
            wrapper->readData(data, length);
        }

        ~CompressionDecorator() {
            std::cout << "~CompressionDecorator" << std::endl;
        }
};

#endif