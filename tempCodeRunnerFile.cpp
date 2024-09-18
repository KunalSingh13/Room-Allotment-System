#include <iostream>
#include <conio.h>
#include <cstdio>
#include <string.h>
#include <cstdlib>
using namespace std;

static int p = 0;

class Hotel
{
    char roomnum[10], host[20], start[10], send[10], from[20], to[20], chair[16][8][20];

public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
} room[20];

void vline(char ch)
{
    for (int i = 100; i > 0; i--)
    {
        cout << ch;
    }
}

void Hotel ::install()
{
    cout << "Enter Room Number: \n";
    cin >> room[p].roomnum;
    cout << "Enter Host's Number: \n";
    cin >> room[p].host;
    cout << "Session Start Time: \n";
    cin >> room[p].start;
    cout << "Session End Time: \n";
    cin >> room[p].send;
    cout << "From: \n";
    cin >> room[p].from;
    cout << "To: \n";
    cin >> room[p].to;
    room[p].empty();
    p++;
}

void Hotel ::allotment()
{
    int chair;
    char number[10];
top:
    cout << "Room Number: \n";
    cin >> number;
    int num;
    for (num = 0; num <= p; num++)
    {
        if (strcmp(room[num].roomnum, number) == 0)
            break;
    }

    while (num <= p)
    {
        cout << "\nChair Number: \n";
        cin >> chair;
        if (chair > 32)
        {
            cout << "\nThere are only 32 chair in this Room: \n";
        }
        else
        {
            if (strcmp(room[num].chair[chair / 4][(chair % 4) - 1], "Empty") == 0)
            {
                cout << "Enter Customer's Name: \n";
                cin >> room[num].chair[chair / 4][(chair % 4) - 1];
                break;
            }
            else
            {
                cout << "The Chair number is already reserved.\n";
            }
        }
    }

    if (num > p)
    {
        cout << "Enter correct Room number: \n";
        goto top;
    }
}

void Hotel ::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(room[p].chair[i][j], "Empty");
        }
    }
}

void Hotel ::show()
{
    int num;
    char number[5];
    cout << "Enter Room Number: \n";
    cin >> number;
    for (num = 0; num <= p; num++)
    {
        if (strcmp(room[num].roomnum, number) == 0)
            break;
    }

    while (num <= p)
    {
        vline('*');
        cout << "Room number: \t" << room[num].roomnum << "\nHost: \t" << room[num].host << "\t\tStart Time: \t" << room[num].start << "\t End Time: " << room[num].send << "\nFrom: \t\t" << room[num].from << "\t\tTo: \t\t" << room[num].to << "\n";
        vline('*');
        room[0].position(num);
        int a = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;
                if (strcmp(room[num].chair[i][j], "Empty") != 0)
                    cout << "\nThe Chair number " << (a - 1) << "is resered for " << room[num].chair[i][j] << ".";
            }
        }
        break;
    }
    if (num > p)
        cout << "Enter correct Room Number: ";
}

void Hotel ::position(int l)
{
    int s = 0;
    p = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(room[l].chair[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << room[l].chair[i][j];
            }
        }
    }

    cout << "\n\nThere are " << p << " Chairs empty in Room Number: " << room[l].roomnum;
}

void Hotel ::avail()
{
    for (int num = 0; num < p; num++)
    {
        vline('*');
        cout << "Room number: \t" << room[num].roomnum << "\nHost: \t" << room[num].host << "\t\tStart Time: \t" << room[num].start << "\t End Time: " << room[num].send << "\nFrom: \t\t" << room[num].from << "\t\tTo: \t\t" << room[num].to << "\n";
        vline('*');
        vline('_');
    }
}

int main()
{
    system("cls");
    int w;
    while (1)
    {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t1.Install\n\t\t\t" << "2.Reservation\n\t\t\t" << "3.Show\n\t\t\t" << "4.Rooms Available \n\t\t\t" << "5.Exit";
        cout << "\n\t\t\tEnter your Choice:  ";
        cin >> w;
        switch (w)
        {
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
        }
    }
    return 0;
}