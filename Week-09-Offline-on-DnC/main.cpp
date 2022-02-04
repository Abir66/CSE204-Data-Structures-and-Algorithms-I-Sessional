#include <iostream>
#include<fstream>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include "sort.h"

const int TOTAL_ITERATION = 20;

int main()
{
    freopen("output.csv", "w", stdout);

    std::cout<<"n,Mergesort,Quicksort,Randomized Quicksort,Insertion Sort, STL sort, Quicksort (sorted input), Randomized Quicksort (sorted input)"<<std::endl;

    // std::cout<<std::setw(7)<<"n"<<" | ";
    // std::cout<<std::setw(15)<<"Mergesort"<<" ";
    // std::cout<<std::setw(15)<<"Quicksort"<<" ";
    // std::cout<<std::setw(25)<<"Randomized Quicksort"<<" ";
    // std::cout<<std::setw(15)<<"Insertion Sort"<<" ";
    // std::cout<<std::setw(15)<<"STL sort"<<" ";
    // std::cout<<std::setw(20)<<"Quicksort (Sorted)"<<" ";
    // std::cout<<std::setw(25)<<"Randomized Quicksort (Sorted)"<<" ";
    // std::cout<<std::endl;

    int len[] = {5, 10, 100, 1000, 10000, 100000};
    srand(17);

    for (int l = 0; l < 6; l++)
    {
        int n = len[l];
        int *ara = new int[n];
        int *ara2 = new int[n];

        double mergeSortTime = 0;
        double quickSortTime = 0;
        double randomizedQuicksortTime = 0;
        double insertionSortTime = 0;
        double sortedQsortTime = 0;
        double sortedRandomizedQsortTime = 0;
        double stlSortTime = 0;
        

        for (int iteration = 0; iteration < TOTAL_ITERATION; iteration++)
        {
            

            for (int i = 0; i < n; i++) ara[i] = rand();


            for (int i = 0; i < n; i++) ara2[i] = ara[i];
            clock_t start = clock();
            mergeSort(ara2, 0, n - 1);
            mergeSortTime += (double(clock() - start) / CLOCKS_PER_SEC);

            for (int i = 0; i < n; i++) ara2[i] = ara[i];
            start = clock();
            quickSort(ara2, 0, n - 1);
            quickSortTime += (double(clock() - start) / CLOCKS_PER_SEC);

            for (int i = 0; i < n; i++) ara2[i] = ara[i];
            start = clock();
            randomizedQuickSort(ara2, 0, n - 1);
            randomizedQuicksortTime += (double(clock() - start) / CLOCKS_PER_SEC);

            for (int i = 0; i < n; i++) ara2[i] = ara[i];
            start = clock();
            insertionSort(ara2, n);
            insertionSortTime += (double(clock() - start) / CLOCKS_PER_SEC);

            for (int i = 0; i < n; i++) ara2[i] = ara[i];
            start = clock();
            std::sort(ara2,ara2+n);
            stlSortTime += (double(clock() - start) / CLOCKS_PER_SEC);

            start = clock();
            quickSort(ara2, 0, n - 1);
            sortedQsortTime += (double(clock() - start) / CLOCKS_PER_SEC);
            
            start = clock();
            randomizedQuickSort(ara2, 0, n - 1);
            sortedRandomizedQsortTime += (double(clock() - start) / CLOCKS_PER_SEC);
        }


        mergeSortTime /= TOTAL_ITERATION;
        quickSortTime /= TOTAL_ITERATION;
        randomizedQuicksortTime /= TOTAL_ITERATION;
        insertionSortTime /= TOTAL_ITERATION;
        sortedQsortTime /= TOTAL_ITERATION;
        sortedRandomizedQsortTime /= TOTAL_ITERATION;
        stlSortTime /= TOTAL_ITERATION;

        delete[] ara;
        delete[] ara2;
        // std::cout<<std::setw(7)<<n<<" | ";
        // std::cout<<std::fixed;
        // std::cout<<std::setw(25)<<std::setprecision(4);
        // std::cout<<std::setw(15)<<mergeSortTime*1000<<" ";
        // std::cout<<std::setw(15)<<quickSortTime*1000<<" ";
        // std::cout<<std::setw(25)<<randomizedQuicksortTime*1000<<" ";
        // std::cout<<std::setw(15)<<insertionSortTime*1000<<" ";
        // std::cout<<std::setw(15)<<stlSortTime*1000<<" ";
        // std::cout<<std::setw(20)<<sortedQsortTime*1000<<" ";
        // std::cout<<std::setw(25)<<sortedRandomizedQsortTime*1000 <<std::endl;

        printf("%d,",n);
        printf("%.5lf,",mergeSortTime*1000);
        printf("%.5lf,",quickSortTime*1000);
        printf("%.5lf,",randomizedQuicksortTime*1000);
        printf("%.5lf,",insertionSortTime*1000);
        printf("%.5lf,",stlSortTime*1000);
        printf("%.5lf,",sortedQsortTime*1000);
        printf("%.5lf\n",sortedRandomizedQsortTime*1000);
        
    }

    return 0;
}

// g++ -O2 -std=c++11 -Wall "-Wl,--stack=536870912" main.cpp -o a.exe