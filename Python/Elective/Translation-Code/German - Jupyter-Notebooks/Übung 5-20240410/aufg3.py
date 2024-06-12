# TODO Aufgabe 3
import pickle
import os

def erzeugeTel():
    try:
        pfad =str(os.getcwd())      # gibt aktuellen Pfad des Arbeitsverzeichnisses
        pfad += "Geben Sie hier Ihren Pfad zur Datei telefonbuch.pkl ein"
        print(pfad)
        with open(pfad, "rb") as f:
            t = pickle.load(f)
            print("wurde geladen")
    except:
        t = {}    
        print("leeres Dictionary erzeugt")                            
    return t



# Hauptprogramm
tel = erzeugeTel()                             
