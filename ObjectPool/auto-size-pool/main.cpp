#include <time.h>
#include <iostream>
#include "ObjectPool.h"

using namespace std;

class UserRequest
{
public:
    //UserRequest() {}
    //~UserRequest() {}

    // methods to populate the request with specific information
    // methods to retrive the request data

protected:
    // Data members
    int data;
};

UserRequest& obtainUserRequest(ObjectPool<UserRequest>& pool)
{
    UserRequest& request = pool.acquireObject();
    return request;
}

void processUserRequest(ObjectPool<UserRequest>& pool,
    UserRequest& req)
{
    pool.releaseObject(req);
}

int main(int argc, char** argv)
{
    clock_t start;

    ObjectPool<UserRequest> requestPool(1000);

    start = clock();
    for (int i = 0; i < 1000; i++) {
        UserRequest& req = obtainUserRequest(requestPool);
        processUserRequest(requestPool, req);
    }

    cout << "ObjectPool:" << (((double)clock() - start)) << endl;
    start = clock();

/*
    for (int i = 0; i < 1000; i++) {
        UserRequest* req = new UserRequest();
        delete req;
    }

    cout << "Common(s):" << (((double)clock() - start)) << endl;
*/
    return 0;
}