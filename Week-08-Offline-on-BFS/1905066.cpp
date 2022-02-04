#include <iostream>
#include <cstdio>
#include <queue>

int dis[10001], parent[10001], cell_connection[1001];


// Breadth First Search
// This will visit every reachable cell from src
// and update its distance and parent
// src  - starting position
// x    - total cells
// n    - faces of the dice
void bfs(int src, int x, int n)
{

    for (int i = 1; i <= x; i++) dis[i] = parent[i] = -1;

    std::queue<int> q;
    q.push(src);
    dis[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        //std::cout<<u<<std::endl;
        
        for (int v = u + 1; v<=x && v-u<=n; v++)
        {
            // If this cell has not been visited before
            if (dis[v] == -1)
            {
                //std::cout<<v<<std::endl;
                dis[v] = dis[u] + 1;
                parent[v] = u;

                // If cell 'v' does not have a starting point of a ladder or snake
                if (cell_connection[v] == 0) q.push(v); 
                
                else
                {
                    int startPoint = v, endPoint = cell_connection[v];
                    
                    // Until there is a cell with no starting point of ladder or snake
                    // (End of consecutive laddar/snake)
                    while (endPoint != 0 && dis[endPoint] == -1) 
                    {
                        parent[endPoint] = startPoint;
                        dis[endPoint] = dis[u] + 1;
                        startPoint = endPoint;
                        endPoint = cell_connection[startPoint];
                    }

                    // checking for loop
                    if(cell_connection[startPoint] == 0) q.push(startPoint);
                }
            }
        }
    }
}

// Recursively getting the parent cell till the start
// and then print them
void printPath(int child)
{
    if (parent[child] == -1)
    {
        std::cout << child;
        return;
    }

    printPath(parent[child]);
    std::cout << " -> " << child;
}

int main()
{

    freopen("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    
    int t, n, x, l, s, i, a, b;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> x;
        for (i = 1; i <= x; i++) cell_connection[i] = 0;

        std::cin >> l;
        for (i = 0; i < l; i++)
        {
            std::cin >> a >> b;
            cell_connection[a] = b;
        }

        std::cin >> s;
        for (i = 0; i < s; i++)
        {
            std::cin >> a >> b;
            cell_connection[a] = b;
        }

        // Caling Breadth-First Search from cell 1
        bfs(1, x, n);
        
        
        // Distance of cell x from cell 1
        // -1 if it is unreachable
        std::cout << dis[x] << std::endl;
        if (dis[x] == -1) std::cout << "No solution" << std::endl;
        else
        {
            printPath(x);
            std::cout << std::endl;   
        }


        // Unreachable cells
        bool all_reachable = true;
        for (int i = 1; i <= x; i++)
        {
            if (dis[i] == -1)
            {
                std::cout << i << " ";
                all_reachable = false;
            }
        }
        if (all_reachable) std::cout << "All reachable";
        std::cout << std::endl;

    }

    return 0;
}
