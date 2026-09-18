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
      break;
    }
    if (input.substr(0, 4) == "echo") {
      if (input.length() > 5) {
        std::cout << input.substr(5) << "\n";
      }
      continue;
    }
    // Use '\n' instead of std::endl to avoid unnecessary flushes.
    std::cout << input << ": command not found\n";
  }
  return 0;
}
