# TODO: Implementieren Sie die beiden Funktionen wie in der Aufgabenstellung beschrieben!
def func(L, x):
	odd = []
	temp = x
	while (temp < x + 10):
		temp += 1
		if (temp % 2 == 1):
			odd.append(temp)
	return odd
		
def main(n): 
	L = []
	for _n in range(20, 2*n+1):
		L.append(_n - 5)
	
	odd = func(L, n)

	temp = 0
	for i in odd:
		temp += i
	big = True if temp > 200 else False
	
	i_hex = hex(n)

	return str(odd) + str(big) + str(i_hex)
