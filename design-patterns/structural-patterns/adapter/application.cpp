#include "round-hole.hpp"
#include "round-peg.hpp"
#include "square-peg.hpp"
#include "square-peg-adapter.hpp"

#include <iostream>

class Application {

    public:
        Application() {
            std::cout << "Application" << std::endl;
        }

        void checkRoundPeg() {
            std::cout << "Application::checkRoundPeg()" << std::endl;
            RoundHole rh(5);
            RoundPeg rp(5);
            std::cout << rh.fits(&rp) << std::endl;
        }

        void checkSquarePeg() {
            std::cout << "Application::checkSquarePeg()" << std::endl;
            SquarePeg small_peg(5);
            SquarePeg large_peg(10);
            RoundHole rh(5);

            //std::cout << rh.fits(small_peg); // Won't compile in compatible type

            SquarePegAdapter small_spa(&small_peg);
            SquarePegAdapter large_spa(&large_peg);

            std::cout << rh.fits(&small_spa) << std::endl;
            std::cout << rh.fits(&large_spa) << std::endl;
        }

        ~Application() {
            std::cout << "~Application" << std::endl;
        }
};


int main() {

    Application app;
    app.checkRoundPeg();
    app.checkSquarePeg();

    return 0;
}
