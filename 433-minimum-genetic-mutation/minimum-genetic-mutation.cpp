class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // Initialize the bankSet with elements from the bank vector
        unordered_set<string> bankSet(bank.begin(), bank.end());

        // If the endGene is not in the bank, return -1
        if (bankSet.find(endGene) == bankSet.end()) {
            return -1;
        }

        unordered_set<string> visited; // To track visited genes
        queue<string> que;            // BFS queue

        // Start BFS with the startGene
        que.push(startGene);
        visited.insert(startGene);

        int level = 0; // Tracks the number of mutations

        // BFS traversal
        while (!que.empty()) {
            int n = que.size();

            // Process all nodes at the current level
            while (n--) {
                string curr = que.front();
                que.pop();

                // If we reach the endGene, return the number of mutations
                if (curr == endGene) {
                    return level;
                }

                // Try all possible mutations
                for (int i = 0; i < curr.length(); i++) {
                    string neighbour = curr;

                    // Replace the i-th character with 'A', 'C', 'G', or 'T'
                    for (char ch : "ACGT") {
                        neighbour[i] = ch;

                        // Check if the mutation is valid and not visited
                        if (visited.find(neighbour) == visited.end() && bankSet.find(neighbour) != bankSet.end()) {
                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                    }
                }
            }

            // Increment the mutation count for the next level
            level++;
        }

        // If we exhaust all possibilities and don't find the endGene
        return -1;
    }
};
