from functools import cmp_to_key
class Player:
    def __init__(self, name, score):
        self.name=name
        self.score=score        
    def __repr__(self):
        return {'name':self.name,'score':self.score}
    @staticmethod    
    def comparator(a, b):
        if a.score>b.score:
            return -1
        if a.score<b.score:
            return 1
        if a.name < b.name:
            return -1
        if a.name > b.name:
            return 1
        return 0