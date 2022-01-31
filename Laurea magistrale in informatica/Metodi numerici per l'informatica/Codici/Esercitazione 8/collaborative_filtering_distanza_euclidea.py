
#!/usr/bin/env python
# Implementation of collaborative filtering recommendation engine


from recommendation_data import dataset
from math import sqrt
from prettytable import PrettyTable

def similarity_score(dataset,person1,person2):

	# Rapporto di rendimento del punteggio usando la distanza euclidea tra persona1 e persona2

	both_viewed = {}		# Per ottenere entrambi gli elementi valutati per la persona1 e persona2

	for item in dataset[person1]:
		if item in dataset[person2]:
			both_viewed[item] = 1

		# Condizioni per verificare che entrambi abbiano elementi di valutazione comuni
		if len(both_viewed) == 0:
			return 0

		# Cerchiamo la distanza euclidea
		sum_of_eclidean_distance = []

		for item in dataset[person1]:
			if item in dataset[person2]:
				sum_of_eclidean_distance.append(pow(dataset[person1][item] - dataset[person2][item],2))
		sum_of_eclidean_distance = sum(sum_of_eclidean_distance)

		return 1/(1+sqrt(sum_of_eclidean_distance))


def most_similar_users(dataset,person,number_of_users):
	# restituisce il numero_of_users (persone simili) per una data persona specifica
	scores = [(similarity_score(dataset,person,other_person),other_person) for other_person in dataset if  other_person != person ]

	# Ordina le persone simili in modo che la persona con il punteggio più alto appaia per prima
	scores.sort()
	scores.reverse()
	return scores[0:number_of_users]

def user_recommendations(dataset,person):

	# Ottiene consigli per una persona utilizzando una media ponderata delle classifiche di ogni altro utente
	totals = {}
	simSums = {}
	rankings_list =[]
	for other in dataset:
		# non confronto con la stessa persona
		if other == person:
			continue
		sim = similarity_score(dataset,person,other)
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

def transformPrefs(dataset):
    result={}
    for person in dataset:
        for item in dataset[person]:
            result.setdefault(item,{})
            # Inverte item e persone
            result[item][person]=dataset[person][item]

    return result

def main():
    #Risultato atteso
    userRacomendation = user_recommendations(dataset,'Toby')

    table1 = PrettyTable(['Valutazioni stimate ', 'Film'])

    for x in userRacomendation:
        table1.add_row([x[0], x[1]])

    print("Valutazioni stimate per toby:")
    print(table1)


    #indici di similarita di tutti gli utenti per Toby
    toby = most_similar_users(dataset,'Toby',10)

    table2 = PrettyTable(['Indice similarità ', 'Utente'])

    for x in toby:
        table2.add_row([x[0], x[1]])

    print("\n\nIndici di similarita di tutti gli utenti per Toby")
    print(table2)

main()
