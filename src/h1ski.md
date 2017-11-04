# 1.5 Skip Lists

- **Conceptueel** een meerwegsboom maar **implementatie** lijkt meer op een verzameling gelinkte lijsten. 

- Alle bladeren zitten op **dezelfde diepte**.

- Linkerkind heeft dezelfde sleutel als zijn ouder.

- Elk rechterkind heeft een broer-pointer naar het linkerkind van de rechterbroer zijn ouder. 

Hierdoor vormen de knopen op elk niveau een gelinkte lijst. Hoe hoger het niveau hoe minder knopen. Hierdoor slaat zoeken in een hoger niveau een aantal knopen over (skip). 

Bij toevoegen wordt aan de sleutel random een niveau toegekend. De sleutel wordt dan opgeslagen op dat niveau en alle onderliggende niveaus. 