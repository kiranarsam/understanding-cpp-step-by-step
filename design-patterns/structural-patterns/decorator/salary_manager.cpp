// Option 2. Client code that uses an external data source.
// SalaryManager objects neither know nor care about data
// storage specifics. They work with a pre-configured data
// source received from the app configurator.

#include "data_source.hpp"
#include "file_data_source.hpp"
#include "compression_decorator.hpp"
#include "encryption_decorator.hpp"
#include <cstring>

class SalaryManager
{
    private:
        DataSource *source;
    public:
        SalaryManager(DataSource* src);
        ~SalaryManager();

        void load() {
            char data[50];
            source->readData(data, 50);

            std::cout << "SalaryManager: " << data << std::endl;
        }

        void save() {
            const char* data = "Save salary Records"; 
            source->writeData(data, strlen(data));
        }
};

SalaryManager::SalaryManager(DataSource* src)
{
    source = src;
    std::cout << "SalaryManager" << std::endl;
}

SalaryManager::~SalaryManager()
{
    std::cout << "~SalaryManager" << std::endl;
}

class ApplicationConfigurator {
    private:
        bool enabledEncryption;
        bool enabledCompression;
        SalaryManager* logger;
        DataSource* source;
        DataSource* c_source;
        DataSource* e_source;
    public:
        ApplicationConfigurator() {
            std::cout << "ApplicationConfigurator" << std::endl;
            enabledEncryption = false; // Read this data from the file config
            enabledCompression = true;
        }

        void configurationExample() {
            source = new FileDataSource("salary.dat");
            if (enabledEncryption) {
                e_source = new EncryptionDecorator(source);
            }

            if (enabledCompression) {
                c_source = new CompressionDecorator(source);
            }
            logger = new SalaryManager(source);
            logger->save();
            logger->load();
        }
        ~ApplicationConfigurator() {
            if(logger) {
                delete logger;
            }
            if(enabledCompression && c_source) {
                delete c_source;
            }
            if(enabledEncryption && e_source) {
                delete e_source;
            }
            if(source) {
                delete source;
            }
            std::cout << "~ApplicationConfigurator" << std::endl;
        }
};

int main() {
    ApplicationConfigurator* app;
    app = new ApplicationConfigurator();
    app->configurationExample();

    delete app;
    return 0;
}
