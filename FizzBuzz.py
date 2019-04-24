import os

triggerWords = []
triggerNumbers = []
maxNumber = 0
startNumber = 0

def menu():
    os.system('CLS')
    print("""
welcome to Fizz Buzz
1) Play a 1 player game
2) Play a multiplayer game
3) Display the answers
4) quit\n""")
    choice = input("Please enter a number to continue.\n")
    options = ["1","2","3","4"]
    while choice not in options:
        choice = input("The only valid options are 1, 2, 3 or 4\nPlease enter a number to continue.\n")
    if choice == "1":
        setupSingle()
        playOne()
    if choice == "2":
        setupMulti()
    if choice == "3":
        startupGen()
        displayResults()
        
def checkNum(num, allowOne = False):
    try:
        test = int(num)
        if test == float(num):
            if ((test > 1) and not allowOne) or((test >= 1) and  allowOne):
                return True
            else:
                print("Sorry but that was not a valid number. Please ensure you enter a positive number.")
                return False
        else:
            print("Sorry but that was not a valid number. Please ensure you enter a whole number.")
            return False
    except ValueError:
        print("Sorry but that was not a valid number. Please ensure you enter a positive number.")
        return False


def setTrigger(trigger):
    done = False
    while (not done):
        num = input("What would you like to be the number for "+trigger+"?\n")
        done = checkNum(num)
    return num



def startupGen():
    global startNumber
    done = False
    while not done:
        startNumber = input("What number would you like to start at? (recommended start number 1)\n")
        done = checkNum(startNumber, True)
        if startNumber == "1":
            done = True
    global maxNumber
    done = False
    while not done:
        maxNumber = input("What number would you like to end at? (recommended end number 30)\n")
        done = checkNum(maxNumber)
    global triggerWords
    triggerWords = ["Fizz", "Buzz"]
    global triggerNumbers
    triggerNumbers = [0,0]
    count = 0
    for each in triggerWords:
        triggerNumbers[count] = setTrigger(each)
        count +=1
    choice = input("Would you like to add any custom triggers? (y for yes, n for no)\n")
    done = False
    if choice in ["y","Y","yes"]:
        while not done:
            triggerWords.append(input("What would you like to be a trigger?\n"))
            triggerNumbers.append( setTrigger(triggerWords[count]))
            count +=1
            if (input("Would you like to add another custom trigger? (y for yes, n for no)\n") not in ["y","Y","yes"]):
                done = True
        


def setupSingle():
    global triggerWords
    global triggerNumbers
    os.system('CLS')
    print("Welcome to a single player game, before you start we need to set up the game.\n")
    startupGen()


def setupMulti():
    global triggerWords
    global triggerNumbers
    names = []
    os.system('CLS')
    print("Welcome to a multiplayer game, before you start we need to set up the game.\n")
    done = False
    while (not done):
        num = input("How many players?\n")
        done = checkNum(num)
    for each in range(int(num)):
        names.append(input("What is the name of player "+ str(each+1)+"\n"))
    startupGen()


def displayResults():
    os.system('CLS')
    global triggerWords
    global triggerNumbers
    global startNumber
    global maxNumber
    for number in range(int(startNumber),int(maxNumber)+1):
        temp = ""
        counter = 0
        found = False
        for each in triggerNumbers:
            each = int(each)
            if number % each ==0:
                temp +=  (triggerWords[counter] + " ")
                counter +=1
                found = True
        if found == False:
            temp = str(number)
        print(temp)

def playOne():
    os.system('CLS')
    global triggerWords
    global triggerNumbers
    global startNumber
    global maxNumber
    for number in range(int(startNumber),int(maxNumber)+1):
        temp = ""
        counter = 0
        found = False
        for each in triggerNumbers:
            each = int(each)
            if number % each ==0:
                temp +=  (triggerWords[counter] + " ")
                found = True
            counter +=1
        if found == False:
            temp = str(number )+ " "
        ##print(temp)
        guess = input("please enter what you think it'll be?")
        if (guess+" " == temp):
            print("correct\n")
        else:
            print("incorrect it was "+ temp+"\n")
        
menu()
