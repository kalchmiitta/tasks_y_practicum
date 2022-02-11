#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// set<int>::const_iterator — тип итераторов для константного множества целых чисел

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
    auto search_itr = numbers.lower_bound(border);
    if(search_itr == numbers.end() && !numbers.empty()){
        return prev(numbers.end());
    }
    if(search_itr == numbers.end()){
        return numbers.end();
    }
    if (*search_itr == border) {
        return search_itr;
    }
    if(search_itr == numbers.begin()){
        return search_itr;
    }
    if(*search_itr - border < border - *prev(search_itr) ){
        return search_itr;
    }else{
        return prev(search_itr);
    }
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    
    
    auto it_left = lower_bound(range_begin, range_end, string(1, prefix));
    auto next_prefix = static_cast<char>(prefix + 1);
    auto it_right = lower_bound(range_begin, range_end, string(1, next_prefix));
    return {it_left, it_right};
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, string prefix) {
    auto it_left = lower_bound(range_begin, range_end, prefix);
    string new_prefix = prefix;
    ++new_prefix[new_prefix.size() - 1];
    auto it_right = lower_bound(range_begin, range_end, new_prefix);
    return {it_left, it_right};
}


void PrintSpacesPositions(string& str) {
    auto it = find(str.begin(), str.end(), ' ');
    while(it != str.end()){
        cout << (it - str.begin()) << '\n';
        it = find(++it, str.end(), ' ');
    }
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
    
    const auto mo_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    const auto mt_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt"s);
    cout << (mt_result.first - begin(sorted_strings)) << " " << (mt_result.second - begin(sorted_strings)) << endl;
    
    const auto na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "na"s);
    cout << (na_result.first - begin(sorted_strings)) << " " << (na_result.second - begin(sorted_strings)) << endl;
    
    return 0;
}
