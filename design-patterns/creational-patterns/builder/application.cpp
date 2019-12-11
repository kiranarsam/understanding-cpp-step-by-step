// The client code creates a builder object, passes it to the
// director and then initiates the construction process. The end
// result is retrieved from the builder object.

#include "director.hpp"
#include "car_builder.hpp"
#include "car.hpp"
#include "manual.hpp"
#include "car_manual_builder.hpp"

class Application {
    private:
        Director *director;
    public:
        Application() {
            director = nullptr;
        }

        void makeCar() {
            director = new Director();

            CarBuilder *carBuilder = new CarBuilder();
            director->constructSportsCar(carBuilder);
            Car *car = carBuilder->getProduct();

            CarManualBuilder *carManualBuilder = new CarManualBuilder();
            director->constructSportsCar(carManualBuilder);
            Manual *Manual = carManualBuilder->getProduct();
        }

        ~Application() {
            delete director;
        }
};

// Test the code
int main() {
    Application *app = new Application();
    app->makeCar();

    return 0;
}