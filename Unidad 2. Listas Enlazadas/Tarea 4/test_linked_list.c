#include <stddef.h>
#include "test-framework/unity.h"
#include "linked_list.h"

static list_node_t *list;

void setUp(void)
{
   list_init(&list);
}

void tearDown(void)
{
   list_destroy(&list);
}

static void test_empty_list(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(list_is_empty(list));
}

static void test_count_an_empty_list(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, list_count(list));
}

static void test_push_front_and_get_first_element_from_the_list(void)
{
   TEST_IGNORE();   // delete this line to run test
   list_push_front(&list, 7);
   TEST_ASSERT_EQUAL(7, list_front(list));
}

static void test_push_back_and_get_last_element_from_the_list(void)
{
   TEST_IGNORE();   // delete this line to run test
   list_push_back(&list, 7);
   TEST_ASSERT_EQUAL(7, list_back(list));
}

static void test_add_remove_at_the_end_of_the_list(void)
{
   TEST_IGNORE();   // delete this line to run test
   list_push_back(&list, 11);
   list_push_back(&list, 13);
   TEST_ASSERT_EQUAL(13, list_back(list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(11, list_back(list));
}

static void test_pop_front_gets_an_element_from_the_list(void)
{
   TEST_IGNORE();
   list_push_back(&list, 17);
   TEST_ASSERT_EQUAL(17, list_front(list));
}

static void test_pop_front_gets_first_element_from_the_list(void)
{
   TEST_IGNORE();
   list_push_back(&list, 23);
   list_push_back(&list, 5);
   TEST_ASSERT_EQUAL(23, list_front(list));
   list_pop_front(&list);
   TEST_ASSERT_EQUAL(5, list_front(list));
}

static void test_push_front_adds_element_at_start_of_the_list(void)
{
   TEST_IGNORE();
   list_push_front(&list, 23);
   list_push_front(&list, 5);
   TEST_ASSERT_EQUAL(5, list_front(list));
   list_pop_front(&list);
   TEST_ASSERT_EQUAL(23, list_front(list));
}

static void test_push_pop_front_back_can_be_used_in_any_order(void)
{
   TEST_IGNORE();
   list_push_back(&list, 1);
   list_push_back(&list, 2);
   TEST_ASSERT_EQUAL(2, list_back(list));
   list_pop_back(&list);
   list_push_back(&list, 3);
   TEST_ASSERT_EQUAL(1, list_front(list));
   list_pop_front(&list);
   list_push_front(&list, 4);
   list_push_back(&list, 5);
   TEST_ASSERT_EQUAL(4, list_front(list));
   list_pop_front(&list);
   TEST_ASSERT_EQUAL(5, list_back(list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(3, list_front(list));
}

static void test_count_a_list_with_items(void)
{
   TEST_IGNORE();
   list_push_back(&list, 37);
   list_push_back(&list, 1);
   TEST_ASSERT_EQUAL(2, list_count(list));
}

static void test_count_is_correct_after_mutation(void)
{
   TEST_IGNORE();
   list_push_back(&list, 31);
   TEST_ASSERT_EQUAL(1, list_count(list));
   list_push_front(&list, 43);
   TEST_ASSERT_EQUAL(2, list_count(list));
   list_pop_front(&list);
   TEST_ASSERT_EQUAL(1, list_count(list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(0, list_count(list));
}

static void test_pop_back_to_empty_does_not_break_the_list(void)
{
   TEST_IGNORE();
   list_push_back(&list, 41);
   list_push_back(&list, 59);
   list_pop_back(&list);
   list_pop_back(&list);
   list_push_back(&list, 47);
   TEST_ASSERT_EQUAL(1, list_count(list));
   TEST_ASSERT_EQUAL(47, list_back(list));
}

static void test_pop_front_to_empty_does_not_break_the_list(void)
{
  TEST_IGNORE();
   list_push_back(&list, 41);
   list_push_back(&list, 59);
   list_pop_front(&list);
   list_pop_front(&list);
   list_push_back(&list, 47);
   TEST_ASSERT_EQUAL(1, list_count(list));
   TEST_ASSERT_EQUAL(47, list_front(list));
}

static void test_deletes_the_only_element(void)
{
   TEST_IGNORE();
   list_push_back(&list, 61);
   list_delete(&list, 61);
   TEST_ASSERT_EQUAL(0, list_count(list));
}

static void
test_deletes_the_element_with_the_specified_value_from_the_list(void)
{
   TEST_IGNORE();
   list_push_back(&list, 71);
   list_push_back(&list, 83);
   list_push_back(&list, 79);
   list_delete(&list, 83);
   TEST_ASSERT_EQUAL(2, list_count(list));
   TEST_ASSERT_EQUAL(79, list_back(list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(71, list_front(list));
}

static void
test_deletes_the_element_with_the_specified_value_from_the_list_reassigns_tail(
    void)
{
   TEST_IGNORE();
   list_push_back(&list, 71);
   list_push_back(&list, 83);
   list_push_back(&list, 79);
   list_delete(&list, 83);
   TEST_ASSERT_EQUAL(2, list_count(list));
   TEST_ASSERT_EQUAL(79, list_back(list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(71, list_back(list));
}

static void
test_deletes_the_element_with_the_specified_value_from_the_list_reassigns_head(
    void)
{
   TEST_IGNORE();
   list_push_back(&list, 71);
   list_push_back(&list, 83);
   list_push_back(&list, 79);
   list_delete(&list, 83);
   TEST_ASSERT_EQUAL(2, list_count(list));
   TEST_ASSERT_EQUAL(71, list_front(list));
   list_pop_front(&list);
   TEST_ASSERT_EQUAL(79, list_front(list));
}

static void test_deletes_the_first_of_two_elements(void)
{
   TEST_IGNORE();
   list_push_back(&list, 97);
   list_push_back(&list, 101);
   list_delete(&list, 97);
   TEST_ASSERT_EQUAL(1, list_count(list));
   TEST_ASSERT_EQUAL(101, list_back(list));
}

static void test_deletes_the_second_of_two_elements(void)
{
   TEST_IGNORE();
   list_push_back(&list, 97);
   list_push_back(&list, 101);
   list_delete(&list, 101);
   TEST_ASSERT_EQUAL(1, list_count(list));
   TEST_ASSERT_EQUAL(97, list_back(list));
}

static void
test_delete_does_not_modify_the_list_if_the_element_is_not_found(void)
{
   TEST_IGNORE();
   list_push_back(&list, 89);
   list_delete(&list, 103);
   TEST_ASSERT_EQUAL(1, list_count(list));
}

static void test_deletes_only_the_first_occurrence(void)
{
   TEST_IGNORE();
   list_push_back(&list, 73);
   list_push_back(&list, 9);
   list_push_back(&list, 9);
   list_push_back(&list, 107);
   list_delete(&list, 9);
   TEST_ASSERT_EQUAL(3, list_count(list));
   TEST_ASSERT_EQUAL(107, list_back(list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(9, list_back(list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(73, list_back(list));
}

int main(void)
{
   UnityBegin("test_linked_list.c");

   RUN_TEST(test_empty_list);
   RUN_TEST(test_count_an_empty_list);
   RUN_TEST(test_push_front_and_get_first_element_from_the_list);
   RUN_TEST(test_push_back_and_get_last_element_from_the_list);
   RUN_TEST(test_add_remove_at_the_end_of_the_list);
   RUN_TEST(test_pop_front_gets_an_element_from_the_list);
   RUN_TEST(test_pop_front_gets_first_element_from_the_list);
   RUN_TEST(test_push_front_adds_element_at_start_of_the_list);
   RUN_TEST(test_push_pop_front_back_can_be_used_in_any_order);
   RUN_TEST(test_count_a_list_with_items);
   RUN_TEST(test_count_is_correct_after_mutation);
   RUN_TEST(test_pop_back_to_empty_does_not_break_the_list);
   RUN_TEST(test_pop_front_to_empty_does_not_break_the_list);
   RUN_TEST(test_deletes_the_only_element);
   RUN_TEST(test_deletes_the_element_with_the_specified_value_from_the_list);
   RUN_TEST(
       test_deletes_the_element_with_the_specified_value_from_the_list_reassigns_tail);
   RUN_TEST(
       test_deletes_the_element_with_the_specified_value_from_the_list_reassigns_head);
   RUN_TEST(test_deletes_the_first_of_two_elements);
   RUN_TEST(test_deletes_the_second_of_two_elements);
   RUN_TEST(test_delete_does_not_modify_the_list_if_the_element_is_not_found);
   RUN_TEST(test_deletes_only_the_first_occurrence);

   return UnityEnd();
}
