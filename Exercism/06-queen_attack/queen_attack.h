#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#define MIN 0
#define MAX 7

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);

#endif