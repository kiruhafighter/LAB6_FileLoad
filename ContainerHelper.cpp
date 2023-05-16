#include "ContainerHelper.h"

template <typename T>
ContainerHelper<T>::ContainerHelper(const std::string& filename) : filename(filename) {
    loadFromFile();
}

template <typename T>
ContainerHelper<T>::~ContainerHelper() {
    saveToFile();
}

template <typename T>
void ContainerHelper<T>::push_back(const T& value) {
    container.push_back(value);
}

template <typename T>
void ContainerHelper<T>::pop_back() {
    if (container.empty()) {
        std::cout << "Container is empty!" << std::endl;
        return;
    }

    container.pop_back();
}

template <typename T>
size_t ContainerHelper<T>::size() const {
    return container.size();
}

template <typename T>
T& ContainerHelper<T>::operator[](size_t index) {
    if (index >= container.size()) {
        std::cout << "Index out of range!" << std::endl;
        throw std::out_of_range("Index out of range!");
    }

    return container[index];
}

template <typename T>
typename std::vector<T>::iterator ContainerHelper<T>::begin() {
    return container.begin();
}

template <typename T>
typename std::vector<T>::iterator ContainerHelper<T>::end() {
    return container.end();
}

template <typename T>
void ContainerHelper<T>::loadFromFile() {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        T value;
        while (inputFile >> value) {
            container.push_back(value);
        }
        inputFile.close();
    }
}

template <typename T>
void ContainerHelper<T>::saveToFile() {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto& value : container) {
            outputFile << value << std::endl;
        }
        outputFile.close();
    }
}

// Explicit instantiation of the template class for string type
template class ContainerHelper<std::string>;
