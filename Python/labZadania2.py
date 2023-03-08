from os import system
from platform import system as sys
if(sys()=="Linux"):
    CLEAR = "clear"
if(sys()=="Windows"):
    CLEAR = "cls"
if(sys()=="Darwin"):
    CLEAR = "clear"

set_gene1 = set(['SLC19A2', 'ATP7B', 'ERBB3', 'FGFR4', 'ABCC3','GALNT14', 'ERCC1',
                'LJS19A2', 'AKM7B', 'ELLB34', 'FULR4', 'ANGC3', 'WELNT14', 'EOO1',
                'SAC19A22', 'AAAP7B', 'ERB3', 'FGR4', 'ACC3', 'GASNT14', 'ERSS4'])
set_gene2 = set(['SLC19A3', 'ATP7B', 'ERBB3', 'FGFR4', 'ABCC3','GALNT14', 'ERCC1',
                'LJS19A2', 'AKM7B', 'ELLB32', 'FULR421', 'ANGC3', 'WELNT14', 'EOO11',
                'SAC19A2', 'AAAP7B', 'ERB3', 'FGR4', 'ACC3', 'GASNT14', 'ERSS4'])
set_gene3 = set(['SLC19A3', 'ATP7B1', 'ERBB32', 'FGFR4', 'ABCC3','GALNT14', 'ERCC11',
                'LJS19A2', 'AKM7B', 'ELLB34', 'FULR4', 'ANGC3', 'WELNT15', 'EOO1',
                'SAC19A22', 'AAP7B', 'ERBB3', 'FGR4', 'ACC4', 'GASNT14', 'ERSS4'])
system(CLEAR)
print("Aby przejsc do nastepnego zadania wcisnij enter")
temp = set_gene1.intersection(set_gene2)
commonGenes = temp.intersection(set_gene3)
print(f"Wspolne geny dla wszystkich: {commonGenes}")

print(f"Wspolne geny dla 1 i 2 {set_gene1.intersection(set_gene2)} \n Wspolne geny dla 2 i 3 {set_gene2.intersection(set_gene3)} \n Wspolne geny dla 1 i 3 {set_gene1.intersection(set_gene3)}")
temp = set_gene1.difference(set_gene2)
print(f"Geny w przypadku choroby: {temp.difference(set_gene3)}")
input()
system(CLEAR)
#zad 2
lista_gene1 = ['SLC19A2', 'ATP7B', 'ERBB3', 'FGFR14', 'ABCC3','GALNT14', 'ERCC1',
                'LJS19A2', 'AKM7B', 'ELLB34', 'FULR4', 'ANGC3', 'WELNT14', 'EOO1',
                'SAC19A22', 'FGFR4', 'ERB3', 'FGR4', 'FGFR4', 'GASNT14', 'ERSS4']
indexes = list()
indexes2 = list()
temp = lista_gene1
for i in range(temp.count('FGFR4')):
    indexes.append(temp.index('FGFR4'))
    temp.remove('FGFR4')
print(f"Pozycja genow FGFR4 = {indexes}")
for i in range(temp.count('FGERA4')):
    indexes2.append(temp.index('FGERA4'))
    temp.remove('FGERA4')
print(f"Pozycja genow FGERA4 = {indexes2}")
input()
system(CLEAR)
# zad 3
text = """Emma i ja dostałyśmy instrukcje, by o 9:30 napisać o oficjalnych danych dotyczących zatrudnienia w Wielkiej Brytanii i wysłać nasze wersje do redaktora. Byłam przekonana, że Emma będzie ode mnie szybsza, ale miałam też szczerą nadzieję, że to ja będę lepsza. 
Twórca Emmy, start-up o nazwie Stealth, nazywa ją „niezależną sztuczną inteligencją” zaprojektowaną, by świadczyć profesjonalne usługi, takie jak badania i analiza. Odkąd w modzie są prognozy, że sztuczna inteligencja (ang. artificial intelligence, AI) zastąpi pracowników biurowych, w tym również dziennikarzy, chciałam to sprawdzić na własnej skórze. 
Emma rzeczywiście była szybka – dane wysłała w 12 minut. Mi zajęło to 35. Jej wersja była też lepsza, niż się spodziewałam. Fakty się zgadzały, zawarła nawet trafne treści, takie jak możliwość Brexitu (choć podzielała wątpliwą opinię, że wyjście z Unii Europejskiej byłoby niezwykle korzystne dla brytyjskiej gospodarki)."""
print(f"Ilosc wystapien slowa Emma {text.count('Emma')}")
input()
print(text.upper())
input()
system(CLEAR)
listFromText= text.split(' ')
print(listFromText)
input()
system(CLEAR)
print(f"Ilosc zdan: {text.count('.')}")
input()
system(CLEAR)
#zad 4
number = int(input("Podaj liczbe: "))
if number%2 == 0:
    print("Parzysta")
else:
    print("Nieparzysta")
input()
system(CLEAR)
length = int(input("Podaj liczbe n: "))
sum = 0
for i in range(1,length+1):
    sum+=1/i
print(sum)
input()
system(CLEAR)
