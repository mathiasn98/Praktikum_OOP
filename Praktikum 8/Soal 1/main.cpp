#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> vi;
	vector<int> vi2;
	int n;
	int temp;
	int sum=0;
	cin>>n;
	if(n<=0){
		cout<<'-'<<endl<<'-'<<endl<<'-'<<endl<<'-'<<endl<<0<<endl;
	}
	else{
		for(int i=0;i<n;i++){
			cin>>temp;
			sum+=temp;
			vi.push_back(temp);
		}
		vi2 = vi;
		sort(vi.begin(),vi.end());
		//mean
		cout<<(float)sum/(float)n<<endl;
		if(n%2==1){
			cout<<vi[n/2]<<endl;
		}
		else{
			cout<<((float)vi[(n-1)/2]+(float)vi[(n-1)/2+1])/2<<endl;
		}
		
		int count,xmax,countmax,x;
		countmax = 0;
		for(int i=0;i<n;i++){
			count = 0;
			x = vi[i];
			for(int j=0;j<n;j++){
				if(vi[j]==x){
					count++;
				}
			}
			if(count>countmax){
				countmax = count;
				xmax = vi[i];
			}
		}
		cout<<xmax<<endl;
		for(int i=0;i<countmax;i++){
			vi2.push_back(xmax);
		}
		for(int i=0;i<vi2.size();i++){
			if(i>0){
				cout<<' ';
			}
			cout<<vi2[i];
		}
		cout<<endl;
		cout<<vi2.size()<<endl;
	}
	/*
	for(int i=0;i<n;i++){
		cout<<vi[i];
	}*/
}
