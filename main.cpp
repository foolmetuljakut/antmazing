#include <iostream>
#include "src/Application.hpp"

void ut01() {

}

void mainfn(int argc, char **argv) {
    antmazing::Application app("Antmazing!", 1280, 600, 1, 1, 1, 1);
    app.run();
}

int main(int argc, char **argv) {
#ifdef MAIN
    mainfn(argc, argv);
#endif // MAIN
#ifdef ANTMAZING_UT1
    ut01();
#endif // ANTMAZING_UT01
    return 0;
}

