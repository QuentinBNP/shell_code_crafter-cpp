#include <iostream>
#include <string>

bool is_valid_command(const std::string& input) {
  return false;
}

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    std::cout << "$ ";
    std::string input;
    std::cin >> input;
    if (is_valid_command) {
      std::cout << "{" << input << "}: command not found\n";
    }
  }
}
