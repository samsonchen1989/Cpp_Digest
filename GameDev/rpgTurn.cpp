#include <iostream>
#include <vector>
#include <string>

using namespace std;

const static int SEQUENCE_LIMIT = 100;

typedef struct player_
{
    int hp;
    int agility;
    int sequence;
    string name;
} Player;

void sort(vector<string>& seq, vector<Player*>& playerList, int seqSize)
{
    int seqCount = 0;

    Player* player;
    vector<Player*>::iterator it;

    while (true) {
        for (it = playerList.begin(); it != playerList.end(); ++it) {
            player = *it;
            player->sequence += player->agility;

            if (player->sequence > SEQUENCE_LIMIT) {
                player->sequence -= SEQUENCE_LIMIT;
                seq.push_back(player->name);
                seqCount++;
            }
        }

        if (seqCount >= seqSize) {
            break;
        }
    }
}

int main(int argc, char** argv)
{
    vector<string> fightSequence;
    vector<Player*> playerList;

    Player player1;
    Player player2;
    Player player3;

    player1.hp = 100;
    player1.sequence = 0;
    player1.agility = 10;
    player1.name = "ninja";

    player2.hp = 200;
    player2.sequence = 0;
    player2.agility = 3;
    player2.name = "tank";

    player3.hp = 80;
    player3.sequence = 0;
    player3.agility = 8;
    player3.name = "thieve";

    playerList.push_back(&player1);
    playerList.push_back(&player2);
    playerList.push_back(&player3);

    sort(fightSequence, playerList, 20);

    vector<string>::iterator it;
    for (it = fightSequence.begin(); it != fightSequence.end(); ++it) {
        cout << *it << "\n";
    }

    return 0;
}