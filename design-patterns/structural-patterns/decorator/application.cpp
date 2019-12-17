#include "file_data_source.hpp"
#include "compression_decorator.hpp"
#include "encryption_decorator.hpp"
#include <cstring>

class Application {
    private:
        DataSource *source;
        DataSource *c_source;
        DataSource *e_source;
    public:
        Application() {
            std::cout << "Application" << std::endl;
        }
        void usageExample() {
            
            // The target file has been written with plain data.
            source = new FileDataSource("somefile.dat");
            const char *data = "Select * from table.";
            source->writeData(data, strlen(data));

            // The target file has been written with compressed data
            c_source = new CompressionDecorator(source);
            c_source->writeData(data, strlen(data));

            // The source variable now contains this:
            // Encryption > Compression > FileDataSource
            e_source = new EncryptionDecorator(source);
            //The file has been written with compressed and encrypted data.
            e_source->writeData(data, strlen(data));

            char line[100];
            e_source->readData(line, 100);
            std::cout << line << std::endl;
        }
        ~Application() {
            if(e_source) {
                delete e_source;
            }
            if(c_source) {
                delete c_source;
            }
            if(source) {
                delete source;
            }
            std::cout << "~Application" << std::endl;
        }
};


int main() {
    Application* app = new Application();
    app->usageExample();

    delete app;

    return 0;
}