#include <iostream>
#include <vector>

using namespace std;

class Chair {
private:
    int m_legs{};
    vector<double> m_prices{}; // FIXME: double array
public:
    Chair() : m_legs{0}, m_prices{} {};
    // Setter
    void setLegs(const int userLegs) { m_legs = userLegs; }
    // FIXME: double array
    void setPrices(const vector<double>& userPrices) { m_prices = userPrices; }

    // Getter
    int getLegs() { return m_legs; }
    vector<double> getPrices() { return m_prices; }
};


int main() {

}