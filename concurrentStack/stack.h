
template<class T>
class Stack
{
public:
    virtual bool empty() const;
    virtual size_t size() const;
    virtual T& top() const;
    virtual void push(const T&);
    virtual void push(T&&);

    template< class ... Args>
    decltype(auto) emplace( Args&&... args );

    virtual T pop();
    virtual void swap(Stack& x) noexcept;

};
