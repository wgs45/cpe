#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x1, y1, x2, y2, x3, y3, x4, y4;

    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        double bx, by, ax, ay, cx, cy;

        // Find which point is shared between the two segments
        if (x1 == x3 && y1 == y3) {
            bx = x1; by = y1;
            ax = x2; ay = y2;
            cx = x4; cy = y4;
        } else if (x1 == x4 && y1 == y4) {
            bx = x1; by = y1;
            ax = x2; ay = y2;
            cx = x3; cy = y3;
        } else if (x2 == x3 && y2 == y3) {
            bx = x2; by = y2;
            ax = x1; ay = y1;
            cx = x4; cy = y4;
        } else { // x2 == x4 && y2 == y4
            bx = x2; by = y2;
            ax = x1; ay = y1;
            cx = x3; cy = y3;
        }

        // Calculate the fourth point using the vector fomrula: D = A + C - B
        double dx = ax + cx - bx;
        double dy = ay + cy - by;

        cout << fixed << setprecision(3) << dx << " " << dy << "\n";
    }

    return 0;
}
