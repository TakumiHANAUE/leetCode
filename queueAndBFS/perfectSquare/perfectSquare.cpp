// https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1371/

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
    private:
        struct TermSum {
            int termSqrt;
            int sum;
        };
    private:
        int getMaximumSquareNumLessEqual(int n) {
            return int(sqrt(double(n)));
        }
    public:
        int numSquares(int n) {
            int root_max = getMaximumSquareNumLessEqual(n);
            queue<TermSum> queue;
            // initialize
            int step = 0;
            for ( int root = root_max; root > 0; root-- )
            {
                queue.push({root, root * root});
            }
            // BFS
            while ( !queue.empty() ) {
                step = step + 1;
                // iterate the nodes which are already in the queue
                int size = queue.size();
                for ( int i = 0; i < size; i++ ) {
                    TermSum cur = queue.front();
                    // return step if cur is target
                    if ( cur.sum == n ) {
                        return step;
                    }
                    for ( int i = cur.termSqrt; i > 0; i-- ) {
                        int nextSum = cur.sum + i * i;
                        if ( nextSum == n ) {
                            return step + 1;
                        }
                        else if ( nextSum < n ) {
                            queue.push({i, nextSum});
                        }

                    }
                    // remove the first node from queue
                    queue.pop();
                }
            }
            return -1;
        }
};

int main() {

    Solution s;

    cout << "Output(ex1) : " << s.numSquares(12) << endl;
    cout << "Output(ex2) : " << s.numSquares(13) << endl;

    return 0;
}
