
#include <assert.h>
#include <filesystem>

void some_function(const std::filesystem::path &p) {
  // do something
}

void directory_traversal(const std::filesystem::path &p) {
  using namespace std::filesystem;
  assert(is_directory(p));
  for (auto &directory : directory_iterator(p)) {
    if (is_directory(directory.path())) {
      directory_traversal(directory.path());
      //
    } else if (is_regular_file(directory.path())) {
      // some_function(p);
    } else {
      // something is neither directory nor regular file.
      //
    }
  }
}
