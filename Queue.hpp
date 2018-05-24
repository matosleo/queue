//
//  Queue.hpp
//  Queue
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>

using namespace std;

#define QUEUE_SIZE 7

template<class T>
class Queue
{
public:
    Queue();
    Queue(int);
    bool isEmpty();
    bool isFull();
    void enqueue(T);
    void dequeue();
    T peek();
    int getQuantity();
    
private:
    T* content;
    int size;
    int quantity;
    int begin;
    int end;
};

template<typename T>
Queue<T>::Queue(): Queue(QUEUE_SIZE)
{
}

/**
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Ajustar os valores iniciais de 'begin' e 'end' de acordo com sua implementação.
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
template<typename T>
Queue<T>::Queue(int size): size(size), quantity(0), content(new T[size]), begin(0), end(0)
{
}

template<typename T>
bool Queue<T>::isEmpty(){
    return(this->quantity == 0);
}

template<typename T>
bool Queue<T>::isFull(){
    return(this->quantity == this->size);
}

template<typename T>
int Queue<T>::getQuantity()
{
    return this->quantity;
}

template<typename T>
T Queue<T>::peek(){
    if(!this->isEmpty())
    {
        return this->content[begin];
    }
    else
    {
        cerr << "Deu ruim" << endl;
        exit(1);
    }
}

template<typename T>
void Queue<T>::enqueue(T element){
    if(!isFull())
    {
        this->content[this->end] = element;
        this->quantity++;
        if(this->end == this->size - 1)
        {
            this->end  = 0;
        }
        else
        {
            this->end++;
        }
    }
    else
    {
        cerr << "Deu ruim" << endl;
    }
}

template<typename T>
void Queue<T>::dequeue(){
    if(!isEmpty())
    {
        if(this->begin == this->size - 1)
        {
            this->begin = 0;
        }
        else
        {
            this->begin++;
        }
        this->quantity--;
    }
    else
    {
        cerr << "Deu ruim" << endl;
    }
}

#endif /* Queue_hpp */
