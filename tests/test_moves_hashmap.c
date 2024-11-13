// tests/test_moves_hashmap.c

#include "unity.h"
#include "moves_hashmap.h"

static MoveHash_t *g_moves = NULL;
static IntListNode_t *g_node_head_test = NULL;
void setUp() {
    // 在每个测试之前初始化
    g_moves = NULL;
    g_node_head_test = NULL;
}

void tearDown() {
    // 在每个测试之后清理
}


void test_case_move_hash_empty(){
    TEST_ASSERT_NULL(g_moves);
}

void test_case_merge_flip_to_empty_lists(void){
    int flip_positions[] = {11,12,13,14,15,16,17,18,19,20};
    IntListNode_t *node_head = NULL;
    
    for(size_t i = 0; i < sizeof(flip_positions)/sizeof(flip_positions[0]); i++){
        list_push_front(&node_head, flip_positions[i]);
    }
    // merge_flip_lists(&g_node_head_test,node_head);
    LL_CONCAT(g_node_head_test,node_head);
    TEST_ASSERT_NOT_NULL(g_node_head_test);
}

void test_case_list_push_front(void){
    
    IntListNode_t *node = NULL;
    IntListNode_t *tmp = NULL;
    
    int flip_positions[] = {1,2,3,4,5,6,7,8,9,10};
    
    for(size_t i = 0; i < sizeof(flip_positions)/sizeof(flip_positions[0]); i++){
        list_push_front(&g_node_head_test, flip_positions[i]);
    }
    TEST_ASSERT_NOT_NULL(g_node_head_test);
    TEST_ASSERT_NOT_NULL(g_node_head_test->next);
    size_t index = sizeof(flip_positions)/sizeof(int);
    LL_FOREACH_SAFE(g_node_head_test,node,tmp){
        TEST_ASSERT_NOT_NULL(node);
        TEST_ASSERT_EQUAL(node->flip_position, flip_positions[index-1]);
        index--;
    }
    TEST_ASSERT_EQUAL(0, index);
    
}


void test_case_merge_flip_lists(void){
    // IntListNode_t *node = NULL;
    // IntListNode_t *tmp = NULL;
    IntListNode_t *node_head_2 = NULL;
    
    int flip_positions[] = {11,12,13,14,15,16,17,18,19,20};
    
    for(size_t i = 0; i < sizeof(flip_positions)/sizeof(flip_positions[0]); i++){
        list_push_front(&node_head_2, flip_positions[i]);
    }
    TEST_ASSERT_NOT_NULL(node_head_2);
    // merge_flip_lists(&g_node_head_test,node_head_2);
    LL_CONCAT(g_node_head_test,node_head_2);
    TEST_ASSERT_NOT_NULL(g_node_head_test);
    TEST_ASSERT_NOT_NULL(g_node_head_test->next);
    
}

void test_case_insert_moves_first_moves(void){
    MovePair_t *pair = NULL;
    IntListNode_t *node = NULL;
    IntListNode_t *node2 = NULL;
    int flip_positions[] = {10,9,8,7,6,5,4,3,2,1,0};

    pair = (MovePair_t *)malloc(sizeof(MovePair_t));
    TEST_ASSERT_NOT_NULL(pair);

    pair->position = 3;
    TEST_ASSERT_EQUAL_INT32(3, pair->position);
    
    pair->flip_list = NULL;
    for(size_t i = 0; i < sizeof(flip_positions)/sizeof(flip_positions[0]); i++){
        
        if(NULL == pair->flip_list){
            list_push_front(&pair->flip_list, flip_positions[i]);
        }
    }
    TEST_ASSERT_NOT_NULL(pair->flip_list);

    size_t index = 0;
    LL_FOREACH_SAFE(pair->flip_list,node,node2){
        TEST_ASSERT_EQUAL(flip_positions[index], node->flip_position);
        index++;
    }

    insert_moves(&g_moves, pair);
    TEST_ASSERT_NOT_NULL(g_moves);
    TEST_ASSERT_EQUAL(1, size_moves(g_moves));
    TEST_ASSERT_NOT_NULL(g_moves->moves_pair.flip_list);
    // TEST_ASSERT_EQUAL_INT(11, LL_COUNT(g_moves->moves_pair.flip_list));
    
    
}

