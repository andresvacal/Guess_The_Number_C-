#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& numbers, int target) {
    int low = 0;
    int high = numbers.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (numbers[mid] == target) {
            return mid;
        } else if (numbers[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Not found
}

void playGame(int range) {
    // Create a vector with possible numbers
    vector<int> numbers;
    for (int i = 1; i <= range; ++i) {
        numbers.push_back(i);
    }

    cout << "Think of a number between 1 and " << range << "." << endl;

    int guess;
    int attempts = 0;
    do {
        // Display possible numbers
        cout << "Possible numbers: ";
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;

        // Ask the user if the number is greater, less, or equal to the middle element
        cout << "Is your number greater (1), less (2), or equal (3) to " << numbers[numbers.size() / 2] << "? ";
        cin >> guess;
        attempts++;

        if (guess == 1) {
            // Discard the lower half
            numbers.erase(numbers.begin(), numbers.begin() + numbers.size() / 2 + 1);
        } else if (guess == 2) {
            // Discard the upper half
            numbers.erase(numbers.begin() + numbers.size() / 2, numbers.end());
        }
    } while (guess != 0);

    // Display the guessed number and the number of attempts
    cout << "Your number is: " << numbers[0] << endl;
    cout << "Number of attempts: " << attempts << endl;
}

int main() {
    int choice;
    cout << "Choose the range of the number:" << endl;
    cout << "1. 1 to 100" << endl;
    cout << "2. 1 to 1000" << endl;
    cout << "3. 1 to 10000" << endl;
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> choice;

    int range;
    switch (choice) {
        case 1:
            range = 100;
            break;
        case 2:
            range = 1000;
            break;
        case 3:
            range = 10000;
            break;
        default:
            cout << "Invalid choice. Exiting." << endl;
            return 1;
    }

    playGame(range);

    return 0;
}
