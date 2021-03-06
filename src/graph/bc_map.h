#ifndef BATTLE_CAT_MAP
#define BATTLE_CAT_MAP

#include "header.h"
#include "debug.h"
#include "kth.h"
#include "cache.h"
#include "graph.h"

class Graph;
class Kth;

struct Edge {
    int from, to;
	int id;
    float delay;
	//bool valid;
	//Edge* rev_edge;
    //Edge():from(0), to(0), delay(0), valid(0), rev_edge(nullptr){}
    //Edge(int f,int t,float d):from(f),to(t),delay(d), valid(false), rev_edge(nullptr){}

    Edge():from(0), to(0), delay(0){}
    Edge(int f,int t,float d):from(f),to(t),delay(d){}
};

class BC_map {

public:
    BC_map(Graph* graph, CPPR* cppr);
	~BC_map();

    void build();
    void random_walk(vector<int> &result);
    int get_index(Mode mode,Transition_Type type, int node_id);
    int get_graph_id(int map_id);      // map id to graph node id
    Mode get_graph_id_mode(int map_id);
    Transition_Type get_graph_id_type(int map_id);
    string get_node_name(int map_id);

	void k_shortest_path(vector<int>& _through,
						 const vector<int>& _disable,
						 int k,
						 vector<Path*>& ans,
						 bool cppr_on = false
						 );

	std::atomic<float> threshold;
    
    void add_edge(int from, int to, float delay);
    void build_map(int root);

	void mark_point(vector<int>& through, const vector<int>& disable);

	// iterate the all condidates with calling function fun
    void do_kth(const vector<int>& condidate, size_t k, std::function<void(Kth*,int,int,vector<Path*>&)> fun, vector<Path*>& ans);

	void search(const vector<int>& through);    // deleted
	bool search_fout(int x, int next_level_id); // deleted

	void search_fin(int x);
	bool search_fout_layer(int v, int target_level); // from v to target_level
	bool search_modify(const vector<int>& through,const vector<int>& disable);
	void search_all();

	void choose_cache(const vector<int>& through, const vector<int>& disable);
	int cal_cache_difference(Cache* cache, const vector<int>& through, const vector<int>& disable);

	/* kth */
	// vector<bool> is_valid;
	vector<bool> is_disable, is_through;
	vector<int> next_level;
	vector<int> kth_start, kth_dest;
	// vector<Edge*> valid_edge;   // To clean the mark of the edge of each query, we store the valid edge and clean it after we get the k shortest_path.

	vector<Path*> path_kth[NUM_THREAD];
	Kth* kths[NUM_THREAD];

    Graph* graph;
	CPPR* cppr;
    int num_node;
	int edge_counter;
    int superSource;
	int cache_timestamp;

    vector<vector<Edge*>> G;
    vector<vector<Edge*>> Gr;
	vector<Edge*> es;

    vector<int> to_map_id[2][2];       // graph node id to bc map id
    vector<int> level, in_degree, vis;

	vector<Cache*> caches;
	Cache* current_cache;
    friend class Kth;
};

#endif /* BATTLE_CAT_MAP */
