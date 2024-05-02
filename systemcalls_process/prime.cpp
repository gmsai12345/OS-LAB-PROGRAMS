#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
void generateFibonacci(int start, int end) {
    if (start <= 0 || start > end) {
        std::cout << "Invalid range for Fibonacci series." << std::endl;
        return;
    }

    int prev = 0, current = 1, next;
    std::cout << "Fibonacci series between " << start << " and " << end << ":\n";
    while (current <= end) {
        if (current >= start)
            std::cout << current << " ";
        next = prev + current;
        prev = current;
        current = next;
    }
    std::cout << std::endl;
}

bool isPrime(int num) {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

void generatePrimes(int start, int end) {
    if (start <= 1 || start > end) {
        std::cout << "Invalid range for prime numbers." << std::endl;
        return;
    }

    std::cout << "Prime numbers between " << start << " and " << end << ":\n";
    for (int i = start; i <= end; ++i) {
        if (isPrime(i))
            std::cout << i << " ";
    }
    std::cout << std::endl;
}
int main()
{
    int start=3,end=20;
    pid_t child1,child2;
    child1=fork();
    if(child1<0)
    {
        cerr<< "fork failed"<<endl;
        return 1;
    }else if(child1==0)
    {
        cout << "odd number"<<endl;
        generatePrimes(start,end);
        exit(0);
    }
    else
    {
        child2=fork();
        if(child2<0)
        {
            cerr << "fork failed process 2"<<endl;
            return 1;
        } else if(child2==0)
        {
           cout <<"even numbers"<<endl;
            generateFibonacci(start,end);
            exit(0);
        }
        else
        {
            wait(NULL);
            wait(NULL);
            cout << "both process completed"<<endl;
        }
    }
   
    return 0;
}