#include "test-framework/unity.h"
#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void shuffle_array(int array[], size_t array_length)
{
   srand(time(NULL));
   for (size_t i = 0; i < array_length; i++) {
      size_t swap_index = rand() % array_length;
      int temp = array[i];
      array[i] = array[swap_index];
      array[swap_index] = temp;
   }
}

static void test_insert_data_on_empty_tree(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;

   TEST_ASSERT_TRUE(insert_data(&tree, 1));
   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(1, tree->data);
   TEST_ASSERT_NULL(tree->left);
   TEST_ASSERT_NULL(tree->right);

   free_tree(tree);
}

static void test_do_not_insert_duplicated_data(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;

   TEST_ASSERT_TRUE(insert_data(&tree, 1));
   TEST_ASSERT_FALSE(insert_data(&tree, 1));

   free_tree(tree);
}

static void test_create_small_balanced_tree(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;

   TEST_ASSERT_TRUE(insert_data(&tree, 2));
   TEST_ASSERT_TRUE(insert_data(&tree, 1));
   TEST_ASSERT_TRUE(insert_data(&tree, 3));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(2, tree->data);
   TEST_ASSERT_NOT_NULL(tree->left);
   TEST_ASSERT_NOT_NULL(tree->right);

   TEST_ASSERT_EQUAL_INT(1, tree->left->data);
   TEST_ASSERT_NULL(tree->left->left);
   TEST_ASSERT_NULL(tree->left->right);

   TEST_ASSERT_EQUAL_INT(3, tree->right->data);
   TEST_ASSERT_NULL(tree->right->left);
   TEST_ASSERT_NULL(tree->right->right);

   free_tree(tree);
}

static void test_create_small_unbalanced_left_tree(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;

   TEST_ASSERT_TRUE(insert_data(&tree, 3));
   TEST_ASSERT_TRUE(insert_data(&tree, 2));
   TEST_ASSERT_TRUE(insert_data(&tree, 1));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(3, tree->data);
   TEST_ASSERT_NOT_NULL(tree->left);
   TEST_ASSERT_NULL(tree->right);

   TEST_ASSERT_EQUAL_INT(2, tree->left->data);
   TEST_ASSERT_NOT_NULL(tree->left->left);
   TEST_ASSERT_NULL(tree->left->right);

   TEST_ASSERT_EQUAL_INT(1, tree->left->left->data);
   TEST_ASSERT_NULL(tree->left->left->right);
   TEST_ASSERT_NULL(tree->left->left->left);

   free_tree(tree);
}

static void test_create_small_unbalanced_right_tree(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;

   TEST_ASSERT_TRUE(insert_data(&tree, 1));
   TEST_ASSERT_TRUE(insert_data(&tree, 2));
   TEST_ASSERT_TRUE(insert_data(&tree, 3));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(1, tree->data);
   TEST_ASSERT_NULL(tree->left);
   TEST_ASSERT_NOT_NULL(tree->right);

   TEST_ASSERT_EQUAL_INT(2, tree->right->data);
   TEST_ASSERT_NULL(tree->right->left);
   TEST_ASSERT_NOT_NULL(tree->right->right);

   TEST_ASSERT_EQUAL_INT(3, tree->right->right->data);
   TEST_ASSERT_NULL(tree->right->right->left);
   TEST_ASSERT_NULL(tree->right->right->right);

   free_tree(tree);
}

static void test_search_random_existent_data(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;
   size_t array_size = 100000;
   int array[array_size];
   for (size_t i = 0; i < array_size; i++)   {
      array[i] = i + 1;
   }
   shuffle_array(array, array_size);
   for (size_t i = 0; i < array_size; i++)   {
      TEST_ASSERT_TRUE(insert_data(&tree, array[i]));
   }
   shuffle_array(array, array_size);
   for (size_t i = 0; i < array_size; i++) {
      TEST_ASSERT_NOT_NULL(search_data(tree, array[i]));
   }
   free_tree(tree);
}

static void test_search_random_inexistent_data(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;
   size_t array_size = 100000;
   int array[array_size];
   for (size_t i = 0; i < array_size; i++)   {
      array[i] = i + 1;
   }
   shuffle_array(array, array_size);
   for (size_t i = 0; i < array_size; i++)   {
      TEST_ASSERT_TRUE(insert_data(&tree, array[i]));
   }
   shuffle_array(array, array_size);
   for (size_t i = 0; i < array_size; i++) {
      TEST_ASSERT_NULL(search_data(tree, array_size+array[i]));
   }
   free_tree(tree);
}

