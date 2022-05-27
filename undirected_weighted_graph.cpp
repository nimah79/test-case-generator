#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 4) {
        cout << "Not enough arguments\n";
        return 1;
    }

    const int NODES_COUNT = stoi(argv[1]);
    const int EDGES_COUNT = stoi(argv[2]);
    const int MAX_EDGE_WEIGHT = stoi(argv[3]);

    if (EDGES_COUNT > NODES_COUNT * (NODES_COUNT - 1) / 2) {
        cout << "Invalid edges count "
             << EDGES_COUNT
             << " for "
             << NODES_COUNT
             << " nodes. Maximum count of edges for "
             << NODES_COUNT
             << " nodes can be "
             << (NODES_COUNT * (NODES_COUNT - 1) / 2)
             << ".\n";
        return 1;
    }

    set<pair<int, int> > container;

    // Uncomment the below line to store the test data in a file
    // freopen("input.txt", "w", stdout);

    srand(time(NULL));

    cout << NODES_COUNT << ' ' << EDGES_COUNT << '\n';

    // Print the edges of the form (a b) where 'a' is connected to 'b'
    for (int j = 1; j <= EDGES_COUNT; j++) {
        int a = rand() % NODES_COUNT;
        int b = rand() % NODES_COUNT;
        pair<int, int> p = { a, b };
        pair<int, int> reverse_p = { b, a };
        // Search for a random "new" edge everytime
        // Note - In a tree the edge (a, b) is same
        // as the edge (b, a)
        while (container.find(p) != container.end() || container.find(reverse_p) != container.end()) {
            a = rand() % NODES_COUNT;
            b = rand() % NODES_COUNT;
            p = { a, b };
            reverse_p = { b, a };
        }
        container.insert(p);
    }
    for (auto it = container.begin(); it != container.end(); ++it) {
        int wt = 1 + rand() % MAX_EDGE_WEIGHT;
        cout << (it->first + 1) << ' ' << (it->second + 1) << ' ' << wt << '\n';
    }

    // Uncomment the below line to store the test data in a file
    // fclose(stdout);
}
