#include <iostream>
#include <array>
#include <queue>
#include <exception>

class Graph {
    public:
        Graph() = default;
        Graph(size_t num_of_verticies)
        {
            this->num_of_verticies = num_of_verticies;
            graph = adjacent_list(num_of_verticies);
        };
        ~Graph() = default;

        void new_edge(size_t start_node, size_t end_node)
        {
            graph[start_node].push_back(end_node);
        };

        size_t size()
        {
            return num_of_verticies;
        };

        auto& structure()
        {
            return graph;
        };

        std::vector<size_t> adjacent_verticies(size_t node) {
            return graph[node];
        };

    private:
        using adjacent_list = std::vector<std::vector<size_t>>;
        size_t num_of_verticies;
        adjacent_list graph;
};

void print_node(size_t node)
{
    std::cout << node << "\n";
};

void bfs(Graph& graph, size_t source)
{
    if (!graph.size()) {
        throw std::invalid_argument("Empty graph is given.");
    }

    auto visited_verticies = std::vector<bool>(graph.size(), false);
    auto queue = std::queue<size_t>();

    queue.push(source);
    visited_verticies[source] = true;

    while (!queue.empty()) {
        auto node = queue.front();
        queue.pop();
        print_node(node);

        for (const auto& adjecent_vertex : graph.adjacent_verticies(node)) {
            if (!visited_verticies[adjecent_vertex]) {
                visited_verticies[adjecent_vertex] = true;
                queue.push(adjecent_vertex);
            }
        }
    }
};


// Iterative implementation
void dfs(Graph& graph, size_t source, std::vector<bool>& visited_verticies)
{
    auto explored_path = std::vector<size_t>();
    explored_path.push_back(source);

    while (!explored_path.empty()) {
        auto current_node = explored_path.back();
        explored_path.pop_back();

        if (visited_verticies[current_node]) {
            continue;
        }

        print_node(current_node);
        visited_verticies[current_node] = true;


        for (auto node_number = graph.adjacent_verticies(current_node).begin();
                node_number != graph.adjacent_verticies(current_node).end();
                ++node_number) {
            if (!visited_verticies[*node_number]) {
                explored_path.push_back(*node_number);
            }
        }
    }
};

void iterative_dfs(Graph& graph)
{
    auto visited_verticies = std::vector<bool>(graph.size(), false);
    for (size_t node = 0; node < graph.size(); ++node) {
        dfs(graph, node, visited_verticies);
    }
}

void dfs_on_steroids(Graph& graph, size_t source)
{
    if (!graph.size()) {
        throw std::invalid_argument("Empty graph is given.");
    }

    auto visited_verticies = std::vector<bool>(graph.size(), false);
    auto explored_path = std::vector<size_t>();

    explored_path.push_back(source);
    visited_verticies[source] = true;

    while (!explored_path.empty()) {
        auto current_node = explored_path.back();
        explored_path.pop_back();

        print_node(current_node);

        auto adjacent_verticies = graph.adjacent_verticies(current_node);
        for (auto node_number = adjacent_verticies.rbegin();
                node_number != adjacent_verticies.rend();
                ++node_number) {

            if (!visited_verticies[*node_number]) {
                visited_verticies[*node_number] = true;
                explored_path.push_back(*node_number);
            }
        }
    }
}

// recursive implementation
void rdfs(Graph& graph, size_t vertex, std::vector<bool>& visited)
{
    visited[vertex] = true;
    print_node(vertex);

    for (const auto& adjacent_vertex : graph.adjacent_verticies(vertex)) {
        if (!visited[adjacent_vertex]) {
            rdfs(graph, adjacent_vertex, visited);
        }
    }
}

void dfs_wrapper(Graph& graph, size_t source)
{
    auto visisted_verticies = std::vector<bool>(graph.size(), false);
    rdfs(graph, source, visisted_verticies);
}


int main() {
    auto graph = Graph(6);
    graph.new_edge(0, 1);
    graph.new_edge(0, 5);
    graph.new_edge(0, 4);
    graph.new_edge(1, 2);
    graph.new_edge(2, 1);
    graph.new_edge(2, 3);
    std::cout << "BFS:\n";
    bfs(graph, 0);
    std::cout << "DFS:\n";
    //dfs_wrapper(graph, 0);
    //iterative_dfs(graph);
    dfs_on_steroids(graph, 0);
    return 0;
}