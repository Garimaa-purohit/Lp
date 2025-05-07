import java.util.*;

class Graph {

    private int vertices = 0;
    private LinkedList<Integer>[] adjList;
    private int dfsVertex = 0;
    private int dfsEdge = 0;
    private int bfsVertex = 0;
    private int bfsEdge = 0;

    public Graph(int vertices) {
        this.vertices = vertices;
        adjList = new LinkedList[vertices];
        for (int i = 0; i < vertices; i++) {
            adjList[i] = new LinkedList<>();
        }
    }

    // Add an edge between vertices v and w
    public void addEdge(int v, int w) {
        adjList[v].add(w);
        adjList[w].add(v);
    }

    // Recursive DFS function with level tracking
    private void DFSrecursive(int vertex, boolean[] visited, int[] level) {
        visited[vertex] = true;
        dfsVertex++;
        System.out.println("Vertex: " + vertex + " at Level: " + level[vertex]);

        for (int adj : adjList[vertex]) {
            dfsEdge++;
            if (!visited[adj]) {
                level[adj] = level[vertex] + 1;  // Set level for the adjacent vertex
                DFSrecursive(adj, visited, level);
            }
        }
    }

    // Public DFS function to initiate the DFS traversal
    public void DFS(int startVertex) {
        boolean[] visited = new boolean[vertices];
        int[] level = new int[vertices]; // level tracker
        dfsEdge = 0;
        dfsVertex = 0;

        System.out.println("Depth First Search starting from vertex: " + startVertex);
        DFSrecursive(startVertex, visited, level);

        System.out.println("DFS Vertex Visits: " + dfsVertex);
        System.out.println("DFS Edge Traversals: " + dfsEdge);
        System.out.println("DFS Time Complexity: O(" + dfsVertex + " + " + dfsEdge + ")");
    }

    // Recursive BFS function with level tracking
    public void BFSRecursive(Queue<Integer> queue, boolean[] visited, int[] level) {
        if (queue.isEmpty()) {
            return;
        }

        int currentVertex = queue.poll();
        bfsVertex++;
        System.out.println("Vertex: " + currentVertex + " at Level: " + level[currentVertex]);

        for (int adj : adjList[currentVertex]) {
            bfsEdge++;
            if (!visited[adj]) {
                visited[adj] = true;
                queue.add(adj);
                level[adj] = level[currentVertex] + 1;  // Set level for the adjacent vertex
            }
        }

        BFSRecursive(queue, visited, level);  // Recursive call
    }

    // Public BFS function to initiate the BFS traversal
    public void BFS(int startVertex) {
        boolean[] visited = new boolean[vertices];
        Queue<Integer> queue = new LinkedList<>();
        int[] level = new int[vertices]; // level tracker
        bfsEdge = 0;
        bfsVertex = 0;

        visited[startVertex] = true;
        queue.add(startVertex);

        System.out.println("Breadth First Search starting from vertex: " + startVertex);
        BFSRecursive(queue, visited, level);

        System.out.println("BFS Vertex Visits: " + bfsVertex);
        System.out.println("BFS Edge Traversals: " + bfsEdge);
        System.out.println("BFS Time Complexity: O(" + bfsVertex + " + " + bfsEdge + ")");
    }
}

public class Assignment_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int vertices = sc.nextInt();
        Graph graph = new Graph(vertices);

        System.out.print("Enter the number of edges: ");
        int edges = sc.nextInt();
        System.out.println("Enter the edges (format: v1 v2):");

        // Input edges and add them to the graph
        for (int i = 0; i < edges; i++) {
            int v1 = sc.nextInt();
            int v2 = sc.nextInt();

            // Check for invalid vertices
            if (v1 < 0 || v1 >= vertices || v2 < 0 || v2 >= vertices) {
                System.out.println("Error: Invalid vertex index. Vertex should be in range [0, " + (vertices - 1) + "].");
                return; // Stop execution or ask for re-entry
            }

            graph.addEdge(v1, v2);
        }

        System.out.print("Enter the starting vertex for traversal: ");
        int startVertex = sc.nextInt();

        // Perform DFS and BFS
        graph.DFS(startVertex);
        graph.BFS(startVertex);

        sc.close();
    }
}
