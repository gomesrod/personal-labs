from pymongo import MongoClient

client = MongoClient()
db = client["tutorial"]  # or client.tutorial

col = db.filmes # or db["filmes"]
print(col)
doc = col.find_one()

print(doc)

new_movie={'categoria': 'Aventura', 'ano': 1982, 'nome': 'Goonies'}

col.insert(new_movie)

print("generated ID:", new_movie["_id"])

print("Listando filmes Aventura")
cursor = col.find({"categoria": "Aventura"})

for item in cursor:
	print(item)

client.close()

