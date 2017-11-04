# 5.3 Pairing Heaps

Algemene boom waarvan de sleutels voldoen aan de heapvoorwaarde. Men kiest voor linkerkind en rechterbroer pointers. Wanneer verminderen van prioriteit moet ondersteund worden heeft elke knoop een extra wijzer nodig (linkerkind naar zijn ouder, rechterbroer naar zijn linkerbroer = een terugwijzer).




## Samenvoegen

Vergelijkt de wortelelementen van beide heaps. De wortel met het grootste element wordt het linkerkind van deze met het kleinste element.

## Toevoegen

Speciaal geval van samenvoegen.

## Prioriteit verminderen

Nagaan of de heapvoorwaarde ten opzichte van de ouder nog in orde is. Meestal wordt dan de knoop losgekoppeld van zijn ouder zodat hij de wortel wordt van een nieuwe heap. Nadien voegt men deze dan samen met de oorspronkelijke.

## Minimum verwijderen

Verwijderen van wortel wat voor een collectie van c heaps zorgt. Daarna moet men c-1 keer samenvoegen. 

## Willekeurig verwijderen

Los koppelen van zijn ouder zodat hij wortel wordt van de nieuwe heap. Deze dan verwijderen en rest samenvoegen met oorspronkelijke.

