#include<iostream>
#include<thread.h>
#include<unistd.h>
int balance = 1000;
pthread_mutex_t lock;
void* withdraw(void* arg) {
    int amount = *(int*)arg;
    pthread_mutex_lock(&lock);

    if(balance>= amount) {
        std::cout<<"Withdrawing "<<amount<< "....\n";
        usleep(100000);
        balance-= amount;
        std::cout<<"Transaction successful! Remaining balance: "<<balance<< "\n";
       }
       else {
        std::cout<<"Insufficient balance\n";
       }
       pthread_mutex_unlock(&lock);
       return nullptr;
}
int main()
 {
    pthread_mutex_init(&lock,nullptr);
    for(int i=0;i<3;i++) {
        pthread_join(customers[i]),nullptr);
    }
