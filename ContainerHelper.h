#pragma once
#include <iostream>
#include <vector>
#include <fstream>

template <typename T>
class ContainerHelper {
private:
    std::vector<T> container;
    std::string filename;

public:
    ContainerHelper(const std::string& filename);

    ~ContainerHelper();

    void push_back(const T& value);

    void pop_back();

    size_t size() const;

    T& operator[](size_t index);

    typename std::vector<T>::iterator begin();

    typename std::vector<T>::iterator end();

private:
    void loadFromFile();

    void saveToFile();
};