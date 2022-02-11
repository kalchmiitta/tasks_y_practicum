#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stack>

using namespace std;

template<typename It>
void PrintRange (It range_begin, It range_end) {
    for (auto it = range_begin; it != range_end; ++ it) {
        cout << *it << " "s;
    }
    cout << endl;
}

template<typename Type>
class Stack {
public:
    void Push (const Type &element) {
        elements_.push_back(element);
    }
    
    void Pop () {
        elements_.resize(this->Size() - 1);
    }
    
    const Type &Peek () const {
        return elements_[this->Size() - 1];
    }
    
    Type &Peek () {
        return elements_[this->Size() - 1];
    }
    
    void Print () const {
        PrintRange(elements_.begin(), elements_.end());
    }
    
    uint64_t Size () const {
        return elements_.size();
    }
    
    bool IsEmpty () const {
        return this->Size() == 0;
    }

private:
    vector<Type> elements_;
};

template<typename Type>
class StackMin {
public:
    void Push (const Type &element) {
        elements_.Push(element);
        if (min_elem_.IsEmpty()) {
            min_elem_.Push(element);
        } else if (element < min_elem_.Peek()) {
            min_elem_.Push(element);
        }else {
            min_elem_.Push(min_elem_.Peek());
        }
    }
    
    void Pop () {
        elements_.Pop();
        min_elem_.Pop();
    }
    
    const Type &Peek () const {
        return elements_.Peek();
    }
    
    Type &Peek () {
        return elements_.Peek();
    }
    
    void Print () const {
        elements_.Print();
    }
    
    uint64_t Size () const {
        return elements_.size();
    }
    
    bool IsEmpty () const {
        return elements_.IsEmpty();
    }
    
    const Type &PeekMin () const {
        return min_elem_.Peek();
    }
    
    Type &PeekMin () {
        return min_elem_.Peek();
    }

private:
    Stack<Type> elements_;
    Stack<Type> min_elem_;
};

template <typename Type>
class SortedStack {
public:
    void Push(const Type& element) {
        if(elements_.IsEmpty()){
            elements_.Push(element);
            return;
        }
        if(element <= elements_.Peek()){
            elements_.Push(element);
            return;
        }
        vector<Type> current;
        while(element > elements_.Peek() && !elements_.IsEmpty()){
            current.push_back(elements_.Peek());
            elements_.Pop();
        }
        elements_.Push(element);
        for(int i = current.size() - 1; i >= 0; --i){
            elements_.Push(current[i]);
        }
        
    }
    void Pop() {
        elements_.Pop();
    }
    const Type& Peek() const {
        return elements_.Peek();
    }
    Type& Peek() {
        return elements_.Peek();
    }
    void Print() const {
        elements_.Print();
    }
    uint64_t Size() const {
        return elements_.Size();
    }
    bool IsEmpty() const {
        return elements_.IsEmpty();
    }
private:
    Stack<Type> elements_;
};

template <typename Type>
class Queue {
public:
    void Push (const Type &element) {
        stack_main_.push(element);
    }
    
    void Pop () {
        while (stack_main_.size() != 1) {
            auto temp = stack_main_.top();
            stack_temp_.push(temp);
            stack_main_.pop();
        }
        stack_main_.pop();
        while (! stack_temp_.empty()) {
            auto temp = stack_temp_.top();
            stack_main_.push(temp);
            stack_temp_.pop();
        }
    }
    
    Type &Front () {
        while (stack_main_.size() != 1) {
            auto temp = stack_main_.top();
            stack_temp_.push(temp);
            stack_main_.pop();
        }
        Type& top = stack_main_.top();
        while (! stack_temp_.empty()) {
            auto temp = stack_temp_.top();
            stack_main_.push(temp);
            stack_temp_.pop();
        }
        
        return top;
    }
    
    uint64_t Size () const {
        return stack_main_.size();
    }
    
    bool IsEmpty () const {
        return (this->Size() == 0);
    }

private:
    stack<Type> stack_main_;
    stack<Type> stack_temp_;
};
    
int main() {
    Queue<int> queue;
    vector<int> values(5);
    
    // заполняем вектор для тестирования очереди
    iota(values.begin(), values.end(), 1);
    // перемешиваем значения
    random_shuffle(values.begin(), values.end());
    
    //PrintRange(values.begin(), values.end());
    
    cout << "Заполняем очередь"s << endl;
    
    // заполняем очередь и выводим элемент в начале очереди
    for (int i = 0; i < 5; ++i) {
        queue.Push(values[i]);
        cout << "Вставленный элемент "s << values[i] << endl;
        cout << "Первый элемент очереди "s << queue.Front() << endl;
    }
    
    cout << "Вынимаем элементы из очереди"s << endl;
    
    // выводим элемент в начале очереди и вытаскиваем элементы по одному
    while (!queue.IsEmpty()) {
        // сначала будем проверять начальный элемент, а потом вытаскивать,
        // так как операция Front на пустой очереди не определена
        cout << "Будем вынимать элемент "s << queue.Front() << endl;
        queue.Pop();
    }
    return 0;
}
