#include <iostream>
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b;
	if(a==b==1){
		cout<<1;
		return 0;
	}
	if(a<b){
		while(a<=b){
			a=a*3;
			b=b*2;
			c++;
		}
		
	}
	else{
		c=0;
	}
	cout<<c;
	return 0 ;
}