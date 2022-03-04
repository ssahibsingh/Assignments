#include <iostream>
#include <ctime>
using namespace std;

int sf, sn, window_size;

int *sender(int frames[], int sent[], bool canSend, int ack)
{
    if (canSend && ack == 1)
    {
        for (int i = sf; i <= sn; i++)
        {
            cout << "Sender: " << frames[i] << " Frame Sent" << endl;
            sent[i] = frames[i];
        }
        canSend = false;
    }
    else
    {
        sf--;
        sn--;
        for (int i = sf; i <= sn; i++)
        {
            cout << "Sender: " << frames[i] << " Frame Sent" << endl;
            sent[i] = frames[i];
        }
        canSend = false;
    }
    return sent;
}

int receiver(int received[])
{
    cout << "Receiver: " << received[sf] << " Frame Received" << endl;
    sn++;
    sf++;
    return received[sf - 1];
}

clock_t elapsedTime(clock_t start, clock_t end)
{
    return (end - start) / CLOCKS_PER_SEC;
}

int main()
{
    int n, window_size, seconds = 5;
    cout << "Enter total number of frames: ";
    cin >> n;
    cout << "Enter window size: ";
    cin >> window_size;
    int frames[n];
    cout << "Enter frames: ";
    for (int i = 1; i <= n; i++)
        cin >> frames[i];
    cout << endl;

    int ack = 1;
    bool canSend = true;
    int sent[window_size];
    clock_t start, end;
    bool timeout = false;

    sf = 1, sn = window_size;

    int count = 0;
    if (count < n)
    {
        do
        {
            start = clock();
            int *received = sender(frames, sent, canSend, ack);
            int received_frame = receiver(received);
            end = clock();

            if (received_frame == frames[sf - 1] && (elapsedTime(start, end) < seconds))
            {
                cout << "Acknowledgement Received" << endl;
                ack = 1;
                cout << endl;
            }
            else
            {
                ack = 0;
            }
        } while (sn <= n);

        do
        {

            sn--;
            start = clock();
            int *received = sender(frames, sent, canSend, ack);
            int received_frame = receiver(received);
            end = clock();

            if (received_frame == frames[sf - 1] && (elapsedTime(start, end) < seconds))
            {
                cout << "Acknowledgement Received" << endl;
                ack = 1;
                cout << endl;
            }
            else
            {
                ack = 0;
            }

        } while (sf <= n);
        
    }

    return 0;
}