class train:
        def __init__(self, fileName):
                self.fileName = fileName
                self.contents = ""
                self.chain = []

        def process(self):
                f = open(self.fileName,"r")
                self.contents = f.read()
                self.createTable()
                

        def createTable(self):
                for i in range(0, len(self.contents)-1):
                        self.chain[ord(self.contents[i])][ord(self.contents[i+1])] += 1

                                 
                