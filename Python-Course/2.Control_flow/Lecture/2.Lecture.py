from decimal import Decimal

year = 1986
month = 7
day = 12
hour = 12
minute = 34

if 1900 < year < 2100 \
    and 1 <= month <= 12 \
    and 1 <= day <= 31 \
    and 0 <= hour < 24 \
    and 0 <= minute < 60:
    print(1)

print("-----------------------------------------------")

month_names = ["jan", "feb",
               "march", "apr",
               "May", "Jun"]

print("-----------------------------------------------")

if name := "Ivan":
    print(name)

print("-----------------------------------------------")

string = (
    'Lorem ipsum dolor sit amet, '
    'consectetur adipiscing elit, '
    'sed do eiusum tempor incididunt '
    'ut labore et dolore magna aliqua.'
)

print(string)

print("-----------------------------------------------")

age = 18
age_min = 25

if age < age_min:
    print("under min age")
elif age == age_min:
    print("still not grow enough")
else:
    print("you are welcome")

print("-----------------------------------------------")

print(", ".join([str(num) for num in range(2000, 3201) if num % 7 == 0 and num % 5 != 0]))

print("-----------------------------------------------")

counter = 0
while counter < 5:
    print(f"counter value is: {counter}")
    if counter == 3:
        break
    counter += 1

print("-----------------------------------------------")

bacon = 0
while bacon != 10:
    bacon += 1
    if bacon < 5:
        continue
    print(bacon)

print("-----------------------------------------------")

amounts = [Decimal("300"), Decimal("0"), Decimal("600.25"), None, Decimal("100")]
amounts_sum = Decimal("0")
index = 0

while index < len(amounts):
    if isinstance(amounts[index], Decimal):
        amounts_sum += amounts[index]
    index += 1

print(amounts_sum)


print("-----------------------------------------------")

x = 11
normal_termination = False

while x:
    x -= 1
    if x < 5:
        print("after hitting 5")
        print(x)
        continue
    print(x)
else:
    normal_termination = True

if normal_termination:
    print("normal termination")
else:
    print("abnormal termination")


print("-----------------------------------------------")

for c in [-4, 0, 3, 19]:
    print("\ninitial c =", c)
    count = 0
    while 5 > c >= 0:
        print("c = ", c)
        c += 1
        count += 1
    else:
        if c == count == 5:
            print("normal termination. c =", c)

