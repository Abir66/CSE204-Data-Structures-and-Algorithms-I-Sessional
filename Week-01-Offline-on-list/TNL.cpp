#include <iostream>
#include "Arr.h"
#include "LL.h"

void task1(int k, List<int>&busList, List<int>&trainList ){
    
    for(int i=0;i<k;i++){
        if (i!=0) std::cout<<",";
        std::cout<<i;
    }
    std::cout<<std::endl;

    for(int i = 0; i<k; i++){
        if(i!=0) std::cout<<",";
        if(busList.Search(i)!=-1) std::cout<<i;
    }
    std::cout<<std::endl;

    for(int i = 0; i<k; i++){
        if(i!=0) std::cout<<",";
        if(trainList.Search(i)!=-1) std::cout<<i;
    }
    std::cout<<std::endl;
}

int main(){

    int k,l,m, input,task;

    // For using array based list, just change this 'LL' to 'Arr'
    LinkedList<int> busStops, trainStops;
    std::cin>>k;

    std::cin>>l;
    for(int i=0;i<l;i++){
        std::cin>>input;
        busStops.append(input);
    }

    std::cin>>m;
    for(int i=0;i<m;i++){
        std::cin>>input;
        trainStops.append(input);
    }

    std::cin>>task;
    if(task == 1) task1(k,busStops,trainStops);


    return 0;
}
