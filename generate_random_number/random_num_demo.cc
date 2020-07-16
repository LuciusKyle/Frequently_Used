
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <random>

void stl_random(void) {
  std::random_device random_device;
  std::default_random_engine random_engine(random_device());

  std::normal_distribution<double> Gaussian_distribution(0, 1);
  double random_double_number = Gaussian_distribution(random_engine);

  std::uniform_int_distribution<int> uniform_distribution(-1024, 1024);
  const int random_int_number = uniform_distribution(random_engine);

  std::uniform_real_distribution<double> uniform_floating_point_distribution(-1.0, 1.0);
  random_double_number = uniform_floating_point_distribution(random_engine);
}

void boost_random(void) {
  boost::mt19937_64 random_engine(time(nullptr));

  boost::random::normal_distribution<double> Gaussian_distribution(0, 1);
  Gaussian_distribution(random_engine);

  boost::random::uniform_int_distribution<int> uniform_distribution(-1024, 1024);
  uniform_distribution(random_engine);

  boost::random::uniform_real_distribution<double>
      uniform_floating_point_distribution(-100.0, 100.0);
  uniform_floating_point_distribution(random_engine);
}

void generate_password() {
  const std::string chars(
      R"(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]}\|;:'",<.>/?)");
  // const std::string chars(
  //	"abcdefghijklmnopqrstuvwxyz"
  //	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  //	"1234567890"
  //	"!@#$%^&*()"
  //	"`~-_=+[{]}\\|;:'\",<.>/?");
  boost::random::random_device rng;
  boost::random::uniform_int_distribution<> index_dist(0, chars.size() - 1);
  for (int i = 0; i < 8; ++i) {
    std::cout << chars[index_dist(rng)];
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  stl_random();
  boost_random();
  generate_password();
  return 0;
}