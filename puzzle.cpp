#include<bits/stdc++.h>
using namespace std;

class state{
public:
	int p[9];
	int x;
};

bool operator == (const state& obj1,const state& obj2){
		for(int i=0;i<9;i++){
			if((obj1.p)[i]!=(obj2.p)[i]) return false;
		}
		
		return true;
	}



bool operator < (const state& obj1,const state& obj2){
		for(int i=0;i<9;i++){
			if((obj1.p)[i]<(obj2.p)[i]) return true;
			if((obj1.p)[i]==(obj2.p)[i]) continue;
			return false;
		}
		return false;
	}

int main(){
	map<state,int>m;
	map<state,int>m1;
	state start;
	vector<vector<int>>ans;
	for(int i=0;i<9;i++){
		cin>>(start.p)[i];
	}
	start.x=0;
	state end;
	for(int i=0;i<9;i++){
		cin>>(end.p)[i];
	}
	
	queue<state>q;
	q.push(start);
	m[start]=1;
	m1[start]=-1;
	vector<state>v;
	int c=0;
	while(!q.empty()){
		c++;
		state par=q.front();
		v.push_back(par);
		q.pop();
		int i=0;
		if(m[end]==1) {cout<<"Steps "<<par.x<<endl<<endl;break;}
		for(int j=0;j<9;j++){
			if((par.p)[j]==-1) i=j; 
		}
		if(i%3<2){
			state child1;
			for(int i=0;i<9;i++){
				(child1.p)[i]=(par.p)[i];
			}
			swap((child1.p)[i],(child1.p)[i+1]);
			if(m[child1]!=1){
			m[child1] = 1;
			child1.x= par.x+1;
			m1[child1]=v.size()-1;
			q.push(child1);
			c++;
			
		}
		}
		if(i%3>0){
			state child1;
			for(int i=0;i<9;i++){
				(child1.p)[i]=(par.p)[i];
			}

			swap((child1.p)[i],(child1.p)[i-1]);
			if(m[child1]!=1){
			m[child1] = 1;
			m1[child1]=v.size()-1;
			child1.x= par.x+1;
			q.push(child1);
			c++;
			
		}
		}
		if(i>=3){
			state child1;
			for(int i=0;i<9;i++){
				(child1.p)[i]=(par.p)[i];
			}

			swap((child1.p)[i],(child1.p)[i-3]);
			if(m[child1]!=1){
			m[child1] = 1;
			child1.x= par.x+1;
			m1[child1]=v.size()-1;
			q.push(child1);
			
		}
		}
		if(i<6){
			state child1;
			for(int i=0;i<9;i++){
				(child1.p)[i]=(par.p)[i];
			}

			swap((child1.p)[i],(child1.p)[i+3]);
			if(m[child1]!=1){
			m[child1] = 1;
			child1.x= par.x+1;
			m1[child1]=v.size()-1;
			q.push(child1);
			
		}
		}
	}
	
	while(m1[end]!=-1){
		vector<int>temp;
		for(int i=0;i<9;i++){
			temp.push_back((end.p)[i]);
		}
		ans.push_back(temp);
		end=v[m1[end]];
	}
	vector<int>temp;
	for(int i=0;i<9;i++){
		temp.push_back((start.p)[i]);
	}
	ans.push_back(temp);

	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout<<"State "<<i<<endl;
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
			if(j%3==2) cout<<endl;
		}
		cout<<endl;
	}
}