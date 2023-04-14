#include <iostream>
#include <string>
#include <limits.h>
#include <unistd.h>

int main(int argc, char** argv) {
    std::cout << "Hello, world!\n";
    std::cout << argv[0] <<"\n";

    std::string buf(PATH_MAX, '\0');

    int n = readlink("/proc/self/exe", &buf.front(), buf.size());

    std::cout << "n = " << n <<"\n";
    std::cout << "path = " << buf.c_str() <<"\n";

    return 0;
}
