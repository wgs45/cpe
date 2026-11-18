#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const double earth_radius = 6440.0;
const double pi = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double s, a;
    string unit;

    while (cin >> s >> a >> unit) {
        // Convert mins to degress if necessary
        if (unit == "min") {
            a /= 60.0;
        }

        // Normalize angle to be <= 180 degress (minor arc)
        while (a > 360.0) a-= 360.0;
        if (a > 180.0) {
            a = 360.0 - a;
        }

        // Calculate total orbital radius from Earth's center
        double r = earth_radius + s;

        // Convert angle to radians
        double theta = a * pi / 180.0;

        // Calculate Arc and Chord distances
        double arc_dist = r * theta;
        double chord_dist = 2.0 * r * sin(theta / 2.0);

        cout << fixed << setprecision(6) << arc_dist << " " << chord_dist << "\n";
    }

    return 0;
}

