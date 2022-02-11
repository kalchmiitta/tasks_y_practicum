#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    auto mid = range_begin + (range_end - range_begin) / 2;
    vector<typename RandomIt :: value_type> first(range_begin, mid);
    vector<typename RandomIt :: value_type> second(mid, range_end);
    
    MergeSort(begin(first), end(first));
    MergeSort(begin(second), end(second));
    
    vector<typename RandomIt :: value_type> result;
    
    merge(begin(first), end(first), begin(second), end(second), begin(result), end(result));
    
    swap_ranges(range_begin, range_end, begin(result));
    
}
template <typename MyItr>
void PrintRange(const MyItr& begin, const MyItr& end){
    for(MyItr curr = begin; curr != end; ++curr){
        cout << *curr <<' ';
    }
    cout <<'\n';
}


int main() {
    vector<int> test_vector(10);
    iota(test_vector.begin(), test_vector.end(), 1);

    random_shuffle(test_vector.begin(), test_vector.end());
    
    PrintRange(test_vector.begin(), test_vector.end());
    
    MergeSort(test_vector.begin(), test_vector.end());
    
    PrintRange(test_vector.begin(), test_vector.end());
    
    return 0;
}
