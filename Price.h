#ifndef PRICE_H
#define PRICE_H

#include <iostream>
#include <fstream>
#include <string>

struct Price {
    int hrn;
    short int kop;
};

// Функції для роботи з ціною
void printPrice(Price& p);
void addPrice(Price& p1, Price& p2);
void multiplyPrice(Price& p, int quantity);
void roundPrice(Price& p);
void processFile(const std::string &filename);

#endif