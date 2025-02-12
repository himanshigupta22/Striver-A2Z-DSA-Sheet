/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int> &s, int temp){
    if(s.empty() || s.top() <= temp){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
    
}

void SortedStack :: sort()
{
   //Your code here
   if(s.empty()){
       return;
   }
   int temp = s.top();
   s.pop();
   sort();
   insert(s, temp);
}
