import math 

with open('input.txt') as f:
    lines = f.readlines()





monkeyLineList = []
temp = []
for line in lines:
    if line == '\n':
        monkeyLineList.append(temp)
        temp = [] 

    else:
        temp.append(line.strip())

monkeyLineList.append(temp)



modList = []
monkeys = []
for monkeyLines in monkeyLineList:
    monkeyD = dict() 
    items = monkeyLines[1][16:].split(",")
    monkeyD["items"] = []
    for item in items:
        monkeyD["items"].append(int(item.strip()))

    op = monkeyLines[2][17:].split(" ") #[old * 17]

    monkeyD["op"] = op[1:] #2nd either int or 'old'


    
    test = int(monkeyLines[3][19:])
    ifT = int(monkeyLines[4][25:])
    ifF = int(monkeyLines[5][26:])
    #test - (d,t,f)

    modList.append(test)

    monkeyD["test"] = (test,ifT,ifF)

    monkeyD["i"] = 0


    monkeys.append(monkeyD)

mod = 1
for m in modList:

    mod = math.lcm(mod,m)

for round in range(10000):
    i = 0
    for monkey in monkeys:

        items = monkey["items"]
        for item in items:

            op = monkey["op"]
            
            if op[1] == "old":
                timesBy = item 
            else:
                timesBy = int(op[1])
            

            if op[0] == "*":
                nItem = item * timesBy
            else:
                nItem = item + timesBy 
            
            #nItem //= 3

            nItem = nItem % mod

            #test
            test = monkey["test"]

            if nItem % test[0] == 0:

                monkeys[test[1]]["items"].append(nItem)
            else:
                monkeys[test[2]]["items"].append(nItem)
            
            monkey["i"] += 1
        
        monkeys[i]["items"] = []

        i += 1

for monkey in monkeys:
    print(monkey["i"])

print(117395 * 109450)