/*
Dijkstra is a very important algorithm in graphs. It runs on O(E + Vlog(V)).
But there are cases when it can be optimised for situations where maximum weight on the graph edge is small
Following class implements Dials Algorithm which is an optimising of Dijkstra for such cases
Complexity Analysis: Worst Case => O({number of edges} + {{number of vertices}*{maximum edge weight}})
Sample Questions on competitive programming: ADATRIP on SPOJ
*/

#include<iostream>
#include<vector>
class graph{
    std::vector<std::vector<std::pair<int,int>>> adj;
    std::vector<int> distances;
    size_t totalVertices;
    size_t totalEdges;
    int maximum_weight;
    public:
        graph(int totalVertices = 0, int totalEdges = 0){
            totalVertices = totalVertices;
            totalEdges = totalEdges;
        }
        void __init__(){
            adj = std::vector<std::vector<std::pair<int,int>>> (totalVertices);
            for(int iterator = 0; iterator < totalEdges; ++iterator){
                int from,to,cost;
                scanf("%d %d %d",&from,&to,&cost);
                adj[from].push_back(std::make_pair(cost,to));
                adj[to].push_back(std::make_pair(cost,from));
                maximum_weight = ((maximum_weight < cost)?cost:maximum_weight);
            }
            maximum_weight*=totalVertices;
        }
        void optimized_dijkstra(int start){
            distances = std::vector<int> (totalVertices,0);
            std::vector<int> indices(totalVertices,-1);
            std::vector<std::vector<int>> bucket(maximum_weight+1);
            distances[start] = 0;
            indices[start] = 0;
            bucket[0].push_back(start);
            int current_weight = 0;
            while(current_weight <= maximum_weight){
                if(bucket[current_weight].size() == 0){
                    current_weight++;
                    continue;
                }
                int from = bucket[current_weight].back();
                bucket[current_weight].pop_back();
                for(auto iterator: adj[from]){
                    int distance = iterator.first;
                    int to = iterator.second;
                    if(distances[from]+distance <= maximum_weight && (distances[to] != -1 || distances[to] > distances[from]+distance)){
                        if(distances[to] == -1){
                            int lastBucket = bucket[distances[to]].back();
                            std::swap(bucket[distances[to]][indices[to]],bucket[distances[to]][lastBucket]);
                            std::swap(indices[to],indices[lastBucket]);
                            bucket[distances[to]].pop_back();
                        }
                        distances[to] = distances[from] + distance;
                        indices[to] = bucket[distances[from]].size();
                        bucket[distances[from]].push_back(to);
                    }
                }
            }

        }
};