#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"
#include "../src/puppy.hpp"

TEST_CASE("Empty queue has size 0") {
    QueueTee q;
    REQUIRE(q.size() == 0);
}
TEST_CASE("Enqueue works") {
    QueueTee q;

    Puppy p1("Puppy 1", 5);
    Puppy p2("Puppy 2", 6);

    q.enqueue(&p1);
    q.enqueue(&p2);

    REQUIRE(q.size() == 2);
}
TEST_CASE("Dequeue works") {
    QueueTee q;

    Puppy p1("First", 10);
    Puppy p2("Second", 9);

    q.enqueue(&p1);
    q.enqueue(&p2);

    Cutie* removed = q.dequeue();

    REQUIRE(removed->get_description() == "First");
    REQUIRE(q.size() == 1);
}
TEST_CASE("Dequeue on empty queue returns nullptr") {
    QueueTee q;

    Cutie* removed = q.dequeue();

    REQUIRE(removed == nullptr);
}
TEST_CASE("Enqueue on full queue does not change size") {
    QueueTee q;

    Puppy p("P", 1);

    for (int i = 0; i < 10; i++) {
        q.enqueue(&p);
    }
    REQUIRE(q.size() == 10);

    q.enqueue(&p);

    REQUIRE(q.size() == 10);
}