static void test_delete_nodes_without_children(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;
   int data[] = {50, 20, 60, 15, 45, 58, 70, 16, 35, 73, 36, 75};
   for (size_t i = 0; i < ARRAY_SIZE(data); i++)   {
      TEST_ASSERT_TRUE(insert_data(&tree, data[i]));
   }
   TEST_ASSERT_TRUE(delete_data(&tree, 16));
   TEST_ASSERT_FALSE(delete_data(&tree, 16));
   TEST_ASSERT_NULL(tree->left->left->right);
   TEST_ASSERT_TRUE(delete_data(&tree, 36)); 
   TEST_ASSERT_FALSE(delete_data(&tree, 36));   
   TEST_ASSERT_NULL(tree->left->right->left->right);  
   TEST_ASSERT_TRUE(delete_data(&tree, 58));   
   TEST_ASSERT_FALSE(delete_data(&tree, 58));   
   TEST_ASSERT_NULL(tree->right->left);
   TEST_ASSERT_TRUE(delete_data(&tree, 75));
   TEST_ASSERT_FALSE(delete_data(&tree, 75));   
   TEST_ASSERT_NULL(tree->right->right->right->right);
   free_tree(tree);   
}

static void test_delete_nodes_with_one_child(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;
   int data[] = {50, 20, 60, 15, 45, 58, 70, 16, 35, 73, 36, 75};
   for (size_t i = 0; i < ARRAY_SIZE(data); i++)   {
      TEST_ASSERT_TRUE(insert_data(&tree, data[i]));
   }
   TEST_ASSERT_TRUE(delete_data(&tree, 15));
   TEST_ASSERT_FALSE(delete_data(&tree, 15));
   TEST_ASSERT_EQUAL_INT(16, tree->left->left->data);
   TEST_ASSERT_TRUE(delete_data(&tree, 35)); 
   TEST_ASSERT_FALSE(delete_data(&tree, 35));   
   TEST_ASSERT_EQUAL_INT(36, tree->left->right->left->data);
   TEST_ASSERT_TRUE(delete_data(&tree, 45));   
   TEST_ASSERT_FALSE(delete_data(&tree, 45));   
   TEST_ASSERT_EQUAL_INT(36, tree->left->right->data);
   TEST_ASSERT_TRUE(delete_data(&tree, 70));
   TEST_ASSERT_FALSE(delete_data(&tree, 70));   
   TEST_ASSERT_EQUAL_INT(73, tree->right->right->data);
   TEST_ASSERT_TRUE(delete_data(&tree, 73));
   TEST_ASSERT_FALSE(delete_data(&tree, 73));   
   TEST_ASSERT_EQUAL_INT(75, tree->right->right->data);
   free_tree(tree);   
}

static void test_delete_nodes_with_two_children(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;
   int data[] = {50, 20, 60, 15, 45, 58, 70, 16, 35, 73, 36, 75};
   for (size_t i = 0; i < ARRAY_SIZE(data); i++)   {
      TEST_ASSERT_TRUE(insert_data(&tree, data[i]));
   }
   TEST_ASSERT_TRUE(delete_data(&tree, 20));
   TEST_ASSERT_FALSE(delete_data(&tree, 20));   
   TEST_ASSERT_EQUAL_INT(35, tree->left->data);
   TEST_ASSERT_EQUAL_INT(36, tree->left->right->left->data);
   TEST_ASSERT_TRUE(delete_data(&tree, 60));
   TEST_ASSERT_FALSE(delete_data(&tree, 60));
   TEST_ASSERT_EQUAL_INT(70, tree->right->data);
   TEST_ASSERT_EQUAL_INT(73, tree->right->right->data);   
   TEST_ASSERT_TRUE(delete_data(&tree, 50));
   TEST_ASSERT_FALSE(delete_data(&tree, 50));
   TEST_ASSERT_EQUAL_INT(58, tree->data);
   TEST_ASSERT_NULL(tree->right->left);

   free_tree(tree);   
}

