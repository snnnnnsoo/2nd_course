#include <deque>
#include <iostream>
#include <fstream>
#include <sstream>

int main(){
    std::ifstream list("input2.txt");
    std::ofstream output("output.txt");
    std::deque<std::string> tests;
    int N, M;
    int string_number = 0;

    std::string line;
    while(std::getline(list, line)){
        if(string_number == 0){
            std::stringstream ss(line);
            ss >> N;
        }else if (string_number > 0 && string_number < N + 1){
            std::istringstream iss(line);
            std::string surname, placement;
            iss >> surname >> placement;
            if (placement == "top"){
                tests.push_front(surname);
            }else{
                tests.push_back(surname);
            }
        }else if(string_number == N + 1){
            std::stringstream ss(line);
            ss >> M;
        }else if(string_number > N + 1){
            std::stringstream ss(line);
                int number;
                ss >> number;
                
                output << tests[number - 1];
                if (string_number < N + M + 1){
                    output << std::endl;
                }
            }
        ++string_number;
    }
    list.close();
    output.close();
}