# Klasa-do-zarzadzania-zbiorem-prefiksow-IPv4
Zadanie rekrutacyjne

Opis projektu - projekt implementuje klasę IPv4PrefixSet, służy ona do zarządzania zbiorem prefiksów IPv4. Program ma za zadanie dopasować podany adres IP do najdłuższego prefiksu z bazy.

Instrukcja uruchomienia projektu:
- kompilacja:  g++ -o program zadanie.cpp
- uruchomienie:  ./program

Opis struktury projektu:
- zadanie.cpp - jest to plik źródłowy, zawiera kompletną implementacje klasy IPv4PrefixSet
- README.md - plik zawierający opis techniczny projektu, pełną dokumentację oraz instrukcję kompilacji
- .gitignore - plik który ignoruje pliki tymczasowe, zachowując czystość repozytorium

Krótki opis przyjętego podejścia:
W projekcie zdecydowałam się na użycie bibioteki wbudowanej STL (Jestem świadoma, że nie spełnia to w pełni warunków zadania, ale jestem osobą początkującą i znam język C++ na podstawowym poziomie i nie posiadam takich umiejętności aby samemu stworzyć własną strukturę danych. Zależało mi na wykonaniu tego zadania samodzielnie, dlatego postanowiłam skorzystać z STL)
Użyłam struktury: std::vector<std::pair<uint32_t, uint8_t>>, pozwala ona na przechowanie danych w sposób ciągły w pamięci(std::vector) oraz na logiczne połączenie adresu bazowego z długością jej maski(std::pair).
Metoda w check jest zaiplementowana tak, aby iterowała po całym zbiorze i za pomocą nakładania maski bitowej, porównywała adres IP z prefiksami z bazy.
Zwróciłam również uwagę na odpowiednią walidaję danych, np. funkcje add i del sprawdzają czy podana długość maski mieści się z zakresie 0-32 bitów.
