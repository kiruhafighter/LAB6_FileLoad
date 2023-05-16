#include <iostream>
#include "ContainerHelper.h"

int main() {
    // Create an instance of ContainerHelper for storing strings in a file
    ContainerHelper<std::string> stringContainer("C:\\Users\\Kyrylo\\Desktop\\strings.txt");

    // Add strings to the container
    stringContainer.push_back("Hello");
    stringContainer.push_back("World");
    stringContainer.push_back("!");

    // Print the strings in the container
    std::cout << "Strings in the container:\n";
    for (const auto& str : stringContainer) {
        std::cout << str << "\n";
    }

    // Access a string by index
    size_t index = 1;
    if (index < stringContainer.size()) {
        std::cout << "String at index " << index << ": " << stringContainer[index] << "\n";
    }

    // Remove a string from the container
    stringContainer.pop_back();

    // Print the updated container
    std::cout << "Updated strings in the container:\n";
    for (const auto& str : stringContainer) {
        std::cout << str << "\n";
    }

    return 0;
}
