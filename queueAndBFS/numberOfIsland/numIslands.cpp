

// https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1374/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Solution {
    private:
        struct Position {
            int y;
            int x;
        };
        bool alreadyVisited(Position pos, vector<Position>& visited) {
            for (int i = 0; i < visited.size(); i++) {
                if ( visited[i].x == pos.x && visited[i].y == pos.y ) {
                    return true;
                }
            }
            return false;
        };
    public:
        Solution(){};
        ~Solution(){};
        int numIslands(vector<vector<char>>& grid) {
            int num = 0;
            int ymax = grid.size();
            if ( ymax == 0 ) {
                return 0;
            }
            int xmax = grid[0].size();
            if ( xmax == 0 ) {
                return 0;
            }
            vector<Position> islands;
            for (int y = 0; y < ymax; y++ ) {
                for (int x = 0; x < xmax; x++) {
                    if ( grid[y][x] == '1' ) {
                        Position root = {y, x};
                        if ( alreadyVisited(root, islands) == false ) {
                            queue<Position> queue;
                            vector<Position> visited;
                            // initialize
                            int step = 0;
                            queue.push(root);
                            visited.push_back(root);
                            // BFS
                            while (queue.size() != 0) {
                                step = step + 1;
                                // iterate the node which are already in the queue
                                int size = queue.size();
                                for (int i = 0; i < size; i++) {
                                    Position cur = queue.front();
                                    // iterate neighbors
                                    {
                                        if ( (cur.x + 1) < xmax ) {
                                            if (grid[cur.y][cur.x + 1] == '1' ) {
                                                Position right = {cur.y, cur.x + 1};
                                                if ( alreadyVisited(right, visited) == false ) {
                                                    queue.push(right);
                                                    visited.push_back(right);
                                                }
                                            }
                                        }
                                        if ( (cur.x - 1) >= 0 ) {
                                            if (grid[cur.y][cur.x - 1] == '1' ) {
                                                Position left = {cur.y, cur.x - 1};
                                                if ( alreadyVisited(left, visited) == false ) {
                                                    queue.push(left);
                                                    visited.push_back(left);
                                                }
                                            }
                                        }
                                        if ( (cur.y + 1) < ymax ) {
                                            if ( grid[cur.y + 1][cur.x] == '1' ) {
                                                Position down = {cur.y + 1, cur.x};
                                                if ( alreadyVisited(down, visited) == false ) {
                                                    queue.push(down);
                                                    visited.push_back(down);
                                                }
                                            }
                                        }
                                        if ( (cur.y - 1) >= 0 ) {
                                            if ( grid[cur.y - 1][cur.x] == '1' ) {
                                                Position up = {cur.y - 1, cur.x};
                                                if ( alreadyVisited(up, visited) == false ) {
                                                    queue.push(up);
                                                    visited.push_back(up);
                                                }
                                            }
                                        }
                                        // remove the first node from queue
                                        queue.pop();
                                    }
                                }
                            }
                            if ( visited.size() > 0 ) {
                                num++;
                                islands.insert(islands.end(), visited.begin(), visited.end());
                            }
                        }
                    }
                }
            }
            return num;
        };
};


int main() {
    vector<vector<char>> ex1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    vector<vector<char>> ex2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    vector<vector<char>> ex3 = {
        {'1','1','0','1','1'},
        {'1','1','0','0','1'},
        {'0','0','1','0','1'},
        {'0','0','0','1','1'}
    };

    vector<vector<char>> ex4 = {
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'}
    };

    Solution sol;

    cout << "Number of Islands(ex1) : " << sol.numIslands(ex1) << endl;
    cout << "Number of Islands(ex2) : " << sol.numIslands(ex2) << endl;
    cout << "Number of Islands(ex3) : " << sol.numIslands(ex3) << endl;
    cout << "Number of Islands(ex4) : " << sol.numIslands(ex4) << endl;

}
