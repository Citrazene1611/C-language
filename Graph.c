#include <stdio.h>

#define MAX 10
#define INF 99999

int graph[MAX][MAX];
int n;

void BFS(int start)
{
    int queue[MAX];
    int visited[MAX] = {0};
    int front = 0, rear = 0;
    int i, v;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");

    while(front < rear)
    {
        v = queue[front++];

        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(graph[v][i] != 0 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

void DFSUtil(int v, int visited[])
{
    int i;

    visited[v] = 1;

    printf("%d ", v);

    for(i = 0; i < n; i++)
    {
        if(graph[v][i] != 0 && !visited[i])
            DFSUtil(i, visited);
    }
}

void DFS(int start)
{
    int visited[MAX] = {0};

    printf("DFS: ");

    DFSUtil(start, visited);

    printf("\n");
}

void primMST()
{
    int selected[MAX] = {0};
    int edges = 0;
    int min, x = 0, y = 0;
    int i, j;
    int cost = 0;

    selected[0] = 1;

    printf("\nMinimum Cost Spanning Tree:\n");

    while(edges < n-1)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(selected[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!selected[j] &&
                       graph[i][j] &&
                       graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, min);

        cost += min;
        selected[y] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", cost);
}

void dijkstra(int source)
{
    int distance[MAX];
    int visited[MAX] = {0};
    int i, j, min, next;

    for(i = 0; i < n; i++)
        distance[i] = INF;

    distance[source] = 0;

    for(i = 0; i < n-1; i++)
    {
        min = INF;
        next = -1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && distance[j] < min)
            {
                min = distance[j];
                next = j;
            }
        }

        if(next == -1)
            break;

        visited[next] = 1;

        for(j = 0; j < n; j++)
        {
            if(graph[next][j] != 0 &&
               !visited[j] &&
               distance[next] + graph[next][j] < distance[j])
            {
                distance[j] =
                    distance[next] + graph[next][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for(i = 0; i < n; i++)
        printf("%d -> %d = %d\n",
               source, i, distance[i]);
}

int main()
{
    int i, j;

    n = 5;

    /* Weighted graph */
    int temp[MAX][MAX] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            graph[i][j] = temp[i][j];

    BFS(0);

    DFS(0);

    primMST();

    dijkstra(0);

    return 0;
}