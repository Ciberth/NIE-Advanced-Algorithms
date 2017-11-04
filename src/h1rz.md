# 1.2 Rood-zwarte bomen 

## Definitie & Eigenschappen

Een rood-zwarte boom:
- is een binaire zoekboom
- die een 2-3-4-boom simuleert

Men vervangt een 3-knoop door twee binaire knopen en een 4-knoop door drie. De soorten kind-ouderverbindingen krijgen een kleur. De originele noemt men zwart, de nieuwe rood. 

Theoretisch gezien zou de kleur bij de verbinding moeten opgeslaan worden maar het is makkelijker om dit bij de knoop te doen.

Bij een rood-zwarte boom spreekt men van bladeren bij virtuele kinderen die geen data bevatten maar wel een kleur. 

De **hoogte** wordt laag gehouden via beperkingen:

1. Elke knoop heeft een kleur.
2. Elke virtuele knoop is zwart.
3. Elke rode knoop heeft steeds twee zwarte kinderen.
4. De zwarte hoogte is overal gelijk.
5. De wortel is zwart (niet noodzakelijk wel handig). Een rode wortel kan zwart gemaakt worden.

De boom is slechts bij benadering evenwichtig!


## Zoeken

```cpp
```

## Toevoegen

### Bottom-up

Toevoegen zonder op de kleur te letten (zoals bij binaire zoekboom). We dalen af om nadien via dezelfde weg weer te stijgen via ouderpointers of een stapel.

### Top-Down

Geen ouderwijzers/stapel nodig.

```cpp
```

## Verwijderen

Op dezelfde 2 manieren als toevoegen!

## Rotaties

Behouden de inorder volgorde en de kleur blijft ook gelijk.

## Vereenvoudigde rood-zwarte bomen

Veel *speciale* gevallen. Deze vereenvoudigde bomen leg extra regels op en dit reduceert het aantal speciale gevallen.

### AA-boom

Enkel een rechterkind mag rood zijn.

### Left-leaning red-black tree

Een zwarte knoop mag alleen een rood rechterkind hebben als hij ook een rood linkerkind heeft. 