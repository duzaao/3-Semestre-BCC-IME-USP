#include <bits/stdc++.h>

using namespace std;

const int DEFAULT = -1;

int distanceTable[100008];
vector<int> indexTable[10];

int main() {
    string inputString;
    cin >> inputString;

    int stringLength = inputString.length();

    for (int i = 0; i < inputString.length(); i++) {
        indexTable[inputString[i] - '0'].push_back(i);
    }

    memset(distanceTable, DEFAULT, sizeof(distanceTable));

    queue<int> bfsQueue;

    bfsQueue.push(0);
    distanceTable[0] = 0;

    while (!bfsQueue.empty()) {
        int current = bfsQueue.front();
        bfsQueue.pop();

        if (current - 1 >= 0 && distanceTable[current - 1] == DEFAULT) {
            distanceTable[current - 1] = distanceTable[current] + 1;
            bfsQueue.push(current - 1);
        }

        if (current + 1 < stringLength && distanceTable[current + 1] == DEFAULT) {
            distanceTable[current + 1] = distanceTable[current] + 1;
            bfsQueue.push(current + 1);
        }

        for (int x : indexTable[inputString[current] - '0']) {
            if (distanceTable[x] == DEFAULT) {
                distanceTable[x] = distanceTable[current] + 1;
                bfsQueue.push(x);
            }
        }

        indexTable[inputString[current] - '0'].clear(); // No need to visit again
    }

    cout << distanceTable[stringLength - 1] << endl;

    return 0;
}
