#include<iostream>
#include "AStack.h"
#include "LStack.h"

template<typename T>
void print(Stack<T> &s){
    std::cout<<"<";
    printStack(s);
    std::cout<<">"<<std::endl;
}

int main()
{

    int item;
    LStack<int> stack;
    print(stack);

    int q, n;
    while (1)
    {
        std::cin >> q >> n;

        if (q == 0)
            break;

        switch (q)
        {
        case 1:
            stack.clear();
            print(stack);
            std::cout << -1 << std::endl;
            break;

        case 2:
            stack.push(n);
            print(stack);
            std::cout << -1 << std::endl;
            break;

        case 3:
            item = stack.pop();
            print(stack);
            std::cout << item << std::endl;
            break;

        case 4:
            print(stack);
            std::cout << stack.length() << std::endl;
            break;

        case 5:
            print(stack);
            std::cout << stack.topValue() << std::endl;
            break;

        case 6:
            stack.setDirection(n);
            print(stack);
            std::cout << -1 << std::endl;
            break;

        default:
            break;
        }
    }

    return 0;
}