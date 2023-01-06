


class dir:
    def __init__(self,prev=None,name="",lsList=[]):
        self.dirList = [] #contain other dir objects
        self.fileList = [] #(filename,sizes of files)
        self.prev = prev
        self.name = name

    def getSize(self):
        res = 0

        for fil in self.fileList:
            res += fil[1] 

        
        for dirr in self.dirList:
            res += dirr.getSize()
        
        return res 

    def dotdot(self):
        return self.prev

    def dirMem(self,name):
        for dirr in self.dirList:
            if name == dirr.name:
                return True  
        return False

    def fileMem(self,name):
        for fil in self.fileList:
            if name == fil[0]:
                return True 
        return False


    def printDir(self):
        print(self.name)
        print(f"in {self.name}, there are :"," ")
        for dirr in self.dirList:
            print(dirr.name," ")
        for fil in self.fileList:
            print(fil[0], " ")
        print("")
        for dirr in self.dirList:
            dirr.printDir()

    def findDir(self,d):
        for dirr in self.dirList:
            if dirr.name == d:
                return dirr






with open('input.txt') as f:
    lines = f.readlines()
i = 0 
base = dir()
currDir = base
while i < len(lines):
    #should always start with $
    line = lines[i]
    print(f"line: {line}")



    splitted = line.split(" ")
    if (splitted[0] != "$"):
        print(f"bruhhh, instead it {splitted[0]}")


    command = splitted[1].strip()

    if command == "cd":
        to = splitted[2].strip()
        print(splitted)
        if to != "..":
            print(f"cd'd from {currDir.name} to {to}")
            newDir = dir(currDir,to)
            if not currDir.dirMem(to):
                currDir.dirList.append(newDir)
                currDir = newDir
            else:
                currDir = currDir.findDir(to)
        else:
            print("......")
            currDir = currDir.prev

    elif command == "ls":
        print("that shit was ls")
        print(f"curr dir {currDir.name}")
        i += 1

        curr = lines[i].split(" ")

        while(i < len(lines) and lines[i].split(" ")[0].strip() != "$"):
            curr = lines[i].split(" ")
            print(curr)
            if curr[0] == "dir":
                dirName = curr[1].strip()
                print(f"dirname {dirName}")

                #if not seen yet, add it
                if  not currDir.dirMem(dirName):
                    newDir = dir(currDir,dirName)
                    currDir.dirList.append(newDir)
            else:
                print(f"file adding to {currDir.name}")
                sz = int(curr[0].strip())
                filename = curr[1].strip()
                if not currDir.fileMem(filename):
                    currDir.fileList.append((filename,sz))
                    print(currDir.fileList)
            i += 1
        continue

    else:
        print(f"command {command}ppp")
    i += 1

    
print(base.getSize())

#find all at most 100000


def findRes(d):
    res = 0
    sz = d.getSize()
    print(f"dir: {d.name}, sz: {sz}")
    if d.getSize() <= 100000:
        res += d.getSize()
    
    for dd in d.dirList:
        res += findRes(dd)
    return res

    
    

print(findRes(base))



        