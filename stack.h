#ifndef STACK_H_
#define STACK_H_

#include <exception>

/* exception class for error handling */
class stack_exception: public std::exception {
public:
    stack_exception(const char* msg) throw(): _msg{msg}{}
    const char * what() const throw() {return _msg;}
private:
    const char * _msg;    
};

template <typename T>
class stack {
public:
    stack(const size_t);
    ~stack();
    void push(const T&);
    T& pop();
    const T& top() const;
    bool isEmpty() const;
    bool isFull() const;
private:
    T * _elements;
    size_t _top;
    size_t _size;         
};

/* stack constructor */
template<typename T>
stack<T>::stack(const size_t size) : _size{size}, _top{0}
{
    if(_size == 0) throw stack_exception{"error: invalid stack size"};
    _elements = new T[_size];
}

/* stack destructor */
template<typename T>
stack<T>::~stack(){
    delete[] _elements;
}

/* push method */
template<typename T>
void stack<T>::push(const T & e)
{
    if(isFull()) throw stack_exception{"error: stackoverflow"};
    else {
        _elements[_top] = e;
        _top++;
    }
}

/* pop method */
template<typename T>
T & stack<T>::pop()
{
    if(isEmpty()) throw stack_exception{"error: stack underflow"};
    else {
        _top--;
        return _elements[_top];
    }
}

/* top method */
template<typename T>
const T& stack<T>::top() const
{
    if(isEmpty()) throw stack_exception{"error: stack underflow"};
    else {
        return _elements[_top - 1];
    }
}

/* helper to check if the stack is full */
template<typename T>
bool stack<T>::isFull() const
{
    return _top == _size;
}

/* helper to check if the stack is empty */
template<typename T>
bool stack<T>::isEmpty() const
{
    return (_top - 1) == -1;
}

#endif //!STACK_H_