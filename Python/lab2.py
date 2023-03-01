#initializing dictionary
dictionaryOfNames = {"imie": ["Tom","John","Ben"],
                     "nazwisko": ["Johnson","Bundy","Marks"],
                     "wiek":[23,43,31]}
#Menu
index = int(input("Podaj index (1-3): "))
print(f'Imie: {dictionaryOfNames["imie"][index-1]} Nazwisko: {dictionaryOfNames["nazwisko"][index-1]}, wiek: {dictionaryOfNames["wiek"][index-1]}')