#include <stdio.h>
#include <stdbool.h>

#define NUM_NODES 5

void tokenBusSimulation(int nodes[], int numNodes)
{
    int token = 0;
    int transmissionData[NUM_NODES] = {10, 20, 0, 15, 5};
    while (true)
    {
        printf("\nNode %d has the token.\n", token + 1);

        if (transmissionData[token] > 0)
        {
            printf("Node %d is transmitting data: %d units.\n", token + 1, transmissionData[token]);
            transmissionData[token] = 0;
        }
        else
        {
            printf("Node %d has no data to transmit.\n", token + 1);
        }

        token = (token + 1) % numNodes;

        bool allDataTransmitted = true;
        for (int i = 0; i < numNodes; i++)
        {
            if (transmissionData[i] > 0)
            {
                allDataTransmitted = false;
                break;
            }
        }

        if (allDataTransmitted)
        {
            printf("\nAll nodes have transmitted their data. Ending simulation.\n");
            break;
        }
    }
}

int main()
{
    int nodes[NUM_NODES] = {1, 2, 3, 4, 5};

    printf("Token Bus Simulation\n");
    tokenBusSimulation(nodes, NUM_NODES);

    return 0;
}