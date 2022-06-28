class MyQueue {
public:
        stack < int > input, output;
      /** Initialize your data structure here. */
      MyQueue() {

      }

      /** Push element x to the back of queue. */
      void push(int x) {
        //cout << "The element pushed is " << x << endl;
        input.push(x);
      }

      /** Removes the element from in front of queue and returns that element. */
      int pop() {
        // shift input to output 
        if (output.empty())
          while (input.size())
            output.push(input.top()), input.pop();

        int x = output.top();
        output.pop();
        return x;
      }

      /** Get the front element. */
      int peek() {
        // shift input to output 
        if (output.empty())
          while (input.size())
            output.push(input.top()), input.pop();
        return output.top();
      }

    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */