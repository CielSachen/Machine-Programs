#include <gtest/gtest.h>

#include <cstdio>

/**
 * Verifies if `freopen()` has successfully reopened a file.
 * @param reopened_file The file that `freopen()` reopened.
 */
void verify_file_reopening(FILE* reopened_file) {
  if (reopened_file == NULL) {
    std::cerr << "The file that contains the mocked user inputs could not be opened." << std::endl;

    exit(EXIT_FAILURE);
  }
}
