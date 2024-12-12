// Anton

#include "gtest/gtest.h"
#include "priorityQueue.h"

#define P_LOW 0
#define P_HIGH 1

#define EXCEPTION_1 std::out_of_range
//#define EXCEPTION_1 std::runtime_error

// Testing with int

// Test of enqueu and deque
TEST(PriorityQueueTest, EnqueDequeOrder) {
  PriorityQueue<int> pq;

  // Enquing
  pq.queueWithPriority(1, P_LOW);
  pq.queueWithPriority(200, P_HIGH);
  pq.queueWithPriority(3, P_LOW);
  pq.queueWithPriority(400, P_HIGH);

  // Dequeuing
  EXPECT_EQ(pq.removeFromqueue(), 200);
  EXPECT_EQ(pq.removeFromqueue(), 400);
  EXPECT_EQ(pq.removeFromqueue(), 1);
  EXPECT_EQ(pq.removeFromqueue(), 3);
  EXPECT_TRUE(pq.isEmpty());
}

// Test of peek
TEST(PriorityQueueIntTest, Peek) {
  PriorityQueue<int> pq;

  // Enquing
  pq.queueWithPriority(1, P_LOW);
  pq.queueWithPriority(200, P_HIGH);

  // Peeking dequing and peeking again
  EXPECT_EQ(pq.peek(), 200);
  pq.removeFromqueue();
  EXPECT_EQ(pq.peek(), 1);
}

// Size test
TEST(PriorityQueueIntTEST, Size) {
  PriorityQueue<int> pq;

  // Test size on empty queueu
  EXPECT_EQ(pq.size(), 0);

  // Enquing
  pq.queueWithPriority(1, P_LOW);
  pq.queueWithPriority(200, P_HIGH);

  // Test size after enque
  EXPECT_EQ(pq.size(), 2);
}

// Fail tests
TEST(PriorityQueueIntTest, Fails) {
  PriorityQueue<int> pq;

  // Test of removeFromqueue on empty queue
  EXPECT_THROW(pq.removeFromqueue(), EXCEPTION_1);

  // Test of peek on empty queue
  EXPECT_THROW(pq.peek(), EXCEPTION_1);

  // Test of invalid prio
  EXPECT_THROW(pq.queueWithPriority(1, 2), std::invalid_argument);
}

// Testing with strings

// Test of enqueu and deque
TEST(PriorityQueueStringTest, EnqueDequeOrder) {
  PriorityQueue<std::string> pq;

  // Enquing
  pq.queueWithPriority("Hello", P_LOW);
  pq.queueWithPriority("World", P_HIGH);
  pq.queueWithPriority("Priority", P_LOW);
  pq.queueWithPriority("Queue", P_HIGH);

  // Dequeuing
  EXPECT_EQ(pq.removeFromqueue(), "World");
  EXPECT_EQ(pq.removeFromqueue(), "Queue");
  EXPECT_EQ(pq.removeFromqueue(), "Hello");
  EXPECT_EQ(pq.removeFromqueue(), "Priority");
  EXPECT_TRUE(pq.isEmpty());
}

// Test of peek
TEST(PriorityQueueStringTest, Peek) {
  PriorityQueue<std::string> pq;

  // Enquing
  pq.queueWithPriority("Hello", P_LOW);
  pq.queueWithPriority("World", P_HIGH);

  // Peeking dequing and peeking again
  EXPECT_EQ(pq.peek(), "World");
  pq.removeFromqueue();
  EXPECT_EQ(pq.peek(), "Hello");
}

// Size test
TEST(PriorityQueueStringTEST, Size) {
  PriorityQueue<std::string> pq;

  // Test size on empty queueu
  EXPECT_EQ(pq.size(), 0);

  // Enquing
  pq.queueWithPriority("Hello", P_LOW);
  pq.queueWithPriority("World", P_HIGH);

  // Test size after enque
  EXPECT_EQ(pq.size(), 2);
}

// Fail tests
TEST(PriorityQueueStringTest, Fails) {
  PriorityQueue<std::string> pq;

  // Test of removeFromqueue on empty queue
  EXPECT_THROW(pq.removeFromqueue(), EXCEPTION_1);

  // Test of peek on empty queue
  EXPECT_THROW(pq.peek(), EXCEPTION_1);

  // Test of invalid prio
  EXPECT_THROW(pq.queueWithPriority("Hello", 2), std::invalid_argument);
}