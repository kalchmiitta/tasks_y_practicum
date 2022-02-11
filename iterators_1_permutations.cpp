#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

template<typename Itr>
vector<string> GetPermutations (const Itr &begin, const Itr &end) {
    vector<string> result;
    sort(begin, end);
    reverse(begin, end);
    do {
        int stop = (end - begin);
        string current;
        Itr curr_itr = begin;
        while (stop --) {
            current += to_string(*curr_itr) + " "s;
            ++ curr_itr;
        }
        if(!stop){
            current = current.substr(0, current.size()-1);
        }
        result.push_back(current);
        
    } while (prev_permutation(begin, begin + (end - begin)));
    return result;
}

// функция, записывающая элементы диапазона в строку
template<typename It>
string PrintRangeToString (It range_begin, It range_end) {
    ostringstream out;
    for (auto it = range_begin; it != range_end; ++ it) {
        out << *it << " "s;
    }
    out << endl;
    return out.str();
}

int main () {
    vector<int> permutation(3);
    iota(permutation.begin(), permutation.end(), 1);
    auto result = GetPermutations(permutation.begin(), permutation.end());
    for (const auto &s: result) {
        cout << s;
    }
    return 0;
}
