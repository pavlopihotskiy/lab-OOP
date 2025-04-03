#include "Price.h"

// Додавання ціни
void addPrice(Price& p1, Price& p2) {

    p2.hrn += p1.hrn;
    p2.kop += p1.kop;

}

// Множення ціни на коефіцієнт
void multiplyPrice(Price& p, int quantity) {

    p.hrn *= quantity;
    p.kop *= quantity;

}

// Округлення ціни
void roundPrice(Price& p) {

    while(p.kop >= 100){
        p.hrn += 1;
        p.kop -= 100;
    }

    int totaltemp = 0;

    totaltemp = (p.hrn * 100 + p.kop + 5) / 10 * 10;
    p.hrn = totaltemp / 100;
    p.kop = totaltemp % 100;
}

// Вивід ціни
void printPrice(Price& p) {
    std::cout << p.hrn << " UAH " << p.kop << " kop" << std::endl;
}

// Функція обробки файлу
void processFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open the file!" << std::endl;
        return;
    }

    Price temp = {0, 0};
    Price total = {0, 0};

    int grn, quantity;
    short int kop;
    
    // Зчитування даних 
    while (file >> grn >> kop >> quantity) {

        temp.hrn = grn;
        temp.kop = kop;

        multiplyPrice(temp, quantity);
        addPrice(temp, total);
    }
    file.close();

    std::cout << "Total amount: ";
    printPrice(total);

    roundPrice(total);

    std::cout << "Amount to be paid (rounded): ";
    printPrice(total);
}