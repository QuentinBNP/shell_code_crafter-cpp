#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    std::cout << "$ ";
    std::string input;
    // Read the whole line (including spaces) and handle EOF cleanly.
    if (!std::getline(std::cin, input)) {
      break; // EOF or error
    }
    if (input.empty()) {
      continue; // ignore empty lines
    }
    if (input == "exit") {
      // Use '\n' instead of std::endl to avoid unnecessary flushes.
      break;
    }
    std::cout << input << ": command not found\n";
  }
  return 0;
}
