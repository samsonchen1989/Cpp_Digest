#include "RoundRobin.h"

class NetworkRequest {};

class Host
{
public:
    void processRequest(NetworkRequest& request) {
        cout << "processRequest." << endl;
    }
};

class LoadBalancer
{
public:
    LoadBalancer(const vector<Host>& hosts)
    {
        for (size_t i = 0; i < hosts.size(); ++i) {
            rr.add(hosts[i]);
        }
    }

    ~LoadBalancer() {}

    void distributeRequest(NetworkRequest& request)
    {
        try {
            rr.getNext().processRequest(request);
        } catch (out_of_range& e) {
            cerr << "No more hosts.\n";
        }
    }

protected:
    RoundRobin<Host> rr;
};

// a simple app to distribute network request to
// a list of server
// request1 server1, request2 server2...
// request'n' server (n % server_num)
int main(int argc, char** argv)
{
    vector<Host> hostVec(10);

    LoadBalancer loadBal(hostVec);

    for (int i = 0; i < 20; i++) {
        NetworkRequest request;
        cout << "request:" << i << endl;
        loadBal.distributeRequest(request);
    }

    return 0;
}