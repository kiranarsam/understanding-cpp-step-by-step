// The builder interface specifies methods for creating the
// different parts of the product objects.

#ifndef BUILDER_HPP
#define BUILDER_HPP

class Builder {
    public:
        virtual void reset() = 0;
        virtual void setSeats() = 0;
        virtual void setEngine() = 0;
        virtual void setTripComputer() = 0;
        virtual void setGPS() = 0;
        virtual ~Builder() { }
};

#endif