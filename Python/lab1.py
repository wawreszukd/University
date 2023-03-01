import os
#Zad 1
#initialization of list
listOfNames = ["John","Ted","Anna","Merry","Anna","Anna","John","Terry","Max","Ben","Tom"]
# Menu
exit = False
while(exit==False):
    os.system("clear")
    choice = input("1. Wyszukaj osobe \n2. Ile osob posiada dane imie? \n3. Dodaj na koniec dane imie\n4. Posortuj i usun ostatnie \n5. Podaj 3 imiona do listy, polacz obie.\n6. Wyswietl liste \nWybor: ")
    match choice:
        case "1":
            name = input("Imie:")
            index = listOfNames.index(name)
            print(index)
            input()
        case "2":
            name = input("Imie:")
            coutOfNames = listOfNames.count(name)
            print(coutOfNames)
            input()
        case "3":
            name = input("Imie do dodania: ")
            listOfNames.append(name)
            print(listOfNames)
        case "4":
            listOfNames.sort()
            listOfNames.pop(-1)
            input()
        case "5":
            tempList = []
            for i in range(3):
                name = input(f"Podaj {i} imie do listy: ")
                tempList.append(name)
            listOfNames.extend(tempList)
        case "6":
            print(listOfNames)
            input()
        case "x":
            exit = True
        case _:
            os.system("clear")
            print("Bledny wybor, podaj x aby zamknac")
            input()

