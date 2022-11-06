# Example:
# while <condition>:
#     do something
#     <do something to update condition>
from decimal import Decimal

counter = 0
while counter < 5:
    # if condition:
    #   do something
    print(f'Counter value is: {counter}')
    counter += 1  # If we don’t add this line, we’ll simply enter an infinite loop
else:
    print("CodeAcademy")


counter = 0
while True:
    print("Counter", counter)
    counter += 1
    if counter > 100:
        break


amounts = [Decimal("300"), Decimal("0"), Decimal("600.25"), None, Decimal("100")]
amounts_sum = Decimal("0")  # Seems to be 1000.25, is that correct?

# while amounts can be looped:
#   add the amount to the amounts sum if and only if the amount if valid for adding
