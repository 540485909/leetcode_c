#include <iostream>
#include <stack>
#include <cassert>
using namespace std;/*
class MinStack {
public:
    stack<int> m_data;
    stack<int> min_stack;
    void push(int x) {
      m_data.push(x);
      if(min_stack.size()==0){
          min_stack.push(x);
      }
      else{
        if(x<=min_stack.top())
            min_stack.push(x);
        else min_stack.push(min_stack.top());

      }
    }

    void pop() {

        m_data.pop();
        min_stack.pop();



    }

    int top() {

       return m_data.top();

    }

    int getMin() {
        assert(m_data.size()>0);
        assert(min_stack.size()>0);
        int value=min_stack.top();
        min_stack.pop();
        return value;


    }
};*/
template <typename T> class CStackWithMin{

public:
    CStackWithMin(void){};
    virtual ~CStackWithMin(void){};
    T &top(void);
    const T& top(void)const;
    void push(const T& value);
    void pop(void);
    const T& min(void) const;
private:
     stack<T> m_data;               // the elements of stack
     stack<T> m_min;      // the indices of minimum elements

};
template<typename T> void CStackWithMin<T>::push(const T& value){
     m_data.push(value);
     if(m_min.size()==0){
        m_min.push(0);
     }
     else{
         if(value<=m_min.top())
         {
             m_min.push(value);
         }
         else{
            m_min.push(m_min.top());
         }

     }
}
template<typename T> T& CStackWithMin<T>::top()
{
    return m_data.top();
}
template<typename T> const T &CStackWithMin<T>::top(){
return m_data.top();

}
int main()
{

    return 0;
}
