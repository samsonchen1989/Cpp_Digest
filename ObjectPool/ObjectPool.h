#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include <queue>
#include <vector>
#include <stdexcept>
#include <memory>
#include <algorithm> // std::for_each

using std::queue;
using std::vector;

template <typename T>
class ObjectPool
{
public:
    //create an object pool with chunkSize objects.
    //whenever the object pool runs out of objects, chunkSize
    //more objects will be added to the pool.
    //The pool only grows: objects are never removed from the
    //pool(freed), until the pool is destroyed.
    ObjectPool(int chunkSize = kDefaultChunkSize)
        throw(std::invalid_argument, std::bad_alloc);

    //free all the allocated objects, Invalidates any objects
    //that have been acquired for use.
    ~ObjectPool();

    //Reserve an object for use, the reference to the object
    //is invalidated 
    T& acquireObject();

    //return the object to the pool. Clients must not use the
    //object after it has been returned to the pool
    void releaseObject(T& obj);

protected:
    //mFreeList stores the objects that are not currently in
    //use by clients
    queue<T*> mFreeList;

    //mAllObjects stores pointers to all objects, in use or
    //not. This vector is needed in order to ensure that all
    //objects are freed properly in the destructor.
    vector<T*> mAllObjects;

    int mChunkSize;
    static const int kDefaultChunkSize = 10;

    //Allocates mChunkSize new objects and adds them
    //to the mFreeList
    void allocateChunk();
    static void arrayDeleteObject(T* obj);

private:
    ObjectPool(const ObjectPool<T>& src);
    ObjectPool<T>& operator=(const ObjectPool<T>& rhs);
};

#include "ObjectPool.tpp"

#endif