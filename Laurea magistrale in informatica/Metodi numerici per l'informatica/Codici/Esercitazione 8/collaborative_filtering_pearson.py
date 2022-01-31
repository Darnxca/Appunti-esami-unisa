
#!/usr/bin/env python
# Implementation of collaborative filtering recommendation engine


from recommendation_data import dataset
from math import sqrt
from prettytable import PrettyTable

#implementa la formula di pearson tra due utenti
def pearson_correlation(dataset,person1,person2):

	# Per ottenere entrambi gli articoli valutati
	both_rated = {}
	for item in dataset[person1]:
		if item in dataset[person2]:
			both_rated[item] = 1

	number_of_ratings = len(both_rated)

	# Verifica del numero di valutazioni in comune
	if number_of_ratings == 0:
		return 0

	# Somma tutte le preferenze di ogni utente
	person1_preferences_sum = sum([dataset[person1][item] for item in both_rated])
	person2_preferences_sum = sum([dataset[person2][item] for item in both_rated])

	# Somma i quadrati delle preferenze di ogni utente
	person1_square_preferences_sum = sum([pow(dataset[person1][item],2) for item in both_rated])
	person2_square_preferences_sum = sum([pow(dataset[person2][item],2) for item in both_rated])

	# Somma il valore del prodotto di entrambe le preferenze per ogni articolo
	product_sum_of_both_users = sum([dataset[person1][item] * dataset[person2][item] for item in both_rated])

	# Calcola la pearson score
	numerator_value = product_sum_of_both_users - (person1_preferences_sum*person2_preferences_sum/number_of_ratings)
	denominator_value = sqrt((person1_square_preferences_sum - pow(person1_preferences_sum,2)/number_of_ratings) * (person2_square_preferences_sum -pow(person2_preferences_sum,2)/number_of_ratings))
	if denominator_value == 0:
		return 0
	else:
		r = numerator_value/denominator_value
		return r

def sim(dataset,person1,person2):

	# Per ottenere entrambi gli articoli valutati
	both_rated = {}
	for item in dataset[person1]:
		if item in dataset[person2]:
			both_rated[item] = 1

	number_of_ratings = len(both_rated)

	# Verifica del numero di valutazioni in comune
	if number_of_ratings == 0:
		return 0

	# Somma tutte le preferenze di ogni utente
	person1_preferences_sum = sum([dataset[person1][item] for item in both_rated])
	person2_preferences_sum = sum([dataset[person2][item] for item in both_rated])

	# Somma i quadrati delle preferenze di ogni utente
	person1_square_preferences_sum = sum([pow(dataset[person1][item],2) for item in both_rated])
	person2_square_preferences_sum = sum([pow(dataset[person2][item],2) for item in both_rated])

	# Somma il valore del prodotto di entrambe le preferenze per ogni articolo
	product_sum_of_both_users = sum([dataset[person1][item] * dataset[person2][item] for item in both_rated])

	# Calcola la pearson score
	numerator_value = product_sum_of_both_users - (person1_preferences_sum*person2_preferences_sum/number_of_ratings)
	denominator_value = sqrt((person1_square_preferences_sum - pow(person1_preferences_sum,2)/number_of_ratings) * (person2_square_preferences_sum -pow(person2_preferences_sum,2)/number_of_ratings))
	if denominator_value == 0:
		return 0
	else:
		r = numerator_value/denominator_value
		return r

#esegue la formula di pearson su un determinato utente in confronto a tutto il resto del dataset restituendo gli item suggeriti
def user_recommendations(dataset,person):

	# Ottiene consigli per una persona utilizzando una media ponderata delle classifiche di ogni altro utente
	totals = {}
	simSums = {}
	rankings_list =[]
	for other in dataset:
		# non confronto con la stessa persona
		if other == person:
			continue
		sim = pearson_correlation(dataset,person,other)
		#print(">>>>>>>",sim)

		# ignora punteggio di 0 o minore
		if sim <=0:
			continue
		for item in dataset[other]:

			# punteggio dei film che non ho ancora visto
			if item not in dataset[person] or dataset[person][item] == 0:

			# similarita' * score
				totals.setdefault(item,0)
				totals[item] += dataset[other][item]* sim
				# somma di tutte le similarita'
				simSums.setdefault(item,0)
				simSums[item]+= sim

    # Creo la lista normalizata
	rankings = [(total/simSums[item],item) for item,total in totals.items()]
	rankings.sort()
	rankings.reverse()

	# returns the recommended items
	#recommendataions_list = [recommend_item for score,recommend_item in rankings]
	return rankings

