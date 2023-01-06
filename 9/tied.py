with open('input.txt') as f:
    lines = f.readlines()

movList = []
for line in lines:
    split = line.split(" ")
    movList.append((split[0],int(split[1].strip())))

#python...
#last ind is head

class Coords:
    def __init__(self):
        self.coords = [(0,0) for _ in range(10)]
        self.sett = {(0,0)}


    def adjust(self): 
        
        i = 9
        while (i > 0):
            (px,py) = self.coords[i-1]
            (cx,cy) = self.coords[i]

            if (px == cx and abs(py - cy) > 1):
                if py < cy: py += 1
                else: py -= 1
            elif (py == cy and abs(px - cx) > 1):
                if px < cx: px += 1
                else: px -= 1 
            elif (abs(px - cx) > 1 or abs(py- cy) > 1):
                if px < cx:
                    px += 1
                elif px > cx:
                    px -= 1
                
                if py < cy:
                    py += 1
                elif py > cy:
                    py -= 1
            
            
            self.coords[i-1] = (px,py)


            i-=1

    def memo(self):
        self.sett.update([self.coords[0]])
        print(self.coords)

    def mov(self,cx,cy,d):
        for _ in range(d):
            self.coords[9] = (self.coords[9][0]+cx,self.coords[9][1]+cy)
            self.adjust()
            self.memo()

        


coords = Coords()
for m,d in movList:
    print("next move")
    if m == 'U': coords.mov(0,1,d)
    elif m == 'D': coords.mov(0,-1,d)

    elif m == 'R': coords.mov(1,0,d)
    elif m == 'L': coords.mov(-1,0,d)


print(len(coords.sett))


