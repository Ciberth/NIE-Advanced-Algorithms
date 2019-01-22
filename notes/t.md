
Principe
Performantie
Uitbreidingen


## Red/black Trees



## Splay Trees


## Randomized search trees


## Skip lists


```cpp
template<typename T>
void SkipList<T>::insert(T* key) {
	vector<SkipNode<T*>> update(MAXLEVEL, 0);
	SkipNode<T>* x = &header; // start at dummy header
	for(int i=MAXLEVEL-1; i>=0; i--) {
		while( x->forward.at(i) && *(x->forward.at(i).key) < *key ) {
			x = x->forward.at(i); // follow pointer
		}
		update[i] = x; 
	}
	int newLevel = randomLevel();;
	x = new SkipNode<T>(key, newLevel);

	for (int i=0; i < newLevel; i++) {
		x->forward[i] = update[i]->forward[i];
		update[i]->forward[i] = x;
	}
}

```


## Langste gemeenschappelijke deelsequentie

## B-trees

## Uitwendige hashing

## Quadtrees

## k-d trees

## Binomial queues

## Pairing heaps

## (Enkelvoudige) Samenhang van grafen

## Dubbele samenhang van ongerichte grafen

## Eulercircuits

## Bellman-Ford

## Johnson

## Transitieve sluiting

## Stroomnetwerken

## Koppelen in tweeledige grafen

## Stable marriage

## Tries

## Huffmancodering

## Patriciatries

## Ternaire zoekbomen

## Formele talen

## KMP

## Boyer-Moore

## Karp-Rabin

## Zoeken met automaten

## Shift-AND-methode

## Suffixbomen

## Suffixtabellen

## Tekstzoekmachines

## NP

## Heuristieken