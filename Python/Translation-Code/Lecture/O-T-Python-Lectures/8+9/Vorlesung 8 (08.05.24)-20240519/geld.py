class Geld(object):  
    __wechselkurs = {'USD':0.84998,
                     'GBP':1.39480,
                     'EUR':1.0,
                     'JPY':0.007168}         

    def __init__(self, waehrung, betrag):            
        self.waehrung = waehrung
        self.betrag = float(betrag)
    def getEuro(self):                                
        return self.betrag*self.__wechselkurs[self.waehrung]

    def __add__ (self, geld):                        #1
        a = self.getEuro()
        b = geld.getEuro()
        faktor = 1.0/self.__wechselkurs[self.waehrung]
        summe = Geld (self.waehrung, (a+b)*faktor )   #2
        return summe

    def __lt__(self, other):                         #3
        a = self.getEuro () 
        b = other.getEuro ()
        return a < b                                 #4

    def __le__(self, other):
        a = self.getEuro () 
        b = other.getEuro ()
        return a <= b

    def __eq__(self, other):
        a = self.getEuro () 
        b = other.getEuro ()
        return a == b

    def __str__(self):                               #5
        return self.waehrung + ' ' + str(round(self.betrag, 2))