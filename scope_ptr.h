#ifndef scope_ptr_h
#define scope_ptr_h

namespace ice { namespace utils
{

// 一个删减版的基于作用域智能指针。
// 不能传递所有权，不能修改裸指针。
template <typename T>
class ScopePtr
{
public:
    explicit ScopePtr(T* raw_ptr) throw():
        m_raw_ptr(raw_ptr)
    {}
	~ScopePtr() throw() { /* delete 0是合法的。*/ delete m_raw_ptr; }

    T& operator*() const throw() { return *m_raw_ptr; }
    T* operator->() const throw() { return m_raw_ptr; }
    T* get() const throw() { return m_raw_ptr; }
    explicit operator bool() const throw() { return m_raw_ptr == 0; }

private:
    T *m_raw_ptr;
}

}} // ice::utils
#endif scope_ptr_h
