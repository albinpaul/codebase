from bs4 import BeautifulSoup as bs
import urllib2
if __name__=="__main__":
    url=raw_input("Enter the url from codeforces")
    response = urllib2.urlopen(url)
    html = response.read()
    soupobject = bs(html, 'html.parser')
    testcases = soupobject.findAll("div", attrs={"class": "sample-test"})[0]
    inputs = testcases.findAll("div", attrs={"class": "input"})
    outputs = testcases.findAll("div", attrs={"class": "output"})


    startinginputfilename = "input"
    startingoutputfilename = "output"
    for k, v in enumerate(inputs):
        stringoftestcase = str(v.pre)
        testcase = stringoftestcase[5:-6].split("<br/>")
        with open(startinginputfilename+str(k+1), 'w') as f:
            for line in testcase:
                f.write(line+'\n')

    for k, v in enumerate(outputs):
        stringoftestcase = str(v.pre)
        testcase = stringoftestcase[5:-6].split("<br/>")
        with open(startingoutputfilename+str(k+1), 'w') as f:
            for line in testcase:
                f.write(line+'\n')
