#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stdio.h>

typedef struct{
    char message[40];
}Message;

typedef struct{   
    Message message[3];
    int messagesCount;
    int paid;
}Customer;

void createCustomers(Customer *user);
int totalPaid(Customer *user);
int randomCustomer(Customer *user, int sum, int userToPresent);

#endif