template <typename T>
const int ObjectPool<T>::kDefaultChunkSize;

template <typename T>
ObjectPool<T>::ObjectPool(int chunkSize) throw(std::invalid_argument,
    std::bad_alloc) : mChunkSize(chunkSize)
{
    if (mChunkSize <= 0) {
        throw std::invalid_argument("chunk size must be positive");
    }
    //Create mChunkSize objects to start
    allocateChunk();
}

//allocates an array of mChunkSize objects because that's
//more efficient than allocating each of them individually.
//Stores a pointer to the first element of the array in the
//mAllObjects vector. Adds a pointer to each new Object to
//the mFreeList.
template <typename T>
void ObjectPool<T>::allocateChunk()
{
    T* newObjects = new T[mChunkSize];
    mAllObjects.push_back(newObjects);

    for (int i = 0; i < mChunkSize; i++) {
        mFreeList.push(&newObjects[i]);
    }
}

// free function for use in the for_each algorithm in the destructor
template <typename T>
void ObjectPool<T>::arrayDeleteObject(T* obj)
{
    delete [] obj;
}

template <typename T>
ObjectPool<T>::~ObjectPool()
{
    //free each of the allocation chunks
    for_each(mAllObjects.begin(), mAllObjects.end(), arrayDeleteObject);
}

template <typename T>
T& ObjectPool<T>::acquireObject()
{
    if (mFreeList.empty()) {
        allocateChunk();
    }

    T* obj = mFreeList.front();
    mFreeList.pop();

    return (*obj);
}

template <typename T>
void ObjectPool<T>::releaseObject(T& obj)
{
    mFreeList.push(&obj);
}