#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter total no of frames to be send:";
    cin >> n;
    if (n > 0)
    {
        int p = 1;
        string r = "";
        while (n--)
        {
            cout << "Enter " << p << " frame:";
            string s;
            cin >> s;
            cout << "Length of frame " << p++ << ":" << s.size()<<"\n\n";
            r = r + s;
        }
            cout << "Recieved frame :" << r << endl;
            cout << "Length of recieved frame :" << r.size() << endl;
    }
    else
    {
        cout << "No frames were send\n";
    }
    return 0;
}