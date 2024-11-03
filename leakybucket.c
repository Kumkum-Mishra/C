#include <stdio.h>

#define BUCKET_SIZE 10
#define LEAK_RATE 2

void leakyBucket(int incomingPackets[], int n)
{
    int bucketContent = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nPacket %d: Incoming packet size = %d units\n", i + 1, incomingPackets[i]);

        if (incomingPackets[i] <= (BUCKET_SIZE - bucketContent))
        {
            bucketContent += incomingPackets[i];
            printf("Bucket content: %d units\n", bucketContent);
        }
        else
        {
            printf("Bucket overflow! Packet size %d is dropped.\n", incomingPackets[i]);
        }

        bucketContent -= LEAK_RATE;
        if (bucketContent < 0)
        {
            bucketContent = 0;
        }
        printf("After leaking, bucket content: %d units\n", bucketContent);
    }
}

int main()
{
    int incomingPackets[] = {5, 3, 8, 7, 4, 2};
    int n = sizeof(incomingPackets) / sizeof(incomingPackets[0]);

    printf("Leaky Bucket Simulation\n");
    leakyBucket(incomingPackets, n);

    return 0;
}