#ifndef SCOPE_PTR_H
#define SCOPE_PTR_H

namespace camp { namespace utils
{

// A simplified boost::scope_ptr
template <typename T>
class ScopePtr
{
public:
    explicit ScopePtr(T* raw_ptr) throw():
        m_raw_ptr(raw_ptr)
    {}
    ~ScopePtr() { delete m_raw_ptr; }

    T& operator*() const throw() { return *m_raw_ptr; }
    T* operator->() const throw() { return m_raw_ptr; }
    T* get() const throw() { return m_raw_ptr; }

    T* reset(T* new_ptr)
    {
        if (m_raw_ptr != 0)
            delete m_raw_ptr;
        m_raw_ptr = new_ptr;
    }

    explicit operator bool() const throw() { return m_raw_ptr == 0; }

private:
    T *m_raw_ptr;
};

}} // camp::utils
#endif SCOPE_PTR_H
