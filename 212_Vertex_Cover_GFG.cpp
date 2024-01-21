#include<iostream>
#include<vector>
using namespace std;

 int vertexCover(int num_nodes, vector<pair<int, int>> &edges) {
    if (num_nodes == 0) {
        return 0;
    }
    // 👉 Initialize separate vectors for edges connected to two different vertices.
    vector<pair<int, int>> first_vertex_edges, second_vertex_edges;

    // 👉 Get the first edge to compare with other edges.
    int first_vertex = edges[0].first;
    int second_vertex = edges[0].second;
    int count_first_vertex = 0, count_second_vertex = 0;

    // 👉 Iterate through the edges to categorize them based on their vertices.
    for ( auto edge : edges) {
        int vertex1 = edge.first;
        int vertex2 = edge.second;

        // 👉 Check if the current edge is not connected to the first vertex.
        if (!(vertex1 == first_vertex || vertex2 == first_vertex)) {
            first_vertex_edges.push_back({vertex1, vertex2});
            count_first_vertex++;
        }

        // 👉 Check if the current edge is not connected to the second vertex.
        if (!(vertex1 == second_vertex || vertex2 == second_vertex)) {
            second_vertex_edges.push_back({vertex1, vertex2});
            count_second_vertex++;
        }
    }

    // 👉 Recursively find the minimum vertex cover size for both sets of edges.
    return 1 + min(
        vertexCover(count_first_vertex, first_vertex_edges),
        vertexCover(count_second_vertex, second_vertex_edges)
    );
}


// ⏲️ Expected Time Complexity: O(M*2N)
// 🛢️ Expected Auxiliary Space: O(N2)


int main()
{
    int N=5;
    vector<pair<int, int>> edges ={ {1,2},
                                    {4, 1},
                                    {2, 4},
                                    {3, 4},
                                    {5, 2},
                                    {1, 3}};
    int ans = vertexCover(N,edges);
    cout<< "ans is : " << ans << endl;                            
    return 0;
}
