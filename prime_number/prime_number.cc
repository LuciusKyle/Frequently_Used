#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

int main() {
  for (int n = 0; n < 10000; ++n) {
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
        cout << n << " isn't a prime" << endl;
        return 1;
      }
    }
    cout << n << " is a prime" << endl;
  }
  return 0;
}