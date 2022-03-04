#include <iostream>
#include <ctime>
using namespace std;

int count = 0;

int sender(int frames[], bool canSend)
{
    cout << "\nEnter Frame: " << endl;
    cin >> frames[count];
    cout << "Frame Sent: " << frames[count];
    canSend = false;
    return frames[count];
}

int receiver(int frame, int ack, bool canSend)
{
    cout << "\t\t\t\tFrame Received: " << frame << endl;
    count++;
    ack = frame;
    canSend = true;
    return ack;
}

clock_t elapsedTime(clock_t start, clock_t end)
{
    return (end - start) / CLOCKS_PER_SEC;
}

int main()
{
    int n;
    float seconds = 0;
    cout << "Enter total number of frames: ";
    cin >> n;
    int frames[n], ack;
    bool canSend = true;

    clock_t start, end;
    cout << "\nSender\t\t\t\t\tReceiver" << endl;
    while (count < n)
    {
        int sentFrame, receivedFrame;
        bool timeout = false;
        if (canSend)
        {
            start = clock();
            sentFrame = sender(frames, canSend);

            end = clock();

            if (elapsedTime(start, end) < seconds)
            {
                ack = receiver(sentFrame, ack, canSend);
            }
            else
            {
                cout << "\nTimeout" << endl;
                timeout = true;
            }
            end = clock();
            if (elapsedTime(start, end) > seconds)
            {
                cout << "Delayed Acknowledgement" << endl;
                count--;
            }
            else if (!timeout)
                cout << "Acknowledgement: " << ack << endl;
        }
    }

    return 0;
}