#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int arr[maxn];

int main(int argc, char* argv[])
{
    if (argc < 3) {
        cout << "Not enough arguments\n";
        return 1;
    }

    int n = stoi(argv[1]);
    int seed = stoi(argv[2]);

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    shuffle(arr + 1, arr + n, default_random_engine(seed));

    cout << n << '\n';

    for (int i = 1; i < n; i++) {
        cout << arr[i] << ' ' << arr[(i - 1) / 2] << ' ' << ((i % 2) ? 'R' : 'L') << '\n';
    }
}
