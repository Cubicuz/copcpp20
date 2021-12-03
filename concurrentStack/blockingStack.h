#include <mutex>

template <class T> class BlockingStack {
private:
  struct stackframe {
    stackframe *prev;
    T obj;
    stackframe *next;
  };
  stackframe *root;
  stackframe *last;
  mutable std::mutex mutex;

public:
  BlockingStack() {
    root = new stackframe;
    root->prev = nullptr;
    root->next = nullptr;
    last = root;
  }
  ~BlockingStack() {
    while (!empty())
    {
      pop();
    }
    delete root;
    root = nullptr;
  }
  bool empty() const { return root->next == nullptr; }
  size_t size() const {
    std::lock_guard<std::mutex> lockguard(mutex);
    stackframe *frame{root};
    size_t cnt{0};
    while (frame->next != nullptr)
    {
        cnt++;
        frame = frame->next;
    }
    return cnt;
  }
  T &top() const {
    std::lock_guard<std::mutex> lockguard(mutex);
    return last->obj;
  }
  void push(const T &t) {
    auto ref = new stackframe;
    ref->next = nullptr;
    ref->obj = t;
    std::lock_guard<std::mutex> lockguard(mutex);
    last->next = ref;
    ref->prev = last;
    last = ref;
  }
  void push(T &&t) {
    auto ref = new stackframe;
    ref->next = nullptr;
    ref->obj = std::move(t);
    std::lock_guard<std::mutex> lockguard(mutex);
    last->next = ref;
    ref->prev = last;
    last = ref;
  };

  template <class... Args> decltype(auto) emplace(Args &&...args){};

  T pop() {
    if (root == last) {
      return {};
    }
    stackframe* ref;
    {
      std::lock_guard<std::mutex> lockguard(mutex);
      ref = last;
      ref->prev->next = nullptr;
      last = ref->prev;
    }
    auto obj = ref->obj;
    delete ref;
    return obj;
  };

private:
};
