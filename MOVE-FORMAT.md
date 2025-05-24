
- `MOVE` — słowo kluczowe oznaczające ruch przeniesienia kart
- `<FROM>` — źródłowy stos, z którego przenosimy karty
- `<TO>` — docelowy stos, do którego przenosimy karty
- `[COUNT]` — opcjonalna liczba kart do przeniesienia (domyślnie 1)

---

## Opis stosów

| Symbol | Znaczenie                 | Zakres indeksów / Uwagi                |
|--------|--------------------------|---------------------------------------|
| `T`    | Tableau (kolumny)        | Numerowane od 1 do 7 (np. T1, T3)    |
| `F`    | Foundation (fundamenty)  | Numerowane od 1 do 4 (np. F2, F4)    |
| `W`    | Waste (odkryta karta z talii) | Bez indeksu, zawsze jeden stos      |

---

## Szczegóły

- `FROM` i `TO` muszą zawierać symbol stosu oraz, jeśli dotyczy, numer stosu (np. `T3`, `F1`).
- `W` (Waste) nie ma numeru, bo jest jeden stos waste.
- `[COUNT]` jest potrzebne tylko przy przenoszeniu wielu kart jednocześnie, możliwe tylko między tableau (T).
- Przenoszenie kart między fundamentami jest niedozwolone.
- Przenoszenie kart na waste lub z waste do talii (stock) jest niedozwolone (poza komendą `DRAW`).

---

## Dozwolone ruchy

| FROM  | TO    | COUNT   | Uwagi                               |
|-------|-------|---------|------------------------------------|
| `Tn`  | `Tm`  | 1..n    | Przenoszenie sekwencji kart (COUNT)|
| `Tn`  | `Fm`  | 1       | Przenoszenie pojedynczej karty     |
| `W`   | `Tm`  | 1       | Przenoszenie pojedynczej karty     |
| `W`   | `Fm`  | 1       | Przenoszenie pojedynczej karty     |
| `Fn`  | `Tm`  | 1       | Cofnięcie ruchu z fundamentu (opcjonalne) |

---

## Przykłady

| Komenda       | Znaczenie                                             |
|---------------|-------------------------------------------------------|
| `MOVE T4 T1 3`| Przenieś 3 karty z tableau nr 4 do tableau nr 1       |
| `MOVE T7 F2`  | Przenieś 1 kartę z tableau nr 7 do fundamentu nr 2    |
| `MOVE W T3`   | Przenieś kartę z waste do tableau nr 3                 |
| `MOVE W F1`   | Przenieś kartę z waste do fundamentu nr 1               |
| `MOVE F3 T5`  | Przenieś kartę z fundamentu nr 3 do tableau nr 5 (undo) |

---

## Błędy i ograniczenia

- Niepoprawny format komendy (np. brak numeru stosu tam gdzie jest wymagany)
- Próba przeniesienia wielu kart poza tableau
- Ruchy niezgodne z zasadami gry (np. karta o nieodpowiednim kolorze lub wartości)
- Próba przeniesienia na nieistniejący stos

Program zwróci stosowny komunikat błędu.