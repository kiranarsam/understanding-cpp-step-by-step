// The director is only responsible for executing the building
// steps in a particular sequence. It's helpful when producing
// products according to a specific order or configuration.
// Strictly speaking, the director class is optional, since the
// client can control builders directly.

#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include "builder.hpp"

class Director {
    private:
        Builder *builderObj;
    public:
        void setBuilder(Builder *builder) {
            builderObj = builder;
        }

        void constructSportsCar(Builder *builder) {
            builder->reset();
            builder->setSeats();
            builder->setEngine();
            builder->setTripComputer();
            builder->setGPS();
        }

        void constructSUVCar(Builder *builder) {
            builder->reset();
            builder->setSeats();
            builder->setEngine();
            builder->setTripComputer();
            builder->setGPS();
        }

        ~Director() {
            if(builderObj) {
                delete builderObj;
            }
        }

};

#endif