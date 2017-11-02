# 6.1 Enkelvoudige samenhang van grafen

## 6.1.1 Samenhangende componenten van een ongerichte graaf

Een ongerichte graaf heet **samenhangend**, wanneer er een weg bestaat tussen elk paar knopen. **DEZ** vindt alle knopen die met de wortel van de diepte-eerst boom (en dus ook onderling) verbonden zijn. **De ongerichte graaf is samenhangend wanneer die boom alle knopen bevat.** Bij meerdere bomen, vormt elke boom een samenhangende component. In plaats van *DEZ* kan ook *BEZ* gebruikt worden.

**Testen of een ongerichte graaf samenhangend is**, en eventueel de componenten bepalen, is:

- Theta(n+m) voor een ijle graaf,
- Theta(n²) voor een dichte graaf.

## 6.1.2 Sterk samenhangende componenten van een gerichte graaf

Een gerichte graaf met een weg tussen elk paar knopen, in beide richtingen, noemt men **sterk samenhangend** (‘strongly connected’). Een gerichte graaf noemt men **zwak samenhangend** (‘weakly connected’) als de graaf samenhangend is wanneer men de richtingen van de verbindingen achterwege laat.

Een gerichte graaf die niet sterk samenhangend is, bestaat uit sterk samenhangende componenten. Sommige graafalgoritmes maken hier gebruik van. Zo wordt er soms een **componentengraaf** opgesteld, die een knoop heeft voor elke sterk samenhangende component, en een verbinding van knoop a naar knoop b als er in de originele graaf een verbinding bestaat vanuit één van de knopen van a naar één van de knopen van b. 

Deze componentengraaf heeft geen lussen omdat ... [] (p. 61)

DEZ kan gebruikt worden om sterk samenhangende componenten te vinden. Er bestaat echter een eenvoudiger algoritme dat tweemaal DEZ gebruikt (dat een constante trager is):

1. Stel de **omgekeerde graaf** op.
2. Pas DEZ toe op deze omgekeerde graaf, met **post-order** nummering.
3. Pas DEZ toe op de oorspronkelijke graaf waarbij men als startknoop steeds de resterende knoop met het hoogste postordernummer neemt. 

**Resultaat is een diepte-eerst bos, waar de bomen de gezochte sterk samenhangende componenten zijn.**

Opmerking bij 2: Hoe groter dat nummer, des te later werd de knoop afgewerkt. 

[...] (p. 61, 62 bovenaan)

