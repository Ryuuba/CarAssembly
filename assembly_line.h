#include <chrono>
#include <thread>
#include <mutex>
#include <iostream>
#include <string>
#include <sstream>

#define NUM_OF_STAGES 5

using std::thread;
using std::mutex;
using std::chrono::system_clock;
using std::chrono::microseconds;
using std::chrono::seconds;
using std::chrono::duration_cast;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ref;

class AssemblyLine {
private:
    unsigned request;
private:
    void build_bodywork(unsigned);
    void paint_bodywork(unsigned);
    void install_mechanical_parts(unsigned);
    void install_electronics(unsigned);
    void decorate(unsigned);
    void stage0();
    void stage1();
    void stage2();
    void stage3();
    void stage4();
public:
    AssemblyLine(unsigned);
    void assemble_pip();
    void assemble_seq();
};