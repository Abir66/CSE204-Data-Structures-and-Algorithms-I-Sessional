#include<iostream>
#include "ArrayList.h"


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
    ArrayList<int> arrayList(ara, k, x);
    printList(arrayList);

    int q, n;
    while (1)
    {
        std::cin >> q >> n;

        if (q == 0)
            break;

        switch (q)
        {
        case 1:
            arrayList.clear();
            printList(arrayList);
            std::cout << -1 << std::endl;
            break;

        case 2:
            arrayList.insert(n);
            printList(arrayList);
            std::cout << -1 << std::endl;
            break;

        case 3:
            arrayList.append(n);
            printList(arrayList);
            std::cout << -1 << std::endl;
            break;

        case 4:
            returnValue = arrayList.remove();
            printList(arrayList);
            std::cout << returnValue << std::endl;
            break;

        case 5:
            arrayList.moveToStart();
            printList(arrayList);
            std::cout << -1 << std::endl;
            break;

        case 6:
            arrayList.moveToEnd();
            printList(arrayList);
            std::cout << -1 << std::endl;
            break;

        case 7:
            arrayList.prev();
            printList(arrayList);
            std::cout << -1 << std::endl;
            break;

        case 8:
            arrayList.next();
            printList(arrayList);
            std::cout << -1 << std::endl;
            break;

        case 9:
            printList(arrayList);
            std::cout << arrayList.length() << std::endl;
            break;

        case 10:
            printList(arrayList);
            std::cout << arrayList.currPos() << std::endl;
            break;

        case 11:
            arrayList.moveToPos(n);
            printList(arrayList);
            std::cout << -1 << std::endl;
            break;

        case 12:
            printList(arrayList);
            std::cout << arrayList.getValue() << std::endl;
            break;

        case 13:
            printList(arrayList);
            std::cout << arrayList.Search(n) << std::endl;
            break;

        default:
            break;
        }
    }

    return 0;
}