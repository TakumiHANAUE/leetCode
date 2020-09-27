
// https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1375/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>

using namespace std;

// Normal BFS
class Solution {
    private:
        int m_codeLength = 4;
        set<string> m_deadends;
        string m_target;
    private:
        bool isDeadend(string code) {
            bool isDeadend = false;
            if ( m_deadends.find(code) != m_deadends.end() ) {
                isDeadend = true;
            }
            return isDeadend;
        }
        vector<string> getNeighbors(string code) {
            vector<string> neighbors;
            // if code is not included m_deadends
            if ( isDeadend(code) == true ) {
                return neighbors;
            }
            for ( int i = 0; i < m_codeLength; i++ ) {
                // rotate 0 to 1
                string neighbor1 = code;
                if ( neighbor1[i] == '9' ) {
                    neighbor1[i] = '0';
                }
                else {
                    neighbor1[i] = neighbor1[i] + 1;
                }
                neighbors.push_back(neighbor1);
                // rotate 0 to 9
                string neighbor2 = code;
                if ( neighbor2[i] == '0' ) {
                    neighbor2[i] = '9';
                }
                else {
                    neighbor2[i] = neighbor2[i] - 1;
                }
                neighbors.push_back(neighbor2);
            }
            return neighbors;
        }
    public:
        int openLock(vector<string>& deadends, string target) {
            queue<string> queue;
            set<string> visited;
            // initialize
            int step = -1;
            for ( int i = 0; i < deadends.size(); i++ ) {
                m_deadends.insert(deadends[i]);
            }
            m_target = target;
            queue.push("0000");
            visited.insert("0000");
            // BFS
            while ( queue.size() != 0 ) {
                step = step + 1;
                // iterate the nodes which are already in the queue
                int size = queue.size();
                for ( int i = 0; i < size; i++ ) {
                    string cur = queue.front();
                    // return step if cur is target
                    if ( cur == m_target ) {
                        return step;
                    }
                    vector<string> neighbors = getNeighbors(cur);
                    for ( int i = 0; i < neighbors.size(); i++ ) {
                        // if the neighbor hasn't visited yet
                        if ( visited.find(neighbors[i]) == visited.end() ) {
                            // add next to queue
                            queue.push(neighbors[i]);
                            // add next to visited
                            visited.insert(neighbors[i]);
                        }
                    }
                    // remove the first node from queue
                    queue.pop();
                }
            }
            return -1;
        }
};

// Bidirectional BFS
class Solution2 {

};

int main() {
    Solution s;

    vector<string> deadends;
    string target;

    // Example 1
    deadends = {"0201","0101","0102","1212","2002"};
    target = "0202";
    cout << "Output(ex1) : " << s.openLock(deadends, target) << endl;
    // Example 2
    deadends = {"8888"};
    target = "0009";
    cout << "Output(ex2) : " << s.openLock(deadends, target) << endl;
    // Example 3
    deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    target = "8888";
    cout << "Output(ex3) : " << s.openLock(deadends, target) << endl;
    // Example 4
    deadends = {"0000"};
    target = "8888";
    cout << "Output(ex4) : " << s.openLock(deadends, target) << endl;

}
