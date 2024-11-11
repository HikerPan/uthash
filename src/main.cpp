#include <cstdio>
#include "moves_hashmap.h"

int main() {
    MoveHash *moves = NULL;
    int flip_positions[] = {12, 23, 34}; // 示例翻转位置

    // 添加移动
    insert_moves(moves, 10, flip_positions, 3);
    print_moves(moves);

    // 清除所有移动
    clear_moves(moves);
    return 0;
}
