# H1: Efficiente zoekbomen

## AVL-bomen

Eis: Hoogteverschil tussen twee deelbomen van elke knoop mag nooit groter zijn dan één.
Hierdoor slaat men de hoogte (of hoogteverschil) op in elke knoop.

Implementatie is ingewikkeld en structuurwijzigingen eisen veel werk (O(lg n) rotaties).

## 2-3-bomen

Eis: Elke knoop heeft twee of drie kinderen en alle bladeren hebben dezelfde diepte. 

Voorlopers van de B-trees. En ook 2-3-4-bomen bestaan voor meer flexibiliteit.


## Splay

Elke reeks operaties gaan we steeds efficiënter maken. Ook wel **move-to-root** boom genoemd. **Geamortiseerd** of ook uitgemiddeld over de reeks, is performantie per operatie goed.

## Randomized search tre

Men gaat via een RNG de boom verplicht random houden.

Voorbeeld is **treap**.