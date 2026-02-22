#include "TV.h"
#include <iostream>

TV::TV() : itsStation(1) {}

TV::TV(int station) : itsStation(1) {
    SetStation(station);
}

void TV::SetStation(int station) {
    if (station >= 1 && station <= 999) {
        itsStation = station;
    }
    // else ignore invalid request (keep current station valid)
}

int TV::GetStation() const {
    return itsStation;
}

void TV::channelUp() {
    if (itsStation < 999) itsStation++;
}

void TV::channelDown() {
    if (itsStation > 1) itsStation--;
}

void TV::displayStatus() const {
    std::cout << "TV is on station " << itsStation << "\n";
}
