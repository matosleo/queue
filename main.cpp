//
//  main.cpp
//  Queue
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include <iostream>
#include <cassert>
#include "Queue.hpp"

int main(int argc, const char * argv[]) {
    Queue<int> q(20);

    assert( q.isEmpty() );

    int i = 0;
    while( !q.isFull() )
    {
        assert(q.getQuantity() == i);

        int quantityBefore = q.getQuantity();
        q.enqueue(i);
        int quantityAfter = q.getQuantity();

        assert( quantityAfter == quantityBefore+1);
        assert( q.peek() == 0 );

        ++i;
    }

    i = 0;
    while( !q.isEmpty() )
    {
        assert( q.peek() == i );

        int quantityBefore = q.getQuantity();
        q.dequeue();
        int quantityAfter = q.getQuantity();

        assert( quantityAfter == quantityBefore-1);

        ++i;
    }

    for(int j = 0; j < 10; j++)
    {
        int quantityBefore = q.getQuantity();
        q.enqueue(j);
        int quantityAfter = q.getQuantity();

        assert( quantityAfter == quantityBefore+1);
        assert( q.peek() == 0 );
    }

    std::cout << "Todos os testes passaram.\n";

    return 0;
}