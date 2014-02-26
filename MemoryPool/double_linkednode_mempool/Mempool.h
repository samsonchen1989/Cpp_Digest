#ifndef MEMPOOL_H
#define MEMPOOL_H

class CMemPool
{
private:
    //The purpose of the structure is that we can operate linkedlist
    struct _Unit
    {
        struct _Unit *pPrev;
        struct _Unit *pNext;
    };

    void *m_pMemBlock;  //The address of memory pool.

    //Manage all unit with two LinkedList
    struct _Unit *m_pAllocatedMemBlock; //Head pointer to Allocated linkedlist
    struct _Unit *m_pFreeMemBlock;      //Head pointer to Free linkedlist

    unsigned long m_ulUnitSize;     //Memory unit size.
    unsigned long m_ulBlockSize;    //Memory pool size.

public:
    CMemPool(unsigned long lUnitNum = 50, unsigned long lUnitSize = 1024);
    ~CMemPool();

    void* Alloc(unsigned long ulSize, bool bUseMemPool);
    void Free(void* p);
};

#endif