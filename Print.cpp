#include <iostream>


template<typename T>
void Print(const T& container, const std::string divider){
    for (const auto& x: container){
        std::cout << x << divider;
    }
    std::cout << "\n";
}

int main(){
    std::vector<char> data;
    data.push_back('a');
    data.push_back('b');
    data.push_back('c');
    data.push_back('d');
    std::string divider = "";

    Print(data, divider);
}