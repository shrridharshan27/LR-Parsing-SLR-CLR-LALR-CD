# LR Parsing (SLR, CLR, LALR) & Table Generation

[![Language](https://img.shields.io/badge/Language-C99%20%2F%20Lex%20%26%20Yacc-00599C.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Parser](https://img.shields.io/badge/Parsing-SLR(1)%20%2F%20CLR(1)%20%2F%20LALR(1)-green.svg)](https://gcc.gnu.org/)
[![Course](https://img.shields.io/badge/Course-BCSE306L%20Compiler%20Design-red.svg)](https://vit.ac.in)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Author Information
- **Author:** Shrri Dharshan D R
- **GitHub:** [@shrridharshan27](https://github.com/shrridharshan27)
- **Registration Number:** `23BPS1090`
- **Course:** Compiler Design Laboratory (`BCSE306L`)
- **Lab Slot:** `L23+L24`

---

## Overview
This repository contains algorithmic implementations and comparative evaluations of the three principal **Bottom-Up LR Parsing** methodologies:
1. **Simple LR (SLR(1))**: Uses $LR(0)$ item collections and places reduce actions according to non-terminal $FOLLOW$ sets.
2. **Canonical LR (CLR(1))**: Employs $LR(1)$ items $[A \to \alpha \cdot \beta, a]$ carrying lookaheads; achieves maximum parsing expressiveness.
3. **Look-Ahead LR (LALR(1))**: Merges $LR(1)$ states possessing identical cores; the standard parsing architecture for Yacc and Bison.

---

## Comparison Table
| Metric | SLR(1) | CLR(1) | LALR(1) |
| :--- | :--- | :--- | :--- |
| **Item Form** | $[A \to \alpha \cdot \beta]$ | $[A \to \alpha \cdot \beta, a]$ | Merged $[A \to \alpha \cdot \beta, a/b]$ |
| **Number of States** | $K$ (Minimal) | Significantly larger | Identical to SLR ($K$) |
| **Reduce Action Condition** | $a \in FOLLOW(A)$ | $a ==$ lookahead | Lookahead of merged core |
| **Parsing Power** | Weakest LR family | Strongest deterministic CFG | Industry standard |

---

## Compilation & Execution
```bash
# Compile and run LR demonstration
gcc -std=c99 -Wall -Wextra src/lr_parser.c -o build/lr_parser
./build/lr_parser
```

---

## License
MIT License - see [LICENSE](LICENSE) for details.
