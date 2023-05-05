#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void predatorPrey(int vs, int ks, double a1, double a2, double b1, double b2, int timeLimit, int approximation) {
    /*
     * v'(t) = alpha1 * v(t) + beta1 * v(t) * k(t),
     * k'(t) = -alpha2 * v(t) + beta2 * v(t) * k(t)
     */

    auto time = vector<double>();
    for (double i = 0; i <= timeLimit; i += (double) timeLimit / (double) approximation) {
        time.push_back(i);
    }

    double v0 = vs - a2 / b2;
    double k0 = ks - a1 / b1;

    auto v = vector<double>();
    auto k = vector<double>();
    for (auto t: time) {
        v.push_back(
                v0 * cos(sqrt(a1 * a2) * t) - k0 * sqrt(a2) * b1 * sin(sqrt(a1 * a2) * t) / (b2 * sqrt(a1)) + a2 / b2);

        k.push_back(
                v0 * sqrt(a1) * b2 * sin(sqrt(a1 * a2) * t) / (b1 * sqrt(a2)) + k0 * cos(sqrt(a1 * a2) * t) + a1 / b1);
    }


    cout << "t:\n";
    for (auto value: time)
        cout << value << " ";
    cout << "\n";

    cout << "v:\n";
    for (auto value: v)
        cout << value << " ";
    cout << "\n";

    cout << "k:\n";
    for (auto value: k)
        cout << value << " ";
}


int main() {
    cout << fixed;
    cout << setprecision(2);

    int numberOfVictims, numberOfKillers;
    cin >> numberOfVictims >> numberOfKillers;

    double a1, a2, b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int timeLimit, approximationPoints;
    cin >> timeLimit >> approximationPoints;

    predatorPrey(numberOfVictims, numberOfKillers, a1, a2, b1, b2, timeLimit, approximationPoints);
    return 0;
}
