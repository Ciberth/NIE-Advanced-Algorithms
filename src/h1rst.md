# 1.4 Randomized search trees

Dankzij RNG wordt het effect van de operatievolgorde geneutraliseerd. Deze bomen blijven random ook na elke operatie.

## Treap

Combineert een **tree** met een **heap**. Elke knoop krijgt ook een **prioriteit**. Deze dient voor de *heapvoorwaarde*. Het is echter niet noodzakelijk een complete binaire boom. 

### Zoeken

Net zoals een "gewone" binaire boom.

### Toevoegen

Toevoegen gebeurt als blad en daarna houdt men rekening met de prioriteiten en wordt de knoop naar boven geroteerd. Stijgen verwijst ouderwijzers of stapel. 

### Verwijderen 

Een te verwijderen knoop krijgt de hoogst mogelijke prioriteit zodat hij naar beneden geroteerd wordt en als blad eruit gaat.