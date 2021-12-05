#include <mutex>

template <class T>
class BlockingStack
{
private:
  struct stackframe
  {
    T obj;
    stackframe *next;
  };
  stackframe *root{nullptr};
  mutable std::mutex mutex;

public:
  ~BlockingStack()
  {
    while (!empty())
    {
      pop();
    }
  }
  bool empty() const { return root == nullptr; }
  size_t size() const
  {
    std::lock_guard<std::mutex> lockguard(mutex);
    stackframe *frame{root};
    size_t cnt{0};
    while (frame != nullptr)
    {
      cnt++;
      frame = frame->next;
    }
    return cnt;
  }
  T &top() const
  {
    std::lock_guard<std::mutex> lockguard(mutex);
    return root->obj;
  }
  void push(const T &t)
  {
    auto ref = new stackframe;
    ref->obj = t;
    std::lock_guard<std::mutex> lockguard(mutex);
    ref->next = root;
    root = ref;
  }
  void push(T &&t)
  {
    auto ref = new stackframe;
    ref->obj = std::move(t);
    std::lock_guard<std::mutex> lockguard(mutex);
    ref->next = root;
    root = ref;
  };

  template <class... Args>
  decltype(auto) emplace(Args &&...args){};

  T pop()
  {
    if (root == nullptr)
    {
      // or throw or so
      return {};
    }
    stackframe *ref;
    {
      std::lock_guard<std::mutex> lockguard(mutex);
      ref = root;
      if (ref == nullptr){
        // or throw or so
        return {};
      }
      root = ref->next;
    }
    auto obj = ref->obj;
    delete ref;
    return obj;
  };

private:
};
