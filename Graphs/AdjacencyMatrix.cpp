#include<iostream>
#include<vector>

using vi = std::vector<int>; 

//n -> #vertices, m -> #edges
int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<vi> directedGraph(n,vi(n,0));

    for(int i=0;i<n;i++){
        int src, dest;
        std::cin>>src>>dest;
        directedGraph[src-1][dest-1] = 1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout<<directedGraph[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}