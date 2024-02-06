# scorp10ns_myfirst_crackme

"prime number" is a nice idea

- syntax of command line must be "crackme key"
  - argc must be exactly 2
- key in XXXX-XXXX-XXXX-XXXX format
- strlen of key must be 19
- dashes ('-') must appear in the right places
- as in AAAA-BBBB-CCCC-DDDD:
  - the sum of each group ("AAAA" or "BBBB" ... ) must be a prime number
  - the sum for each group must exactly in an ascending order
    - i.e. sumof("AAAA") < sumof("BBBB") < sumof("CCCC") < sumof("DDDD")

note:
in the crackme we can see the author checks prime numbers not divisible by all numbers from 2 to (target number/2).
actually only [2, floor of sqrt(n)] is required