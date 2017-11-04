# H4: Meerdimensionale gegevensstructuren

Gegevenstructure met meer dan 1 sleutel noemen we meerdimensionaal. Gegevensstructuren moeten dan toelaten om te zoeken op al die sleutels, of in een bereik van een of meerdere sleutels. Hoe meer dimensies hoe moeilijker zoeken (the curse of dimensionality). 

Elk gegeven wordt beschouwd als een punt in een meerdimensionale ruimte. Computational Geometry schiet dan te hulp.

Een meerdimensionaal punt zoeken is een speciaal geval van zoeken naar alle punten gelegen in een meerdimensionale hyperrechthoek (‘range search’).

Afspraken:

- **n** = het aantal punten
- **k** = het aantal dimensies


### Projectie 

Projectie gebruikt per dimensie een gegevenstructuur die alle punten rangschikt. Nadien overloopt men sequentieel de punten en kijkt men of deze in de hyperrechthoek ligt.

Vooral interessant bij een zoekrechthoek die een zijde heeft die de meeste punten uitsluit. 

### Rasterstructuur

Voor elk van de rastergebieden houdt men een gelinkte lijst bij met punten.

[...] (p. 49)