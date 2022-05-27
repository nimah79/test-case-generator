#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Not enough arguments\n";
        return 1;
    }

    int n = stoi(argv[1]);

    cout << n << '\n';

    for (int i = 3; i <= n; i += 2) {
        cout << i << ' ' << (i - 2) << ' ' << 'R' << '\n';
    }

    cout << "2 1 L\n";
    for (int i = 4; i <= n; i += 2) {
        cout << i << ' ' << (i - 2) << ' ' << 'L' << '\n';
    }
}
