#include<iostream>
#include "LinkedList.h"


template <typename T>
void printList(List<T> &list)
{
    int size = list.length();
    int pos = list.currPos();
    list.moveToStart();
    std::cout << "<";
    for (int i = 0; i < size; i++)
    {
        if (i == pos) std::cout << "| ";
        std::cout << list.getValue();
        list.next();
        if (i != size - 1) std::cout << " ";
    }
    std::cout << ">" << std::endl;
    list.moveToPos(pos);
}

int main()
{
    int k, x, returnValue, ara[100];
    std::cin >> k >> x;
    for (int i = 0; i < k; i++) std::cin >> ara[i];
    LinkedList<int> linkedList(ara, k);
    printList(linkedList);

    int q, n;
    while (1)
    {
        std::cin >> q >> n;

        if (q == 0)
            break;

        switch (q)
        {
        case 1:
            linkedList.clear();
            printList(linkedList);
            std::cout << -1 << std::endl;
            break;

        case 2:
            linkedList.insert(n);
            printList(linkedList);
            std::cout << -1 << std::endl;
            break;

        case 3:
            linkedList.append(n);
            printList(linkedList);
            std::cout << -1 << std::endl;
            break;

        case 4:
            returnValue = linkedList.remove();
            printList(linkedList);
            std::cout << returnValue << std::endl;
            break;

        case 5:
            linkedList.moveToStart();
            printList(linkedList);
            std::cout << -1 << std::endl;
            break;

        case 6:
            linkedList.moveToEnd();
            printList(linkedList);
            std::cout << -1 << std::endl;
            break;

        case 7:
            linkedList.prev();
            printList(linkedList);
            std::cout << -1 << std::endl;
            break;

        case 8:
            linkedList.next();
            printList(linkedList);
            std::cout << -1 << std::endl;
            break;

        case 9:
            printList(linkedList);
            std::cout << linkedList.length() << std::endl;
            break;

        case 10:
            printList(linkedList);
            std::cout << linkedList.currPos() << std::endl;
            break;

        case 11:
            linkedList.moveToPos(n);
            printList(linkedList);
            std::cout << -1 << std::endl;
            break;

        case 12:
            printList(linkedList);
            std::cout << linkedList.getValue() << std::endl;
            break;

        case 13:
            printList(linkedList);
            std::cout << linkedList.Search(n) << std::endl;
            break;

        default:
            break;
        }
    }

    return 0;
}