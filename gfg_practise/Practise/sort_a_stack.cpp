void sortinsert(stack<int>&s,int x){

}
void sortedStack::sort(){
	stack<int>s;
	while(!s.empty()){
		int x=s.top();
		s.pop();
		sortinsert(s,x);

	}
}
 