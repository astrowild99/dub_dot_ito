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

TEST_CASE("[queue] retrieve player commands") {
    Player *player = new Player("test");
    Command *a = new NoOp(player);


    Player *player1 = new Player("test1");
    Command *b = new NoOp(player1);
    Command *c = new NoOp(player1);

    Player *player2 = new Player("test2");

    Queue *queue = new Queue();
    queue->push(a);
    queue->push(b);
    queue->push(c);
    CHECK(queue->get_next_queue_size() == 3);
    CHECK(queue->get_next_queue_size(player) == 1);
    CHECK(queue->next(player) == a);
    CHECK(queue->next(player) == NULL);
    CHECK(queue->get_next_queue_size() == 3);
    CHECK(queue->get_next_queue_size(player1) == 2);
    CHECK(queue->next(player1) == b);
    CHECK(queue->get_next_queue_size(player1) == 1);
    CHECK(queue->next(player1) == c);
    CHECK(queue->next(player1) == NULL);
    CHECK(queue->get_next_queue_size(player2) == 0);
    CHECK(queue->next(player2) == NULL);
}