//
// Created by steed on 2022/1/26.
//
#include <vector>
#include "iostream"
#include "string"

using namespace std;

int main() {
    string s = "We are happy.";
    string news;
    for (int i = 0; i < s.size(); ++i) {
//        cout<<item<<endl;
        if (s[i] == ' ') {
            news.append("%20");
            continue;
        }
        news.push_back(s[i]);
    }
    cout << news << endl;

    return 0;

}