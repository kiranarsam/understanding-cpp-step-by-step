// The Database class defines the `getInstance` method that lets
// clients access the same instance of a database connection
// throughout the program.

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <iostream>

class Database {
    private:
        static Database* _instance;
        Database() {
            std::cout << "Database " << std::endl;
        }
    public:
        static Database* getInstance() {
            if(_instance == nullptr) {
                _instance = new Database();
            }

            return _instance;
        }

        void query(std::string sql) {
            std::cout << "Database::query() = " << sql << std::endl;
        }

        void destroy() {
            if(_instance) {
                delete _instance;
                _instance = nullptr;
            }
        }

        virtual ~Database() {
            std::cout << "~Database " << std::endl;
        }
};

Database* Database::_instance = nullptr;

#endif