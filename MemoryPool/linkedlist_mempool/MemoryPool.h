#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <limits.h>
#include <stddef.h>

template <typename T, size_t BlockSize = 4096>
class MemoryPool
{
public:
    //Member types
    typedef T    value_type;
    typedef T*   pointer;
    typedef T&   reference;
    typedef const T*    const_pointer;
    typedef const T&    const_reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference_type;

    template <typename U> struct rebind {
        typedef MemoryPool<U> other;
    };

    MemoryPool() throw();
    MemoryPool(const MemoryPool& memoryPool) throw();
    template <class U> MemoryPool(const MemoryPool<U>& memoryPool) throw();

    ~MemoryPool() throw();

    pointer address(reference x) const throw();
    const_pointer address(const_reference x) const throw();

    //can only allocate one object at a time
    pointer allocate(size_type n = 1, const_pointer hint = 0);
    void deallocate(pointer p, size_type n = 1);

    size_type max_size() const throw();

    void construct(pointer p, const_reference val);
    void destroy(pointer p);

    pointer newElement(const_reference val);
    void deleteElement(pointer p);

private:
    union Slot_ {
        value_type element;
        Slot_* next;
    };

    typedef char* data_pointer_;
    typedef Slot_ slot_type_;
    typedef Slot_* slot_pointer_;

    slot_pointer_ currentBlock_;
    slot_pointer_ currentSlot_;
    slot_pointer_ lastSlot_;
    slot_pointer_ freeSlots_;

    size_type padPointer(data_pointer_ p, size_type align) const throw();
    void allocateBlock();
};

#endif