#restituisce il numero di utente piu simili ad un determinato utente restituendo le similarità con gli altri utenti
def most_similar_users(dataset,person,number_of_users):
	# restituisce il numero_of_users (persone simili) per una data persona specifica
	scores = [(pearson_correlation(dataset,person,other_person),other_person) for other_person in dataset if  other_person != person ]

	# Ordina le persone simili in modo che la persona con il punteggio più alto appaia per prima
	scores.sort()
	scores.reverse()
	return scores[0:number_of_users]

#inverte gli indici e serve per calcolare le similarità tra gli item
def getAllFilm(dataset):
	result={}
	for person in dataset:
		for item in dataset[person]:
			result.setdefault(item,{})
			# Inverte item e persona
			result[item][person]=dataset[person][item]

	list1 =[]
	for item in result:
		list1.append(item)
	return list1

	return result

def getAllUserButNo(dataset,person):
	list1 =[]
	for user in dataset:
		if user == person:
            		continue
		list1.append(user)
	return list1

def main():
	#Risultato atteso
	userRacomendation = user_recommendations(dataset,'Toby')

	table1 = PrettyTable(['Valutazioni stimate', 'Film'])

	for x in userRacomendation:
		table1.add_row([x[0], x[1]])

	print("Valutazioni stimate per Toby:")
	print(table1)

	#indici di similarita di tutti gli utenti per Toby
	toby = most_similar_users(dataset,'Toby',10)
	table2 = PrettyTable(['Indice similarità', 'Utente'])

	for x in toby:
		table2.add_row([x[0], x[1]])

	print("\n\nIndici di similarita di tutti gli utenti per Toby:")
	print(table2)
	print("\n")

	user = getAllUserButNo(dataset,'Toby') #prendo tutti gli utenti tranne

	film = getAllFilm(dataset) #prendo tutti i film nel dataset

	#genero l'header
	header = ['Critic', 'Similarity']
	#creo le altre colonne della tabella in base a quanti film ci sono
	for nomeFilm in film:
		header.append(nomeFilm)
		header.append("S.x"+nomeFilm)

	table3 = PrettyTable(header)

	Totale = []
	SimSum = []

	# creo una riga per ogni utente
	for utente in user:
		row=[]
		row.append(utente)
		sim = pearson_correlation(dataset,'Toby',utente)
		row.append(round(sim,2))
		totale = 0
		simsum = 0
		#per ogni film che è nell'utente vedo il suo voto per il film, la sua similitudine * il voto e sommo tutti questi valori
		for i in film:
			try:
				rank = dataset[utente][i]
				row.append(round(rank,2))
				row.append(round((rank * sim),2))
				totale += rank * sim
				simsum += round(sim,2)
			except KeyError:
				row.append(0)
				row.append(0)

		table3.add_row(row)
		Totale.append(round(totale,2))
		SimSum.append(round(simsum,2))

	rowTotale = []
	rowTotale.append("Total")
	rowTotale.append(" ")

	#inserisco i totali nelle rispettive colonne creando campi vuoti
	for i in range(len(film)*2):
		if(i%2!=0):
			rowTotale.append(Totale[i%6])
		else:
			rowTotale.append(" ")


	rowSim = []
	rowSim.append("Sim.Sum")
	rowSim.append(" ")

	for i in range(len(film)*2):
		if(i%2!=0):
			rowSim.append(SimSum[i%6])
		else:
			rowSim.append(" ")

	rowTotSim = []
	rowTotSim.append("Total/Sim.Sum")
	rowTotSim.append(" ")

	for i in range(len(film)*2):
		if(i%2!=0):
			rowTotSim.append(round(Totale[i%6]/SimSum[i%6],2))
		else:
			rowTotSim.append(" ")

	table3.add_row(rowTotale)
	table3.add_row(rowSim)
	table3.add_row(rowTotSim)

	print("Prodotto tra l’indice di similarità e ogni film")
	print(table3)

main()
