
#!/usr/bin/env python
# Implementation of collaborative filtering recommendation engine


from recommendation_data import dataset
from math import sqrt
from prettytable import PrettyTable

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

#Voto medio di un utente
def average_ranking(dataset,person):
	average_rank = 0;
	item_voted = 0;

	for item in dataset[person]:
	    average_rank += dataset[person][item]
	    item_voted+=1

	average_rank /= item_voted

	return average_rank

def user_recommendations(dataset,person):

	# Ottiene consigli per una persona utilizzando una media ponderata delle classifiche di ogni altro utente
	totals = {}
	simSums = {}
	rankings_list =[]

	#Voto medio di person
	average_rank = 0
	average_rank = average_ranking(dataset,person)

	#print(average_rank)

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

			    average_rank2=0
			    average_rank2= average_ranking(dataset,other)

			    # similarita' * score
			    totals.setdefault(item,0)
			    totals[item] += sim * (dataset[other][item] - average_rank2)
			    # somma di tutte le similarita'
			    simSums.setdefault(item,0)
			    simSums[item]+= sim

    # Creo la lista normalizata
	rankings = [(average_rank + total/simSums[item],item) for item,total in totals.items()]
	rankings.sort()
	rankings.reverse()

	# returns the recommended items
	#recommendataions_list = [recommend_item for score,recommend_item in rankings]
	return rankings

def main():
    toby = user_recommendations(dataset,'Toby')

    table1 = PrettyTable(['Valutazioni stimate', 'Film'])

    for x in toby:
        table1.add_row([x[0], x[1]])

    print("Valutazioni stimate per Toby:")
    print(table1)


main()
