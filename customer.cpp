#include "customer.h"
#include <string.h> //strcpy()
#include <stdlib.h> //rand()

void createCustomers(Customer *user){
    //Hederlige Harry
    user[0].paid = 5000;
    user[0].messagesCount = 3;
    strcpy(user[0].message[0].message, "Köp bil hos Harry");
    strcpy(user[0].message[1].message, "En god bilaffär (för Harry!)");
    strcpy(user[0].message[2].message, "Hederlige Harrys Bilar");

    //Farmor Anka
    user[1].paid = 3000;
    user[1].messagesCount = 2;
    strcpy(user[1].message[0].message, "Köp paj hos Farmor Anka");
    strcpy(user[1].message[1].message, "Skynda innan Mårten ätit alla pajer");

    //Svarte Petter
    user[2].paid = 1500;
    user[2].messagesCount = 2;
    strcpy(user[2].message[0].message, "Låt Petter bygga åt dig");
    strcpy(user[2].message[1].message, "Bygga svart? Ring Petter");

    //Långbens detektivbyrå
    user[3].paid = 4000;   
    user[3].messagesCount = 2;
    strcpy(user[3].message[0].message, "Mysterier? Ring Långben");
    strcpy(user[3].message[1].message, "Långben fixar biffen");
    
    //IoTs reklambyrå
    user[4].paid = 1000;
    user[4].messagesCount = 1;
    strcpy(user[4].message[0].message, "Synas här? IOT:s Reklambyrå");
}

int totalPaid(Customer *user){
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += user[i].paid;
    return sum;
}

int randomCustomer(Customer *user, int sum, int userToPresent){
    // get a NEW random customer
    int lastPresented = userToPresent;
        
    while (userToPresent == lastPresented){
        int randCustomer = rand() % sum; 
        int paidSoFar = 0;
            
        for (int i = 0; i < 5; i++){
            paidSoFar += user[i].paid;

            // om randCustomer är mindre än paidSoFar - lagras userToPresent.
            if (randCustomer < paidSoFar){
                userToPresent = i;
                break;
            }
        }
    }
    return userToPresent;
}