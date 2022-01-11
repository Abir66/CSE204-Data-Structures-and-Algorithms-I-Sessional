#include <iostream>
#include "LStack.h"
#include "AStack.h"

struct Dish
{
    int startTime;
    int washingTime;
    int endTime;
    friend std::ostream &operator<<(std::ostream &os, const Dish &dish) {os << dish.endTime; return os;}
};

void cleaning(int &freetime, Stack<Dish> &dirty, Stack<Dish> &clean)
{
    Dish cleaningDish = dirty.pop();
    cleaningDish.startTime = std::max(cleaningDish.startTime, freetime);
    cleaningDish.endTime = cleaningDish.startTime + cleaningDish.washingTime - 1;
    freetime = cleaningDish.endTime+1;
    //std::cout << "cleaning done. startTime = " << cleaningDish.startTime << " endtime = " << cleaningDish.endTime << " , freetime = " << freetime << std::endl;
    clean.push(cleaningDish);
}

int main()
{
    int friends, courses, k, t, s, freetime = 0;
    std::cin >> friends >> courses;
    
    int *washingTime = new int[courses + 1]; //because my compiler didn't allow static array of non-constant length
    for (int i = 1; i <= courses; i++) std::cin >> washingTime[i];
    
    LStack<int> fullMealFriends;
    LStack<Dish> dirty, clean;
    
    while (true)
    {
        std::cin >> k >> t >> s;
        if (k == 0)
        {
            //cleaning all remaining dishes
            while (dirty.length()) cleaning(freetime, dirty, clean);
            break;
        }

        Dish dirtyDish;
        dirtyDish.washingTime = washingTime[s];
        dirtyDish.startTime = t;


        // first push to dirty stack and then try to clean
        if (freetime >= t){
            dirty.push(dirtyDish);
            // push to dirty stack
            //std::cout << "Pushing to dirty at time = " << t << ". washing time = " << dirtyDish.washingTime << " , freetime = " << freetime << std::endl;
            // clean
            while (freetime <= t && dirty.length()) cleaning(freetime, dirty, clean);
        }


        // first clean as much as you can then push the new dish
        else {
            // clean
            while (freetime <= t && dirty.length()) cleaning(freetime, dirty, clean);
            dirty.push(dirtyDish);
            // push to dirty stack
            //std::cout << "Pushing to dirty at time = " << t << ". washing time = " << dirtyDish.washingTime << " , freetime = " << freetime << std::endl;  
        }

        // stack of friends who have completed full course meal
        if (s == courses) fullMealFriends.push(k);
    }

    //std::cout<<"--------------------------"<<std::endl;
    std::cout << clean.topValue() << std::endl;

    printStack(clean,',',true);
    std::cout<<std::endl;

    if (fullMealFriends.length() == friends) std::cout << "Y" << std::endl;
    else std::cout << "N" << std::endl;

    // Printing friends who had full meal
    printStack(fullMealFriends, ',');
    std::cout<<std::endl;
    
    delete[] washingTime;
    return 0;
}