#include <stdlib.h>
#include <list>
#include <time.h>
#include <iostream>

using namespace std;

class TestObject
{
public:
    int Value;
    TestObject() { Value = 0; }
};

template <typename OPDataType>
class ObjectPool
{
protected:
    OPDataType* _ObjectData;
    OPDataType** _ObjectFree;
    int _ObjectCount, _Top;

protected:
    void FreeAll()
    {
        int i = (_ObjectCount - 1);
        for (_Top = 0; _Top < _ObjectCount; _Top++) {
            _ObjectFree[_Top] = &_ObjectData[i--];
        }
    }

public:
    void FreeInstance(OPDataType* instance)
    {
        if (instance && (_Top < _ObjectCount) && (instance >= &_ObjectData[0])
            && (instance <= &_ObjectData[_ObjectCount - 1]))
        {
            _ObjectFree[_Top++] = instance;
        }
    }

    OPDataType* NewInstance()
    {
        if (_Top > 0) {
            return _ObjectFree[--_Top];
        }

        return 0;
    }

    ObjectPool(int count)
    {
        _ObjectData = new OPDataType[count];
        _ObjectFree = new OPDataType*[count];

        _ObjectCount = count;

        FreeAll();
    }

    virtual ~ObjectPool()
    {
        delete[] _ObjectData;
        delete[] _ObjectFree;
    }
};

#define TEST_POOL_SIZE  20000

int main(int argc, char** argv)
{
    ObjectPool<TestObject> pool(TEST_POOL_SIZE);
    list<TestObject*> objects;

    clock_t start;
    start = clock();

    for (int i = 0; i < TEST_POOL_SIZE; i++) {
        TestObject* test = pool.NewInstance();
        test->Value = rand();
        objects.push_back(test);
    }

    list<TestObject*>::iterator it = objects.begin();
    while (it != objects.end()) {
        pool.FreeInstance(*it);
        ++it;
    }

    objects.clear();

    std::cout << "Pool time:" << (clock() - start) << std::endl;

    return 0;
}