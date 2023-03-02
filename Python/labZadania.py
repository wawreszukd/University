from os import system
from platform import system as sys
if(sys()=="Linux"):
    CLEAR = "clear"
if(sys()=="Windows"):
    CLEAR = "cls"
if(sys()=="Darwin"):
    CLEAR = "clear"


#zad 1
print("""## 1. Sprawdź wynik działań
# 0 > 1
# 0 <= 1
# 0 >= 1
# 1 == 0
# 1 == 1
# 1 != 0
# 1 != 1""")
print("Po kazdym zadaniu enter przenosi do nastepnego zadania")
print("Zad 1. Wyniki:")
print(0>1)
print(0<=1)
print(0>=1)
print(1==1)
print(1==1)
print(1!=0)
print(1!=1)
input()
system(CLEAR)
# Zad 2
print("2. Oblicz wyrażenie 2x+5y   gdzie: x,y to dowolne dwie liczby które podaje użytkownik (w konsoli)")
varX = input("x=")
varY = input("y=")
print(2*int(varX)+5*int(varY))
input()
system(CLEAR)
# zad 3
print("""
## 3. Wyświetl zdanie "Jestem a b mam c lat studiuję d",
##  gdzie : a-imie, a-nazwisko, c-liczba, d-kierunek studiów są dowolne zmienne które podaje użytkownik (wczytywane z klawiatury)""")
name = input("Imie: ")
surname = input("Nazwisko: ")
age = int(input("Wiek: "))
studies = input("Kierunek studiow: ")
print(f"Jestem {name} {surname} mam {age} lat studiuję {studies}")
input()
system((CLEAR))
# zad 4
print("## 4. Sprawdź/porównaj czy 1+2+10+20000001+4+347586970885 jest równa 321784560456434534646")
print((1+2+10+20000001+4+347586970885)==321784560456434534646)
input()
system(CLEAR)
# zad 5
print("""## 5. Sprawdź czy suma dowolnych dwóch liczb podanych przez użytkownika jest liczbą parzystą czy nieparzystą wyświetl właściwy komunikat
##   użyj operatora modulo % który zwraca resztę z dzielenia  np. 5%2   czyli 2 reszta 0""")
varA = int(input("Podaj a: "))
varB = int(input("Podaj b: "))
if (varA+varB)%2==0:
    print("Parzysta")
else:
    print("Nieparzysta")
input()
system(CLEAR)
# zad 6

end = False
while(end==False):
    system(CLEAR)
    print("""## 6. Utwórz prosty kalkulator dla 2 zmiennych podanych przez użytkownika, który obliczy: sumę, różnicę,
    ## iloczyn, iloraz, potęgę tych liczb, nie zapomnij o stosownych komentarzach informacyjnych dla użytkownika.""")
    varA = int(input("a= "))
    varB = int(input("b= "))
    choice = input("1. Dodawanie\n2. Odejmowanie\n3. Mnozenie\n4. Dzielenie\nx. Wyjscie\n")
    match choice:
        case "1":
            print(f"wynik = {varA+varB}")
            input()
        case "2":
            print(f"wynik = {varA-varB}")
            input()
        case "3":
            print(f"wynik = {varA*varB}")
            input()
        case "4":
            print(f"wynik = {varA/varB}")
            input()
        case "x":
            end=True
        case _:
            print("Podano zly wybor")
            input()
system(CLEAR)
print("## 7. Dla dowolnego x sprawdź wynik działań (x > 1 and x < 13) oraz (x != 5 or x < 0)")
varX = int(input("Podaj x: "))
print(x>1 and x<13)
print(x!=5 or x<0)
# Zadania dodatkowe:
# 1. Wykonaj mini ankietę tj. poproś użytkownika o następujące informacje: imie, nazwisko, wiek, zadaj mu pytania: "Czy zdrowo się odżywiasz?",
# , "Czy lubisz sport?" i dodatkowo 3 inne własne. Po uzyskaniu wszystkich odpowiedzi wyświetl ich podsumowanie.
# 2. Twoim zadaniem jest przygotowanie uniwersalnego i profesjonalnego życiorysu, złożonego z 5-ciu zdań, które wyświetlisz na ekranie
# Użytkownik wpisuje tylko swoje imie, nazwisko, wiek, zawód, miejsce urodzenia, zainteresowania i ... życiorys jest gotowy.
# 3. Przygotuj dla dziecka, które uczy się czytać zestaw sylab do nauki, ale zrób to inteligentnie tj.
# dziecko wpisuje na klawiaturze 1 spółgłoskę a Ty dodajesz do niej odpowiednie samogłoski i wyświetlasz całość na ekranie
# 4. Użytkownik podaje imie, sprawdź czy to imie to Janusz lub Grażyna
