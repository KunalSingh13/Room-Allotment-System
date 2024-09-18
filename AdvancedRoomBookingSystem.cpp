#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

static int p = 0;

class Hotel {
    char roomnum[5], host[10], start[5], send[5], from[10], to[10], chair[8][4][10];

public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
} room[20];

void vline(char ch) {
    for (int i = 80; i > 0; i--) {
        cout << ch;
    }
    cout << endl;
}

void Hotel::install() {
    cout << "Enter Room Number: ";
    cin >> room[p].roomnum;
    cout << "Enter Host's Name: ";
    cin >> room[p].host;
    cout << "Session Start Time: ";
    cin >> room[p].start;
    cout << "Session End Time: ";
    cin >> room[p].send;
    cout << "From: ";
    cin >> room[p].from;
    cout << "To: ";
    cin >> room[p].to;
    room[p].empty();
    p++;
}

void Hotel::allotment() {
    int chairNum;
    char number[5];
    cout << "Enter Room Number: ";
    cin >> number;
    int num;
    for (num = 0; num < p; num++) {
        if (strcmp(room[num].roomnum, number) == 0)
            break;
    }

    if (num == p) {
        cout << "Room number not found.\n";
        return;
    }

    while (true) {
        cout << "\nEnter Chair Number (1-32): ";
        cin >> chairNum;
        if (chairNum < 1 || chairNum > 32) {
            cout << "Invalid chair number. There are only 32 chairs in this room.\n";
        } else {
            int row = (chairNum - 1) / 4;
            int col = (chairNum - 1) % 4;
            if (strcmp(room[num].chair[row][col], "Empty") == 0) {
                cout << "Enter Customer's Name: ";
                cin >> room[num].chair[row][col];
                break;
            } else {
                cout << "The chair is already reserved.\n";
            }
        }
    }
}

void Hotel::empty() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(room[p].chair[i][j], "Empty");
        }
    }
}

void Hotel::show() {
    char number[5];
    cout << "Enter Room Number: ";
    cin >> number;
    int num;
    for (num = 0; num < p; num++) {
        if (strcmp(room[num].roomnum, number) == 0)
            break;
    }

    if (num == p) {
        cout << "Room number not found.\n";
        return;
    }

    vline('*');
    cout << "Room number: " << room[num].roomnum << "\nHost: " << room[num].host
         << "\nStart Time: " << room[num].start << "\tEnd Time: " << room[num].send
         << "\nFrom: " << room[num].from << "\tTo: " << room[num].to << "\n";
    vline('*');
    room[num].position(num);

    int a = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            if (strcmp(room[num].chair[i][j], "Empty") != 0) {
                cout << "\nChair number " << a << " is reserved for " << room[num].chair[i][j] << ".";
            }
            a++;
        }
    }
    cout << endl;
}

void Hotel::position(int l) {
    int s = 1, emptyCount = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            cout.width(5);
            cout.fill(' ');
            cout << s << ".";
            cout.width(10);
            cout.fill(' ');
            cout << room[l].chair[i][j];
            if (strcmp(room[l].chair[i][j], "Empty") == 0)
                emptyCount++;
            s++;
        }
        cout << endl;
    }
    cout << "\n\nThere are " << emptyCount << " chairs empty in Room Number: " << room[l].roomnum << endl;
}

void Hotel::avail() {
    for (int num = 0; num < p; num++) {
        vline('*');
        cout << "Room number: " << room[num].roomnum << "\nHost: " << room[num].host
             << "\nStart Time: " << room[num].start << "\tEnd Time: " << room[num].send
             << "\nFrom: " << room[num].from << "\tTo: " << room[num].to << "\n";
        vline('*');
        vline('_');
    }
}

int main() {
    system("cls");
    int w;
    while (true) {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t1. Install\n\t\t\t2. Reservation\n\t\t\t3. Show\n\t\t\t4. Rooms Available\n\t\t\t5. Exit";
        cout << "\n\t\t\tEnter your Choice: ";
        cin >> w;
        switch (w) {
            case 1:
                room[p].install();
                break;
            case 2:
                room[p].allotment();
                break;
            case 3:
                room[p].show();
                break;
            case 4:
                room[p].avail();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}
