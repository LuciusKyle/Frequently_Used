
#include <boost/chrono.hpp>
#include <boost/timer/timer.hpp>
#include <chrono>
#include <iostream>

using std::cout;
using std::endl;

void boost_chrono_ver(void) {
  using boost::chrono::duration_cast;
  using boost::chrono::milliseconds;
  using boost::chrono::system_clock;

  auto start = system_clock::now();

  start = system_clock::now();
  // do something.
  cout << "time: "
       << duration_cast<milliseconds>(system_clock::now() - start).count()
       << " milliseconds" << endl;
}

void stl_ver(void) {
  using std::chrono::duration_cast;
  using std::chrono::milliseconds;
  using std::chrono::system_clock;

  auto start = system_clock::now();

  start = system_clock::now();
  // do something.
  cout << "time: "
       << duration_cast<milliseconds>(system_clock::now() - start).count()
       << " milliseconds" << endl;
}

void boost_timer_ver() {
  boost::timer::cpu_timer timer;

  timer.start();
  // do something.
  cout << "time: " << timer.elapsed().wall << " nanoseconds" << endl;
}

int main(int argc, char *argv[]) {
  boost_chrono_ver();
  stl_ver();
  boost_timer_ver();
  return 0;
}