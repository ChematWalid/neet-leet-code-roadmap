
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

namespace prnt {

    template <typename T>
    void printElement(const T& value) {
        if constexpr (std::is_same_v<T, std::string>) {
            std::cout << '"' << value << '"';
        } else {
            std::cout << value;
        }
    }

    // Print vector<T>
    template <typename T>
    void printVectorInline(const std::vector<T>& v) {
        std::cout << '[';

        for (size_t i = 0; i < v.size(); ++i) {
            if (i > 0) std::cout << ',';
            printElement(v[i]);
        }

        std::cout << ']';
    }

    template <typename T>
    void printVector(const std::vector<T>& v) {
        printVectorInline(v);
        std::cout << '\n';
    }

    // Print vector<vector<T>>
    template <typename T>
    void printVector(const std::vector<std::vector<T>>& v) {
        std::cout << '[';

        for (size_t i = 0; i < v.size(); ++i) {
            if (i > 0) std::cout << ',';
            printVectorInline(v[i]);
        }

        std::cout << "]\n";
    }

}