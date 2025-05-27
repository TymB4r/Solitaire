[Back to README](README.md)

# `MOVE` Command Syntax

- `MOVE` — Keyword indicating a move operation
- `<FROM>` — Source pile to move cards from
- `<TO>` — Destination pile to move cards to
- `[COUNT]` — Optional number of cards to move (defaults to 1)

---

## Pile Types

| Symbol | Meaning                 | Index Range / Notes                    |
|--------|-------------------------|----------------------------------------|
| `T`    | Tableau (columns)       | Numbered from 1 to 7 (e.g., `T1`, `T3`)|
| `F`    | Foundation piles        | Numbered from 1 to 4 (e.g., `F2`, `F4`)|
| `W`    | Waste pile (from stock) | No index; always a single pile         |

---

## Details

- `FROM` and `TO` must include the pile type symbol and, if applicable, a number (e.g., `T3`, `F1`).
- `W` (Waste) does not have a number since there is only one waste pile.
- `[COUNT]` is only needed when moving multiple cards — allowed **only** between tableau columns (`T -> T`).
- ✅ You **can move cards from the waste pile** to tableau or foundation piles.
- ❌ You **cannot move cards to the waste pile** directly. The waste pile only receives cards via the `DRAW` command from the stock.
- ❌ Moving cards between foundation piles is not allowed.

---

## Allowed Moves

| FROM | TO  | COUNT | Notes                                    |
|------|-----|-------|------------------------------------------|
| `T`  | `T` | 1..n  | Move a sequence of cards (`COUNT`)       |
| `T`  | `F` | 1     | Move a single card to a foundation       |
| `W`  | `T` | 1     | Move one card from waste to tableau      |
| `W`  | `F` | 1     | Move one card from waste to foundation   |
| `F`  | `T` | 1     | Move one card from foundation to tableau |

---

## Examples

| Command         | Meaning                                           |
|-----------------|---------------------------------------------------|
| `MOVE T4 T1 3`  | Move 3 top cards from tableau 4 to tableau 1      |
| `MOVE T7 F2`    | Move 1 card from tableau 7 to foundation 2        |
| `MOVE W T3`     | Move 1 card from the waste to tableau 3           |
| `MOVE W F1`     | Move 1 card from the waste to foundation 1        |
| `MOVE F3 T5`    | Move 1 card from foundation 3 to tableau 5 (undo) |

---

## Errors and Limitations

- ❌ Invalid command format (e.g., missing pile index where required)
- ❌ Attempt to move multiple cards outside tableau columns
- ❌ Illegal moves (e.g., card does not follow suit or rank rules)
- ❌ Attempt to move to or from a non-existent pile
- ❌ Attempt to move to the waste pile manually

The program will display an appropriate error message if a move is invalid.
