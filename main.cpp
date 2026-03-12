// COMSC-210 | Lab 20 | Barsbek
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        const int MIN_LEGS = 3;
        const int MAX_LEGS = 4;

        const int MIN_PRICES = 10000;
        const int MAX_PRICES = 99999;
        int rndLegs = (rand() % (MAX_LEGS - MIN_LEGS + 1) + MIN_LEGS);
        prices = new double[SIZE];
        legs = rndLegs;
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX_PRICES - MIN_PRICES + 1) + MIN_PRICES) / 100.0;
    }

    Chair(int l, double pricesInput[]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = pricesInput[i];
    }
    // setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }
    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }
    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }
    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << '$' << prices[i] << " ";
        cout << endl << "Historical avg price: $" << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(time(0));
    cout << fixed << setprecision(2);
    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    double prices[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, prices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;
    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    delete[] collection; // frees memory
    collection = nullptr;
    return 0;
}

