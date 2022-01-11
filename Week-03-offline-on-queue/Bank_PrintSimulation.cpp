#include <iostream>
#include "LLQueue.h"
#include "ArrayQueue.h"
int num = 1;
struct Customer
{
    int enterTime, serviceTime, no;
    Customer(){};
    Customer(int enterTime, int serviceTime, int no)
    {
        this->enterTime = enterTime;
        this->serviceTime = serviceTime;
        this->no = no;
    }
    friend std::ostream &operator<<(std::ostream &os, Customer &c)
    {
        os << c.no;
        return os;
    }
};

struct Bank
{
    LLQueue<Customer> q1, q2;
    int booth1Freetime = 0, booth2Freetime = 0;
    int c1 = 0, c2 = 0; // for printing purpose
    bool free1 = true, free2 = true;

    void enterCustomer(Customer &c)
    {
        if (booth1Freetime <= c.enterTime && q1.length() == 0)
        {
            booth1Freetime = c.enterTime + c.serviceTime;
            c1 = c.no;
            std::cout << "t = " << c.enterTime << " Customer " << c.no << " enters service area 1 - freetime = " << booth1Freetime << std::endl;
            free1 = false;
        }
        else if (booth2Freetime <= c.enterTime && q2.length() == 0)
        {
            booth2Freetime = c.enterTime + c.serviceTime;
            c2 = c.no;
            std::cout << "t = " << c.enterTime << " Customer " << c.no << " enters service area 2 - freetime = " << booth2Freetime << std::endl;
            free2 = false;
        }
        else if (q1.length() <= q2.length())
        {
            std::cout << "t = " << c.enterTime << " Customer " << c.no << " enters queue 1" << std::endl;
            q1.enqueue(c);
        }

        else if (q1.length() > q2.length())
        {
            std::cout << "t = " << c.enterTime << " Customer " << c.no << " enters queue 2" << std::endl;
            q2.enqueue(c);
        }
    }

    void switchQueues(int t)
    {
        if ((q1.length() - 1 > q2.length()) || (q1.length() != 0 && q2.length() == 0 && free2))
        {
            std::cout << "t = " << t << " Customer " << q1.rearValue().no << " switch from 1 to 2 " << std::endl;
            q2.enqueue(q1.leaveQueue());
        }
        else if ((q2.length() - 1 > q1.length()) || (q2.length() != 0 && free1 && !free2))
        {
            std::cout << "t = " << t << " Customer " << q2.rearValue().no << " switch from 2 to 1 " << std::endl;
            q1.enqueue(q2.leaveQueue());
        }
    }

    void run(int newCustomerEnterTime = -1)
    {

        int t = std::min(booth1Freetime, booth2Freetime);
        while (t <= newCustomerEnterTime || newCustomerEnterTime == -1)
        {
            // if (newCustomerEnterTime == -1 && t == booth1Freetime && q1.length() == 0 && c1 != 0)
            //     std::cout << "t = " << t << " Customer " << c1 << " leaves service area 1 " << std::endl;
            // if (newCustomerEnterTime == -1 && t == booth2Freetime && q2.length() == 0 && c2 != 0)
            //     std::cout << "t = " << t << " Customer " << c2 << " leaves service area 2 " << std::endl;

            if (q1.length() == 0 && q2.length() == 0)
                break;
            if (t == booth1Freetime)
            {
                if (c1 != 0)
                {
                    std::cout << "t = " << t << " Customer " << c1 << " leaves service area 1 " << std::endl;
                    free1 = true;
                }
                if (q1.length() != 0)
                {
                    Customer c = q1.dequeue();
                    booth1Freetime += c.serviceTime;
                    std::cout << "t = " << t << " Customer " << c.no << " enters service area 1 - freetime = " << booth1Freetime << std::endl;
                    c1 = c.no;
                    free1 = false;
                }
            }
            if (t == booth2Freetime)
            {
                if (c2 != 0)
                {
                    std::cout << "t = " << t << " Customer " << c2 << " leaves service area 2 " << std::endl;
                    free2 = true;
                }
                if (q2.length() != 0)
                {
                    Customer c = q2.dequeue();
                    booth2Freetime += c.serviceTime;
                    std::cout << "t = " << t << " Customer " << c.no << " enters service area 2 - freetime = " << booth2Freetime << std::endl;
                    c2 = c.no;
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
        //std::cout<<"Input -- ";
        std::cin >> enterTime >> serviceTime;
        Customer c(enterTime, serviceTime, num);
        bank.run(enterTime);
        bank.enterCustomer(c);
        //bank.operate(enterTime);
        num++;
    }
    bank.run();
    bank.show();

    return 0;
}