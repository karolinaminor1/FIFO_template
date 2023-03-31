#include <cstdlib>
#include "TFifo.h"
#define NSIZE 10


int main()
{
    
    cout << "---------- TFifo z int i double: ----------" << endl;
    TFifo<int, double> FIFO = (NSIZE);

    FQINFO<int, double> info1 = FQINFO<int, double>(3, 4.7);
    FIFO.Enqueue(&info1);

    FQINFO<int, double> info2 = FQINFO<int, double>(10, 7.58);
    FIFO.Enqueue(&info2);

    FQINFO<int, double> info3 = FQINFO<int, double>(7, 8.232);
    FIFO.Enqueue(&info3);

    FQINFO<int, double> info4 = FQINFO<int, double>(13, 1.4683);
    FIFO.Enqueue(&info4);

    FQINFO<int, double> info5 = FQINFO<int, double>(25, 9.99);
    FIFO.Enqueue(&info5);

    FIFO.printQueue();
    cout << endl;


    cout << "---------- TFifo z string i char: ----------" << endl;
    TFifo<string, char> FIFO1 = (NSIZE);

    FQINFO<string, char> info6 = FQINFO<string, char>("blabla", '%');
    FIFO1.Enqueue(&info6);

    FQINFO<string, char> info7 = FQINFO<string, char>("abcabcabc", '?');
    FIFO1.Enqueue(&info7);

    FQINFO<string, char> info8 = FQINFO<string, char>("cos", 'A');
    FIFO1.Enqueue(&info8);

    FQINFO<string, char> info9 = FQINFO<string, char>("fifo:)", '.');
    FIFO1.Enqueue(&info9);

    FQINFO<string, char> info10 = FQINFO<string, char>("<3 <3 <3", '>');
    FIFO1.Enqueue(&info10);

    FIFO1.printQueue();
    cout << endl;





















    return 0;







    /*TFifo FIFO = TFifo(NSIZE);

   
    for(int i = 0; i < NSIZE-3; i++) {
        FQINFO info = FQINFO(1,1);
        FIFO.Enqueue(&info);
     }

    FQINFO info2 = FQINFO(3,4);
    FIFO.Enqueue(&info2);

    FQINFO info3 = FQINFO(9,11);
    FIFO.Enqueue(&info3);

    FQINFO info4 = FQINFO(7,7);
    FIFO.Enqueue(&info4);

    cout << "FIFO tablicowe:" << endl;
    FIFO.printQueue();
    cout << endl;

    FIFO.FQDequeue();
    cout << "FIFO tablicowe po usunieciu jednego elementu:" << endl;
    FIFO.printQueue();
    cout << endl;


    */
    
}

