#include <iostream>
#include <vector>
using namespace std;

// A simple class to show how constructors respond to different initializations
class Box {
public:
    // Marking it 'explicit' prevents the old '=' style from doing implicit conversions
    explicit Box (int size) {
        cout << "Box is created with size: " << size << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The Loid-Back style (=)
    int width_1 = 5.9; // Compiles fine! Silently chops off .9, width1 becomes 5
    cout << "width_1 (=) : " << width_1 << "\n";

    // The Direct style ()
    int width_2(5.9); // Compiles fine! also Silently chops off .9
    cout << "width_2 (=) : " << width_2 << "\n";

    // The Strict Safety Guard Style ({})
    // UNCOMMENT THE LINE BELOW TO TEST: It will cause a COMPILER ERROR because of narrowing!
    // int width3{5.9};

    int width_3{5}; // This works perfectly because 5 is a true integer
    cout << "width_3 ({}) : " << width_3 << "\n\n";

    // Box b1 = 10; // ERROR! Fails because 'explicit' blocks the assignment operator (=)
    Box b2(10); // WORKS! Directly calls the constructor using ()
    Box b3{10}; // WORKS! Directly calls the constructor using {}

    vector<int> v_parentheses(3, 10); // Creates 3 elements: [10, 10, 10]
    vector<int> v_braces{3, 10}; // Creates 2 elements: [3, 10]

    std::cout << "v_parentheses size: " << v_parentheses.size() << "\n";
    std::cout << "v_braces size: " << v_braces.size() << "\n";


    return 0;
}

