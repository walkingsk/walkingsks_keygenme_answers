# scorp10ns_myfirst_crackme

"prime number" is a nice idea

- syntax of command line must be "crackme key"
  - `argc` must be exactly 2
- key in `XXXX-XXXX-XXXX-XXXX` format
- `strlen of key` must be 19
- dashes `('-')` must appear in the right places
- as in `AAAA-BBBB-CCCC-DDDD`:
  - the sum of each group (`"AAAA" or "BBBB" ...` ) must be a prime number
  - the sum for each group must exactly in an ascending order
    - i.e. `sumof("AAAA") < sumof("BBBB") < sumof("CCCC") < sumof("DDDD")`

note1:
- in the crackme we can see the author checks prime numbers not divisible by all numbers from `2 to (target number/2)`.
- actually only `[2, floor of sqrt(n)]` is required

note2:
- since I want to cover all the printable characters `[0x20, 0x7F)` in the basic ASCII table
- the total complexity is limited and the response time can be accepctable
- so brute-force is used to get all possible answers

note3:
- if a space `' '` is generated in the key, single quotes `''` are needed otherwise `argc` will not be 2
- characters related with shell stuffs `'"< | ...` will lead to human-made swamps, that is stupid
