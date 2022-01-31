from matplotlib.image import imread
import matplotlib.pyplot as plt
import numpy as np

'''
funzione per il calcolo dell'energia conservata
la formula si basa sulla divisione di due sommatorie:
1) Sommatoria che va da j=0 a k dei valori singolari;
2) Sommatoria che va da j=0 al numero totale dei valori singolari dei valori singolari
'''
def energiaConservata(k, row, valori_singolari):
	sommatoria1=0
	sommatoria2=0
	for j in range(0, k):
  		sommatoria1 += valori_singolari[j][j]
	for j in range(0, row):
  		sommatoria2 += valori_singolari[j][j]

	energia_conservata = sommatoria1 / sommatoria2

	return energia_conservata

def minApprox():
	approx = 0
	min = 0
	while approx <= 0.80:
		approx = energiaConservata(min,rows,S)
		if approx <= 0.80:
			min +=1
	return min

A = imread('cane.png')
# A è una matrice  M x N x 3, essendo un'immagine RGB
# A(:,:,1) Red A(:,:,2) Blue A(:,:,3) Green
# su una scala tra 0 e 1


X = np.mean(A,-1); # media lungo l'ultimo asse, cioè 2
img = plt.imshow(X)
img.set_cmap('gray')
plt.axis('off')
plt.show()


# If full_matrices=True (default), u and vT have the shapes (M, M) and (N, N), respectively.
# Otherwise, the shapes are (M, K) and (K, N), respectively, where K = min(M, N).
U, S, VT = np.linalg.svd(X,full_matrices=False)
S = np.diag(S)


rows = len(S)

min = minApprox()
print("valore minimo di k per cui si conserva l’80% dell’energia totale e' {}".format(min))

j=0
for r in (5,20,100,min):
	Xapprox = U[:,:r] @ S[0:r,:r] @ VT[:r,:]
	plt.figure(j+1)
	j +=1
	img = plt.imshow(Xapprox)
	img.set_cmap('gray')
	plt.axis('off')
	plt.title('r = ' + str(r))
	plt.show()
	print("Energia conservata per k = {0} e' {1}".format(r,energiaConservata(r,rows,S)))
