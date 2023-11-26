#include <iostream>

void ut01() {

}

void mainfn(int argc, char **argv) {
    std::cout << "lol" << std::endl;
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

