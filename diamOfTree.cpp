// Question: given a tree, represented as a list of edges,
// find the length of its diameter
// the diameter is the longest path from one node to another

vector<int> *adj;

void dfs(int node, int par, vector<int> &d){
    for(auto nei: adj[node]){
        if(nei==par){
            continue;
        }
        if(d[nei]>d[node]+1){
            d[nei]=d[node]+1;
            dfs(nei,node,d);
        }
    }
}

vector<int> getDiaInfo(int n){
    vector<int> dist1(n,INT_MAX);
    vector<int> dist2(n,INT_MAX);
    
    dist1[0]=0;
    dfs(0,-1,dist1);
    
    int u=max_element(dist1.begin(),dist1.end())-dist1.begin();
    
    dist2[u]=0;
    dfs(u,-1,dist2);    
    
    int v=max_element(dist2.begin(),dist2.end())-dist2.begin();
    
    return {u,v,dist2[v]};
}

int main(){
    int n;
    vector<vector<int>> edges;
    
    // TEST CASE: 1
    
    n=9;
    edges={{0,1},{2,1},{1,3},{3,4},{3,5},{3,6},{6,7},{6,8}};
    
    
    // n=7;
    // edges={{0,2},{1,2},{2,3},{3,4},{4,5},{4,6}};
    
    adj=new vector<int>[n];

    for(auto edge: edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    auto info=getDiaInfo(n); // returns two nodes who are ends of the largest diameter and the diameter
    
    int node1=info[0];
    int node2=info[1];
    int diameter=info[2];
    
    
    vector<int> d1(n,INT_MAX);
    vector<int> d2(n,INT_MAX);
    
    d1[node1]=0;
    dfs(node1,-1,d1);
    
    d2[node2]=0;
    dfs(node2,-1,d2);
    
    
    set<int> nodes;
    
    for(int i=0;i<n;i++){
        if(d1[i]==diameter){
            nodes.insert(i);
        }
        if(d2[i]==diameter){
            nodes.insert(i);
        }
    }
    
    cout<<"Maximum diameter is -> "<<diameter<<endl;
    cout<<"Answer Nodes -> ";
    for(auto v: nodes){
        cout<<v<<" , ";
    }
    return 0;
}
