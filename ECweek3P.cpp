//Erika Coreth Project 3
#include <iostream>
#include <string>
using namespace std;

class FSA {
private:
    // STATES
    // Start: Beginning of input
    // A1: Saw 1 'a' in a row
    // A2: Saw 2 'a's in a row
    // B1: Saw 1 'b' in a row
    // B2: Saw 2 'b's in a row
    // Accept: Found 'aaa' or 'bbb'
    // Reject: Invalid input (e.g., not a, b, or c)
    enum State { Start, A1, A2, B1, B2, Accept, Reject };
    State currentState;
    int charCount = 0; // total number of characters seen

public:
    // constructor: start in the Start state
    FSA() {
        currentState = Start;
    }

    // this function reads one char at a time and updates the state
    void ProcessChar(char c) {
        charCount++;  // track how many letters we've read
        switch (currentState) {
            case Start:
                if (c == 'a') currentState = A1;       // saw 1 'a'
                else if (c == 'b') currentState = B1;  // saw 1 'b'
                else if (c == 'c') currentState = Start; // 'c' resets the sequence
                else currentState = Reject;            // invalid character
                break;
            case A1:
                if (c == 'a') currentState = A2;       // now 2 'a's in a row
                else if (c == 'b') currentState = B1;  // switch to tracking 'b'
                else if (c == 'c') currentState = Start;
                else currentState = Reject;
                break;
            case A2:
                if (c == 'a') currentState = Accept;   // 3 'a's in a row!
                else if (c == 'b') currentState = B1;
                else if (c == 'c') currentState = Start;
                else currentState = Reject;
                break;
            case B1:
                if (c == 'b') currentState = B2;       // now 2 'b's in a row
                else if (c == 'a') currentState = A1;  // switch to tracking 'a'
                else if (c == 'c') currentState = Start;
                else currentState = Reject;
                break;
            case B2:
                if (c == 'b') currentState = Accept;   // 3 'b's in a row!
                else if (c == 'a') currentState = A1;
                else if (c == 'c') currentState = Start;
                else currentState = Reject;
                break;
            case Accept:
                // stay here — we've already accepted
                break;
            case Reject:
                // stay here — invalid input
                break;
        }
    }

    // check final result: did we find 'aaa' or 'bbb' AND have at least 3 chars total?
    bool IsAccepted() {
        return currentState == Accept && charCount >= 3;
    }
};
int main() {
    string input;
    cout << "Enter a string over the alphabet {a, b, c}: ";//character output
    cin >> input;//character input from user

    FSA fsa;

    // loop through each character and process it
    for (char c : input) {
        fsa.ProcessChar(c);
    }

    // final decision
    if (fsa.IsAccepted()) {
        cout << "Accepted: The string contains 'aaa' or 'bbb' and is at least 3 characters long.\n";
    } else {
        cout << "Rejected: Does not meet the conditions.\n";
    }

    return 0;
}
