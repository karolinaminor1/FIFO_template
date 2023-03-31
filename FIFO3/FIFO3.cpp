// FIFO3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fifo.h"

int main()
{
    cout << "---------- Fifo z int : ----------" << endl;
    Fifo<int> FIFO = Fifo<int>();

    FIFO.Enqueue(11);
    FIFO.Enqueue(10);
    FIFO.Enqueue(7);
    FIFO.Enqueue(19);
    FIFO.Enqueue(22);
    FIFO.Enqueue(19);
    FIFO.FQDel();

    FIFO.printQueue();
    cout << endl;

    cout << "---------- Fifo z double : ----------" << endl;
    Fifo<double> FIFO2 = Fifo<double>();

    FIFO2.Enqueue(10.66);
    FIFO2.Enqueue(8.55);
    FIFO2.Enqueue(19.3);
    FIFO2.Enqueue(22.03723);
    FIFO2.Enqueue(19.362537);

    FIFO2.printQueue();
    cout << endl;


    cout << "---------- Fifo string: ----------" << endl;
    Fifo<string> FIFO3 = Fifo<string>();

    FIFO3.Enqueue("<3<3");
    FIFO3.Enqueue("cos");
    FIFO3.Enqueue("abcbhdaj");
    FIFO3.Enqueue("blabla");
    FIFO3.Enqueue("xd");
    FIFO3.Enqueue(":(((");

    FIFO3.printQueue();
    cout << endl;
    
    return 0;
}

