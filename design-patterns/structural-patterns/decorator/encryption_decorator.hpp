#ifndef ENCRYPTION_DECORATOR_HPP
#define ENCRYPTION_DECORATOR_HPP

#include "data_source_decorator.hpp"

class EncryptionDecorator : public DataSourceDecorator {
    public:
        EncryptionDecorator(DataSource* source) : DataSourceDecorator(source) {
            std::cout << "EncryptionDecorator" << std::endl;
        }

        void writeData(const char* data, int length) {
            // 1. Encrypt passed data.
            // 2. Pass encrypted data to the wrappee's writeData method.
            wrapper->writeData(data, length);
        }

        void readData(char *data, int length) {
            // 1. Get data from the wrappee's readData method.
            // 2. Try to decrypt it if it's encrypted.
            // 3. Return the result.
            wrapper->readData(data, length);
        }

        ~EncryptionDecorator() {
            std::cout << "~EncryptionDecorator" << std::endl;
        }
};

#endif