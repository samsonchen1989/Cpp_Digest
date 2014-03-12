#include <queue>
#include <stdexcept>
using std::queue;

template <typename T>
class PacketBuffer
{
public:
    // if maxSize is nonpositive, the size is unlimited
    // otherwise only maxSize packets are allowed in the
    // buffer at any one time
    PacketBuffer(int maxSize = -1);

    // store the packet in the buffer.
    // throw overflow_error is the buffer is full
    void bufferPacket(const T& packet);

    // return next packet, throws out_of_range if
    // the buffer is empty
    T& getNextPacket() throw (std::out_of_range);

protected:
    queue<T> mPackets;
    int mMaxSize;

private:
    //prevent assignment and pass-by-value
    PacketBuffer(const PacketBuffer& src);
    PacketBuffer& operator=(const PacketBuffer& rhs);
};

template <typename T>
PacketBuffer<T>::PacketBuffer(int maxSize)
{
    mMaxSize = maxSize;
}

template <typename T>
void PacketBuffer<T>::bufferPacket(const T& packet)
{
    if (mMaxSize > 0 && mPackets.size() == static_cast<size_t>(mMaxSize)) {
        //no more space, just drop the packet
        return;
    }

    mPackets.push(packet);
}

template <typename T>
T& PacketBuffer<T>::getNextPacket() throw (std::out_of_range)
{
    if (mPackets.empty()) {
        throw(std::out_of_range("Buffer is empty"));
    }

    T& temp = mPackets.front();
    mPackets.pop();

    return temp;
}