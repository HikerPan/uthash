// tests/test_moves_hashmap.c

#include "unity.h"
#include "moves_hashmap.h"

void setUp() {
    // 在每个测试之前初始化
}

void tearDown() {
    // 在每个测试之后清理
}

void test_insert_moves(){
    MoveHash_t *moves = NULL;
    MovePair_t *pair = NULL;
    int flip_positions[] = {10,9,8,7,6,5,4,3,2,1,0};

    pair = (MovePair_t *)malloc(sizeof(MovePair_t));
    TEST_ASSERT_NOT_NULL(pair);

    // pair->position = 3;
    // for(size_t i = 0; i < sizeof(flip_positions)/sizeof(flip_positions[0]); i++){
        
    //     if(NULL == pair->flip_list){
    //         list_push_front(&pair->flip_list, flip_positions[i]);
    //     }
        
    // }

    // insert_moves(moves, pair);
    
    // list_push_front(&pair->flip_list, flip_positions[0]);

    // // 测试插入移动
    // insert_moves(moves, 10, flip_positions, 3);
    // TEST_ASSERT_NOT_NULL(moves);
    // TEST_ASSERT_EQUAL(1, size_moves(moves));


}

void test_add_move() {
    // MoveHash *moves = NULL;
    // int flip_positions[] = {1, 2, 3};

    // // 测试添加移动
    // insert_moves(moves, 10, flip_positions, 3);
    // TEST_ASSERT_NOT_NULL(moves);
    // TEST_ASSERT_EQUAL(1, size_moves(moves));

    // // 检查 flip 列表是否包含正确的元素
    // MOVES_PAIR_T *move = find_move(moves, 10);
    // TEST_ASSERT_NOT_NULL(move);
    // TEST_ASSERT_EQUAL(10, move->position);

    // // 清理
    // clear_moves(moves);
}

void test_clear_moves() {
    MoveHash_t *moves = NULL;

    // 添加一些移动
    int flip_positions[] = {1, 2, 3};
    // insert_moves(moves, 10, flip_positions, 3);
    // insert_moves(moves, 20, flip_positions, 3);

    // 确认插入
    TEST_ASSERT_EQUAL(2, size_moves(moves));

    // 清空所有移动
    clear_moves(moves);
    TEST_ASSERT_EQUAL(0, size_moves(moves));
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_insert_moves);


    return UNITY_END();
}
