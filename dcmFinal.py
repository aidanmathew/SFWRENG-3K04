# importing necessary libraries
from tkinter import *
from tkinter import ttk
from tkinter import messagebox
import json
import os

class guiDCM:
    # defining the directory for the image logo and respective directory
    imageFilepath = "./images"
    mainImage = "/heartbeat.png"

    # creating folder which will contain json file with all users
    userFilepath = "./user"
    patientDatabase = "/database.json"
    
    def __init__(self):
        # initial check to verify the directory of the database and other files
        self.checkuserFilepath()
        
        # Defining the window for the GUI using Tkinter
        self.root = Tk()
        self.root.title("Group 9 - GUI")
        self.root.columnconfigure(0, weight = 1)
        self.root.rowconfigure((0, 2), weight = 1)
        self.root.rowconfigure(1, weight = 3)
        self.root.configure(bg='white')

        # calling functions to create the header and logo components of the screen
        self.createGuiHeader()
        self.logoCreation()
        
        # calling function to create the login component of the screen
        self.initiateLoginScreen()

        # calling the mainloop of Tk which will keep the program constantly running
        self.root.mainloop()

    # defining all of the functions relating to the database

    # checking the filepath, creating the file and the initialUser user
    def checkuserFilepath(self, initialUserUsername = ""):
        self.paitentLogin = {}

        # if doesn't exist, makes database.json
        if not os.path.exists(self.userFilepath):
            os.mkdir(self.userFilepath)

        # checking if the database.json file exists
        if os.path.isfile(self.userFilepath+self.patientDatabase):
            with open(self.userFilepath+self.patientDatabase, "r") as iFile:
                # try to load the file data
                try:
                    self.paitentLogin = json.load(iFile)
                    # if initialUser doesn't exist, this ensures that the initialUser is created
                    if ("initialUser" not in self.paitentLogin or not isinstance(self.paitentLogin["initialUser"], str)):
                        self.paitentLogin["initialUser"] = initialUserUsername
                # if the try block fails then initialUser is created
                except:
                    self.paitentLogin["initialUser"] = initialUserUsername
        # else run same as except block
        else:
            self.paitentLogin["initialUser"] = initialUserUsername
        
       # opening the file to write, and then writing the name to the json and returning the username
        with open(self.userFilepath+self.patientDatabase, "w") as oFile:
            json.dump(self.paitentLogin, oFile)
        return self.paitentLogin["initialUser"]

    # functions that define the components for the screen display

    # creating the window to breakdown into 3 rows
    def rowCheck(self, rowLocation):
        if not (rowLocation == "top" or rowLocation == "mid" or rowLocation == "bot"):
            raise ValueError('the row value is not one of the desired options.')
        else:
            if (rowLocation == "top"):
                return 0
            if (rowLocation == "mid"):
                return 1
            # else bottom row
            return 2

    # verification that the screen is in the dictionary
    def screenCheck(self, screenIDName):
        try:
            # this will return the coressponding location
            return screenIDName in self.dictOfScreens
        # dictionary created if doesn't exist yet
        except:
            self.dictOfScreens = {"top":None, "mid":None, "bot":None}
            return False

    # calling screencheck, if not true then will add frame into the dictonary
    def appendNewScreen(self, screenIDName, frame):
        if not self.screenCheck(screenIDName):
            self.dictOfScreens[screenIDName] = frame

    # this function will call create the screen on the user window
    def visibleScreen(self, screenIDName, rowLocation = "mid"):
        if screenIDName in self.dictOfScreens:
            self.rowCheck(rowLocation)
            # verification to see if a particular row is already full
            if self.dictOfScreens.get(rowLocation) is not None:
                self.dictOfScreens[rowLocation].grid_forget()
            self.dictOfScreens[rowLocation] = self.dictOfScreens[screenIDName]
            self.dictOfScreens[rowLocation].grid(row=self.rowCheck(rowLocation), column = 0, sticky = W + E + N + S)
            self.guiWindowResize()
            return True
        else:
            return False

    # this function will resize the screen based on the current screen
    def guiWindowResize(self):
        self.root.update()
        self.root.minsize(self.root.winfo_reqwidth(), self.root.winfo_reqheight())
        self.root.geometry('%dx%d' % (self.root.winfo_reqwidth(), self.root.winfo_reqheight()))
        self.root.resizable(1, 1)

    # this function will create the header of the gui by calling previous functions 
    def createGuiHeader(self):
        if self.screenCheck("screenHeaderComponent"):
            self.visibleScreen("screenHeaderComponent", "top")
            return False
        else:
            self.headerFrameArea = Frame(self.root, padx = 20, pady = 0)
            self.appendNewScreen("screenHeaderComponent", self.headerFrameArea)

            # calling visible screen to display screen
            self.visibleScreen("screenHeaderComponent", "top")
            return True

    
    # function that will add the logo in the images folder at the bottom section
    def logoCreation(self):
        if self.screenCheck("screenLogo"):
            self.visibleScreen("screenLogo", "bot")
            return False
        else:
            self.frameLogo = Frame(self.root, padx = 0, pady = 10)
            self.frameLogo.columnconfigure(0, weight = 1)
            self.appendNewScreen("screenLogo", self.frameLogo)

            # if the path exists on the operating system, then it will go and select image
            if os.path.exists(self.imageFilepath):
                self.mainImage = PhotoImage(file = self.imageFilepath + self.mainImage).subsample(2, 2)
                self.mainImageLogo = Label(self.frameLogo, image = self.mainImage)
                self.mainImageLogo.grid(row = 0, pady = 5)
            
            self.groupName = Label(self.frameLogo, text="Software 3K04 - Group 9 - 2022")
            self.groupName.grid(row = 1)

            # show screen
            self.visibleScreen("screenLogo", "bot")
            return True

    # function that will create the login screen section
    def initiateLoginScreen(self):
        # initiating valCheck as a checking value to hold stuff
        valCheck = IntVar
        if self.screenCheck("loginScreen"):
            self.visibleScreen("loginScreen")
            return False
        
        else:
            loginFont = "arial 12"
            self.frameLoginArea = Frame(self.root, padx = 20, pady = 10)
            self.frameLoginArea.columnconfigure((1, 2), weight = 1)
            self.frameLoginArea.rowconfigure((0, 1, 3), weight = 1)
            self.appendNewScreen("loginScreen", self.frameLoginArea)

            self.mainLoginTitle = Label(self.frameLoginArea, text = "Heart Care", font = "arial 30 bold")

            self.usernameTextLabel = Label(self.frameLoginArea, text = "Username", font = loginFont)
            self.passwordTextLabel = Label(self.frameLoginArea, text = "Password", font = loginFont)
            self.usernameTextEntry = ttk.Entry(self.frameLoginArea, font = loginFont)
            self.passwordTextEntry = ttk.Entry(self.frameLoginArea, font = loginFont, show = "*")

            self.userLoginButton = Button(self.frameLoginArea, text = "Sign in", command=lambda:self.loginUser())
            self.userRememberButton = ttk.Checkbutton(self.frameLoginArea, text = "Remember Me", variable = valCheck)
            self.createNewUserButton = ttk.Button(self.frameLoginArea, text = "Create New User", command = lambda:self.createNewUserScreen())
            
            self.mainLoginTitle.grid(row = 0, columnspan = 3, sticky = N)
                        
            self.usernameTextLabel.grid(row = 1, sticky = E + S)
            self.passwordTextLabel.grid(row = 2, sticky = E + N)
            self.usernameTextEntry.grid(row = 1, column = 1, columnspan = 2, padx = 5, pady = 2, sticky = W + E + S)
            self.passwordTextEntry.grid(row = 2, column = 1, columnspan = 2, padx = 5, pady = 2, sticky = W + E + N)

            self.userLoginButton.grid(row = 3, columnspan = 3, pady = 10)
            self.userRememberButton.grid(row = 4, column = 0, columnspan = 2, sticky = W)
            self.createNewUserButton.grid(row = 4, column =1, columnspan = 2, sticky = E)

            # these statements will assign string variable types and configure these values for future use
            self.usernameAsString = StringVar()
            self.passwordAsString = StringVar()
            self.usernameTextEntry.configure(textvariable=self.usernameAsString)
            self.passwordTextEntry.configure(textvariable=self.passwordAsString)

            # this will check to see if there is a remember me username from previous login
            self.usernameAsString.set(self.getUserlogin("initialUser"))
            if (self.usernameAsString.get() == ""):
                self.setButtonSelect(self.userRememberButton, '!selected')
            else:
                self.setButtonSelect(self.userRememberButton)

            # calling visible screen to show the main display
            self.visibleScreen("loginScreen")
            return True

    # Password check to ensure type safety
    def passwordTypeCheck(self, string):               
        if not isinstance(string, str):
            raise TypeError('The <string> parameter is of incorrect type and must be "str" type')
        else:
            return string

    def loginUser(self):
        # temporary variable for password
        passwordTempVar = self.passwordTypeCheck(self.passwordAsString.get())
        # clearing the password on relogin in order to preserve application safety
        self.passwordAsString.set("")

        if (self.usernameAsString.get() in self.paitentLogin and passwordTempVar == self.paitentLogin[self.usernameAsString.get()]):
            # this will store the present user
            self.currentUsername = self.usernameAsString.get()
            
            # this statement will check if the rememember me button is selected
            if not (self.userRememberButton.state() == ()):
                # if the statement is true then it will remember the current username
                self.setUserlogin("initialUser", self.usernameAsString.get())
            else:
                self.setUserlogin("initialUser", "")
                # otherwise, it will make sure that the entrybox is empty
                self.usernameAsString.set("") 

            self.assembleMainProfile()
            self.assembleMainProgram()

        # otherwise, the login was not able to occur
        else:
            messagebox.showerror("Login Unsuccessful", "The username or the password is not correct.")

    # this function will assemble the main header
    def assembleMainProfile(self):
        if self.screenCheck("profileScreen"):
            self.visibleScreen("profileScreen", "top")
            return False
        else:
            self.mainScreenHeader = Frame(self.root, padx = 20, pady = 10)
            self.mainScreenHeader.columnconfigure(0, weight = 1)
            self.appendNewScreen("profileScreen", self.mainScreenHeader)

            self.signOut = ttk.Button(self.mainScreenHeader, text = "Sign Out", command = lambda:self.patientOut())
            self.signOut.grid(row = 0, sticky = E)

            # calling visible screen in order to display the screen at top
            self.visibleScreen("profileScreen", "top")
            return True

    # this function will create the window upon a successful login
    def assembleMainProgram(self):
        if self.screenCheck("programScreen"):
            self.visibleScreen("programScreen")

            # this will reveal the stored user data
            #self.readPatientData(self.currentUsername)
            return False
        else:
            self.window = Frame(self.root, padx = 20, pady = 10)
            self.window.columnconfigure(0, weight = 1)
            self.appendNewScreen("programScreen", self.window)

            # using TKinter library in order to style the window label
            self.heading = Label(self.window, text = "Heart Care", font = "arial 30 bold")
            self.heading.grid(row = 0)

            # this will create the UI tab feature that can switch between parameters and the hardware details
            self.notebook = ttk.Notebook(self.window)
            self.notebook.grid(row = 1, column = 0, padx = 0, pady = 0, sticky = W + E + N + S)

            # initiating tabs for Pacemaker Parameters and Hardware Status
            self.paitentDataEntry = Frame(self.notebook)
            self.paitentDataEntry.columnconfigure((1, 3, 5), weight = 1)
            self.notebook.add(self.paitentDataEntry, text = "Pacemaker Attributes", padding = (10, 10))
            self.hardwareInformation = Frame(self.notebook)
            self.notebook.add(self.hardwareInformation, text = "Hardware Status", padding = (10, 10))

            # This defines the tab that contains the hardware status information
            self.boardConnection = Label(self.hardwareInformation, text = "The borad is connected/disconnected")
            self.boardSerialNum = Label(self.hardwareInformation, text = "The serial number of the board is ...")
            self.sameBoard = Label(self.hardwareInformation, text = "Is this the same board YES/NO")
            
            self.boardConnection.grid(row = 1, column = 0, padx = 5, pady = 5, sticky = W) 
            self.boardSerialNum.grid(row = 2, column = 0, padx = 5, pady = 5, sticky = W) 
            self.sameBoard.grid(row = 3, column = 0, padx = 5, pady = 5, sticky = W) 

            # this will use TKinter in order to create the dropdown UI for the Pacing Modes
            self.programModeLabel = Label(self.paitentDataEntry, text = "Select Pacing Mode:")
            self.programModeLabel.grid(row = 0, column = 0)
            self.programModeCombobox = ttk.Combobox(self.paitentDataEntry, width = 6)
            self.programModeCombobox.grid(row = 0, column = 2)
            self.programModeCombobox['values'] = ('AOO','VOO','AAI','VVI','AOOR','VOOR','VVIR','AAIR')

            # this will create the labels for the patient Data Entries
            self.data1 = Label(self.paitentDataEntry, text = "Lower Rate Limit")
            self.data2 = Label(self.paitentDataEntry, text = "Upper Rate Limit")
            self.data3 = Label(self.paitentDataEntry, text = "Atrial Amplitude")
            self.data4 = Label(self.paitentDataEntry, text = "Atrial Pules Width")
            self.data5 = Label(self.paitentDataEntry, text = "Ventrical Amplitude")
            self.data6 = Label(self.paitentDataEntry, text = "Ventrical Pules Width")
            self.data7 = Label(self.paitentDataEntry, text = "VRP")
            self.data8 = Label(self.paitentDataEntry, text = "ARP")
            self.data9 = Label(self.paitentDataEntry, text = "PVARP")
            self.data10 = Label(self.paitentDataEntry, text = "Hystersis")
            self.data11 = Label(self.paitentDataEntry, text = "Rate Smoothing")
            self.data12 = Label(self.paitentDataEntry, text = "Activity Threshold")
            self.data13 = Label(self.paitentDataEntry, text = "Reaction Time")
            self.data14 = Label(self.paitentDataEntry, text = "Respnse Factor")
            self.data15 = Label(self.paitentDataEntry, text = "Recovery Time")

            # these string variables are initiated so that the user input can be stored
            self.lowRateLim = StringVar()
            self.upperRateLim = StringVar()
            self.atrialAmp = StringVar()
            self.atrialPulesWidth = StringVar()
            self.ventricalAmp = StringVar()
            self.ventricalPulesWidth = StringVar()
            self.vrp = StringVar()
            self.arp = StringVar()
            self.pvarp = StringVar()
            self.hystersis = StringVar()
            self.rateSmoothing = StringVar()
            self.activityThreshold = StringVar()
            self.reactionTime = StringVar()
            self.responseTime = StringVar()
            self.recoveryTime = StringVar()


            # this will use TKinter in order to store the user entry into the previous string variables
            self.val1 = ttk.Entry(self.paitentDataEntry, textvariable = self.lowRateLim)
            self.val2 = ttk.Entry(self.paitentDataEntry, textvariable = self.upperRateLim)
            self.val3 = ttk.Entry(self.paitentDataEntry, textvariable = self.atrialAmp)
            self.val4 = ttk.Entry(self.paitentDataEntry, textvariable = self.atrialPulesWidth)
            self.val5 = ttk.Entry(self.paitentDataEntry, textvariable = self.ventricalAmp)
            self.val6 = ttk.Entry(self.paitentDataEntry, textvariable = self.ventricalPulesWidth)
            self.val7 = ttk.Entry(self.paitentDataEntry, textvariable = self.vrp)
            self.val8 = ttk.Entry(self.paitentDataEntry, textvariable = self.arp)
            self.val9 = ttk.Entry(self.paitentDataEntry, textvariable = self.pvarp)
            self.val10 = ttk.Entry(self.paitentDataEntry, textvariable = self.hystersis)
            self.val11 = ttk.Entry(self.paitentDataEntry, textvariable = self.rateSmoothing)
            self.val12 = ttk.Entry(self.paitentDataEntry, textvariable = self.activityThreshold)
            self.val13 = ttk.Entry(self.paitentDataEntry, textvariable = self.reactionTime)
            self.val14 = ttk.Entry(self.paitentDataEntry, textvariable = self.responseTime)
            self.val15 = ttk.Entry(self.paitentDataEntry, textvariable = self.recoveryTime)
            
            # using TKinter UI in order to align the information into a grid layout
            self.data1.grid(row = 1, column = 0, padx = 5, pady = 5)
            self.data2.grid(row = 2, column = 0, padx = 5, pady = 5)
            self.data3.grid(row = 3, column = 0, padx = 5, pady = 5)
            self.data4.grid(row = 4, column = 0, padx = 5, pady = 5)
            self.data5.grid(row = 5, column = 0, padx = 5, pady = 5)
            self.data6.grid(row = 6, column = 0, padx = 5, pady = 5)
            self.data7.grid(row = 7, column = 0, padx = 5, pady = 5)
            self.data8.grid(row = 8, column = 0, padx = 5, pady = 5)
            self.data9.grid(row = 1, column = 3, padx = 5, pady = 5)
            self.data10.grid(row = 2, column = 3, padx = 5, pady = 5)
            self.data11.grid(row = 3, column = 3, padx = 5, pady = 5)
            self.data12.grid(row = 4, column = 3, padx = 5, pady = 5)
            self.data13.grid(row = 5, column = 3, padx = 5, pady = 5)
            self.data14.grid(row = 6, column = 3, padx = 5, pady = 5)
            self.data15.grid(row = 7, column = 3, padx = 5, pady = 5)

            self.val1.grid(row = 1, column = 2)
            self.val2.grid(row = 2, column = 2)
            self.val3.grid(row = 3, column = 2)
            self.val4.grid(row = 4, column = 2)
            self.val5.grid(row = 5, column = 2)
            self.val6.grid(row = 6, column = 2)
            self.val7.grid(row = 7, column = 2)
            self.val8.grid(row = 8, column = 2)
            self.val9.grid(row = 1, column = 5)
            self.val10.grid(row = 2, column = 5)
            self.val11.grid(row = 3, column = 5)
            self.val12.grid(row = 4, column = 5)
            self.val13.grid(row = 5, column = 5)
            self.val14.grid(row = 6, column = 5)
            self.val15.grid(row = 7, column = 5)

            # creating the confirm button for the user
            self.confirmButton = ttk.Button(self.paitentDataEntry, text = "Confirm", command = lambda:self.writePatientData(self.currentUsername))
            self.confirmButton.grid(row = 11, column = 5, padx = 5, sticky = E)

            # this will display the user data that is stored
            self.readPatientData(self.currentUsername)
            
            # calling the visible screen function in order to display the screen
            self.visibleScreen("programScreen")
            return True

    # this function will be called if the button for sign-out is clicked
    def patientOut(self):
        self.root.config(menu = "")
        self.initiateLoginScreen()
        self.createGuiHeader()
        
    # this function will take the patient database and read from the local file
    def readPatientData(self, username):
        self.patientDataFile = "/"+username+".json"
        self.patientData = {}
        try:
            with open(self.userFilepath+self.patientDataFile, "r") as iFile:
                # loading the user file date
                self.patientData = json.load(iFile)

                self.programModeCombobox.set(self.patientData["pacingMode"])
                self.lowRateLim.set(self.patientData["value1"])
                self.upperRateLim.set(self.patientData["value2"])
                self.atrialAmp.set(self.patientData["value3"])
                self.atrialPulesWidth.set(self.patientData["value4"])
                self.ventricalAmp.set(self.patientData["value5"])
                self.ventricalPulesWidth.set(self.patientData["value6"])
                self.vrp.set(self.patientData["value7"])
                self.arp.set(self.patientData["value8"])
                self.pvarp.set(self.patientData["value9"])
                self.hystersis.set(self.patientData["value10"])
                self.rateSmoothing.set(self.patientData["value11"])
                self.activityThreshold.set(self.patientData["value12"])
                self.reactionTime.set(self.patientData["value13"])
                self.responseTime.set(self.patientData["value14"])
                self.recoveryTime.set(self.patientData["value15"])
                
        # if unsuccessful, then the values will be set to an empty string
        except:
            self.programModeCombobox.set("")
            self.lowRateLim.set("")
            self.upperRateLim.set("")
            self.atrialAmp.set("")
            self.atrialPulesWidth.set("")
            self.ventricalAmp.set("")
            self.ventricalPulesWidth.set("")
            self.vrp.set("")
            self.arp.set("")
            self.pvarp.set("")
            self.hystersis.set("")
            self.rateSmoothing.set("")
            self.activityThreshold.set("")
            self.reactionTime.set("")
            self.responseTime.set("")
            self.recoveryTime.set("")


    # this function will put the data into the database JSON
    def writePatientData(self, username):
        """self.pacingmode = StringVar()
        pacingmode = self.programModeCombobox.get()
        print(pacingmode)

        self.aoo = ["LRL","URL","AAMP","APW"]
        self.voo = ["LRL","URL","VAMP","VPW"]
        self.aai = ["LRL","URL","AAMP","APW","AS","ARP","PVARP","HS","RS"]
        self.vvi = ["LRL","URL","VAMP","VPW","VS","VRP","PVARP","HS","RS"]
        self.aoor = ["LRL","URL","MSR","AAMP","APW","AT","RT","RF","RCOVT"]
        self.voor = ["LRL","URL","MSR","VAMP","VPW","AT","RT","RF","RCOVT"]
        self.vvir = ["LRL","URL","MSR","VAMP","VPW","VS","VRP","PVARP","HS","RS","AT","RT","RF","RCOVT"]
        self.aair = ["LRL","URL","MSR","AAMP","APW","AS","ARP","PVARP","HS","RS","AT","RT","RF","RCOVT"]
        print("HI")
        if (pacingmode == "AOO"):
            print("HII")
            n = 0
            self.LRL = StringVar()
            self.URL = StringVar()
            self.AAMP = StringVar()
            self.APW = StringVar()
            for self.i in self.aoo:
                self.l =  Label(self.paitentDataEntry, text = pacingmode[n])
                self.l.grid(row = 1, column = 0, padx = 5, pady = 5)
                self.e = ttk.Entry(self.paitentDataEntry, textvariable = self.pacingmode[n])
                self.e.grid(row = 1, column = 2)
                n = n + 1"""

        if (int(self.lowRateLim.get()) < 30 or int(self.lowRateLim.get()) > 175):
            messagebox.showerror("Input Error","The Lower Rate Limit has to be between 30ppm and 175ppm")
            self.lowRateLim.set("")

        if (int(self.upperRateLim.get()) < 50 or int(self.upperRateLim.get()) > 175):
            messagebox.showerror("Input Error","The Upper Rate Limit has to be between 50ppm and 175ppm")
            self.upperRateLim.set("")

        if (int(self.lowRateLim.get()) > int(self.upperRateLim.get())):
            messagebox.showerror("Input Error","The Lower Rate Limit cannot be larger than the Upper Rate Limit")
            self.lowRateLim.set("")
            self.upperRateLim.set("")
        
        if (float(self.atrialAmp.get()) < 0 or float(self.atrialAmp.get()) > 5):
            messagebox.showerror("Input Error","The Arital Amplitude has to be between 0V and 5V")
            self.atrialAmp.set("")

        if (float(self.atrialPulesWidth.get()) < 0.05 or float(self.atrialPulesWidth.get()) > 1.9):
            messagebox.showerror("Input Error","The Arital Pules Width has to be between 0.05ms and 1.9ms")
            self.atrialPulesWidth.set("")

        if (float(self.ventricalAmp.get()) < 0 or float(self.ventricalAmp.get()) > 5):
            messagebox.showerror("Input Error","The Ventrical Amplitude has to be between 0V and 5V")
            self.ventricalAmp.set("")

        if (float(self.ventricalPulesWidth.get()) < 0.05 or float(self.ventricalPulesWidth.get()) > 1.9):
            messagebox.showerror("Input Error","The Ventrical Pules Width has to be between 0.05ms and 1.9ms")
            self.ventricalPulesWidth.set("")

        if (float(self.vrp.get()) < 150 or float(self.vrp.get()) > 500):
            messagebox.showerror("Input Error","The Ventrical Refactory Period has to be between 150ms and 500ms")
            self.vrp.set("")

        if (float(self.arp.get()) < 150 or float(self.arp.get()) > 500):
            messagebox.showerror("Input Error","The Atrial Refactory Period has to be between 150ms and 500ms")
            self.arp.set("")


        self.patientData = {}

        self.patientDataFile = "/"+username+".json"
        with open(self.userFilepath + self.patientDataFile, "w") as oFile:
            self.patientData["pacingMode"] = self.programModeCombobox.get()
            self.patientData["value1"] = self.lowRateLim.get()
            self.patientData["value2"] = self.upperRateLim.get()
            self.patientData["value3"] = self.atrialAmp.get()
            self.patientData["value4"] = self.atrialPulesWidth.get()
            self.patientData["value5"] = self.ventricalAmp.get()
            self.patientData["value6"] = self.ventricalPulesWidth.get()
            self.patientData["value7"] = self.vrp.get()
            self.patientData["value8"] = self.arp.get()
            self.patientData["value9"] = self.pvarp.get()
            self.patientData["value10"] = self.hystersis.get()
            self.patientData["value11"] = self.rateSmoothing.get()
            self.patientData["value12"] = self.activityThreshold.get()
            self.patientData["value13"] = self.reactionTime.get()
            self.patientData["value14"] = self.responseTime.get()
            self.patientData["value15"] = self.recoveryTime.get()
            # send the data to the file, AKA dump = writing data
            json.dump(self.patientData, oFile)
    
    # this function will determine if a user will be added to the database or not
    def registerUser(self):
        # if the length of the paitentLogin is more than 10 then the database is full
        if len(self.paitentLogin) > 10:
            messagebox.showerror("The database is full, the maximum capable users are reached", "only up to 10 users can be registered")
        # check to see if username already exists
        elif (self.registerusernameAsString.get() in self.paitentLogin or self.registerusernameAsString.get() == "initialUser"):
            messagebox.showerror("The username is not valid.", "The username already exists.")
        # check for valid username
        elif (len(self.registerusernameAsString.get()) < 4 or 20 < len(self.registerusernameAsString.get())):
            messagebox.showwarning("The username is not valid", "The username has to be 4 to 20 characters in length")
        # check for valid password
        elif (len(self.registerpasswordAsString.get()) < 5 or 25 < len(self.registerpasswordAsString.get())):
            messagebox.showwarning("The password is not valid", "The password has to be 5 to 25 characters in length")
        # check to make sure password and username are unique from each other
        elif (self.registerpasswordAsString.get() == self.registerusernameAsString.get()):
            messagebox.showwarning("The password is not valid", "Oops! The password appears to be the same as the username... that's not safe. Try again.")
        # check to make sure that the retyped password matches 
        elif not (self.registerpasswordAsString.get() == self.regStringPassword.get()):
            messagebox.showerror("The password is not valid", "Retype Password does not match")
        else:
            self.setUserlogin(self.registerusernameAsString.get(), self.passwordTypeCheck(self.registerpasswordAsString.get()))
            self.usernameAsString.set(self.registerusernameAsString.get())
            self.registerusernameAsString.set("")
            self.registerpasswordAsString.set("")
            self.regStringPassword.set("")
            messagebox.showinfo("User has been made!","Please login with user on login screen.")
    
    def getUserlogin(self, userLoginName):
        with open(self.userFilepath+self.patientDatabase, "r") as iFile:
            # reading the file
            self.paitentLogin = json.load(iFile) 
        return self.paitentLogin[userLoginName]

    def setUserlogin(self, userLoginName, userPassword):
        self.paitentLogin[userLoginName] = userPassword
        with open(self.userFilepath+self.patientDatabase, "w") as oFile:
            # writing to the file
            json.dump(self.paitentLogin, oFile)
    
    # this function will set the state of the UI button accordingly
    def setButtonSelect(self, uiButton, state = 'selected'):
        if not ("alternate" in state):
            uiButton.state(['!alternate'])
        uiButton.state([state])

    # function that will create the screen for a new user
    def createNewUserScreen(self):
        if self.screenCheck("screenRegister"):
            self.visibleScreen("screenRegister")
            return False
        else:
            loginFont = "arial 12"
            # UI configurations
            self.mainFrameReg = Frame(self.root, padx = 20, pady = 10)
            self.mainFrameReg.columnconfigure((1, 2), weight = 1)
            self.mainFrameReg.rowconfigure((0, 1, 4), weight = 1)
            self.appendNewScreen("screenRegister", self.mainFrameReg)

            self.mainTitleReg = Label(self.mainFrameReg, text = "Register", font = "arial 30 bold", height = 2)
            
            self.regUsernameText = Label(self.mainFrameReg, text = "New Username", font = loginFont)
            self.regPasswordText = Label(self.mainFrameReg, text = "New Password", font = loginFont)
            self.regPasswordReType = Label(self.mainFrameReg, text = "Confirm Password", font = loginFont)
            
            self.regUserNameEntry = ttk.Entry(self.mainFrameReg, font = loginFont)
            self.regPasswordEntry = ttk.Entry(self.mainFrameReg, font = loginFont, show = "*")
            self.regReTypePasswordEntry = ttk.Entry(self.mainFrameReg, font = loginFont, show = "*")

            self.createUserButton = ttk.Button(self.mainFrameReg, text = "Create Account", command = lambda:self.registerUser())
            self.secLoginLabel = Label(self.mainFrameReg, text = "You have an existing account")
            self.secUserButtonLogin = ttk.Button(self.mainFrameReg, text = "Login", command = lambda:self.initiateLoginScreen())
            
            # calling UI configurations to set up the aesthetics of the GUI
            self.mainTitleReg.grid(row = 0, columnspan = 3, sticky = N)
            
            self.regUsernameText.grid(row = 1, padx = 5, sticky = E + S)
            self.regPasswordText.grid(row = 2, padx = 5, sticky = E)
            self.regPasswordReType.grid(row = 3, padx = 5, sticky = E + N)
            
            self.regUserNameEntry.grid(row = 1, column = 1, columnspan = 2, pady = 2, sticky = W + E + S)
            self.regPasswordEntry.grid(row = 2, column = 1, columnspan = 2, pady = 2, sticky = W + E)
            self.regReTypePasswordEntry.grid(row = 3, column = 1, columnspan = 2, pady = 2, sticky = W + E + N)

            self.createUserButton.grid(row = 4, columnspan = 3, pady = 10)
            self.secLoginLabel.grid(row = 5, column = 0, columnspan = 2, sticky = W)
            self.secUserButtonLogin.grid(row = 5, column = 1, columnspan = 2, sticky = E)

            # initiating string variables
            self.registerusernameAsString = StringVar()
            self.registerpasswordAsString = StringVar()
            self.regStringPassword = StringVar()

            self.regUserNameEntry.configure(textvariable = self.registerusernameAsString)
            self.regPasswordEntry.configure(textvariable = self.registerpasswordAsString)
            self.regReTypePasswordEntry.configure(textvariable = self.regStringPassword)

            # calling visible screen to show the GUI
            self.visibleScreen("screenRegister")
            return True                   
            
login = guiDCM()