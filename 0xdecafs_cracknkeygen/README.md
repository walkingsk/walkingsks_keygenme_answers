# 0xdecafs_cracknkeygen

Exclusive OR and sum based check
- syntax of command line must be "crackme key"
  - `argc` must be exactly 2
- key must not be "secret"
- in a string "ABCDE...X"
  - a sum is calculated by `A ^ (zero-based-index of A) + B ^ (zero-based-index of B) + ... + X ^ (zero-based-index of X)`
  - I call it xor_sum in this example
  - the xor_sum of "secret" is 0x27B
  - any string other than "secret" that has `xor_sum == 0x27B` would be the correct key


note1:
- analyzing the crackme is not too difficult
- to write a keygen and to cover as many valid cases as possible, however is not easy

writing the keygen:
- each time we generate a random printable character `[0x20, 0x7F)`
- since we know the total xor_sum value, we can calculate the current xor_sum value (to the char we just generated) and calculate the remaining sum `sum_left`
  - if sum_left can fit into a single byte position, we can easily get the could-be character `s_next_could_be`
  - if the calculated `s_next_could_be` is less than `0x20`, that means this is not a proper case, we need to go back and regenerate
  - if the calculated `s_next_could_be` is greater than or equal to `0x7F`, that means it does not fit into a single byte position, we can go ahead to generate random characters
  - if `s_next_could_be` is in `[0x20, 0x40)`, that range could harly (not accurate ?) hold 2 printable characters, we choose to take one character for `s_next_could_be` and end the string
  - if `s_next_could_be` is in `[0x40, 0x7F)`, that means there could be one character or 2 or more characters, we throw a dice to choose: whether to end the string with one character, or with more characters
- we take consideration in each step on the possible `s_next_could_be` cases, and finally get the corrent answer
- I hope my keygen covers all cases with printable characters
