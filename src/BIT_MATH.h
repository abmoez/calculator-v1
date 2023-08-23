#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(var,bit_no) var|=(1<<bit_no)
#define clear_bit(var,bit_no) var&=~(1<<bit_no)
#define toggle_bit(var,bit_no) var^=(1<<bit_no)
#define get_bit(var,bit_no) ((var>>bit_no)&1)

#endif
