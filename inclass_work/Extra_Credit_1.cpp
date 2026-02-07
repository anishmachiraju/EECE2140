#include <iostream>
using namespace std;

void A1_countUp() {
    int i = 1;
    while (i <= 10) {
        cout << i << " ";
        i++;
    }
    cout << "\n";
}

void A2_countDown() {
    int i = 10;
    while (i >= 1) {
        cout << i << " ";
        --i;
    }
    cout << "\n";
}

void A3_evenNumbers() {
    int i = 2;
    do {
        cout << i << " ";
        i += 2;
    } while (i <= 20);
    cout << "\n";
}

void A4_countdownLaunch() {
    int i = 5;
    do {
        cout << i << " ";
        i--;
    } while (i >= 1);
    cout << "\n";
}

void A5_sumUntil0() {
    int x, sum = 0;
    cout << "Enter integers for Task 5 (0 to stop): ";
    cin >> x;
    while (x != 0) {
        sum += x;
        cin >> x;
    }
    cout << "Sum = " << sum << "\n";
}

void A6_multiplesOf3() {
    int i = 3;
    while (i <= 60) {
        cout << i << " ";
        i += 3;
    }
    cout << "\n";
}

void A7_tracePostIncrement() {
    int i = 0;
    while (i < 5) {
        cout << i++ << " ";
    }
    cout << "\n";
}

void A8_reverseOdds() {
    int i = 19;
    do {
        cout << i << " ";
        i -= 2;
    } while (i >= 1);
    cout << "\n";
}

void A9_digitsRightToLeft() {
    int n;
    cout << "Enter a positive integer for Task 9: ";
    cin >> n;

    while (n > 0) {
        cout << (n % 10) << " ";
        n /= 10;
    }
    cout << "\n";
}

void A10_controlledGrowth() {
    int n = 1;
    while (n <= 100) {
        cout << n << " ";
        n *= 2;
    }
    cout << "\n";
}

void Bug1_fixed() {
    cout << "[Bug 1] What was wrong: i was never updated, so the loop never ends.\n";
    int i = 1;
    while (i <= 10) {
        cout << i << "\n";
        i++;
    }
}

void Bug2_fixed() {
    cout << "[Bug 2] What was wrong: loop condition was incorrect, so it never ran.\n";
    int i = 10;
    while (i >= 1) {
        cout << i << " ";
        i--;
    }
    cout << "\n";
}

void Bug3_fixed() {
    cout << "[Bug 3] What was wrong: pre-increment in the condition and no proper update inside.\n";
    int i = 1;
    while (i <= 5) {
        cout << i << " ";
        i++;
    }
    cout << "\n";
}

void Bug4_fixed() {
    cout << "[Bug 4] What was wrong: condition printed one extra value (included 5).\n";
    int i = 0;
    do {
        cout << i << " ";
        i++;
    } while (i < 5);
    cout << "\n";
}

void Bug5_fixed() {
    cout << "[Bug 5] What was wrong: starting value didn't satisfy the loop condition.\n";
    int i = 5;
    while (i > 0) {
        cout << i << "\n";
        i--;
    }
}

void Bug6_fixed() {
    cout << "[Bug 6] What was wrong: i increased twice per loop, so it skipped values.\n";
    int i = 0;
    while (i < 10) {
        cout << i << " ";
        i++;
    }
    cout << "\n";
}

void Bug7_fixed() {
    cout << "[Bug 7] What was wrong: do-while structure/syntax was incorrect.\n";
    int i = 1;
    do {
        cout << i << " ";
        i++;
    } while (i <= 10);
    cout << "\n";
}

void Bug8_fixed() {
    cout << "[Bug 8] What was wrong: input/loop control needed to stop exactly when 0 is entered.\n";
    int x = 0, sum = 0;
    do {
        cout << "Enter a number for Bug 8 (0 to stop): ";
        cin >> x;
        sum += x;
    } while (x != 0);

    cout << "Sum (excluding 0) = " << sum << "\n";
}

void Bug9_fixed() {
    cout << "[Bug 9] What was wrong: decrement statement was invalid/incorrect.\n";
    int i = 5;
    while (i >= 0) {
        cout << i << " ";
        i--;
    }
    cout << "\n";
}

void Bug10_fixed() {
    cout << "[Bug 10] What was wrong: i was not initialized (undefined behavior).\n";
    int i = 0;
    while (i < 5) {
        cout << i << "\n";
        i++;
    }
}

int main() {
    cout << "=== Part A: Practice ===\n";
    cout << "1) Counting Up:\n"; A1_countUp();
    cout << "2) Counting Down:\n"; A2_countDown();
    cout << "3) Even Numbers:\n"; A3_evenNumbers();
    cout << "4) Countdown Launch:\n"; A4_countdownLaunch();
    cout << "5) Sum Until 0:\n"; A5_sumUntil0();
    cout << "6) Multiples of 3:\n"; A6_multiplesOf3();
    cout << "7) Trace the Post-Increment:\n"; A7_tracePostIncrement();
    cout << "8) Reverse Odds:\n"; A8_reverseOdds();
    cout << "9) Digits of a Number:\n"; A9_digitsRightToLeft();
    cout << "10) Controlled Growth:\n"; A10_controlledGrowth();

    cout << "\n=== Part B: Fix-the-Bug (Fixed + Explanation) ===\n";
    Bug1_fixed();  cout << "\n";
    Bug2_fixed();  cout << "\n";
    Bug3_fixed();  cout << "\n";
    Bug4_fixed();  cout << "\n";
    Bug5_fixed();  cout << "\n";
    Bug6_fixed();  cout << "\n";
    Bug7_fixed();  cout << "\n";
    Bug8_fixed();  cout << "\n";
    Bug9_fixed();  cout << "\n";
    Bug10_fixed(); cout << "\n";

    return 0;
}
