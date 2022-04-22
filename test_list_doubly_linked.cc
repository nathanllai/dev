template <typename T>
class ListDoublyLinked {
    private:
    struct Node {
        T item;
        //Switch next to be like prev if want to not use unique pointers
        std::unique_ptr<Node> next;
        Node* prev;
    };

    //have head owns first node
    std::unique_ptr<Node> head = nullptr;
    // OPtimization: allow for O(1) insertion + deletion @ tail
    unsigned int cur_size = 0;

    // Return pointer on node located as position @pos 
    Node* GetNode(unsigned int pos) {
        assert (pos < cur_size);

        // end case
        if (pos == cur_size - 1) 
          return tail;

        Node* n = head.get();
        while (pos--)
            n = n->next.get();
        return n;
    }
      
    public:
      // Constructor
      ListDoublyLinked() = default;
      // Destructor
      ~ListDoublyLinked() = default;

      // From singly linked list code of lecture, use the Get and Find examples



      //Insert @item at position @pos 
      void Insert(const T &item, const unsigned int pos) {
        if (pos > cur_size)
          throw std::out_of_range("Position out of range!");
        

          auto n = std::unique_ptr<Node>(new Node);
          n->item = item;

        if (pos == 0) {
          // 1. Insert at front
          // move ownership of head to n
          n->next = std::move(head);
          n->prev = nullptr;
          if (n->next != nullptr)   //Same as n->next
            // a. List was not empty, point old head' prev to n
            n->next->prev = n.get();
          else  
            // b. List was empty
            tail = n.get();

        head = std::move(n);
        } else {
            // 2. Insert not at front
            auto prev = GetNode(pos - 1);
            // Set up n
            n->next = std::move(prev->next);
            n->prev = prev;
            if (n->next != nullptr)
              // a. Insert not at end, connect next node's prev ptr to n
              n->next->prev = n.get();
            else
              // b. Insert at end
              tail = n.get();
            prev->next = std::move(n);

        }
        cur_size++;    
      }

        
        
};


//compile:
//g++ =Wall -Werror -std=c++11 -o test_list_doubly_linked test_list_doubly_linked.cc -lgtest -pthread