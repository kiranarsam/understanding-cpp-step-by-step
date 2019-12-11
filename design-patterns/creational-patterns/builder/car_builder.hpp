// The concrete builder classes follow the builder interface and
// provide specific implementations of the building steps. Your
// program may have several variations of builders, each
// implemented differently.

#ifndef CAR_BUILDER_HPP
#define CAR_BUILDER_HPP

#include "car.hpp"
#include "builder.hpp"

class CarBuilder : public Builder {
    private:
        Car *car;
    public:
        CarBuilder() {
            car = nullptr;
            reset();
        }

        void reset() {
            car = new Car();
        }

        void setSeats() {

        }

        void setEngine() {

        }

        void setTripComputer() {

        }

        void setGPS() {

        }

        Car * getProduct() {
            Car *product = this->car;
            this->reset();
            return product;
        }

        ~CarBuilder() {
            if(car) {
                delete car;
            }
        }
};


#endif