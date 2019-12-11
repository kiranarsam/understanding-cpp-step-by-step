// Unlike other creational patterns, builder lets you construct
// unrelated products that don't follow a common interface.

#ifndef CAR_MANUAL_BUILDER_HPP
#define CAR_MANUAL_BUILDER_HPP

#include "manual.hpp"
#include "builder.hpp"

class CarManualBuilder : public Builder {
    private:
        Manual *manual;
    public:
        CarManualBuilder() {
            manual = nullptr;
            reset();
        }

        void reset() {
            manual = new Manual();
        }

        void setSeats() {

        }

        void setEngine() {

        }

        void setTripComputer() {

        }

        void setGPS() {

        }

        Manual* getProduct() {
            Manual* product = this->manual;
            this->reset();
            return product;
        }

        ~CarManualBuilder() {
            if(manual) {
                delete manual;
            }
        }
};

#endif