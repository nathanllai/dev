// For n operations: O(1)
// For 1 (the N+1 pop): O(N)

// Overall tiem complexity for pop: O(1) amortized (averages to constant time)

//queue different from stack, uses two stacks to pop first in, first out

class Queue {
  private:
    Stack sPush, sPop;

  public:
    
    Push(item) {
      sPush.Push(item);
      // Time complexity O(1)
    }

    item Pop() {
      // Refiling sPop if necessary O(N)
      if(!sPop.Size()) {
          while (sPush.Size()) {
            // Moving each element from sPush to sPop
            sPop.Push(sPush.Pop());
          }
      }
      
      // If sPush awas also empty
      if (!sPop.Size()) {
          throw std::out_of_range("Queue is empty!");
      }

      return sPop.Pop();    // O(1)
    }
};


