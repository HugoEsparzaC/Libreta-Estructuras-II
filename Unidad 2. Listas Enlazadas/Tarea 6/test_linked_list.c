#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "test-framework/unity.h"
#include "linked_list.h"

static list_t list;

void setUp(void)
{
   list_init(&list);
}

void tearDown(void)
{
   list_destroy(&list);
}

static void check_contents(const list_data_t *expected_data, size_t expected_data_size, 
                           const list_t *list)
{
   TEST_ASSERT_EQUAL_size_t_MESSAGE(expected_data_size, list_size(list),
                                    "Incorrect number of elements");
   const list_data_t *data_ptr = expected_data; 
   const list_node_t *node_ptr = list->sentinel->next;
   while (data_ptr < expected_data + expected_data_size && node_ptr != list->sentinel)
   {
      TEST_ASSERT_EQUAL(*data_ptr, node_ptr->data);
      node_ptr = node_ptr->next;
      data_ptr++;
   }
   data_ptr = expected_data + expected_data_size - 1;
   node_ptr = list->sentinel->prev;
   while (data_ptr >= expected_data && node_ptr != list->sentinel)
   {
      TEST_ASSERT_EQUAL(*data_ptr, node_ptr->data);
      node_ptr = node_ptr->prev;
      data_ptr--;
   }
}

static void shuffle(list_data_t array[], size_t length)
{
   srand(time(NULL));
   for (size_t i = 0; i < length; i++) {
      size_t swap_index = rand() % length;
      list_data_t temp = array[i];
      array[i] = array[swap_index];
      array[swap_index] = temp;
   }
}

static void test_empty_list(void)
{
   TEST_IGNORE();
   TEST_ASSERT_TRUE(list_is_empty(&list));
}

static void test_count_an_empty_list(void)
{
   TEST_IGNORE();
   TEST_ASSERT_EQUAL(0, list_size(&list));
}

static void test_push_front_and_get_first_element_from_the_list(void)
{
   TEST_IGNORE();   // delete this line to run test
   list_push_front(&list, 7);
   TEST_ASSERT_EQUAL(7, list_front(&list));
}

static void test_push_back_and_get_last_element_from_the_list(void)
{
   TEST_IGNORE();   // delete this line to run test
   list_push_back(&list, 7);
   TEST_ASSERT_EQUAL(7, list_back(&list));
}

