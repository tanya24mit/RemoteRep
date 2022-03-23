import random
number = random.randint(1, 100)
print(f'random number {number}')
x = int(input('Введите число:'))
while x != number:
    if x < number:
        print(f'Загаданное число больше, чем {x}')
        x = int(input('Введите число:'))
    else:
        print(f'Загаданное число меньше, чем {x}')
        x = int(input('Введите число:'))
print(f'Верно! Было загадано число {x}.')
