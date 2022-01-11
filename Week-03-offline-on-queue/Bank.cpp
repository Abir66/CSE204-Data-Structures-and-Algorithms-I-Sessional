#include <iostream>
#include "LLQueue.h"
#include "ArrayQueue.h"

struct Customer
{
    int enterTime, serviceTime;
    Customer(){};
    Customer(int enterTime, int serviceTime)
    {
        this->enterTime = enterTime;
        this->serviceTime = serviceTime;
    }
};

class Bank
{
    LLQueue<Customer> q1, q2;
    int booth1Freetime = 0, booth2Freetime = 0;
    bool free1 = true, free2 = true;

    void switchQueues(int t)
    {
        if ((q1.length() - 1 > q2.length()) || (q1.length() != 0 && q2.length() == 0 && free2)) q2.enqueue(q1.leaveQueue());
        else if ((q2.length() - 1 > q1.length()) || (q2.length() != 0 && free1 && !free2)) q1.enqueue(q2.leaveQueue());
    }

public:

    void enterCustomer(Customer &c)
    {
        if (booth1Freetime <= c.enterTime && q1.length() == 0)
        {
            booth1Freetime = c.enterTime + c.serviceTime;
            free1 = false;
        }
        else if (booth2Freetime <= c.enterTime && q2.length() == 0)
        {
            booth2Freetime = c.enterTime + c.serviceTime;
            free2 = false;
        }
        else if (q1.length() <= q2.length()) q1.enqueue(c);
        else if (q1.length() > q2.length()) q2.enqueue(c);
        
    }

    void run(int newCustomerEnterTime = -1)
    {

        int t = std::min(booth1Freetime, booth2Freetime);
        while (t <= newCustomerEnterTime || newCustomerEnterTime == -1)
        {
            
            if (q1.length() == 0 && q2.length() == 0) break;
            if (t == booth1Freetime)
            {
                free1 = true;
                if (q1.length() != 0)
                {
                    Customer c = q1.dequeue();
                    booth1Freetime += c.serviceTime;
                    free1 = false;
                }
            }
            if (t == booth2Freetime)
            {
                free2 = true;
                if (q2.length() != 0)
                {
                    Customer c = q2.dequeue();
                    booth2Freetime += c.serviceTime;
                    free2 = false;
                }
            }

            if (t != newCustomerEnterTime || newCustomerEnterTime == -1) switchQueues(t);

            if (booth1Freetime <= booth2Freetime)
            {
                if (q1.length() != 0 || (q1.length() == 0 && !free1)) t = booth1Freetime;
                else t = booth2Freetime;
            }
            else
            {
                if (q2.length() != 0 || (q2.length() == 0 && !free2)) t = booth2Freetime;
                else t = booth1Freetime;
            }
        }
    }

    void show()
    {
        std::cout << "Booth 1 finishes service at t=" << booth1Freetime << std::endl;
        std::cout << "Booth 2 finishes service at t=" << booth2Freetime << std::endl;
    }
};

int main()
{

    int n, enterTime, serviceTime;
    Bank bank;
    std::cin >> n;
    while (n--)
    {
        std::cin >> enterTime >> serviceTime;
        Customer c(enterTime, serviceTime);
        bank.run(enterTime);
        bank.enterCustomer(c);
    }
    bank.run();
    bank.show();

    return 0;
}