void test_case_insert_moves_merge_flip_in_moves(void){
    MovePair_t *pair = NULL;
    IntListNode_t *node = NULL;
    IntListNode_t *node2 = NULL;
    
    // 测试向当前move下面增加翻转棋子
    int flip_positions2[] = {11,12,13,14,15};
    pair = (MovePair_t *)malloc(sizeof(MovePair_t));
    TEST_ASSERT_NOT_NULL(pair);

    pair->position = 3;
    TEST_ASSERT_EQUAL_INT32(3, pair->position);
    
    pair->flip_list = NULL;
    for(size_t i = 0; i < sizeof(flip_positions2)/sizeof(flip_positions2[0]); i++){
        
        if(NULL == pair->flip_list){
            list_push_front(&pair->flip_list, flip_positions2[i]);
        }
    }
    TEST_ASSERT_NOT_NULL(pair->flip_list);

    
    size_t index_2 = 0;
    LL_FOREACH_SAFE(pair->flip_list,node,node2){
        TEST_ASSERT_EQUAL(flip_positions2[index_2], node->flip_position);
        index_2++;
    }
    
    insert_moves(&g_moves, pair);
    TEST_ASSERT_NOT_NULL(g_moves);
    TEST_ASSERT_EQUAL(1, size_moves(g_moves));
}

void test_case_insert_moves_insert_another_move(void){
    MovePair_t *pair = NULL;
    IntListNode_t *node = NULL;
    IntListNode_t *node2 = NULL;
    int flip_positions3[] = {16,17,18,19,20};
    
    pair = (MovePair_t *)malloc(sizeof(MovePair_t));
    TEST_ASSERT_NOT_NULL(pair);

    pair->position = 4;
    TEST_ASSERT_EQUAL_INT32(4, pair->position);
    
    pair->flip_list = NULL;
    for(size_t i = 0; i < sizeof(flip_positions3)/sizeof(flip_positions3[0]); i++){
        
        if(NULL == pair->flip_list){
            list_push_front(&pair->flip_list, flip_positions3[i]);
        }
    }
    TEST_ASSERT_NOT_NULL(pair->flip_list);

    
    size_t index_3 = 0;
    LL_FOREACH_SAFE(pair->flip_list,node,node2){
        TEST_ASSERT_EQUAL(flip_positions3[index_3], node->flip_position);
        index_3++;
    }
    
    insert_moves(&g_moves, pair);
    TEST_ASSERT_NOT_NULL(g_moves);
    TEST_ASSERT_EQUAL(2, size_moves(g_moves));
    

    print_moves(g_moves);
    
}

void test_case_delete_move(void){
    int postion = 3;
    
    delete_move(g_moves, postion);
    TEST_ASSERT_NOT_EQUAL(2, size_moves(g_moves));
    TEST_ASSERT_EQUAL(1, size_moves(g_moves));
    TEST_ASSERT_NOT_NULL(g_moves);
}

void test_add_move() {
    // MoveHash *g_moves = NULL;
    // int flip_positions[] = {1, 2, 3};

    // // 测试添加移动
    // insert_moves(g_moves, 10, flip_positions, 3);
    // TEST_ASSERT_NOT_NULL(g_moves);
    // TEST_ASSERT_EQUAL(1, size_moves(g_moves));

    // // 检查 flip 列表是否包含正确的元素
    // MOVES_PAIR_T *move = find_move(g_moves, 10);
    // TEST_ASSERT_NOT_NULL(move);
    // TEST_ASSERT_EQUAL(10, move->position);

    // // 清理
    // clear_moves(g_moves);
}

void test_clear_moves() {
    MoveHash_t *g_moves = NULL;

    // 添加一些移动
    int flip_positions[] = {1, 2, 3};
    // insert_moves(g_moves, 10, flip_positions, 3);
    // insert_moves(g_moves, 20, flip_positions, 3);

    // 确认插入
    TEST_ASSERT_EQUAL(2, size_moves(g_moves));

    // 清空所有移动
    clear_moves(g_moves);
    TEST_ASSERT_EQUAL(0, size_moves(g_moves));
}

int main() {
    UNITY_BEGIN();

    // 测试哈希表是否为空
    RUN_TEST(test_case_move_hash_empty);

    // 测试构建一个非空的哈希表
    // RUN_TEST();
    
    RUN_TEST(test_case_merge_flip_to_empty_lists);
    RUN_TEST(test_case_list_push_front);
    RUN_TEST(test_case_merge_flip_lists);
    RUN_TEST(test_case_insert_moves_first_moves);
    RUN_TEST(test_case_insert_moves_merge_flip_in_moves);
    RUN_TEST(test_case_insert_moves_insert_another_move);
    RUN_TEST(test_case_delete_move);
      


    return UNITY_END();
}
