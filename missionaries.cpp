#include<bits/stdc++.h>
using namespace std;

class state{
public:
	int a,b,c;
	int x;
};

bool operator == (const state& obj1,const state& obj2){
		if(obj1.a==obj2.a && obj1.b==obj2.b && obj1.c==obj2.c) return true;
		return false;
	}

bool operator < (const state& obj1,const state& obj2){
	if(obj1.a<obj2.a) return true;
	else if(obj1.b<obj2.b && obj1.a==obj1.a) return true;
	else if(obj1.c<obj2.c && obj1.b==obj2.b && obj1.a==obj1.a) return true;
	return false;
}


int main(){
	state start;
	start.a=3;
	start.b=3;
	start.c=0;
	start.x=0;
	state final;
	final.a=0;
	final.b=0;
	final.c=1;
	queue<state>q;
	map<state,int>m;
	map<state,int>m1;
	m1[start]=-1;
	q.push(start);
	m[start]=1;
	vector<state>v;
	int c=0;
	while(!q.empty()){
		c++;
		state par=q.front();
		q.pop();
		v.push_back(par);
		// cout<<v.size()<<endl;
		// cout<<m1[par]<<" ";
		// cout<<par.a<<par.b<<par.c<<endl;
		if(m[final]==1) {cout<<"Number of turns needed to cross:"<<par.x+1<<endl;break;}
		if(((par.a-2)>=par.b || (par.a-2)==0) && ((3-par.a+2)>=(3-par.b)) && par.c==0){
			state child;
			child.a=par.a-2;
			child.b=par.b;
			child.c=1;
			// cout<<child.c;
			if(m[child]==0 && child.a>=0){
				m[child]=1;
				child.x=par.x+1;
				m1[child]=v.size()-1;
				q.push(child);

			}
		}
		if(((par.b-2)<=par.a || par.a==0) && ((3-par.b+2)<=(3-par.a) || (3-par.a)==0) && par.c==0){
			state child;
			child.a=par.a;
			child.b=par.b-2;
			child.c=1;
			// cout<<child.c;
			if(m[child]==0 && child.b>=0){
				m[child]=1;
				child.x=par.x+1;
				m1[child]=v.size()-1;
				q.push(child);
			}
		}
		if(((par.a-1)>=(par.b-1) || par.a==0) && ((3-par.a+1)>=(3-par.b+1) || (3-par.a)==0) && par.c==0){
			state child;
			child.a=par.a-1;
			child.b=par.b-1;
			child.c=1;
			if(m[child]==0 && child.a>=0 && child.b>=0){
				m[child]=1;
				child.x=par.x+1;
				// cout<<v.size()<<" ";
				m1[child]=v.size()-1;
				q.push(child);
			}
		}
		if(((par.a-1)>=par.b || par.a==0) && ((3-par.a+1)>=(3-par.b)) && par.c==0){
			state child;
			child.a=par.a-1;
			child.b=par.b;
			child.c=1;
			if(m[child]==0 && child.a>=0){
				m[child]=1;
				child.x=par.x+1;
				m1[child]=v.size()-1;
				q.push(child);
			}
		}
		if(((par.b-1)<par.a || par.a==0) && ((3-par.b+1)<=(3-par.a) || (3-par.b)==0) && par.c==0){
			state child;
			child.a=par.a;
			child.b=par.b-1;
			child.c=1;
			if(m[child]==0 && child.b>=0){
				m[child]=1;
				child.x=par.x+1;
				m1[child]=v.size()-1;
				q.push(child);
			}
		}
		if(((3-par.a-2)>=(3-par.b) || (3-par.a-2)==0) && ((par.a+2)>=par.b) && par.c==1){
			state child;
			child.a=par.a+2;
			child.b=par.b;
			child.c=0;
			// cout<<child.c;
			if(m[child]==0 && child.a<=3){
				m[child]=1;
				child.x=par.x+1;
				m1[child]=v.size()-1;
				q.push(child);
			}
		}
		if(((3-par.b-2)<=(3-par.a) || (3-par.a)==0) && ((par.b+2)<=(par.a) || (par.a)==0) && par.c==1){
			state child;
			child.a=par.a;
			child.b=par.b+2;
			child.c=0;
			// cout<<child.c;
			if(m[child]==0 && child.b<=3){
				m[child]=1;
				child.x=par.x+1;
				m1[child]=v.size()-1;
				q.push(child);
			}
		}
		if(((3-par.a-1)>=(3-par.b-1) || (3-par.a)==0) && ((par.a+1)>=(par.b+1) || (par.a)==0) && par.c==1){
			state child;
			child.a=par.a+1;
			child.b=par.b+1;
			child.c=0;
			if(m[child]==0 && child.a<=3 && child.b<=3){
				m[child]=1;
				child.x=par.x+1;
				m1[child]=v.size()-1;
				q.push(child);
			}
		}
		if(((3-par.a-1)>=3-par.b || (3-par.a)==0) && ((par.a+1)>=(par.b)) && par.c==1){
			state child;
			child.a=par.a+1;
			child.b=par.b;
			child.c=0;
			if(m[child]==0 && child.a<=3){
				m[child]=1;
				child.x=par.x+1;
				m1[child]=v.size()-1;
				q.push(child);
			}
		}
		if(((3-par.b-1)<(3-par.a) || (3-par.a)==0) && ((par.b+1)<=(par.a) || (par.a)==0) && par.c==1){
			state child;
			child.a=par.a;
			child.b=par.b+1;
			child.c=0;
			if(m[child]==0 && child.b<=3){
				m[child]=1;
				child.x=par.x+1;
				m1[child]=v.size()-1;
				q.push(child);
			}
		}
		// if(c==100) break;
	}
	

}