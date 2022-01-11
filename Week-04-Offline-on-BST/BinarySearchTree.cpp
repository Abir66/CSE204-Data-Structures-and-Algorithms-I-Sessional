#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

int main()
{

    std::string filename = "input.txt", travarsal;
    char command;
    int param;
    BST<int> tree;

    std::ifstream input(filename);
    if (!input)
    {
        std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
        return 3;
    }

    while(!input.eof()){
        input>>command;
        switch (command)
        {
        case 'I':
            input>>param;
            tree.insert(param);
            tree.print();
            break;
        
        case 'D':
            input>>param;
            if(tree.remove(param)) tree.print();
            else std::cout<<"Invalid Operation"<<std::endl;
            break;

        case 'F':
            input>>param;
            if(tree.find(param)) std::cout<<"True"<<std::endl;
            else std::cout<<"False"<<std::endl;
            break;

        case 'T':
            input>>travarsal;
            if(travarsal == "Pre") tree.preOrder();
            else if(travarsal == "Post") tree.postOrder();
            else tree.inOrder();
            break;
        default:
            break;
        }
    }
    input.close();
    return 0;
}