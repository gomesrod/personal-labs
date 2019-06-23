import datetime

now = datetime.date.today()
print(now)

print(now.strftime("%m-%d-%y. %d %b %Y is a %A on the %d day of %B."))

print()
print()

birthday = datetime.date(1981, 4, 27)
print(birthday)

age = now - birthday
print(age)
print(age.__class__)
print(age.days)
print(int(age.days / 365))

