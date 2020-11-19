#include <bits/stdc++.h> 
using namespace std; 


int main() 
{ 
	int a,b,target; 
	cin>>a>>b>>target;
	map<tuple<int,int>, int> m; 
	bool check = false; 
	vector<tuple<int,int>> path; 
	queue<tuple<int,int>> q; 
	q.push(make_tuple(0,0));
	while (!q.empty()) { 
		tuple<int,int> u = q.front(); 
		q.pop(); 
		if (m[make_tuple(get<0>(u),get<1>(u))] == 1) 
			continue; 
		if ((get<0>(u) > a || get<1>(u) > b || 
			get<0>(u) < 0 || get<1>(u) < 0)) 
			continue; 
		path.push_back(make_tuple( get<0>(u), get<1>(u))); 
		m[make_tuple( get<0>(u), get<1>(u))] = 1; 
		if (get<0>(u) == target || get<1>(u) == target) { 
			check = 1; 
			if (get<0>(u) == target) { 
				if (get<1>(u) != 0) 
					path.push_back( make_tuple(get<0>(u), 0) ); 
			} 
			else { 
				if (get<0>(u) != 0) 
					path.push_back(make_tuple( 0, get<1>(u))); 
			} 
			int sz = path.size();
			cout<<path.size()<<endl; 
			for (int i = 0; i < sz; i++) 
				cout << get<0>(path[i])<< " " << get<1>(path[i]) << "\n"; 
			break; 
		} 
		q.push( make_tuple(get<0>(u), b) ); 
		q.push( make_tuple(a, get<1>(u)) ); 

		for (int ap = 0; ap <= max(a, b); ap++) { 
			int c = get<0>(u) + ap; 
			int d = get<1>(u) - ap; 
			if (c == a || (d == 0 && d >= 0)) 
				q.push( make_tuple(c, d) ); 
			c = get<0>(u) - ap; 
			d = get<1>(u) + ap; 
			if ((c == 0 && c >= 0) || d == b) 
				q.push( make_tuple(c, d) ); 
		} 

		q.push( make_tuple(a, 0) ); 
		q.push( make_tuple(0, b) ); 
	} 
	if (!check) 
		cout << "No solution"; 
	return 0; 
} 
