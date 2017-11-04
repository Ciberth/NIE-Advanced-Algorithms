# 2.2 Langste gemeenschappelijke deelsequentie (LGD)

Een **deelsequentie** van een string bekomt men door nul of meer stringelementen weg te laten.

**Elke deelstring is een deelsequentie, maar niet omgekeerd.**

Een (niet per se uniek) LGD kan bepaalt worden via een **bruteforcemethode** die alle 2^n deelsequenties van string X gaat nagaan of ze een deelsequentie zijn van string Y. Voor lange strings is dit geen optie!

Er is aan alle voorwaarden voldaan om dit probleem aan te pakken via **dynamisch programmeren.**

![H2.1](/img/h2d1.png)
![H2.2](/img/h2d2.png)

```cpp

double z[][];
int g[][]
int r[][]

for(int i=1; i<=n+1; i++){
	z[i][i-1] = g[i][i-1] = q[i-1];
}

for(int k=1 ; k<=n; k++){
	for(int i=1; i<=n-k+1; i++){
		int j = i+k-1;
		g[i][j] = g[i][j-1] + p[j] + q[j];
		z[i][j] = infinity;
		for(int w=i; w<=j; w++){
			double t=z[i][w-1]+z[w+1][j]+g[i][j];
			if(t<z[i][j]){
				z[i][j] = t;
				r[i][j] = w;
			}
		}
	}
}
// Result: z[1][n]
// and rootindices in table r

```