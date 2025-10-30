#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "🧠 Reverse Mind – Guessing Game\n";
    cout << "Think of a number between 1 and 100.\n";
    cout << "Respond with:\n";
    cout << " 1 → My number is higher\n";
    cout << " 2 → My number is lower\n";
    cout << " 3 → Correct!\n\n";

    int low = 1, high = 100, guess, response;

    while (low <= high) {
        guess = low + (high - low) / 2;
        cout << "❓ Is your number " << guess << "? ";
        cin >> response;

        if (response == 1)
            low = guess + 1;
        else if (response == 2)
            high = guess - 1;
        else if (response == 3) {
            cout << "\n🎯 Great! I guessed your number: " << guess << "\n";
            return 0;
        } else
            cout << "⚠️ Invalid input! Please enter 1, 2, or 3.\n";
    }

    cout << "\n🤔 Your answers were inconsistent! Try again.\n";
    return 0;
}