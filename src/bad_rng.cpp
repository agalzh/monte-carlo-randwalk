#include <iostream>
#include <fstream>
#include <random>
#include <vector>
using namespace std;

int main()
{
    const int W = 800;
    const int H = 800;

    vector<unsigned char> img(W * H * 3, 255);

    // randomizer not used...
    //  random_device rd;
    //  mt19937 gen(rd());
    //  uniform_int_distribution<int> dir(0, 3);

    int x = W / 2;
    int y = H / 2;

    int steps = 50000;
    int walkers = 30000;

    unsigned int seed = 1;

    for (int i = 1; i <= walkers; i++)
    {
        for (int j = 1; j <= steps; j++)
        {
            seed = seed * 1103515245u + 12345u;
            int r = int((seed >> 16) & 3u);

            if (r == 0)
                x++;
            if (r == 1)
                x--;
            if (r == 2)
                y++;
            if (r == 3)
                y--;

            if (x < 0)
                x = 0;
            if (x >= W)
                x = W - 1;
            if (y < 0)
                y = 0;
            if (y >= H)
                y = H - 1;
        }

        int idx = (y * W + x) * 3;
        img[idx + 0] = 0;
        img[idx + 1] = 0;
        img[idx + 2] = 0;

        if (i % 100 == 0)
        {
            cerr << "[INFO] " << "Walkers ran: " << i << " out of " << walkers << " " << (double(i) / double(walkers)) * 100 << "%\n";
        }

        x = W / 2;
        y = H / 2;
    }

    ofstream out("bad_walk.ppm", ios::binary);
    out << "P6\n"
        << W << " " << H << "\n255\n";
    out.write((char *)img.data(), img.size());
    out.close();

    cout << "Saved bad_walk.ppm\n";
    return 0;
}
