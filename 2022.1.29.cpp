//
// Created by steed on 2022/1/27.
//

#include <unordered_map>
#include <iostream>

using namespace std;

int main(){
    int tmp[5] = {0};
    string in = "loonbalxballpoon";
    for (const auto &str: in) {
        switch (str) {
            case 'b':
                tmp[0]++;
                break;
            case 'a':
                tmp[1]++;
                break;
            case 'l':
                tmp[2]++;
                break;
            case 'o':
                tmp[3]++;
                break;
            case 'n':
                tmp[4]++;
                break;
            default:
                break;
        }
    }
    tmp[2]/=2;
    tmp[3]/=2;
    int min = 99;
    for (const auto &num: tmp) {
        if (num < min){
            min = num;
        }
    }
    cout<<min<<endl;

//    unordered_map<int, int> map;
//    map[3]++;
//    map[3]++;
//    cout << map.count(3);
    return 0;
}
