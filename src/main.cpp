#include <iostream>
#include <string>
#include <unordered_set>


bool handle_command(std::string& input) {
  static const std::unordered_set<std::string> valid_commands = {"echo", "type", "exit"};
  size_t space_pos = input.find(' ');
  std::string command = input.substr(0, space_pos);

  if (command == "echo") {
    if (input.length() > 5) {
      std::cout << input.substr(5) << "\n";
    }
    return true;
  }

  if (command == "type") {
    std::string sub_command = (space_pos != std::string::npos) ? input.substr(space_pos+1) : "";
    if (valid_commands.count(sub_command) > 0) {
      std::cout << sub_command << " is a shell builtin\n";
    }
    else {
      std::cout << sub_command << ": not found\n";
    }
    return true;
  }

  return false;
}

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    std::cout << "$ ";
    std::string input;
    // Read the whole line (including spaces) and handle EOF cleanly.
    if (!std::getline(std::cin, input)) {
      break;
    }
    if (input.empty()) {
      continue; // ignore empty lines
    }
    if (input == "exit") {
      break;
    }
    if (handle_command(input)) {
      continue;
    }
    // Use '\n' instead of std::endl to avoid unnecessary flushes.
    std::cout << input << ": command not found\n";
  }
  return 0;
}
