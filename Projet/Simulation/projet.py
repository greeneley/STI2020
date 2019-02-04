#!/usr/bin/python3.6.4
###########################################
###########################################
# DINH THANH HAI
# 4A STI 
# SIMULATION A EVENEMENTS DISCRETS
# PROJET 2018-2019
###########################################
###########################################

# ================================
# >>>>>>>>>>> IMPORTS <<<<<<<<<<<<
# ================================

import ciw
import matplotlib.pyplot as plt
import numpy as np


# ===========================
# >>> CONSTANTES GLOBALES <<<
# ===========================

# Les valeurs sont en minutes

WARMUP   = 100
COOLDOWN = 100
MAX_SIMUL_T = 1440 # Le nombre de simulation a effectuer. Si rien n'est indique, n'effectue que 1440 simulations. 
AMELIORE_VITESSE_SERVEUR = 1 # Afi  n de diminuer le temps de reponse
AMELIORE_BANDE_PASSANTE = 1
AMELIORE_NOMBRE_SERVEUR = 1
# =======================================
# >>>>>>>>>>>>>> CLASSES <<<<<<<<<<<<<<<<
# =======================================

class Reseau(object):
    """Implementation du reseau de files d'attente du projet. Voir compte-rendu pour plus d'informations."""

    #######################
    #>>>> INIT METHOD <<<<<
    #######################

    def __init__(self, warmup_time = 0, cooldown_time = 0, a = 1 ):

        #     Initialise le reseau ainsi que les variables utiles
        #     @param int  A  Taux d'arrivee du reseau            (s)
        #     @param int  F  Taille moyenne du fichier           (Mbits)
        #     @param int  B  Taille du tampon                    (Mbits)
        #     @param int  I  Temps d'initialisation              (s)
        #     @param int  Y  Heure du serveur statique           (Y)
        #     @param int  R  Taux de serveur dynamique           (Mbits/s)
        #     @param int  S  Bande passante reseau du serveur    (Mbits/s)
        #     @param int  C  Bande passante reseau client        (Mbits/s)
        
        
       self.A           = a
       self.F           = 0.0422
       self.B           = 0.0152
       self.I           = 1
       self.Y           = 0
       self.R           = 10 * AMELIORE_VITESSE_SERVEUR
       self.S           = 1.5 * AMELIORE_BANDE_PASSANTE
       self.C           = 0.707
       self.cooldown    = cooldown_time
       self.warmup      = warmup_time
    
    # Definition du reseau

    def create_reseau(self):
            self.N = ciw.create_network(
                Arrival_distributions = [['Exponential', 1/self.A],
                                    'NoArrivals',
                                    'NoArrivals',
                                    'NoArrivals'],
                Service_distributions=
                    [['Exponential', 1/self.I],
                    ['Exponential', ( 1 / ( self.Y + (self.B/self.R)))],
                    ['Deterministic', self.S/ self.B],
                    ['Deterministic', self.C/ self.B]],
                Transition_matrices = [
                                    [0.0, 1.0, 0.0, 0.0],
                                    [0.0, 0.0, 1.0, 0.0],
                                    [0.0, 0.0, 0.0, 1.0],
                                    [0.0, 1 - self.B/self.F, 0.0, 0.0]
                                    ],
                Number_of_servers = [1, 1 * AMELIORE_NOMBRE_SERVEUR , 1, 1]
            )
            return self.N
    #END_DEF

    #############################
    # CREER DES RECORDS METHOD
    #############################

    def trial(self, reseau):
        # Effectue CREER DES SIMULATIONS
        # @param reseau     Le reseau qu'on a cree dans l'init method
        #
        
        ciw.seed(1)
        Q = ciw.Simulation(reseau)
        Q.simulate_until_max_time(self.warmup+MAX_SIMUL_T+self.cooldown)
        recs = Q.get_all_records()
        
        # ========================
        #   AFFICHIE DES RECORDS
        # ========================
        
        # for r in recs:
        #     if r.arrival_date > self.warmup and r.arrival_date < MAX_SIMUL_T:
        #         print(r)
        
        # END AFFICHIE DES RECORDS

        return recs

    ##################################################
    # RECUPER ET CALCULER LE TEMPS MOYEN DE REPONSE 
    ##################################################

    def recupere(self, recs):
        # Permet de recuper 2 informations exit_date et arrival_date
        # Grace a eux, on calcule le temps moyen de reponse (la duree de sejour)
        #
        # @param    recs    Toutes des records qu'on a cree dans le method trial
        #
        dlist = {} # dlist contient 2 informations: Key est id_number de record et Value est le nombre de fois que ce record repete
        for r in recs:
            if r.arrival_date > self.warmup and r.arrival_date < MAX_SIMUL_T:
                if r.id_number not in dlist:
                    dlist[r.id_number] = 1
                else:
                    dlist[r.id_number] += 1
        # END_FOR
        result = {} # result contient aussi 2 informations: Key est id_number de record et Value est le temps moyen de reponse de ce record
        sum = 0
        for i in dlist.keys():
            sum = 0
            for r in recs:
                if r.id_number == i and r.arrival_date > self.warmup and r.arrival_date < MAX_SIMUL_T:
                    sum += r.exit_date - r.arrival_date
            result[i] = sum/dlist[i]
            reponse_time = 0
        # END_FOR
        
        # Enfin, on retourn le temps moyen de reponse de toutes des records
        for i in result.keys():
            reponse_time += result[i]
        return (reponse_time/len(result))    
# ==========================================
# >>>>>>>>>>>>>>> MAIN <<<<<<<<<<<<<<<<<<<<<
# ==========================================

if __name__ == '__main__':
    print("============INIT=================")
    result_time = {}
    for i in np.arange(1.0,36.0, 0.1):
        projet = Reseau(WARMUP, COOLDOWN, i)
        reseau = projet.create_reseau()
        recs = projet.trial(reseau)
        result_time[i] = projet.recupere(recs)

    print("==== MOYEN TEMPS DE REPONSE ====")
    mean_result_time = 0
    for i in np.arange(1.0,36.0, 0.1):
        mean_result_time += result_time[i]
    print("moyen temps de reponse: ")
    print(mean_result_time/len(result_time))

    # CREE UNE GRAPHE 
    # DATA VISUALIZATION    

    A = []
    B = []
    for i in np.arange(1.0,36.0, 0.1):
        A.append(i)
        B.append(result_time[i])
    plt.plot(A, B)
    plt.xlabel('Arrival Rate(A)')
    plt.ylabel('Response Time (s) ')
    plt.title('Response Time Curve')
    plt.show()