static void test_delete_random_data(void)
{
   TEST_IGNORE();
   node_t *tree = NULL;
   size_t array_length = 100000;
   int array[array_length];
   for (size_t i = 0; i < array_length; i++)   {
      array[i] = i + 1;
   }
   shuffle_array(array, array_length);
   for (size_t i = 0; i < array_length; i++)   {
      TEST_ASSERT_TRUE(insert_data(&tree, array[i]));
   }
   int data = array[rand() % array_length];
   TEST_ASSERT_TRUE(delete_data(&tree, data));
   TEST_ASSERT_FALSE(delete_data(&tree, data));
   TEST_ASSERT_NULL(search_data(tree, data));

   free_tree(tree);
}

static void test_data_build_small_tree(void)
{
   TEST_IGNORE();   // delete this line to run test
   int tree_data[] = { 4 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(4, tree->data);
   TEST_ASSERT_NULL(tree->left);
   TEST_ASSERT_NULL(tree->right);

   free_tree(tree);
}

static void test_data_smaller_number_at_left_node(void)
{
   TEST_IGNORE();   // delete this line to run test
   int tree_data[] = { 4, 2 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(4, tree->data);
   TEST_ASSERT_NOT_NULL(tree->left);
   TEST_ASSERT_NULL(tree->right);

   TEST_ASSERT_EQUAL_INT(2, tree->left->data);
   TEST_ASSERT_NULL(tree->left->left);
   TEST_ASSERT_NULL(tree->left->right);

   free_tree(tree);
}

static void test_data_not_duplicated(void)
{
   TEST_IGNORE();
   int tree_data[] = { 4, 4 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(4, tree->data);
   TEST_ASSERT_NULL(tree->left);
   TEST_ASSERT_NULL(tree->right);

   free_tree(tree);
}

static void test_data_greater_number_at_right_node(void)
{
   TEST_IGNORE();
   int tree_data[] = { 4, 5 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(4, tree->data);
   TEST_ASSERT_NULL(tree->left);
   TEST_ASSERT_NOT_NULL(tree->right);

   TEST_ASSERT_EQUAL_INT(5, tree->right->data);
   TEST_ASSERT_NULL(tree->right->left);
   TEST_ASSERT_NULL(tree->right->right);

   free_tree(tree);
}

static void test_data_build_tree(void)
{
   TEST_IGNORE();
   int tree_data[] = { 4, 2, 6, 1, 3, 5, 7 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_NOT_NULL(tree);
   TEST_ASSERT_EQUAL_INT(4, tree->data);
   TEST_ASSERT_NOT_NULL(tree->left);
   TEST_ASSERT_NOT_NULL(tree->right);

   TEST_ASSERT_EQUAL_INT(2, tree->left->data);
   TEST_ASSERT_NOT_NULL(tree->left->left);
   TEST_ASSERT_NOT_NULL(tree->left->right);

   TEST_ASSERT_EQUAL_INT(6, tree->right->data);
   TEST_ASSERT_NOT_NULL(tree->right->left);
   TEST_ASSERT_NOT_NULL(tree->right->right);

   TEST_ASSERT_EQUAL_INT(1, tree->left->left->data);
   TEST_ASSERT_NULL(tree->left->left->left);
   TEST_ASSERT_NULL(tree->left->left->right);

   TEST_ASSERT_EQUAL_INT(3, tree->left->right->data);
   TEST_ASSERT_NULL(tree->left->right->left);
   TEST_ASSERT_NULL(tree->left->right->right);

   TEST_ASSERT_EQUAL_INT(5, tree->right->left->data);
   TEST_ASSERT_NULL(tree->right->left->left);
   TEST_ASSERT_NULL(tree->right->left->right);

   TEST_ASSERT_EQUAL_INT(7, tree->right->right->data);
   TEST_ASSERT_NULL(tree->right->right->left);
   TEST_ASSERT_NULL(tree->right->right->right);

   free_tree(tree);
}

static void test_sorted_data_can_sort_single_number(void)
{
   TEST_IGNORE();
   int tree_data[] = { 2 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   int expected[] = { 2 };
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

static void
test_sorted_data_can_sort_if_second_number_is_smaller_than_first(void)
{
   TEST_IGNORE();
   int tree_data[] = { 2, 1 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   int expected[] = { 1, 2 };
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

static void test_sorted_data_can_sort_if_second_number_is_same_as_first(void)
{
   TEST_IGNORE();
   int tree_data[] = { 2, 2 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   int expected[] = { 2 };
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

static void
test_sorted_data_can_sort_if_second_number_is_greater_than_first(void)
{
   TEST_IGNORE();
   int tree_data[] = { 2, 3 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   int expected[] = { 2, 3 };
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

static void test_sorted_data_can_sort_tree(void)
{
   TEST_IGNORE();
   int tree_data[] = { 2, 1, 3, 6, 7, 5 };
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   int expected[] = { 1, 2, 3, 5, 6, 7 };
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

static void test_sorted_data_can_sort_huge_amount_of_data(void)
{
   TEST_IGNORE();
   size_t array_size = 100000;
   int tree_data[array_size];
   int expected[array_size];
   for (size_t i = 0; i < array_size; i++)   {
      expected[i] = tree_data[i] = i + 1;
   }
   shuffle_array(tree_data, array_size);
   node_t *tree = build_tree(tree_data, array_size);
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, array_size);

   free_tree(tree);
   free(actual);
}

static void test_sorted_data_after_delete_nodes_without_children(void)
{
   TEST_IGNORE();
   int tree_data[] = {50, 20, 60, 15, 45, 58, 70, 16, 35, 73, 36, 75};
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_TRUE(delete_data(&tree, 58));
   TEST_ASSERT_TRUE(delete_data(&tree, 16));
   TEST_ASSERT_TRUE(delete_data(&tree, 75));
   TEST_ASSERT_TRUE(delete_data(&tree, 36));

   int expected[] = { 15, 20, 35, 45, 50, 60, 70, 73};
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}


static void test_sorted_data_after_delete_nodes_with_one_child(void)
{
   TEST_IGNORE();
   int tree_data[] = {50, 20, 60, 15, 45, 58, 70, 16, 35, 73, 36, 75};
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_TRUE(delete_data(&tree, 70));
   TEST_ASSERT_TRUE(delete_data(&tree, 15));
   TEST_ASSERT_TRUE(delete_data(&tree, 73));
   TEST_ASSERT_TRUE(delete_data(&tree, 45));
   TEST_ASSERT_TRUE(delete_data(&tree, 35));

   int expected[] = { 16, 20, 36, 50, 58, 60, 75};
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

static void test_sorted_data_after_delete_nodes_with_two_children(void)
{
   TEST_IGNORE();
   int tree_data[] = {50, 20, 60, 15, 45, 58, 70, 16, 35, 73, 36, 75};
   node_t *tree = build_tree(tree_data, ARRAY_SIZE(tree_data));

   TEST_ASSERT_TRUE(delete_data(&tree, 20));
   TEST_ASSERT_TRUE(delete_data(&tree, 60));
   TEST_ASSERT_TRUE(delete_data(&tree, 50));

   int expected[] = { 15, 16, 35, 36, 45, 58, 70, 73, 75};
   int *actual = sorted_data(tree);
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_SIZE(expected));

   free_tree(tree);
   free(actual);
}

int main(void)
{
   UnityBegin("test_binary_search_tree.c");

   RUN_TEST(test_insert_data_on_empty_tree);
   RUN_TEST(test_do_not_insert_duplicated_data);
   RUN_TEST(test_create_small_balanced_tree);
   RUN_TEST(test_create_small_unbalanced_left_tree);
   RUN_TEST(test_create_small_unbalanced_right_tree);
   RUN_TEST(test_search_random_existent_data);
   RUN_TEST(test_search_random_inexistent_data);
   RUN_TEST(test_delete_nodes_without_children);   
   RUN_TEST(test_delete_nodes_with_one_child);
   RUN_TEST(test_delete_nodes_with_two_children);   
   RUN_TEST(test_delete_random_data);

   RUN_TEST(test_data_build_small_tree);
   RUN_TEST(test_data_smaller_number_at_left_node);
   RUN_TEST(test_data_not_duplicated);
   RUN_TEST(test_data_greater_number_at_right_node);
   RUN_TEST(test_data_build_tree);

   RUN_TEST(test_sorted_data_can_sort_single_number);
   RUN_TEST(test_sorted_data_can_sort_if_second_number_is_smaller_than_first);
   RUN_TEST(test_sorted_data_can_sort_if_second_number_is_same_as_first);
   RUN_TEST(test_sorted_data_can_sort_if_second_number_is_greater_than_first);
   RUN_TEST(test_sorted_data_can_sort_tree);
   RUN_TEST(test_sorted_data_can_sort_huge_amount_of_data);
   RUN_TEST(test_sorted_data_after_delete_nodes_without_children);
   RUN_TEST(test_sorted_data_after_delete_nodes_with_one_child);   
   RUN_TEST(test_sorted_data_after_delete_nodes_with_two_children);

   return UnityEnd();
}
