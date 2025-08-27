#include <deque>
#include <iostream>
#include <fstream>

void MakeTrain(){
    std::ifstream src("input3.txt");
    std::ofstream rslt("result.txt");
    std::deque<int> train;
    std::string action;
    int wagon;

    while (src >> action >> wagon){
        if (action == "+left"){
            train.push_front(wagon);
        }else if(action == "+right"){
            train.push_back(wagon);
        }else if(action =="-left"){
            if (wagon >= int(train.size())){
                train.clear();
            }else{
                train.erase(train.begin(), train.begin() + wagon);
            }
        }else if(action == "-right"){
            if (wagon >= int(train.size())){
                train.clear();
            }else{
                train.erase(train.end() - wagon, train.end());
            }
        }   
    }
    for (size_t i = 0; i < train.size(); ++i){
        rslt << train[i] << " ";
    }
    src.close();
    rslt.close();
}

int main(){
    MakeTrain();
}