static void test_add_remove_at_the_end_of_the_list(void)
{
   TEST_IGNORE();   // delete this line to run test
   list_push_back(&list, 11);
   list_push_back(&list, 13);
   TEST_ASSERT_EQUAL(13, list_back(&list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(11, list_back(&list));
}

static void test_pop_front_gets_an_element_from_the_list(void)
{
   TEST_IGNORE();
   list_push_back(&list, 17);
   TEST_ASSERT_EQUAL(17, list_front(&list));
}

static void test_pop_front_gets_first_element_from_the_list(void)
{
   TEST_IGNORE();
   list_push_back(&list, 23);
   list_push_back(&list, 5);
   TEST_ASSERT_EQUAL(23, list_front(&list));
   list_pop_front(&list);
   TEST_ASSERT_EQUAL(5, list_front(&list));
}

static void test_push_front_adds_element_at_start_of_the_list(void)
{
   TEST_IGNORE();
   list_push_front(&list, 23);
   list_push_front(&list, 5);
   TEST_ASSERT_EQUAL(5, list_front(&list));
   list_pop_front(&list);
   TEST_ASSERT_EQUAL(23, list_front(&list));
}

static void test_push_pop_front_back_can_be_used_in_any_order(void)
{
   TEST_IGNORE();
   list_push_back(&list, 1);
   list_push_back(&list, 2);
   TEST_ASSERT_EQUAL(2, list_back(&list));
   list_pop_back(&list);
   list_push_back(&list, 3);
   TEST_ASSERT_EQUAL(1, list_front(&list));
   list_pop_front(&list);
   list_push_front(&list, 4);
   list_push_back(&list, 5);
   TEST_ASSERT_EQUAL(4, list_front(&list));
   list_pop_front(&list);
   TEST_ASSERT_EQUAL(5, list_back(&list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(3, list_front(&list));
}

static void test_count_a_list_with_items(void)
{
   TEST_IGNORE();
   list_push_back(&list, 37);
   list_push_back(&list, 1);
   TEST_ASSERT_EQUAL(2, list_size(&list));
}

static void test_count_is_correct_after_mutation(void)
{
   TEST_IGNORE();
   list_push_back(&list, 31);
   TEST_ASSERT_EQUAL(1, list_size(&list));
   list_push_front(&list, 43);
   TEST_ASSERT_EQUAL(2, list_size(&list));
   list_pop_front(&list);
   TEST_ASSERT_EQUAL(1, list_size(&list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(0, list_size(&list));
}

static void test_pop_back_to_empty_does_not_break_the_list(void)
{
   TEST_IGNORE();
   list_push_back(&list, 41);
   list_push_back(&list, 59);
   list_pop_back(&list);
   list_pop_back(&list);
   list_push_back(&list, 47);
   TEST_ASSERT_EQUAL(1, list_size(&list));
   TEST_ASSERT_EQUAL(47, list_back(&list));
}

static void test_pop_front_to_empty_does_not_break_the_list(void)
{
   TEST_IGNORE();
   list_push_back(&list, 41);
   list_push_back(&list, 59);
   list_pop_front(&list);
   list_pop_front(&list);
   list_push_back(&list, 47);
   TEST_ASSERT_EQUAL(1, list_size(&list));
   TEST_ASSERT_EQUAL(47, list_front(&list));
}

static void test_deletes_the_only_element(void)
{
   TEST_IGNORE();
   list_push_back(&list, 61);
   list_delete(&list, 61);
   TEST_ASSERT_EQUAL(0, list_size(&list));
}

static void
test_deletes_the_element_with_the_specified_value_from_the_list(void)
{
   TEST_IGNORE();
   list_push_back(&list, 71);
   list_push_back(&list, 83);
   list_push_back(&list, 79);
   list_delete(&list, 83);
   TEST_ASSERT_EQUAL(2, list_size(&list));
   TEST_ASSERT_EQUAL(79, list_back(&list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(71, list_front(&list));
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
   TEST_ASSERT_EQUAL(2, list_size(&list));
   TEST_ASSERT_EQUAL(79, list_back(&list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(71, list_back(&list));
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
   TEST_ASSERT_EQUAL(2, list_size(&list));
   TEST_ASSERT_EQUAL(71, list_front(&list));
   list_pop_front(&list);
   TEST_ASSERT_EQUAL(79, list_front(&list));
}

static void test_deletes_the_first_of_two_elements(void)
{
   TEST_IGNORE();
   list_push_back(&list, 97);
   list_push_back(&list, 101);
   list_delete(&list, 97);
   TEST_ASSERT_EQUAL(1, list_size(&list));
   TEST_ASSERT_EQUAL(101, list_back(&list));
}

static void test_deletes_the_second_of_two_elements(void)
{
   TEST_IGNORE();
   list_push_back(&list, 97);
   list_push_back(&list, 101);
   list_delete(&list, 101);
   TEST_ASSERT_EQUAL(1, list_size(&list));
   TEST_ASSERT_EQUAL(97, list_back(&list));
}

static void
test_delete_does_not_modify_the_list_if_the_element_is_not_found(void)
{
   TEST_IGNORE();
   list_push_back(&list, 89);
   list_delete(&list, 103);
   TEST_ASSERT_EQUAL(1, list_size(&list));
}

static void test_deletes_only_the_first_occurrence(void)
{
   TEST_IGNORE();
   list_push_back(&list, 73);
   list_push_back(&list, 9);
   list_push_back(&list, 9);
   list_push_back(&list, 107);
   list_delete(&list, 9);
   TEST_ASSERT_EQUAL(3, list_size(&list));
   TEST_ASSERT_EQUAL(107, list_back(&list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(9, list_back(&list));
   list_pop_back(&list);
   TEST_ASSERT_EQUAL(73, list_back(&list));
}

static void test_reverse_empty_list(void)
{
   TEST_IGNORE();
   list_reverse(&list);
   TEST_ASSERT_TRUE(list_is_empty(&list));
}

static void test_reverse_list_with_one_element(void)
{
   TEST_IGNORE();
   list_data_t expected[] = {1};

   list_push_back(&list, 1);
   list_reverse(&list);
   check_contents(expected, sizeof(expected)/sizeof(expected[0]), &list);
}

static void test_reverse_list_with_two_elements(void)
{
   TEST_IGNORE();
   list_data_t expected[] = {2, 1};

   list_push_back(&list, 1);
   list_push_back(&list, 2);
   list_reverse(&list);
   check_contents(expected, sizeof(expected)/sizeof(expected[0]), &list);
}

static void test_reverse_some_data(void)
{
   TEST_IGNORE();
   list_data_t expected[] = {9, 73, 107, 81};

   list_push_back(&list, 73);
   list_push_back(&list, 9);
   list_push_front(&list, 107);
   list_push_front(&list, 81);
   list_reverse(&list);
   check_contents(expected, sizeof(expected)/sizeof(expected[0]), &list);
}

static void test_reverse_huge_amount_of_data(void)
{
   TEST_IGNORE();
   size_t expected_size = 1000000;
   list_data_t expected[expected_size];

   for (size_t i = 0; i < expected_size; i++)   {
      list_data_t data = i+1;
      expected[i] = data;
      list_push_front(&list, data);
   }
   list_reverse(&list);
   check_contents(expected, sizeof(expected)/sizeof(expected[0]), &list);
}

static void test_sort_empty_list(void)
{
   TEST_IGNORE();
   list_sort(&list);
   TEST_ASSERT_TRUE(list_is_empty(&list));
}

static void test_sort_list_with_one_element(void)
{
   TEST_IGNORE();
   list_data_t expected[] = {1};

   list_push_back(&list, 1);
   list_sort(&list);
   check_contents(expected, sizeof(expected)/sizeof(expected[0]), &list);
}

static void test_sort_list_with_two_elements(void)
{
   TEST_IGNORE();
   list_data_t expected[] = {1, 2};

   list_push_back(&list, 2);
   list_push_back(&list, 1);
   list_sort(&list);
   check_contents(expected, sizeof(expected)/sizeof(expected[0]), &list);
}

static void test_sort_some_data(void)
{
   TEST_IGNORE();
   list_data_t expected[] = {1, 2, 3, 4, 5, 6};

   list_push_back(&list, 5);
   list_push_back(&list, 2);
   list_push_back(&list, 4);
   list_push_back(&list, 6);
   list_push_back(&list, 1);
   list_push_back(&list, 3);
   list_sort(&list);
   check_contents(expected, sizeof(expected)/sizeof(expected[0]), &list);
}

static void test_sort_shuffled_data(void)
{
   TEST_IGNORE();
   list_data_t expected[] = {2, 2, 4, 6, 8, 8, 12, 14, 16, 16, 18, 20, 20};
   size_t expected_size = sizeof(expected)/sizeof(expected[0]);
   list_data_t shuffled[expected_size];
   memcpy(shuffled, expected, expected_size * sizeof(list_data_t));
   shuffle(shuffled, expected_size);

   for (size_t i = 0; i < expected_size; i++)   {
      list_push_back(&list, shuffled[i]);
   }
   list_sort(&list);
   check_contents(expected, expected_size, &list);
}

static void test_sort_random_order(void)
{
   TEST_IGNORE();
   size_t expected_size = 5000;
   list_data_t expected[expected_size];
   srand(time(NULL));
   for (size_t i = 0; i < expected_size; i++)   {
      list_data_t data = i+1;
      expected[i] = data;
      if (rand() % 2 == 0) {
         list_push_front(&list, data);
      }
      else {
         list_push_back(&list, data);         
      }
   }
   list_sort(&list);
   check_contents(expected, expected_size, &list);
}

static void test_sort_reversed_data(void)
{
   TEST_IGNORE();
   size_t expected_size = 5000;
   list_data_t expected[expected_size];
   for (size_t i = 0; i < expected_size; i++)   {
      list_data_t data = (i+1) << 1;
      expected[i] = data;
      list_push_back(&list, data);
   }
   list_reverse(&list);
   list_sort(&list);
   check_contents(expected, expected_size, &list);
}

static void test_sort_huge_amount_of_sorted_data(void)
{
   TEST_IGNORE();
   size_t expected_size = 1000000;
   list_data_t expected[expected_size];
   for (size_t i = 0; i < expected_size; i++)   {
      list_data_t data = (i+1) << 1;
      expected[i] = data;
      list_push_back(&list, data);
   }
   list_sort(&list);
   check_contents(expected, expected_size, &list);
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
   RUN_TEST(test_reverse_empty_list);
   RUN_TEST(test_reverse_list_with_one_element);   
   RUN_TEST(test_reverse_list_with_two_elements);   
   RUN_TEST(test_reverse_some_data);
   RUN_TEST(test_reverse_huge_amount_of_data);
   RUN_TEST(test_sort_empty_list);
   RUN_TEST(test_sort_list_with_one_element);   
   RUN_TEST(test_sort_list_with_two_elements);
   RUN_TEST(test_sort_some_data);
   RUN_TEST(test_sort_shuffled_data);      
   RUN_TEST(test_sort_random_order);
   RUN_TEST(test_sort_reversed_data);
   RUN_TEST(test_sort_huge_amount_of_sorted_data);

   return UnityEnd();
}
