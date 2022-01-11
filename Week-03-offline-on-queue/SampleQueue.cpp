#include<iostream>
#include"ArrayQueue.h"
#include"LLQueue.h"

int main()
{
    int item;
    LLQueue<int> queue;

    int q, n;
    while (1)
    {
        std::cin >> q >> n;

        if (q == 0)
            break;

        switch (q)
        {
        case 1:
            queue.clear();
            printQueue(queue, ',', '<', '>');
            std::cout << -1 << std::endl;
            break;

        case 2:
            queue.enqueue(n);
            printQueue(queue, ',', '<', '>');
            std::cout << -1 << std::endl;
            break;

        case 3:
            item = queue.dequeue();
            printQueue(queue, ',', '<', '>');
            std::cout << item << std::endl;
            break;

        case 4:
            printQueue(queue, ',', '<', '>');
            std::cout << queue.length() << std::endl;
            break;

        case 5:
            printQueue(queue, ',', '<', '>');
            std::cout << queue.frontValue() << std::endl;
            break;
        
        case 6:
            printQueue(queue, ',', '<', '>');
            std::cout << queue.rearValue() << std::endl;
            break;

        case 7:
            item = queue.leaveQueue();
            printQueue(queue, ',', '<', '>');
            std::cout << item << std::endl;
            break;

        default:
            break;
        }
    }

    return 0;
}