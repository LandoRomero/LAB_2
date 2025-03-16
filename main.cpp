#include <iostream>
#include <iomanip>
using namespace std;

enum MenuOption { ADD_SERIES = 1, SQUARE_SUM = 2, QUIT = 3 };

void addSeriesRecursive(int n, int term, double sum) {
    if(term > n) {
        cout << "=" << fixed << setprecision(4) << sum;
        return;
    }
    if(term == 1) {
        cout << "1";
        sum += 1.0;
    } else {
        cout << "+1/(" << (term - 1) << "+" << term << ")";
        sum += 1.0 / ((term - 1) + term);
    }
    addSeriesRecursive(n, term + 1, sum);
}

void squareSumRecursive(int current, int sum) {
    if(current == 0) {
        cout << "=" << sum;
        return;
    }
    if(current == 1) {
        cout << "1";
        sum += 1;
    } else {
        cout << "(" << current << "*" << current << ")+";
        sum += current * current;
    }
    squareSumRecursive(current - 1, sum);
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add series: \n";
        cout << "2. Sum of squares series: \n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(static_cast<MenuOption>(choice)) {
            case ADD_SERIES: {
                int n;
                cout << "Enter number of terms (above zero): ";
                cin >> n;
                if(n <= 0) {
                    cout << "Error: Number must be above zero.\n";
                } else {
                    cout << "Series: ";
                    addSeriesRecursive(n, 1, 0.0);
                    cout << "\n";
                }
                break;
            }
            case SQUARE_SUM: {
                int n;
                cout << "Enter number of terms (above zero): ";
                cin >> n;
                if(n <= 0) {
                    cout << "Error: Number must be above zero.\n";
                } else {
                    cout << "Series: ";
                    squareSumRecursive(n, 0);
                    cout << "\n";
                }
                break;
            }
            case QUIT:
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while(choice != QUIT);

    return 0;
}
