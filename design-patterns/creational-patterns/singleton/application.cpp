
#include "database.hpp"

class Application {
    public:
        Application() {
            std::cout << "Application " << std::endl;
        }

        Database* getDatabase() {
            return Database::getInstance();
        } 

        ~Application() {
            std::cout << "~Application " << std::endl;
        }
};

int main() {

    Application app;
    app.getDatabase()->query("Create table;");
    app.getDatabase()->query("Select table;");

    {
        Application app1;

        app1.getDatabase()->query("Create table;");
        app1.getDatabase()->query("Drop table;");
    }

    app.getDatabase()->query("Update table;");
    app.getDatabase()->query("Drop table;");

    app.getDatabase()->destroy();

    app.getDatabase()->query("Select table;");

    app.getDatabase()->destroy();

    return 0;
}