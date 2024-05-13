#########################################
# CsvConnector.py
# categories: ingest
# more info @: http://myrobotlab.org/service/CsvConnector
#########################################
# uncomment for virtual hardware
# virtual = True
import time
# crawlers publish documents
def onDocument(doc):
    print(doc)

# start the service
csvconnector = runtime.start("csvconnector","CsvConnector")

csvconnector.setFilename("crazybigdata.csv")

csvconnector.setColumns("FirstName", "LastName", "Sex", "Occupation", "Address")
csvconnector.setSeparator(";")
csvconnector.addListener("publishDocument","python","onDocument")

# start crawling
csvconnector.startCrawling()

time.sleep(5)

csvconnector.stopCrawling()
