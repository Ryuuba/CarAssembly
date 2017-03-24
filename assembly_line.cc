#include "assembly_line.h"

unsigned car_counter[NUM_OF_STAGES];

AssemblyLine::AssemblyLine(unsigned request) {
  this->request = request;
  for (unsigned i = 0; i < NUM_OF_STAGES; i++)
    car_counter[i] = 0;
}

void AssemblyLine::build_bodywork(unsigned i) {
  string s = "Building bodywork of car number: " + std::to_string(i) + '\n';
  cout << s;
  std::this_thread::sleep_for(seconds(2));
}

void AssemblyLine::stage0() {
  while (car_counter[0] < request) {
    build_bodywork(car_counter[0]);
    while (car_counter[0] > car_counter[1]);
    car_counter[0]++;
  }
}

void AssemblyLine::paint_bodywork(unsigned i) {
  string s = "Painting bodywork of car number: " + std::to_string(i) + '\n';
  cout << s;
  std::this_thread::sleep_for(seconds(2));
}

void AssemblyLine::stage1() {
  while (car_counter[1] < request) {
    while (!(car_counter[0] > car_counter[1]));
    paint_bodywork(car_counter[1]);
    while (car_counter[1] > car_counter[2]);
    car_counter[1]++;
  }
}

void AssemblyLine::install_mechanical_parts(unsigned i) {
  string s = "Installing mechanical parts of car number: " + std::to_string(i) + '\n';
  cout << s;
  std::this_thread::sleep_for(seconds(2));
}

void AssemblyLine::stage2() {
  while (car_counter[2] < request) {
    while (!(car_counter[1] > car_counter[2]));
    install_mechanical_parts(car_counter[2]);
    while (car_counter[2] > car_counter[3]);
    car_counter[2]++;
  }
}

void AssemblyLine::install_electronics(unsigned i) {
  string s = "Installing electronics of car number: " + std::to_string(i) + '\n';
  cout << s;
  std::this_thread::sleep_for(seconds(2));
}

void AssemblyLine::stage3() {
  while (car_counter[3] < request) {
    while (!(car_counter[2] > car_counter[3]));
    install_electronics(car_counter[3]);
    while (car_counter[3] > car_counter[4]);
    car_counter[3]++;
  }
}

void AssemblyLine::decorate(unsigned i) {
  string s = "Decorating car number: " + std::to_string(i) + '\n';
  cout << s;
  std::this_thread::sleep_for(seconds(2));
}

void AssemblyLine::stage4() {
  while (car_counter[4] < request) {
    while (!(car_counter[3] > car_counter[4]));
    decorate(car_counter[4]);
    car_counter[4]++;
  } 
}

void AssemblyLine::assemble_pip() {
  auto start = system_clock::now();
  thread s0(&AssemblyLine::stage0, ref((*this)));
  thread s1(&AssemblyLine::stage1, ref((*this)));
  thread s2(&AssemblyLine::stage2, ref((*this)));
  thread s3(&AssemblyLine::stage3, ref((*this)));
  thread s4(&AssemblyLine::stage4, ref((*this)));
  s0.join();
  s1.join();
  s2.join();
  s3.join();
  s4.join();
  auto elapsed = system_clock::now() - start;
  cout << "Concurrent time: " 
       << duration_cast<seconds>(elapsed).count()
       << " s " << endl;
}

void AssemblyLine::assemble_seq() {
  auto start = system_clock::now();
  for (unsigned i = 0; i < request; i++) {
    build_bodywork(i);
    paint_bodywork(i);
    install_mechanical_parts(i);
    install_electronics(i);
    decorate(i);
  }
  auto elapsed = system_clock::now() - start;
  cout << "Sequential time: " 
       << duration_cast<seconds>(elapsed).count()
       << " s " << endl;
}