#include <bits/stdc++.h>

using namespace std;

// Generate the binary tree using BFS
vector<pair<int, int> > generateBinaryTree(int n)
{
    // Stores number of children a node can have
    vector<int> options = { 0, 1, 2 };

    // Check if a node is already included in the tree or not
    map<int, int> mp;

    // Stores node of tree at each level of the tree
    queue<int> q;

    // Insert root node
    q.push(1);

    // Stores the generated tree
    vector<pair<int, int> > v;

    // Store count of nodes already included
    int count = 1;

    // Marking the inclusion of node 1
    mp[1] = 1;

    // Traverse tree using BFS
    while (!q.empty() or count < n) {

        // Stores from element of queue
        int front;

        if (!q.empty()) {

            // Update front
            front = q.front();

            // Pop front element of queue
            q.pop();
        }

        // If all the nodes are already included
        if (count >= n)
            continue;

        // Find count of child nodes of current node
        int numberOfChilds = options[rand() % (options.size())];

        // Connect child node to the parent node
        while (numberOfChilds--) {

            // Stores value in node which is not already included
            int child = rand() % n + 1;

            // Find the child until found a node that is not yet included
            while (mp[child]) {
                if (++child > n) {
                    child = 1;
                }
            }

            // Update count
            count++;

            // Mark the included node
            mp[child] = 1;

            // Insert it to the generated tree as {parent, child}
            v.push_back({ front, child });

            // Push the child into the queue
            q.push(child);

            // Break if all the nodes are included
            if (count == n)
                break;
        }
    }

    // Shuffle the v vector randomly
    random_shuffle(v.begin(), v.end());

    return v;
}

// Function to print the generated tree
void printTree(int n, vector<pair<int, int> > v)
{
	map<int, char> mp;

    int s = v.size();

    // Number of nodes
    cout << n << "\n";

    // Print n-1 edges as {child, parent}
    for (int i = 0; i < v.size(); i++) {
    	char direction = (rand() % 2) ? 'L' : 'R';
    	if (mp.find(v[i].first) != mp.end())
    		direction = (mp[v[i].first] == 'L') ? 'R' : 'L';
    	else
    		mp[v[i].first] = direction;
        cout << v[i].second << ' ' << v[i].first << ' ' << direction << '\n';
    }
}

// Driver Code
int main(int argc, char* argv[])
{
    if (argc < 3) {
        cout << "Not enough arguments\n";
        return 1;
    }

    int n = stoi(argv[1]);
    int seed = stoi(argv[2]);

    srand(seed);

    // Function Call
    vector<pair<int, int> > v = generateBinaryTree(n);

    // Print the generated tree
    printTree(n, v);
}
