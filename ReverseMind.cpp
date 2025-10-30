#include <iostream>
using namespace std;

int main() {
    cout << "Reverse Mind Program" << endl;
    cout << "Think of a number between 1 and 100" << endl;
    cout << "Answer with: " << endl;
    cout << "1 - My number is higher" << endl;
    cout << "2 - My number is lower" << endl;
    cout << "3 - That's correct!" << endl;
    
    int low = 1;
    int high = 100;
    int guess;
    int response;
    
    do {
        guess = (low + high) / 2;
        cout << "\nIs your number " << guess << "? ";
        cin >> response;
        
        if (response == 1) {  // Number is higher
            low = guess + 1;
        } else if (response == 2) {  // Number is lower
            high = guess - 1;
        }
        
    } while (response != 3);
    
    cout << "Great! I guessed your number: " << guess << endl;
    
    return 0;
}