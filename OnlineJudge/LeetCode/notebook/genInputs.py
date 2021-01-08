import sys
from os import listdir
from os.path import isfile
from pathlib import Path

pathSplit = "/"

class NoteGenerator:

    newline = "\n"

    institution = "leetcode"
    id = ""
    weblink = "https://leetcode-cn.com/"

    problemDir = "../problem/"
    sampleIptDir = "../sampleIpt/"
    sampleOptDir = "../sampleOpt/"
    solutionDir = "../solution/"
    codeDir = "../codes/"

    desOptFile = "./assets/file/des.tex"
    solOptFile = "./assets/file/sol.tex"

    def getFileWithEnding(self, path2dir, end):
        ans = [f for f in listdir(path2dir) 
               if (isfile(pathSplit.join([path2dir, f])) and f.endswith(end))]
        ans.sort()
        return ans

    def getFile(self, path2file):
        with open(path2file, 'r') as loadFile:
            content = loadFile.read()
        return content

    def write2File(self, path2file, content):
        with open(path2file, 'w') as fopt:
            fopt.write(content)

    def getNewLines(self, n=1):
        ans = ""
        for idx in range(n):
            ans += "\n"

        return ans

    def getSpace(self, n=1):
        ans = ""
        for idx in range(n):
            ans += " "

        return ans

    def getListing(self, file_t, path2file):
        ans = ""
        ans += "\\lstinputlisting[language=" + file_t + "]{"
        ans += path2file + "}"

        return ans

    def getLabel(self, problemlist=True):
        ans = ""
        if(problemlist):
            ans += "\\label{app:problemslist"
            ans += ":" + self.institution + ":" + self.id
            ans += "}"
        else:
            ans += "\\label{app:codeslist"
            ans += ":" + self.institution + ":" + self.id
            ans += "}"

        return ans

    def genLatex(self, prefix, content):
        return "\\" + prefix + "{" + content + "}"

    def genDes(self):
        fileList = self.getFileWithEnding(self.problemDir, "tex")
        fileList = [int(f.split(".")[0]) for f in fileList]
        fileList.sort()
        fileList = [str(item) for item in fileList]
        content = ""

        for f in fileList:
            self.id = f
            problem = self.getFile(self.problemDir + self.id + ".tex")
            sampleIpt = self.getFile(self.sampleIptDir + self.id + ".tex")
            sampleOpt = self.getFile(self.sampleOptDir + self.id + ".tex")
            solution = self.getFile(self.solutionDir + self.id + ".tex")

            content += self.genLatex(
                "subsection", 
                self.genLatex(
                    "href", 
                    self.weblink +
                    "}{" +
                    self.institution.capitalize() +
                    self.getSpace() +
                    self.id))

            content += self.genLatex(
                "label", 
                "app:problemlist:" +
                self.institution +
                ":" +
                self.id)

            content += self.getNewLines(2)

            content += self.genLatex("textbf", "Problem Description:")
            content += "\\par" + self.getNewLines(2)
            content += problem
            content += self.getNewLines(2)

            content += self.genLatex("textbf", "Sample:")
            content += "\\par" + self.getNewLines(2)
            
            content += "input:"
            content += "\\par" + self.getNewLines(2)
            content += "\\begin{lstlisting}[language=bash]"
            content += self.getNewLines()
            content += sampleIpt
            # content += self.getNewLines()
            content += "\\end{lstlisting}"
            content += self.getNewLines(2)

            content += "otput:"
            content += "\\par" + self.getNewLines(2)
            content += "\\begin{lstlisting}[language=bash]"
            content += self.getNewLines()
            content += sampleOpt
            # content += self.getNewLines()
            content += "\\end{lstlisting}"
            content += self.getNewLines(2)

            content += self.genLatex("textbf", "Solution ")
            content += "(Codes at~"
            content += self.genLatex(
                "ref",
                "app:codelist:" +
                self.institution +
                ":" +
                self.id)
            content += "):"
            content += "\\par" + self.getNewLines(2)

            content += solution
            content += self.getNewLines(3)

        return content

    def genSol(self):
        fileList = self.getFileWithEnding(self.problemDir, "tex")
        fileList = [int(f.split(".")[0]) for f in fileList]
        fileList.sort()
        fileList = [str(item) for item in fileList]
        content = ""

        for f in fileList:
            self.id = f
            path2Cpp = "../codes/" + self.id + ".cpp"
            path2Java = "../codes/" + self.id + ".java"

            codeCpp = self.getFile(path2Cpp)
            codeJava = self.getFile(path2Java)

            content += self.genLatex(
                "subsection", 
                self.genLatex(
                    "href", 
                    self.weblink +
                    "}{" +
                    self.institution.capitalize() +
                    self.getSpace() +
                    self.id))

            content += self.genLatex(
                "label", 
                "app:codelist:" +
                self.institution +
                ":" +
                self.id)
            content += self.getNewLines()

            if(len(codeCpp) > 0):
                content += self.getNewLines()
                content += self.genLatex("textbf", "C++")
                content += "\\par" + self.getNewLines()

                content += "\\lstinputlisting[language=C++]"
                content += "{" + "../codes/" + self.id + ".cpp}"
                content += self.getNewLines()

            if(len(codeJava) > 0):
                content += self.getNewLines()
                content += self.genLatex("textbf", "Java")
                content += "\\par" + self.getNewLines()

                content += "\\lstinputlisting[language=Java]"
                content += "{" + "../codes/" + self.id + ".java}"
                content += self.getNewLines()

            content += self.getNewLines(2)

        return content


if __name__ == "__main__":

    handler = NoteGenerator()

    desContent = handler.genDes()
    handler.write2File(handler.desOptFile, desContent)

    solContent = handler.genSol()
    handler.write2File(handler.solOptFile, solContent)

