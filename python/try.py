import json
from pprint import pprint
with open('config.json','r') as f:
    data =json.load(f)

pprint (data)