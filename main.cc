#include <iostream>
#include <cstdlib>
#include "assembly_line.h"

int main(int argc, char* argv[]) {
    unsigned request = std::atoi(argv[1]);
    AssemblyLine assembly_line(request);
    assembly_line.assemble_pip();
    assembly_line.assemble_seq();
    return 0;
} 