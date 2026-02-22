#ifndef TV_H
#define TV_H

class TV {
private:
    int itsStation;

public:
    TV();            // default station = 1
    TV(int station); // station constructor

    void SetStation(int station);
    int GetStation() const;

    void channelUp();
    void channelDown();

    void displayStatus() const;
};

#endif
