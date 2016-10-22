// INPUT: 	w[i][j] = edge between row node i and column node j
// OUTPUT: 	mr[i] = assignment for row node i, -1 if unassigned
//			mc[j] = assignment for column node j, -1 if unassigned
//			function returns number of matches made

#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool find_match(int i, const VVI &w, VI &mr, VI &mc, VI &seen){
	for (int j = 0; j < w[i].size(); j++){
		if (w[i][j] && !seen[j]) {
			seen[j] = true;
			if (mc[j] < 0 || find_match(mc[j], w, mr, mc, seen)){
				mr[i] = j;
				mc[j] = i;
				return true;
			}
		}
	}
	return false;
}

int bipartite_matching(const VVI &w, VI &mr, VI &mc){
	mr = VI(w.size(), -1);
	mc = VI(w[0].size(), -1);

	int ct = 0;
	for(int i = 0; i < w.size(); i++){
		VI seen(w[0].size());
		if (find_match(i, w, mr, mc, seen)) ct++;
	}
	return ct;
}