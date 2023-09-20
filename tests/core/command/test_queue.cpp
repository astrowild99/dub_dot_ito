//
// Created by donato on 20/09/23.
//

#include "../../../thirdparty/doctest.h"
#include "../../../core/player/player.h"
#include "../../../core/command/command.h"
#include "../../../core/command/no_op.h"
#include "../../../core/command/queue.h"

TEST_CASE("[queue] add to queue") {
    Player *player = new Player("test");
    Command *a = new NoOp(player);

    Queue *queue = new Queue();
    queue->push(a);
    CHECK(queue->get_next_queue_size() == 1);
    CHECK(queue->next() == a);
    CHECK(queue->get_next_queue_size() == 0);
}