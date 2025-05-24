## Dostępne komendy w grze

Podczas rozgrywki możesz używać następujących komend:

| Komenda       | Opis                                                                                      |
|---------------|-------------------------------------------------------------------------------------------|
| `MOVE`        | Przenieś określoną liczbę kart między stosami (np. `MOVE T4 T1 3`)                        |
| `DRAW`        | Odkryj kartę z talii i przenieś ją na waste (w zależności od ustawień 1 lub 3 karty)      |
| `UNDO`        | Cofnij ostatni ruch (możesz cofnąć do 3 ruchów z rzędu)                                  |
| `RESTART`     | Zresetuj aktualną rozgrywkę do stanu początkowego                                        |
| `HELP`        | Wyświetl pomoc oraz tutorial wyjaśniający zasady gry i dostępne komendy                   |
| `QUIT`        | Zakończ obecną grę i wyjdź z programu                                                   |
| `GET_DIFFICULTY` | Pobierz od użytkownika poziom trudności (np. liczba kart odkrywanych w komendzie `DRAW`) |
| `INVALID`     | Komenda nierozpoznana — program poinformuje o błędnym wpisie                             |

---

### Uwagi:

- Komenda `MOVE` ma format szczegółowo opisany w pliku MOVE-FORMAT
- Komenda `DRAW` zależy od poziomu trudności i odsłania 1 lub 3 karty z talii.
- Komenda `UNDO` umożliwia cofnięcie do 3 ostatnich ruchów, aby ułatwić naprawę błędów.
- Komenda `HELP` jest przydatna, gdy zapomnisz składnię lub zasady gry.