

/*
浮点数转化为内存存储方式
将一个float型转化为内存存储格式的步骤为：
（1）先将这个实数的绝对值化为二进制格式。
（2）将这个二进制格式实数的小数点左移或右移n位，直到小数点移动到第一个有效数字的右边。
（3）从小数点右边第一位开始数出二十三位数字放入第22到第0位。
（4）如果实数是正的，则在第31位放入“0”，否则放入“1”。
（5）如果n 是左移得到的，说明指数是正的，第30位放入“1”。如果n是右移得到的或n=0，则第30位放入“0”。
（6）如果n是左移得到的，则将n减去1后化为二进制，并在左边加“0”补足七位，放入第29到第23位。如果n是右移得到的或n=0，则将n化为二进制后在左边加“0”补足七位，再各位求反，再放入第29到第23位。
对于指数部分，因为指数可正可负，8位的指数位能表示的指数范围就应该为:-127-128了，所以指数部分的存储采用移位存储，存储的数据为元数据+127
*/

/*
内存存储方式转化为浮点数
将一个内存存储的float二进制格式转化为十进制的步骤：
（1）将第22位到第0位的二进制数写出来，在最左边补一位“1”，得到二十四位有效数字。将小数点点在最左边那个“1”的右边。
（2）取出第29到第23位所表示的值n。当30位是“0”时将n各位求反。当30位是“1”时将n增1。
（3）将小数点左移n位（当30位是“0”时）或右移n位（当30位是“1”时），得到一个二进制表示的实数。
（4）将这个二进制实数化为十进制，并根据第31位是“0”还是“1”加上正号或负号即可。
*/

/*
** converts an integer to a "floating point byte", represented as
** (eeeeexxx), where the real value is (1xxx) * 2^(eeeee - 1) if
** eeeee != 0 and (xxx) otherwise.
*/
int int2fb (unsigned int x) {
  int e = 0;  /* exponent */
  if (x < 8) return x;
  while (x >= (8 << 4)) {  /* coarse steps */
    x = (x + 0xf) >> 4;  /* x = ceil(x / 16) */
    e += 4;
  }
  while (x >= (8 << 1)) {  /* fine steps */
    x = (x + 1) >> 1;  /* x = ceil(x / 2) */
    e++;
  }
  return ((e+1) << 3) | ((int)(x) - 8);
}


/* converts back */
int fb2int (int x) {
  return (x < 8) ? x : ((x & 7) + 8) << ((x >> 3) - 1);
}

