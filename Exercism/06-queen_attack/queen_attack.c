#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (queen_1.column == queen_2.column && queen_1.row == queen_2.row)
        return INVALID_POSITION; // Equal columns and rows
    else if (queen_1.column > MAX || queen_1.column < MIN) // Q1 column on board
        return INVALID_POSITION;
    else if (queen_1.row > MAX || queen_1.row < MIN) // Q1 row on board
        return INVALID_POSITION;
    else if (queen_2.column > MAX || queen_2.column < MIN) // Q2 column on board
        return INVALID_POSITION;
    else if (queen_2.row > MAX || queen_2.row < MIN) // Q2 row on board
        return INVALID_POSITION;
    else if (queen_1.column == queen_2.column) // Equal columns
        return CAN_ATTACK;
    else if (queen_1.row == queen_2.row) // Equal rows
        return CAN_ATTACK;
    else if (abs(queen_1.column - queen_2.column) == abs(queen_1.row - queen_2.row))
        return CAN_ATTACK; // Equal row diff and column diff
    else
        return CAN_NOT_ATTACK;
}

// Needs adaptation to work here