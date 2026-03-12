#include <iostream>
#include <vector>

using namespace std;

class Chair {
private:
    int m_legs{};
    vector<double> m_prices{};
public:
    Chair() : m_legs{0}, m_prices{} {};
    // Setter
    void setLegs(int userLegs) { m_legs = userLegs; }

    // Getter
    int getLegs() {}
};


int main() {

}