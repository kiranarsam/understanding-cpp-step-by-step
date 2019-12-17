
#ifndef DATA_SOURCE_HPP
#define DATA_SOURCE_HPP

class DataSource {
    public:
        virtual void writeData(const char* data, int length) = 0;
        virtual void readData(char* data, int length) = 0;
        virtual ~DataSource() = 0;
};

DataSource::~DataSource() { }

#endif