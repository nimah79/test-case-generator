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

    for (int i = 2; i <= n; i++) {
        cout << i << ' ' << (i - 1) << ' ' << 'R' << '\n';
    }
}
