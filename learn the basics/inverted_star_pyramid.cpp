#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for (int i = n; i >= 0; i--) {

        // spaces
        for (int j = 0; j < n - i; j++) {
            cout << "  ";
        }

        // stars
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}


// * * * * * * * * * * * 
//   * * * * * * * * * 
//     * * * * * * * 
//       * * * * * 
//         * * * 
//           * 